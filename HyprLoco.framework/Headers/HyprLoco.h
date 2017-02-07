//
//  HyprLoco.h
//  HyprLoco
//
//  Created by Dave Batton on 11/16/16.
//  Copyright © 2016 HyprLoco, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "HLLocation.h"
#import "HLCustomer.h"
#import "HLOrder.h"


/**
 The version of the framework.
 */
FOUNDATION_EXPORT double HyprLocoVersionNumber;

/**
 This notification will be posted whenever the HyprLoco SDK detects a change in the user’s location.
 */
FOUNDATION_EXPORT NSNotificationName _Nonnull const HLDeviceLocationDidChangeNotification;

/**
 The error domain used for HyprLoco generated errors.
 */
FOUNDATION_EXPORT NSErrorDomain _Nonnull const HLErrorDomain;

/**
 This notification will be posted when the HyprLoco SDK receives a request to display the survey web page.
 
 The `userInfo` dictionary will contain the URL to display with a `HLSurveyURL` key.
 */
FOUNDATION_EXPORT NSNotificationName _Nonnull const HLSurveyRequestNotification;

/**
 This notification will be posted when the HyprLoco SDK recieves a notification that the user has a new order.
 */
FOUNDATION_EXPORT NSNotificationName _Nonnull const HLNewOrderNotification;

/**
 This notification will be posted when the HyprLoco SDK recieves a notification that the status of an existing order has changed.
 */
FOUNDATION_EXPORT NSNotificationName _Nonnull const HLOrderStatusDidChangeNotification;

/**
 The HyprLoco OIS server to use.
 */
typedef NS_ENUM(NSInteger, HLServer) {
    /**
     The development server.
     */
    HLServerDevelopment = 0,

    /**
     The testing server.
     */
    HLServerTesting,

    /**
     The staging server.
     */
    HLServerStaging,

    /**
     The production server.
     */
    HLServerProduction
};

/**
 Create an instance of the HyprLoco class to communicate with the HyprLoco Order Information System (OIS). Use it to fetch locations, customers, and orders. This instance will handle location tracking automatically while a customer has an open order.
 
 You can either create and retain your own instance of the HyprLoco class, or you can use the lazily loaded `+[HyprLoco sharedInstance]` singleton.
 */
@interface HyprLoco : NSObject

/**
 The OIS server to use.

 The server can be changed at any time. By default the development server is used (`HLServerDevelopment`).
 */
@property (nonatomic) HLServer server;  // HLServerDevelopment is the default value.

/**
 Enables or disables HyprLoco logging to the console.

 Set to `YES`/`true` to enable HyprLoco logging. Set to `NO`/`false` to disable logging.

 Logging is enabled by default.
 */
@property (nonatomic) BOOL loggingEnabled;

/**
 The push notification deviceToken value received by `-[UIApplicationDelegate application:didRegisterForRemoteNotificationsWithDeviceToken:]`.
 
 Set this value to enable the HyprLoco server to send push notifications to the user (with permission).
 */
@property (nonatomic, copy) NSData * _Nonnull deviceToken;

/**
 Enables or disables HyprLoco location tracking.

 HyprLoco automatically starts location tracking when it sees a fetched customer has an open order. After a subsequent fetch indicates there is no longer an open order, HyprLoco stops tracking the user’s location. Location tracking is enabled by default.

 If `trackingEnabled` is set to `NO`/`false`, HyprLoco will not track the user’s location. There is no need to disable `trackingEnabled` in normal use of the HyprLoco SDK.
 */
@property (nonatomic) BOOL trackingEnabled;

/**
 A lazily-loaded shared HyprLoco instance. You are not required to use this shared instance. It is provided as a convenience.

 @return A shared, initialized `HyprLoco` object instance.
 */
+ (instancetype _Nonnull)sharedInstance;

/**
 Pass in your application key and subscription key. No network call is made by this function. These keys are added to the headers of any subsequent network calls.

 @param applicationKey The application key you received from HyprLoco, Inc.
 @param subscriptionKey The subscription key you received from HyprLoco, Inc.
 */
- (void)setApplicationKey:(NSString * _Nonnull)applicationKey subscriptionKey:(NSString * _Nonnull)subscriptionKey;

/**
 Fetches an array of all locations, sorted alphabetically by location name.

 @param completion A block object to be executed when the fetch is complete. This block has no return value and has two arguments. If the fetch is successful, the first argument will contain an array of `HLLocation` objects. Otherwise, the second parameter will contain an error. This block is always called on the main thread.
 */
- (void)fetchLocations:(void (^ _Nonnull)(NSArray<HLLocation *> * _Nullable locations, NSError * _Nullable error))completion;

/**
 Fetches an array of all locations near the specified coordinate, sorted by distance.

 @param coordinate A valid latitude and longitude coordinate.
 @param completion A block object to be executed when the fetch is complete. This block has no return value and has two arguments. If the fetch is successful, the first argument will contain an array of `HLLocation` objects. Otherwise, the second parameter will contain an error. This block is always called on the main thread.
 */
- (void)fetchLocationsNearCoordinate:(CLLocationCoordinate2D)coordinate completion:(void (^ _Nonnull)(NSArray<HLLocation *> * _Nullable locations, NSError * _Nullable error))completion;

/**
 Fetches the location with the specified location identifier.

 @param identifier A HyprLoco location identifier.
 @param completion A block object to be executed when the fetch is complete. This block has no return value and has two arguments. If the fetch is successful, the first argument will contain a `HLLocation` object with the specified ID. Otherwise, the second parameter will contain an error. This block is always called on the main thread.
 */
- (void)fetchLocationWithIdentifier:(NSString * _Nonnull)identifier completion:(void (^ _Nonnull)(HLLocation * _Nullable location, NSError * _Nullable error))completion;

/**
 Fetches the customer with the specified identifier.

 @param identifier The customer’s HyprLoco identifier.
 @param completion A block object to be executed when the fetch is complete. This block has no return value and has two arguments. If the fetch is successful, the first argument will contain a `HLCustomer` object with the customer with the specified identifier. Otherwise, the second parameter will contain an error. This block is always called on the main thread.
 */
- (void)fetchCustomerWithIdentifier:(NSString * _Nonnull)identifier completion:(void (^ _Nonnull)(HLCustomer * _Nullable customer, NSError * _Nullable error))completion;

/**
 Fetches the customer with the specified phone number.

 @param phoneNumber The customer’s phone number. Must contain at least 10 digits. The number can be formatted, but any formatting is ignored.
 @param completion A block object to be executed when the fetch is complete. This block has no return value and has two arguments. If the fetch is successful, the first argument will contain a `HLCustomer` object with the customer with the specified phone number. Otherwise, the second parameter will contain an error. This block is always called on the main thread.
 */
- (void)fetchCustomerWithPhone:(NSString * _Nonnull)phoneNumber completion:(void (^ _Nonnull)(HLCustomer * _Nullable customer, NSError * _Nullable error))completion;

/**
 Informs the OIS that a push notification was received.

 If server sends either a CREATE_ORDER or REGISTER_USER request and does not receive this acknowledgement within 20 seconds, it will resend the notification as an SMS message.
 
 There is no confirmation that this message was received, but its success or failure will be displayed in the console if logging is enabled.

 @param phoneNumber The customer’s phone number. Must contain at least 10 digits. The number can be formatted, but any formatting is ignored.
 @param messageIdentifier The messageID string included with the HyprLoco push notification. May be `nil`.
 */
- (void)acknowledgeBackgroundNotificationWithPhone:(NSString * _Nonnull)phoneNumber messageIdentifier:(NSString * _Nullable)messageIdentifier;

/**
 Informs the OIS that a push notification to present the survey was received.

 If server sends a survey request push notification and does not receive this acknowledgement within 20 seconds, it will resend the notification as an SMS message.

 There is no confirmation that this message was received, but its success or failure will be displayed in the console if logging is enabled.

 @param identifier The customer identifier.
 */
- (void)acknowledgeSurveyNotificationWithCustomerIdentifier:(NSString * _Nonnull)identifier;

@end
