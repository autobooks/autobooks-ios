//
//  ExpressTransactionParserDelegate.swift
//  Autobooks
//
//  Created by Donovan Cotter on 1/26/23.
//

import Foundation

class ExpressTransactionParserDelegate: NSObject, XMLParserDelegate {
    var currentElement = ""
    var currentValue = ""
    var expressTransaction = ExpressTransaction()
    var card = Card()
    var parseCard = false

    func parser(_ parser: XMLParser, didStartElement elementName: String, namespaceURI: String?, qualifiedName qName: String?, attributes attributeDict: [String: String] = [:]) {
        currentElement = elementName
        if elementName == "Card" {
            parseCard = true
        }
    }

    func parser(_ parser: XMLParser, foundCharacters string: String) {
        currentValue += string
    }

    func parser(_ parser: XMLParser, didEndElement elementName: String, namespaceURI: String?, qualifiedName qName: String?) {
        if !parseCard {
            switch elementName {
            case "ExpressResponseMessage": expressTransaction.ExpressResponseMessage = currentValue
            case "ExpressTransactionDate": expressTransaction.ExpressTransactionDate = currentValue
            case "ExpressTransactionTime": expressTransaction.ExpressTransactionTime = currentValue
            case "TransactionID": expressTransaction.TransactionID = currentValue
            case "ApprovalNumber": expressTransaction.ApprovalNumber = currentValue
            case "ReferenceNumber": expressTransaction.ReferenceNumber = currentValue
            case "ProcessorName": expressTransaction.ProcessorName = currentValue
            case "ApprovedAmount": expressTransaction.ApprovedAmount = currentValue
            case "NetworkTransactionID": expressTransaction.NetworkTransactionID = currentValue
            case "RetrievalReferenceNumber": expressTransaction.RetrievalReferenceNumber = currentValue
            case "SystemTraceAuditNumber": expressTransaction.SystemTraceAuditNumber = currentValue
            default: break
            }
        } else {
            switch elementName {
            case "ExpirationMonth": card.ExpirationMonth = currentValue
            case "ExpirationYear": card.ExpirationYear = currentValue
            case "CardLogo": card.CardLogo = currentValue
            case "CardNumberMasked": card.CardNumberMasked = currentValue
            case "BIN": card.BIN = currentValue
            default: break
            }
        }
        if elementName == "Card" {
            parseCard = false
            expressTransaction.card = card
        }
        currentValue = ""
    }
}
