//
//  HLDataManager.h
//  HyprLoco
//
//  Created by Dave Batton on 12/3/16.
//  Copyright © 2016 HyprLoco, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HyprLoco.h"
#import "HLBluedotManager.h"
#import "HLAzureManager.h"

@interface HLDataManager : NSObject

@property (nonatomic) HLServer server;  // HLServerDevelopment is the default value.

- (instancetype _Nullable)initWithBluedotManager:(HLBluedotManager * _Nonnull)bluedotManager azureManager:(HLAzureManager * _Nonnull)azureManager NS_DESIGNATED_INITIALIZER;
- (void)setApplicationKey:(NSString * _Nonnull)applicationKey subscriptionKey:(NSString * _Nonnull)subscriptionKey;
- (void)fetchLocations:(void (^ _Nonnull)(NSArray<HLLocation *> * _Nullable locations, NSError * _Nullable error))completion;
- (void)fetchLocationsNearCoordinate:(CLLocationCoordinate2D)coordinate completion:(void (^ _Nonnull)(NSArray<HLLocation *> * _Nullable locations, NSError * _Nonnull error))completion;
- (void)fetchLocationWithIdentifier:(NSString * _Nonnull)identifier completion:(void (^ _Nonnull)(HLLocation * _Nullable location, NSError * _Nonnull error))completion;
- (void)fetchCustomerWithIdentifier:(NSString * _Nonnull)identifier completion:(void (^ _Nonnull)(HLCustomer * _Nullable customer, NSError * _Nullable error))completion;
- (void)fetchCustomerWithPhone:(NSString * _Nonnull)phoneNumber completion:(void (^ _Nonnull)(HLCustomer * _Nullable customer, NSError * _Nullable error))completion;

@end
