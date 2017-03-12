//
//  HLOrder.h
//  HyprLoco
//
//  Created by Dave Batton on 11/14/16.
//  Copyright © 2016 HyprLoco, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HLModelObject.h"


/**
 The current status of the order.
 */
typedef NS_ENUM(NSInteger, HLOrderStatus) {
    /**
     The order is pending.
     */
    HLOrderStatusPending = 0,

    /**
     The order is being processed.
     */
    HLOrderStatusProcessing,

    /**
     The order is ready for pickup.
     */
    HLOrderStatusReady,

    /**
     The order has been picked up.
     */
    HLOrderStatusDelivered,

    /**
     The order has been canceled.
     */
    HLOrderStatusCanceled
};


/**
 The customer order model class. This represents the
 customer’s food order, including total amount due.
 */
@interface HLOrder : HLModelObject

/**
 A session identifier for tracking purposes. May match the order identifier value.

 Example content:

     "124041"
 */
@property (nonatomic, copy, nonnull) NSString *sessionIdentifier;

/**
 The restaurant’s check or ticket number associated with the order.

 Example content:

 "1234"
 */
@property (nonatomic, copy, nullable) NSString *checkNumber;

/**
 The current status of the order.
 */
@property (nonatomic) HLOrderStatus status;

/**
 A name for the order.

 Example content:

     "Current Order"
 */
@property (nonatomic, copy, nonnull) NSString *label;

/**
 The complete contents of the order. Formatted with tab and carriage return/newline characters.

 Example content:

     "Turkey Cobb\t$7.89\tCiabatta\tBag of Chips\tKettle Jalapeno Chips\r\nMcAlister's Famous Sweet Tea\t$2.29\tLemon\r\nCup of Soup and Half Sandwich\t$7.49\tCup of Broccoli and Cheddar\tMcAlister's Club\tPita\tNo Honey Mustard\r\nBowl of Soup or Chili*\t$4.99\tChicken Tortilla Soup (Bowl)\r\n"
 */
@property (nonatomic, copy, nonnull) NSString *itemsString;

/**
 The HyprLoco location identifier. Call `-fetchLocationWithIdentifier:completion:` to get the `HLLocation` object.

 Example content:

     "7f6aacabd2734d86875dc93778656c31"
 */
@property (nonatomic, copy, nonnull) NSString *locationIdentifier;

/**
 The date and time the order was placed.
 */
@property (nonatomic, copy, nonnull) NSDate *orderDate;

/**
 The order subtotal, formatted, in US dollars.

 Example content:

     "$10.00"
 */
@property (nonatomic, copy, nonnull) NSString *subtotalString;

/**
 The amount of taxes on the order, formatted, in US dollars.

 Example content:

     "$2.34"
 */
@property (nonatomic, copy, nonnull) NSString *taxesString;

/**
 The total amount of the order, formatted, in US dollars.

 Example content:

     "$12.34"
 */
@property (nonatomic, copy, nonnull) NSString *totalString;

/**
 The amount still due on the order, formatted, in US dollars.

 Example content:

     "$12.34"
 
 This string will be "$0.00" if the order has been paid in full.
 */
@property (nonatomic, copy, nonnull) NSString *dueString;

@end
