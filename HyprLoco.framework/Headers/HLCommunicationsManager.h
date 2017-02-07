//
//  HLCommunicationsManager.h
//  HyprLoco
//
//  Created by Dave Batton on 12/3/16.
//  Copyright © 2016 HyprLoco, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HyprLoco.h"

@interface HLCommunicationsManager : NSObject

@property (nonatomic) HLServer server;  // HLServerDevelopment is the default value.

- (instancetype _Nullable)initWithApplicationKey:(NSString * _Nonnull)applicationKey subscriptionKey:(NSString * _Nonnull)subscriptionKey NS_DESIGNATED_INITIALIZER;
- (void)fetchLocations:(void (^ _Nonnull)(NSData * _Nullable response, NSError * _Nullable error))completion;
- (void)fetchLocationsNearCoordinate:(CLLocationCoordinate2D)coordinate completion:(void (^ _Nonnull)(NSData * _Nullable response, NSError * _Nullable error))completion;
- (void)fetchCustomerWithIdentifier:(NSString * _Nonnull)identifier completion:(void (^ _Nonnull)(NSData * _Nullable response, NSError * _Nullable error))completion;
- (void)fetchCustomerWithPhone:(NSString * _Nonnull)phoneNumber completion:(void (^ _Nonnull)(NSData * _Nullable response, NSError * _Nullable error))completion;
- (void)acknowledgeBackgroundNotificationWithPhone:(NSString * _Nonnull)phoneNumber messageIdentifier:(NSString * _Nullable)messageIdentifier completion:(void (^ _Nonnull)(NSData * _Nullable response, NSError * _Nullable error))completion;
- (void)acknowledgeSurveyNotificationWithCustomerIdentifier:(NSString * _Nonnull)identifier completion:(void (^ _Nonnull)(NSData * _Nullable response, NSError * _Nullable error))completion;
- (void)reportBeaconEventWithURLString:(NSString * _Nonnull)URLString telemetricsKey:(NSString * _Nonnull)telemetricsKey parameters:(NSDictionary * _Nonnull)parameters completion:(void (^ _Nonnull)(NSData * _Nullable response, NSError * _Nullable error))completion;

@end
