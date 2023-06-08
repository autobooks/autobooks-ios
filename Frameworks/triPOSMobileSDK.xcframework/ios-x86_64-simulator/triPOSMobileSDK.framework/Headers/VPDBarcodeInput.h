///
/// \file VPDBarcodeInput.h
///

#ifndef VPDBarcodeInput_h
#define VPDBarcodeInput_h

#import "VPDDevice.h"
#import "VPDBarcodeType.h"
#import "VPDBarcodeImageMode.h"
#import "VPDBarcodeLightingMode.h"

///
/// \brief Block definition for completionHandler parameter of the enable methods
///
/// Block definition for completionHandler parameter of the enable methods.
///
/// \param barcodeData The barcode data retrieved from the device.
///
/// \param barcodeType The barcode data type retrieved from the device.
///
/// \sa enableBarcodeInput
///
typedef void (^VPDBarcodeInputCompletionHandler)(NSString *barcodeData, VPDBarcodeType barcodeDataType);

///
/// \protocol VPDBarcodeInput
///
/// \brief POI barcode reader protocol
///
/// The VPDBarcodeInput protocol defines methods a POI barcode reader must implement.
///
@protocol VPDBarcodeInput <VPDDevice>

@required

///
/// \brief Power on the barcode reader
///
/// This method powers on the barcode reader. Its use is intended to be once per multiple barcode reads. The expected flow is power on the barcode reader, read any number of barcodes, then power off the barcode reader to conserver battery life. This method defaults enableAimerLights to YES, enableScanLights to YES, imageMode to VPDBarcodeImageMode1D, and  lightingMode to VPDBarcodeLightingModeShorterExposure;
///
/// \param error A pointer to an NSError. This parameter is only used if an error occurs while powering on the barcode reader.
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)powerOnBarcodeReader:(VPDBarcodeInputCompletionHandler)completionHandler errorHandler:(VPDErrorHandler)errorHandler;

///
/// \brief Power on the barcode reader
///
/// This method powers on the barcode reader. Its use is intended to be once per multiple barcode reads. The expected flow is power on the barcode reader, read any number of barcodes, then power off the barcode reader to conserve battery life.
///
/// \param enableAimerLights Enables or disables aimer lights.<br /><br /><strong>NOTE:</strong> This functionality may not be available on every device.<br /><br />
///
/// \param enableScanLights Enables or disables scan lights.<br /><br /><strong>NOTE:</strong> This functionality may not be available on every device.<br /><br />
///
/// \param imageMode Sets the image mode.<br /><br /><strong>NOTE:</strong> This functionality may differ from device to device.<br /><br />
///
/// \param lightingMode Sets the lighting mode.<br /><br /><strong>NOTE:</strong> This functionality may differ from device to device.<br /><br />
///
/// \param completionHandler A VPDBarcodeInputCompletionHandler used to return the card input.
///
/// \param errorHandler A VPDErrorHandler used to return any errors.
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)powerOnBarcodeReader:(BOOL)enableAimerLights enableScanLights:(BOOL)enableScanLights imageMode:(VPDBarcodeImageMode)imageMode lightingMode:(VPDBarcodeLightingMode)lightingMode completionHandler:(VPDBarcodeInputCompletionHandler)completionHandler errorHandler:(VPDErrorHandler)errorHandler;

///
/// \brief Power off the barcode reader
///
/// This method powers off the barcode reader.
///
/// \param error A pointer to an NSError. This parameter is only used if an error occurs while powering off the barcode reader.
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)powerOffBarcodeReader:(NSError **)error;

///
/// \brief Enable barcode input using the trigger on the device
///
/// This method enables barcode input using the trigger on the device.<br /><br /><strong>NOTE:</strong> This functionality may not be available on every device.<br /><br />
///
/// \param error A pointer to an NSError. This parameter is only used if an error occurs while enabling barcode input trigger.
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)enableBarcodeInputUsingTrigger:(NSError **)error;

///
/// \brief Enable barcode input using the trigger on the device
///
/// This method enables barcode input using the trigger on the device.<br /><br /><strong>NOTE:</strong> This functionality may not be available on every device.<br /><br />
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)enableBarcodeInputUsingTrigger __deprecated;

///
/// \brief Disable barcode using the trigger on the device
///
/// This method disables barcode input using the trigger on the device.<br /><br /><strong>NOTE:</strong> This functionality may not be available on every device.<br /><br />
///
/// \param error A pointer to an NSError. This parameter is only used if an error occurs while powering off the barcode reader.
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)disableBarcodeInputUsingTrigger:(NSError **)error;

///
/// \brief Starts a barcode scan
///
/// This method starts a barcode scan. This method allows the application to control the barcode scan without having to press the trigger on the device.<br /><br /><strong>NOTE:</strong> This functionality may not be available on every device.<br /><br />
///
/// \param error A pointer to an NSError. This parameter is only used if an error occurs while starting a barcode scan.
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)startBarcodeScan:(NSError **)error;

///
/// \brief Starts a barcode scan
///
/// This method starts a barcode scan. This method allows the application to control the barcode scan without having to press the trigger on the device.<br /><br /><strong>NOTE:</strong> This functionality may not be available on every device.<br /><br />
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)startBarcodeScan __deprecated;


///
/// \brief Stop barcode scan
///
/// This method stops a barcode scan.<br /><br /><strong>NOTE:</strong> This functionality may not be available on every device.<br /><br />
///
/// \param error A pointer to an NSError. This parameter is only used if an error occurs while powering off the barcode reader.
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)stopBarcodeScan:(NSError **)error;

@end

#endif /* VPDBarcodeInput_h */
