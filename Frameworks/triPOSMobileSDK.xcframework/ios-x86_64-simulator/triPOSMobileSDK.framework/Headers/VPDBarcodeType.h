///
/// \file VPDBarcodeType.h
///

#ifndef VPDBarcodeType_h
#define VPDBarcodeType_h

///
/// \enum VPDBarcodeType
///
typedef enum _VPDBarcodeType
{
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    _VPDBarcodeTypeMinimum,
#endif
    
    /// Unknown
    VPDBarcodeTypeUnknown = _VPDBarcodeTypeMinimum,
    /// EAN-8
    VPDBarcodeTypeEan8,
    /// EAN-8 2
    VPDBarcodeTypeEan8_2,
    /// EAN-8 5
    VPDBarcodeTypeEan8_5,
    /// EAN-8 composite CC-A
    VPDBarcodeTypeEan8CompositeCcA,
    /// EAN-8 composite CC-B
    VPDBarcodeTypeEan8CompositeCcB,
    /// EAN-13
    VPDBarcodeTypeEan13,
    /// EAN-13 2
    VPDBarcodeTypeEan13_2,
    /// EAN-13 5
    VPDBarcodeTypeEan13_5,
    /// EAN-13 composite CC-A
    VPDBarcodeTypeEan13CompositeCcA,
    /// EAN 13 composite CC-B
    VPDBarcodeTypeEan13CompositeCcB,
    /// UPC-A
    VPDBarcodeTypeUpcA,
    /// UPC-A 2
    VPDBarcodeTypeUpcA_2,
    /// UPC-A 5
    VPDBarcodeTypeUpcA_5,
    /// UPC-A composite CC-A
    VPDBarcodeTypeUpcACcA,
    /// UPC-A composite CC-B
    VPDBarcodeTypeUpcACcB,
    /// UPC-E
    VPDBarcodeTypeUpcE,
    /// UPC-E 2
    VPDBarcodeTypeUpcE_2,
    /// UPC-E 5
    VPDBarcodeTypeUpcE_5,
    /// UPC-E composite CC-A
    VPDBarcodeTypeUpcECcA,
    /// UPC-E composite CC-B
    VPDBarcodeTypeUpcECcB,
    /// Code 39
    VPDBarcodeTypeCode39,
    /// Code 39 Italian CPI
    VPDBarcodeTypeCode39ItalianCpi,
    /// Interleaved 2 of 5
    VPDBarcodeTypeInterleaved2Of5,
    /// Standard 2 of 5
    VPDBarcodeTypeStandard2Of5,
    /// Matrix 2 of 5
    VPDBarcodeTypeMatrix2Of5,
    /// Codabar
    VPDBarcodeTypeCodabar,
    /// Ames Code
    VPDBarcodeTypeAmesCode,
    /// MSI
    VPDBarcodeTypeMsi,
    /// Plessy
    VPDBarcodeTypePlessy,
    /// Code 128
    VPDBarcodeTypeCode128,
    /// Code 16K
    VPDBarcodeTypeCode16K,
    /// Code 93
    VPDBarcodeTypeCode93,
    /// Code 11
    VPDBarcodeTypeCode11,
    /// Telepen
    VPDBarcodeTypeTelepen,
    /// Code 49
    VPDBarcodeTypeCode49,
    /// CodaBlock A
    VPDBarcodeTypeCodaBlockA,
    /// CodaBlock F
    VPDBarcodeTypeCodaBlockF,
    /// CodaBlock 256
    VPDBarcodeTypeCodaBlock256,
    /// PDF417
    VPDBarcodeTypePdf417,
    /// GS1 128
    VPDBarcodeTypeGs1_128,
    /// GS1 128 composite CC-A
    VPDBarcodeTypeGs1_128CompositeCcA,
    /// GS1 128 composite CC-B
    VPDBarcodeTypeGs1_128CompositeCcB,
    /// GS1 128 composite CC-C
    VPDBarcodeTypeGs1_128CompositeCcC,
    /// GS1 DataBar
    VPDBarcodeTypeGs1DataBar,
    /// GS1 DataBar omnidirectional
    VPDBarcodeTypeGs1DataBarOmnidirectional,
    /// GS1 DataBar omnidirectional composite CC-A
    VPDBarcodeTypeGs1DataBarOmnidirectionalCompositeCcA,
    /// GS1 DataBar omnidirectional composite CC-B
    VPDBarcodeTypeGs1DataBarOmnidirectionalCompositeCcB,
    /// GS1 DataBar limited
    VPDBarcodeTypeGs1DataBarLimited,
    /// GS1 DataBar limited composite CC-B
    VPDBarcodeTypeGs1DataBarLimitedCcB,
    /// GS1 DataBar expanded
    VPDBarcodeTypeGs1DataBarExpanded,
    /// GS1 DataBar expanded composite CC-A
    VPDBarcodeTypeGs1DataBarExpandedCompositeCcA,
    /// GS1 DataBar expanded composite CC-B
    VPDBarcodeTypeGs1DataBarExpandedCompositeCcB,
    /// ISBT 128
    VPDBarcodeTypeIsbt128,
    /// Micro PDF
    VPDBarcodeTypeMicroPdf,
    /// Data Matrix
    VPDBarcodeTypeDataMatrix,
    /// QR Code
    VPDBarcodeTypeQrCode,
    /// ISBN
    VPDBarcodeTypeIsbn,
    /// POSTNET
    VPDBarcodeTypePostnet,
    /// PLANET
    VPDBarcodeTypePlanet,
    /// BPO
    VPDBarcodeTypeBpo,
    /// Canada Postal
    VPDBarcodeTypeCanadaPostal,
    /// Japan Postal
    VPDBarcodeTypeJapanPostal,
    /// Australia Postal
    VPDBarcodeTypeAustraliaPostal,
    /// Dutch Postal
    VPDBarcodeTypeDutchPostal,
    /// China Postal
    VPDBarcodeTypeChinaPostal,
    /// Korea Postal
    VPDBarcodeTypeKoreaPostal,
    /// Sweden Postal
    VPDBarcodeTypeSwedenPostal,
    /// Infomail
    VPDBarcodeTypeInfomail,
    /// TLC-39
    VPDBarcodeTypeTlc39,
    /// Trioptic
    VPDBarcodeTypeTrioptic,
    /// ISMN
    VPDBarcodeTypeIsmn,
    /// ISSN
    VPDBarcodeTypeIssn,
    /// Aztec
    VPDBarcodeTypeAztec,
    /// Multicode
    VPDBarcodeTypeMulticode,
    /// Incomplete Multicode
    VPDBarcodeTypeIncompleteMulticode,
    
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    _VPDBarcodeTypeMaximum
#endif
}   VPDBarcodeType;

#endif /* VPDBarcodeType_h */
