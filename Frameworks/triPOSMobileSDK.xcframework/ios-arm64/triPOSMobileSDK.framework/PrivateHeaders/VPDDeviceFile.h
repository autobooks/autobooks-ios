//
//  VPDDeviceFile.h
//  triPOSMobileSDK
//
//  Created on 12/17/24.
//  Copyright © 2024 Worldpay from FIS. All rights reserved.
//

#ifndef VPDDeviceFile_h
#define VPDDeviceFile_h

@interface VPDDeviceFile : NSObject

@property (retain, nonatomic) NSString *name;

@property (retain, nonatomic) NSString *version;

@property (retain, nonatomic) NSString *fileHash;

@property (retain, nonatomic) NSString *filePath;

@property (assign, nonatomic) NSString *type;

@property (nonatomic) BOOL requiresReboot;

@property (nonatomic) int order;

@property (retain, nonatomic) NSString *fileTitle;

-(NSString *)toString;

-(BOOL)isValidFileForModel :(NSString *)model error:(NSError **)error;

-(BOOL)isValidFileForModel :(NSString *)model error:(NSError **)error bundle:(NSBundle *)bundle;

-(instancetype)initWithName:(NSString *)name version:(NSString *)version fileHash:(NSString *)fileHash fileType:(NSString *) fileType order:(int)order fileTitle:(NSString *)fileTitle requireReboot:(BOOL)requireReboot;

@end

#endif /* VPDDeviceFile_h */
