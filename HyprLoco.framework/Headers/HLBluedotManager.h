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

@protocol HLBluedotManagerDelegate;

@interface HLBluedotManager : NSObject

- (instancetype _Nullable)initWithDelegate:(id<HLBluedotManagerDelegate> _Nullable)delegate logManager:(HLLogManager * _Nonnull)logManager NS_DESIGNATED_INITIALIZER;
- (void)startUpdatingLocationWithTelemetricsURL:(NSString * _Nonnull)telemetricsURL telemetricsKey:(NSString * _Nonnull)telemetricsKey locationIdentifier:(NSString * _Nonnull)locationIdentifier sessionIdentifier:(NSString * _Nonnull)sessionIdentifier;
- (void)stopUpdatingLocation;

@end


@protocol HLBluedotManagerDelegate <NSObject>

@optional
- (void)bluedotManager:(HLBluedotManager * _Nonnull)sender zoneDidChangeForPlace:(NSString * _Nonnull)place beaconIdentifier:(NSInteger)beaconIdentifier;

@end
