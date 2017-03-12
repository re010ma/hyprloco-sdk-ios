//
//  HLAzureManager.h
//  Pods
//
//  Created by Dave Batton on 1/23/17.
//
//

#import <Foundation/Foundation.h>
#import "HLLogManager.h"

@interface HLAzureManager : NSObject

@property (nonatomic, copy) NSString *applicationKey;
@property (nonatomic, copy) NSData *deviceToken;
@property (nonatomic, copy) NSString *customerIdentifier;

@end
