//
//  HLModelObject.h
//  HyprLoco
//
//  Created by Dave Batton on 12/1/16.
//  Copyright © 2016 HyprLoco, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 `HLModelObject` is a generic model class that implements all the basic behavior required of a HyprLoco model object. This is the superclass for the `HLLocation`, `HLCustomer`, and `HLOrder` classes.
 */
@interface HLModelObject : NSObject

/**
 The HyprLoco record identifier.

 Example content:

     "124041"
 */
@property (nonatomic, copy, nonnull) NSString *identifier;

/**
 Creates an object from JSON data. If the expected JSON data is insuficient, a nil object is returned.
 
 This method parses the JSON data into a dictionary, then passes that dictionary to the class’s `-initWithDictionary:` method.

 @param data A data object containing JSON data. Must not be `nil`.
 @return An `HLModelObject` object
 */
- (instancetype _Nullable)initWithJSONData:(NSData * _Nonnull)data;

/**
 Creates an object from a dictionary. Subclasses of this generic class must override this method.
 
 If any of the required keys are not found or do not contain a value, a nil object is returned.

 @param dictionary A dictionary object containing the required keys. Must not be `nil`.
 @return An `HLModelObject` object
 */
- (instancetype _Nullable)initWithDictionary:(NSDictionary * _Nonnull)dictionary;

@end
