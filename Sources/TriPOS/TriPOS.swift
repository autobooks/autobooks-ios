#if canImport(triPOSMobileSDK)
@_implementationOnly import triPOSMobileSDK

@available(iOS 15, *)
final class TriPOS {
    private let configuration: VTPConfiguration
    private let vtp = triPOSMobileSDK.sharedVtp()! as! VTP
    
    // this is just to determine if it's a real device or not
    // It also doesn't initialize the SDK but setups up the config as well as determines the iOS version support with: @available(iOS 15, *)
    init(device: AB.Device, mode: AB.DeviceMode) {
        let configuration = VTPConfiguration()
        
        configuration.hostConfiguration.applicationName = "Autobooks SDK"
        configuration.hostConfiguration.applicationVersion = AB.version
        
        configuration.deviceConfiguration.terminalId = "0001"
        
        configuration.transactionConfiguration.isGiftCardAllowed = false
        configuration.transactionConfiguration.currencyCode = VTPCurrencyCodeUsd
        configuration.transactionConfiguration.marketCode = VTPMarketCodeRetail
        configuration.transactionConfiguration.arePartialApprovalsAllowed = false // Needs to be true for certification?
        configuration.transactionConfiguration.areDuplicateTransactionsAllowed = true // TODO: Track separately for simulated vs. real device.
        configuration.transactionConfiguration.isCashbackAllowed = false
        configuration.transactionConfiguration.quickChipEnabled = true
        configuration.transactionConfiguration.isDebitAllowed = true
        configuration.transactionConfiguration.isEmvAllowed = true
        
        switch mode {
        case .automatic:
            #if DEBUG
            configuration.applicationConfiguration.mode = VTPApplicationModeTestCertification
            #else
            configuration.applicationConfiguration.mode = VTPApplicationModeProduction
            #endif
        case .certification:
            configuration.applicationConfiguration.mode = VTPApplicationModeTestCertification
        case .production:
            configuration.applicationConfiguration.mode = VTPApplicationModeProduction
        }
        
        configuration.applicationConfiguration.idlePrompt = "\nAutobooks SDK"
        
        switch device {
        case .simulated:
            configuration.deviceConfiguration.deviceType = VTPDeviceTypeNull
                
            configuration.hostConfiguration.acceptorId = "3928907"
            configuration.hostConfiguration.accountId = "1045826"
            configuration.hostConfiguration.accountToken = "079701FC1CBBEACDC0353ADFD246B965965C19C69BE2BC2B102DBCD524A78301A2AC6D01"
            configuration.hostConfiguration.applicationId = "1234"
            configuration.hostConfiguration.storeCardID = "631522003"
            configuration.hostConfiguration.storeCardPassword = "xyz"
        case let .real(ipAddress):
            configuration.deviceConfiguration.deviceType = VTPDeviceTypeAppleTapToPay
            configuration.deviceConfiguration.terminalType = VTPTerminalTypePointOfSale
            configuration.deviceConfiguration.tcpIpConfiguration = VTPDeviceTcpIpConfiguration()
            configuration.deviceConfiguration.tcpIpConfiguration.ipAddress = ipAddress
            configuration.deviceConfiguration.tcpIpConfiguration.port = 12000
            configuration.deviceConfiguration.isKeyedEntryAllowed = true
            configuration.deviceConfiguration.isContactlessEntryAllowed = true
                
            configuration.storeAndForwardConfiguration.shouldTransactionsBeAutomaticallyForwarded = false
        }
            
        self.configuration = configuration
    }

    deinit {
        Log.triPOS.info("*** TriPOS deinit")
        do {
            try vtp.deinitialize()
        } catch {
            Log.triPOS.error("*** VTP failed to deinitialize: \(error)")
        }
    }

    private func setupHostConfiguration(merchantCredentials: MerchantCredentials? = nil) {
        configuration.hostConfiguration.applicationId = merchantCredentials?.applicationId ?? "2342"
        configuration.hostConfiguration.acceptorId = merchantCredentials?.acceptorId ?? "364802200"
        configuration.hostConfiguration.accountId = merchantCredentials?.accountId ?? "1234052"
        configuration.hostConfiguration.accountToken = merchantCredentials?.accountToken ?? "7341786DC28710A1C8DA10871C74E27D5F857EAC594C29F2F9EA9788B88B0DD79272C001"
    }

    // pass merchant credentials in as an argument, set the hostConfiguration credentials here before self.configuration = configuration
    // don't have access to the device here for .simulated vs real
    // func start(merchantCredentials:MerchantCredentials) async -> Result<Nothing, APIError>
    func start(merchantCredentials: MerchantCredentials?) async -> Result<Nothing, APIError> {
        setupHostConfiguration(merchantCredentials: merchantCredentials)
        
        final class Initializer: NSObject, VTPDelegate {
            private let vtp: VTP
            private let configuration: VTPConfiguration
            private let continuation: CheckedContinuation<Result<Nothing, APIError>, Never>

            init(vtp: VTP, configuration: VTPConfiguration, continuation: CheckedContinuation<Result<Nothing, APIError>, Never>) {
                self.vtp = vtp
                self.configuration = configuration
                self.continuation = continuation

                super.init()

                vtp.add(self)
            }

            deinit {
                Log.triPOS.info("*** Initializer deinit")
            }

            func initialize() {
                /*
                 - Without wrapping this inside of DispatchQueue.main.async there is a purple warning "[UIApplication applicationState] must be used from main thread only"
                 - It was causing a weird UI issue with the Loading screen where text from different loading states were being displayed on top of each other. Specifically with "Logging in" and "Setting up triPOS"
                 - "vtp.initialize" might be calling the application.state directly somewhere
                 */
                DispatchQueue.main.async {
                    do {
                        try self.vtp.initialize(with: self.configuration)
                        Log.triPOS.info("*** vtp.initialize")
                    } catch {
                        Log.triPOS.error("*** vtp.initialize failed: \(error)")
                        self.cleanup()
                        self.continuation.resume(returning: .failure(.triPOS(.underlying(error))))
                    }
                }
            }

            func cleanup() {
                Log.triPOS.info("*** Initializer cleanup")
                vtp.remove(self)
            }

            func deviceDidError(_ error: Error!) {
                Log.triPOS.error("*** deviceDidError: \(String(describing: error))")

                cleanup()
                continuation.resume(returning: .failure(.triPOS(.underlying(error))))
            }

            func deviceDidConnect(_ description: String!, model: String!, serialNumber: String!) {
                Log.triPOS.info("*** deviceDidConnect: \(String(describing: description))")

                cleanup()
                continuation.resume(returning: .success(.init()))
            }
        }

        return await Task.detached { [vtp, configuration] in
            await withCheckedContinuation { continuation in
                Initializer(vtp: vtp, configuration: configuration, continuation: continuation).initialize()
            }
        }.value
    }

    func performSale(of amount: PaymentAmount, ticketNumber: String, referenceNumber: String, uuid: UUID) async -> Result<VTPSale, APIError> {
        let saleRequest = VTPSaleRequest()
        saleRequest.cardholderPresentCode = VTPCardHolderPresentCodePresent
        saleRequest.clerkNumber = "1"
        saleRequest.convenienceFeeAmount = nil
        saleRequest.laneNumber = "01"
        saleRequest.referenceNumber = referenceNumber
        saleRequest.salesTaxAmount = nil
        saleRequest.shiftID = "1"
        saleRequest.ticketNumber = ticketNumber
        saleRequest.tipAmount = nil
        saleRequest.transactionAmount = NSDecimalNumber(decimal: amount.decimal)

        return await withCheckedContinuation { continuation in
            vtp.processSaleRequest(saleRequest) { response in
                guard let response else {
                    continuation.resume(returning: .failure(.triPOS(.invalidCompletion)))
                    return
                }

                // If there's no card number, this handler should be ignored and the continuation completed in the error handler.
                guard response.card.maskedAccountNumber != nil else {
                    return
                }

                guard response.transactionStatus != VTPTransactionStatusDeclined else {
                    continuation.resume(returning: .failure(.triPOS(.transactionDeclined)))
                    return
                }

                guard let id = response.host.transactionID
                else {
                    continuation.resume(returning: .failure(.triPOS(.missingValue)))
                    return
                }
                
                let vtpSaleResponse = VTPSale(uuid: uuid, transactionID: id)
                
                Log.triPOS.info("*** Sale succeeded: \(response)")
                continuation.resume(returning: .success(vtpSaleResponse))
            } errorHandler: { error in
                guard let error else {
                    continuation.resume(returning: .failure(.triPOS(.invalidCompletion)))
                    return
                }

                Log.triPOS.error("*** Sale failed due to error: \(error)")
                continuation.resume(returning: .failure(.triPOS(.underlying(error))))
            }
        }
    }
}

#else

@available(iOS 13.0.0, *)
final class TriPOS {
    private let device: AB.Device

    init(device: AB.Device) {
        self.device = device
    }

    func start() async -> Result<Nothing, APIError> {
        .success
    }
}

#endif

enum TriPOSError: Error {
    case invalidCompletion
    case missingValue
    case transactionDeclined
    case underlying(Swift.Error)
}

extension TriPOSError: Equatable {
    static func == (lhs: TriPOSError, rhs: TriPOSError) -> Bool {
        switch (lhs, rhs) {
        case (.invalidCompletion, .invalidCompletion),
             (.missingValue, .missingValue),
             (.transactionDeclined, .transactionDeclined):
            return true
        case let (.underlying(lhsError), .underlying(rhsError)):
            return lhsError.localizedDescription == rhsError.localizedDescription
        default:
            return false
        }
    }
}
