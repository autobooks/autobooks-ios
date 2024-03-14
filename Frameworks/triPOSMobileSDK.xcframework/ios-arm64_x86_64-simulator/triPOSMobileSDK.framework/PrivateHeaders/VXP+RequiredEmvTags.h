//
//  VXP+RequiredEmvTags.h
//  Express
//
//  Created by Chance Ulrich on 4/23/16.
//  Copyright © 2018 Worldpay, LLC. and/or its affiliates. All rights reserved.
//

#ifndef VXP_RequiredEmvTags_h
#define VXP_RequiredEmvTags_h

#import "VXP.h"

///
/// \category VXP(RequiredEmvTags)
///
/// \brief The VXP category that contains the list of required EMV tags
///
/// This category contains the list of required EMV tags.
///
@interface VXP(RequiredEmvTags)

///
/// \brief Gets the list of required tags
///
/// This method gets the list of required tags.
///
+(NSArray<NSNumber *> *)getRequiredEmvTags;

@end

#endif /* VXP_RequiredEmvTags_h */
