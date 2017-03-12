//
//  HLLocation.h
//  HyprLoco
//
//  Created by Dave Batton on 11/14/16.
//  Copyright © 2016 HyprLoco, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>
#import "HLModelObject.h"

/**
 The business location model class.
 
 This class conforms to the `MKAnnotation` protocol, allowing locations to be displayed in MapKit views.
 */
@interface HLLocation : HLModelObject <MKAnnotation>

/**
 A human-readable description used to differentiate this location from other locations with the same business name.
 
 Example content:
 
     "West Odessa"
 */
@property (nonatomic, copy, nonnull) NSString *label;

@property (nonatomic, nonnull) NSString *fullAddress;

/**
 The first mailing address line of the location.
 
 Example content:
 
     "2744 N County Rd W"
 */
@property (nonatomic, copy, nonnull) NSString *address1;

/**
 The second mailing address line of the location. This value may be nil.
 
 Example content:
 
     "Suite 100"
 */
@property (nonatomic, copy, nullable) NSString *address2;

/**
 The location’s city name.
 
 Example content:
 
     "Odessa"
 */
@property (nonatomic, copy, nonnull) NSString *city;

/**
 The location’s state abbreviation.
 
 Example content:
 
     "TX"
 */
@property (nonatomic, copy, nonnull) NSString *state;

/**
 The location’s Zip code.
 
 Example content:
 
     "79764"
 */
@property (nonatomic, copy, nonnull) NSString *zip;

/**
 Returns the phone number for placing an order by phone.
 
 Example content:
 
     "(432) 332-2117,,1"
 */
@property (nonatomic, copy, nonnull) NSString *phone;

/**
 Returns the phone number to display, without the extra commas and digits used to navigate the menu system.

 Example content:

 "(432) 332-2117"
 */
@property (nonatomic, readonly, nonnull) NSString *displayPhone;


// MKAnnotation

/**
 The location’s location, as a `CLLocationCoordinate2D` structure.
 
 For `MKAnnotation` conformance.
 */
@property (nonatomic) CLLocationCoordinate2D coordinate;

/**
 The title to display in map view annotations.
 
 For `MKAnnotation` conformance. I’m not sure what this will return yet. Ideally the business name, but we don’t get that from the API.
 
 Example content:
 
     "McAlister’s Deli"
 */
@property (nonatomic, readonly, copy, nullable) NSString *title;

/**
 The subtitle to display in map view annotations.
 
 For `MKAnnotation` conformance. This value always returns the location’s `label` value.
 
 Example content:
 
     "West Odessa"
 */
@property (nonatomic, readonly, copy, nullable) NSString *subtitle;

@property (nonatomic, readonly, nonnull) MKMapItem *mapItem;

+ (NSArray<HLLocation *> * _Nullable)locationsWithJSONData:(NSData * _Nonnull)data;

@end
