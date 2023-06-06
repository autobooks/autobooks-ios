import UIKit

internal extension UIFont {
    var bold: UIFont? {
        guard let boldFontDescriptor = fontDescriptor.withSymbolicTraits(.traitBold) else {
            return nil
        }

        return UIFont(descriptor: boldFontDescriptor, size: boldFontDescriptor.pointSize)
    }
}
