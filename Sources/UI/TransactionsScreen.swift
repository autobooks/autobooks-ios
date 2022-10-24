import SwiftUI

@available(iOS 15.4, *)
struct TransactionsScreen: View {
    @StateObject private var store: RootStore

    init(store: RootStore) {
        _store = StateObject(wrappedValue: store)
    }

    var body: some View {
        content
            .background(Color(uiColor: .secondarySystemBackground).ignoresSafeArea())
    }

    @ViewBuilder
    private var content: some View {
        switch store.state.transactionsState {
        case .initialLoad(.idle), .initialLoad(.loading):
            initialLoadingView
        case .initialLoad(.failed):
            initialFailureView
        case let .loaded(.loaded(transactions)), let .loaded(.failed(_, transactions)), let .loaded(.refreshing(transactions)):
            if transactions.isEmpty {
                refreshableEmptyView
            } else {
                transactionsList(for: transactions)
            }
        }
    }

    @ViewBuilder
    private var refreshableEmptyView: some View {
        #if swift(>=5.7)
        if #available(iOS 16, *) {
            ScrollView {
                emptyView
            }
            .frame(maxWidth: .infinity, maxHeight: .infinity)
            .refreshable {
                await store.send(.fetchTransactions, while: \.transactionsState.isRefreshing)
            }
        } else {
            emptyView
        }
        #else
        emptyView
        #endif
    }

    private var emptyView: some View {
        VStack(spacing: 0) {
            Spacer()
                .frame(height: 100)

            Image("money", bundle: .resources)

            Spacer()
                .frame(height: 52)

            Text("You haven't received any payments yet")
                .font(.system(.title).bold())
                .multilineTextAlignment(.center)
                .foregroundColor(Color(uiColor: .secondaryLabel))

            Spacer()
                .frame(height: 40)

            Text("Payments and refunds will show up here")
                .font(.system(.body))
                .foregroundColor(Color(uiColor: .secondaryLabel))

            Spacer()
        }
        .frame(maxWidth: .infinity)
        .background(Color(uiColor: .secondarySystemBackground).ignoresSafeArea())
    }

    private func transactionsList(for transactions: [Transaction]) -> some View {
        List {
            ForEach(buildSections(from: transactions)) { section in
                Section(header: Text(section.title)) {
                    ForEach(section.transactions) { transaction in
                        TransactionView(transaction: transaction)
                            .onTapGesture {
                                store.send(.selectTransaction(transaction))
                            }
                    }
                }
            }
        }
        .frame(maxWidth: .infinity, maxHeight: .infinity)
        .refreshable {
            await store.send(.fetchTransactions, while: \.transactionsState.isRefreshing)
        }
    }

    private var initialLoadingView: some View {
        ProgressView("Loading Transactions...")
            .progressViewStyle(.circular)
            .frame(maxWidth: .infinity, maxHeight: .infinity)
            .foregroundColor(.gray)
    }

    private var initialFailureView: some View {
        VStack(spacing: 0) {
            Spacer()
                .frame(height: 200)

            Text("Transactions didn't load")
                .font(.system(.title).bold())
                .multilineTextAlignment(.center)

            Spacer()
                .frame(height: 20)

            Text("Try again or check back later")
                .font(.system(.body))

            Spacer()
                .frame(height: 46)

            Button("Try Again") {
                store.send(.fetchTransactions)
            }
            .buttonStyle(.secondary)

            Spacer()
        }
        .padding(.horizontal, 36)
        .frame(maxWidth: .infinity)
    }

    private struct TransactionSection: Identifiable {
        var id: String { title }

        let title: String
        let transactions: [Transaction]
    }

    private func buildSections(from transactions: [Transaction]) -> [TransactionSection] {
        transactions
            .chunkedByDay()
            .map { TransactionSection(title: $0[0].date.formatted(date: .long, time: .omitted), transactions: $0) }
    }
}

@available(iOS 15, *)
private struct TransactionView: View {
    @Environment(\.primaryColor) var primaryColor

    let transaction: Transaction

    var body: some View {
        HStack(spacing: 12) {
            Image(systemName: "wave.3.right.circle")
                .foregroundColor(primaryColor)
                .font(.system(size: 30))

            VStack(alignment: .leading) {
                Text(transaction.total)
                    .font(.system(.body).bold())
                Text(transaction.name)
                    .font(.system(.subheadline))
                    .foregroundColor(.secondary)
            }

            Spacer()

            if transaction.status == .canceled || transaction.status == .refunded {
                StatusView(status: transaction.status)
            }

            Image(systemName: "chevron.right")
                .font(.system(size: 12))
                .foregroundColor(Color(uiColor: .tertiaryLabel))
        }
        .contentShape(Rectangle())
        .accessibilityRepresentation {
            Text("\(transaction.total) to \(transaction.name)")
        }
        .accessibilityAddTraits(.isButton)
    }
}

@available(iOS 15.0, *)
private struct StatusView: View {
    let status: Transaction.Status

    var body: some View {
        Text(status.rawValue)
            .font(.system(.caption2).weight(.medium))
            .padding(4)
            .background(Color(uiColor: .systemGray6))
            .cornerRadius(4)
    }
}

extension Array where Element == Transaction {
    fileprivate func chunkedByDay() -> [[Transaction]] {
        let calendar = Calendar(identifier: .gregorian)
        var dayChunks: [[Transaction]] = []
        var currentIndex = 0
        while currentIndex < count {
            var chunk: [Transaction] = []
            let chunkStartDate = self[currentIndex].date

            while currentIndex < count, calendar.isDate(self[currentIndex].date, inSameDayAs: chunkStartDate) {
                chunk.append(self[currentIndex])
                currentIndex += 1
            }

            dayChunks.append(chunk)
        }

        return dayChunks
    }
}
