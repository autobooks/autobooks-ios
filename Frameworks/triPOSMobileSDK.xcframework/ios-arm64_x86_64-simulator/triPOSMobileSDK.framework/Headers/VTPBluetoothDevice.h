///
/// \file  VTPBluetoothDevice.h
///

#ifndef VTPBluetoothDevice_h
#define VTPBluetoothDevice_h


NS_ASSUME_NONNULL_BEGIN

///
/// \brief Information about individual bluetooth devices returned from device scan.
///
@interface VTPBluetoothDevice : NSObject

///
/// \brief Serial Number
///
/// The serial number of the Bluetooth device.
///
@property (nullable, nonatomic, strong) NSString * serialNumber;

///
/// \brief Manufacturer
///
/// The manufacturer of the Bluetooth device.
///
@property (nullable, nonatomic, strong) NSString * manufacturer;

///
/// \brief Model
///
/// The model of the Bluetooth device.
///
@property (nullable, nonatomic, strong) NSString * model;

///
/// \brief Designationed Initializer
///
/// \param manufacturer  manufacturer of the Bluetooth device.
///
/// \param model The model of the Bluetooth device.
///
/// \param serialNumber The serial number of the Bluetooth device.
///
///
-(instancetype) initWithManufacturer:(NSString*) manufacturer model: (NSString*) model serialNumber:(NSString*) serialNumber;

@end

NS_ASSUME_NONNULL_END

#endif /* VTPBluetoothDevice_h */
