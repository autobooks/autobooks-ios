//
//  VTPValutecRewardsResponse.h
//  triPOSMobileSDK
//
//  Created on 5/10/21.
//  Copyright © 2021 Vantiv Inc. All rights reserved.
//

#ifndef VTPValutecRewardsResponse_h
#define VTPValutecRewardsResponse_h

///
/// \protocol VTPFinancialResponseBase
///
/// \brief The protocol that defines the properties returned in all financial responses
///
@protocol VTPValutecRewardsResponse

///
/// \brief Gets the gift card balance points for valutec loyalty cards
///
/// This property gets the gift card balance points for valutec loyalty cards.
///
@property (retain, nonatomic) NSString *giftPointsBalance;

///
/// \brief Gets the gift card reward level for valutec loyalty cards
///
/// This property gets the gift card reward level for valutec loyalty cards.
///
@property (retain, nonatomic) NSString *giftRewardLevel;

@end
#endif /* VTPValutecRewardsResponse_h */


