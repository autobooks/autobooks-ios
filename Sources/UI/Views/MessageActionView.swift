import SwiftUI

@available(iOS 14.0, *)
struct MessageActionView: View {
    struct Action {
        static func tryAgain(_ action: @escaping () -> Void) -> Action {
            .init(title: "Try Again", action: action)
        }

        static func start(_ action: @escaping () -> Void) -> Action {
            .init(title: "Get Started", action: action)
        }
        
        static func callUs(_ action: @escaping () -> Void) -> Action {
            .init(title: "If this problem persists, call us toll-free at (866) 617-3122for assistance.", action: action)
        }
        
        let title: String
        let action: () -> Void

        func callAsFunction() {
            action()
        }
    }
    
    enum SourceDomain {
        case tapToPay
        case webFeature
    }
    
    private struct MessageIcon: View {
        let domain: SourceDomain
        
        var body: some View {
            switch domain {
            case .tapToPay:
                if let image = UIImage(named: "tapToPayIcon", in: .resources, compatibleWith: nil) {
                    Image(uiImage: image)
                        .accessibilityHidden(true)
                }
            case .webFeature:
                Image(systemName: "exclamationmark.triangle")
                    .font(.system(size: 72))
                    .accessibilityHidden(true)
            }
        }
    }
    
    let title: String
    let message: String
    let sourceDomain: SourceDomain
    let action: Action?
    let secondaryAction: Action?
    let callUsAction: Action?

    @State private var showingLogSheet = false

    init(title: String, message: String, sourceDomain: SourceDomain = .tapToPay, action: Action?, secondaryAction: Action? = nil, callUsAction: Action? = nil) {
        self.title = title
        self.message = message
        self.sourceDomain = sourceDomain
        self.action = action
        self.secondaryAction = secondaryAction
        self.callUsAction = callUsAction
    }
    
    var body: some View {
        VStack {
            Spacer()
                .frame(height: 36)
            
            MessageIcon(domain: sourceDomain)
            
            Spacer()
                .frame(height: 93)
            
            VStack(spacing: 56) {
                Button {
                    showingLogSheet.toggle()
                } label: {
                    Text(title)
                        .font(.largeTitle.weight(.bold))
                        .multilineTextAlignment(.center)
                        .foregroundColor(.primary)
                }
                .sheet(isPresented: $showingLogSheet) {
                    LogSheetView()
                }

                Text(message)
                    .font(.title2)
                    .multilineTextAlignment(.center)
            }
            .accessibilityElement(children: .combine)
            
            Spacer()
                .frame(height: 20)
            
            if let callUsAction {
                VStack {
                    Text("If this problem persists, call us toll-free at")
                        .foregroundColor(.black)
                        .font(.caption)
                        .multilineTextAlignment(.center)
                    HStack {
                        Button(action: callUsAction.action) {
                            Text("(866) 617-3122")
                                .foregroundColor(.blue)
                                .font(.caption)
                                .padding(.trailing, -5)
                        }
                        
                        Text("for assistance.")
                            .foregroundColor(.black)
                            .font(.caption)
                            .multilineTextAlignment(.center)
                    }
                }
                .buttonStyle(.plain)
                .background(Color.clear)
            }

            Spacer()
            if let action {
                Button {
                    action()
                } label: {
                    Text(action.title)
                }
                .buttonStyle(.action)
            }
            
            if let secondaryAction {
                Button {
                    secondaryAction()
                } label: {
                    Text(secondaryAction.title)
                }
                .buttonStyle(.secondary)
            }
        }
        .padding(32)
    }
}

struct ActivityView: UIViewControllerRepresentable {
    typealias Callback = (_ activityType: UIActivity.ActivityType?, _ completed: Bool, _ returnedItems: [Any]?, _ error: Error?) -> Void
    typealias UIViewControllerType = UIActivityViewController

    let activityItems: [Any]
    let applicationActivities: [UIActivity]? = nil
    let excludedActivityTypes: [UIActivity.ActivityType]? = nil
    let callback: Callback? = nil

    func makeUIViewController(context: Context) -> UIActivityViewController {
        let controller = UIActivityViewController(
            activityItems: activityItems,
            applicationActivities: applicationActivities
        )
        controller.excludedActivityTypes = excludedActivityTypes
        controller.completionWithItemsHandler = callback
        return controller
    }
    
    func updateUIViewController(_ uiViewController: UIActivityViewController, context: Context) {}
}

struct LogSheetView: View {
    @Environment(\.presentationMode) var presentationMode
    @State private var showingActivitySheet = false

    var body: some View {
        NavigationView {
            let logTextView = LogTextView()
            
            logTextView
                .navigationBarItems(leading: Button(action: {
                    showingActivitySheet.toggle()
                }, label: {
                    Image(systemName: "square.and.arrow.up")
                })
                .sheet(isPresented: $showingActivitySheet) {
                    ActivityView(activityItems: [logTextView.textView.text ?? ""])
                },
                                    
                trailing: Button("Close") {
                    presentationMode.wrappedValue.dismiss()
                })
        }
    }
}

struct LogTextView: UIViewRepresentable {
    let textView = UITextView()

    func makeUIView(context: Context) -> UITextView {
        textView.font = UIFont.monospacedSystemFont(ofSize: 14, weight: .semibold)
        textView.text = Log.logEntries(since: -30).reversed().joined(separator: "\n")
        return textView
    }

    func updateUIView(_ uiView: UITextView, context: Context) {}
}
