//
//  HLCustomer.h
//  HyprLoco
//
//  Created by Dave Batton on 11/14/16.
//  Copyright © 2016 HyprLoco, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HLOrder.h"
#import "HLModelObject.h"

/**
 A mobile device type.
 */
typedef NS_ENUM(NSInteger, HLDeviceType) {
    /**
     Unknown
     */
    HLDeviceTypeUnknown,

    /**
     iPhone
     */
    HLDeviceTypeiPhone,

    /**
     Android
     */
    HLDeviceTypeAndroid
};


/**
 The customer model class.
 */
@interface HLCustomer : HLModelObject

/**
 The customer’s name.
 
 Example content:

     "Dave B"
 */
@property (nonatomic, copy, nullable) NSString *name;

/**
 The customer’s mobile phone number.
 
 This value is not formatted. Always 10 digits.
 
 Example content:
 
     "7208785722"
 */
@property (nonatomic, copy, nonnull) NSString *phoneNumber;

/**
 The customer’s current order, if any.
 
 Returns an `HLOrder` object or `nil`.
 */
@property (nonatomic, strong, nullable) HLOrder *order;


/**
 The HyprLoco location identifier for the user’s current (or most recent) order.
 
 Call `-fetchLocationWithIdentifier:completion:` to get the `HLLocation` object.

 Example content:

     "7f6aacabd2734d86875dc93778656c31"

 */
@property (nonatomic, copy, nullable) NSString *currentLocationIdentifier;

/**
 The location of the user expressed as a zone. This response may vary between locations.

 Example content:

     "East Parking Lot"
 */
@property (nonatomic, copy, nullable) NSString *currentZone;

/**
 The time the customer entered the `currentZone`. This value will always be `nil` if `currentZone` is nil.
 */
@property (nonatomic, copy, nullable) NSDate *timeEnteredZone;


/**
 The type of mobile device being used by the customer. Currently either an iPhone or Android device.
 */
@property (nonatomic) HLDeviceType deviceType;

/**
 Provided by OIS for communicating with the Azure server.
 */
@property (nonatomic, copy, nullable) NSString *telemetricsKey;

/**
 Provided by OIS for communicating with the Azure server.
 */
@property (nonatomic, copy, nullable) NSString *telemetricsURL;

@end
