///
/// \file VPDPrint.h
///

#ifndef VPDPrint_h
#define VPDPrint_h

#import "VPDBarcodeType.h"
#import "VPDBarcodeAlignment.h"
#import "VPDBarcodeOrientation.h"
#import "VTPReceiptData.h"

///
/// \protocol VPDPrint
///
/// \brief POI print protocol
///
/// The VPDPrint protocol defines methods a POI print must implement.
///

@protocol VPDPrint <VPDDevice>

-(void)initialize;

///
/// \brief Used to print a receipt on the built-in POI device printer.
///
- (void)printReceipt;

///
/// \brief Used to print a receipt on the built-in POI device printer with receipt data.
///
/// \param receiptData The receipt data object to be printed.
///
-(void)printReceiptData:(VTPReceiptData *)receiptData;

///
/// \brief Used to print a receipt on the built-in POI device printer.
///
///\param textToPrint Used to print custom text.
///
-(void)printCustomText:(NSString *)textToPrint;

///
/// \brief Start building a new receipt for printing.  Any previous receipt data is cleared.
///
-(void)startNewReceipt;

///
/// \brief Add a line that is as long as the width of the device printer, to the receipt.
///
-(void)addSeparatorLine;
 
///
/// \brief Add an array of String objects, each on it's own line, to the receipt.
///
///\param arrayList The list of strings to be printed.
///
///\param withCenterAlignment flag to check if data to be printed needs to be center aligned

-(void)addStringArray:(NSArray<NSString *> *)arrayList withCenterAlignment:(BOOL)centerAlignmentFlag;

///
/// \brief Add a line that is right justified and 1/3 the width of the device printer to the receipt.
///
-(void)addAmountSeparatorLine;

/// \brief Used to forward the receipt on the device printer.
///
/// \param forwardMargin How far to foward device printer.
///
-(void)forwardReceipt:(NSInteger)forwardMargin;

///
/// \brief Add signature line to receipt.
///
-(void)addSignatureLine;

///
/// \brief Add centered text to receipt.
///
/// \param textLine Text to add to center of receipt
///
- (void)addCenteredTextLineOnReceipt:(NSString *)textLine;

///
/// \brief Add left justified text with right justified text on receipt.
///
/// \param leftText Text to add to left side of receipt
///
/// \param rightText Text to add to right side of receipt
///
-(void)addLeftJustifiedTextWithRightJustifiedText:(NSString *)leftText rightText:(NSString *)rightText;

///
/// \brief Adds a 3 column row - with data in each column going to next line if there is any overflow
///
/// \param column1WidthPercentage Width of first column
///
/// \param column2WidthPercentage Width of second column
///
/// \param col1Text Text in first column
///
/// \param col2Text Text in second (middle) column
///
/// \param col3Text Text third column
///
-(void)addThreeColumnsWithColumn1WidthPercentage:(double)column1WidthPercentage  column2WidthPercentage:(double) column2WidthPercentage col1Text:(NSString *)col1Text col2Text:(NSString *)col2Text col3Text:(NSString *)col3Text;

///
/// \brief Add new line to receipt.
///
-(void)addNewLineOnReceipt;

///
/// \brief Add text to receipt.
///
/// \param text Text to add to receipt.
///
- (void)addTextToReceipt:(NSString *)text;

///
/// \brief Sends the current receipt to the device printer for printing
///
-(void)sendCurrentJobToPrinter;

///
/// \brief Sends the current receipt to the device printer for printing
///
/// \param barcodeData barcode data
///
/// \param barcodeType barcode format
///
/// \param barcodeHeight barcode height in pixels
///
/// \param barcodeWidth barcode width in pixels
///
/// \param alignment barcode alignment
///
/// \param orientation barcode orientation

-(void)printBarcode:(NSString *)barcodeData barcodeType:(VPDBarcodeType)barcodeType barcodeHeight:(NSUInteger)barcodeHeight barcodeWidth:(NSUInteger)barcodeWidth barcodeAlignment:(VPDBarcodeAlignment)alignment barcodeOrientation:(VPDBarcodeOrientation)orientation;

@end

#endif /* VPDPrint_h */
