///
/// \file VPDIngenicoRba+Display.h
///

#ifndef VPDIngenicoRba_Display_h
#define VPDIngenicoRba_Display_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#import "VPDIngenicoRba.h"
#import "VPDDisplay.h"

@interface VPDIngenicoRbaUpdateTextItem : NSObject

typedef enum _VPDIngenicoRbaUpdateTextItemControlType
{
    VPDIngenicoRbaUpdateTextItemControlTypeTextField,
    VPDIngenicoRbaUpdateTextItemControlTypeButton,
}   VPDIngenicoRbaUpdateTextItemControlType;
    
@property (nonatomic) VPDIngenicoRbaUpdateTextItemControlType type;
    
@property (retain, nonatomic) NSString *controlId;
    
@property (retain, nonatomic) NSString *text;

+(VPDIngenicoRbaUpdateTextItem *)updateTextItemWithControlType:(VPDIngenicoRbaUpdateTextItemControlType)type controlId:(NSString *)controlId text:(NSString *)text;

@end

@interface  VPDIngenicoRba(Display) <VPDDisplay>

-(BOOL)displayFormName:(NSString *)formName updateTextItems:(NSArray<VPDIngenicoRbaUpdateTextItem *> *)updateTextItems hideButtonIds:(NSArray<NSString *> *)hideButtonIds showButtonIds:(NSArray<NSString *> *)showButtonIds error:(NSError **)error;

-(BOOL) displayIdleForm;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VPDIngenicoRba_Display_h */

