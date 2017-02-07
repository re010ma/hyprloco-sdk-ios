//
//  HLBluedotManager.h
//  HyprLoco
//
//  Created by Dave Batton on 1/2/17.
//  Copyright © 2017 HyprLoco, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HyprLoco.h"
#import "HLLogManager.h"

@interface HLBluedotManager : NSObject

@property (nonatomic, strong, nonnull) HLLogManager *logManager;

- (void)startUpdatingLocationWithTelemetricsURL:(NSString * _Nonnull)telemetricsURL telemetricsKey:(NSString * _Nonnull)telemetricsKey locationIdentifier:(NSString * _Nonnull)locationIdentifier sessionIdentifier:(NSString * _Nonnull)sessionIdentifier;
- (void)stopUpdatingLocation;

@end
