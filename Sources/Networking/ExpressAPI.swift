//
//  ExpressAPI.swift
//  Autobooks
//
//  Created by Donovan Cotter on 1/25/23.
//

import Foundation

#if canImport(FoundationNetworking)
import FoundationNetworking
#endif

@available(iOS 13.0.0, *)
final class ExpressAPI {
    init() {}
    
    func performTransaction(for amount: Decimal, merchantCredentials: MerchantCredentials, ticketNumber: String, referenceNumber: String) async throws -> Result<ExpressTransaction, APIError> {
        let doubleValue = Double(truncating: amount as NSNumber)
        let formattedAmount = String(format: "%.2f", doubleValue)
        
        let xmlRequest = """
                <CreditCardSale xmlns="https://transaction.elementexpress.com">
                    <Credentials>
                        <AccountID>\(merchantCredentials.accountId)</AccountID>
                        <AccountToken>\(merchantCredentials.accountToken)</AccountToken>
                        <AcceptorID>\(merchantCredentials.acceptorId)</AcceptorID>
                    </Credentials>
                    <Application>
                        <ApplicationID>\(merchantCredentials.applicationId)</ApplicationID>
                        <ApplicationName>\(merchantCredentials.applicationName)</ApplicationName>
                        <ApplicationVersion>\(merchantCredentials.applicationVersion)</ApplicationVersion>
                    </Application>
                    <Card>
                        <MagneprintData></MagneprintData>
                        <EncryptedTrack2Data></EncryptedTrack2Data>
                        <EncryptedTrack1Data></EncryptedTrack1Data>
                        <EncryptedCardData></EncryptedCardData>
                        <CardDataKeySerialNumber></CardDataKeySerialNumber>
                        <EncryptedFormat></EncryptedFormat>
                        <Track2Data></Track2Data>
                        <Track1Data></Track1Data>
                        <CardNumber>4761739001020076</CardNumber>
                        <ExpirationMonth>12</ExpirationMonth>
                        <ExpirationYear>20</ExpirationYear>
                        <CVV>123</CVV>
                    </Card>
                    <Transaction>
                        <TransactionAmount>\(formattedAmount)</TransactionAmount>
                        <MarketCode>0</MarketCode>
                        <ReferenceNumber>\(referenceNumber)</ReferenceNumber>
                        <TicketNumber>\(ticketNumber)</TicketNumber>
                        <PartialApprovedFlag>1</PartialApprovedFlag>
                        <DuplicateCheckDisableFlag>1</DuplicateCheckDisableFlag>
                        <PaymentType>0</PaymentType>
                        <SubmissionType>0</SubmissionType>
                        <NetworkTransactionID></NetworkTransactionID>
                    </Transaction>
                    <Terminal>
                        <TerminalID>0001</TerminalID>
                        <TerminalType>0</TerminalType>
                        <TerminalCapabilityCode>0</TerminalCapabilityCode>
                        <TerminalEnvironmentCode>0</TerminalEnvironmentCode>
                        <CardPresentCode>0</CardPresentCode>
                        <CVVPresenceCode>0</CVVPresenceCode>
                        <CardInputCode>0</CardInputCode>
                        <CardholderPresentCode>0</CardholderPresentCode>
                        <MotoECICode>0</MotoECICode>
                    </Terminal>
                    <ExtendedParameters>
                    </ExtendedParameters>
                </CreditCardSale>
        """
        
        let url = URL(string: "https://certtransaction.elementexpress.com")!
        var request = URLRequest(url: url)
        request.httpMethod = "POST"
        request.httpBody = xmlRequest.data(using: .utf8)
        request.addValue("text/xml", forHTTPHeaderField: "Content-Type")
        
        return try await withCheckedThrowingContinuation { continuation in
            let task = URLSession(configuration: .default).dataTask(with: request) { data, response, error in
                switch (data, response, error) {
                case let (_, _, error?):
                    continuation.resume(returning: .failure(.unknown(error)))
                case let (data?, _?, _):
                    let parser = XMLParser(data: data)
                    let delegate = ExpressTransactionParserDelegate()
                    parser.delegate = delegate
                    
                    if parser.parse() {
                        continuation.resume(returning: .success(delegate.expressTransaction))
                    } else {
                        continuation.resume(returning: .failure(.unknown(parser.parserError!)))
                    }
                default:
                    continuation.resume(returning: .failure(.unknown(error!)))
                }
            }
            task.resume()
        }
    }
}
