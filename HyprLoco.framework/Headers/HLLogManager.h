//
//  HLLogManager.h
//  HyprLoco
//
//  Created by Dave Batton on 1/4/17.
//  Copyright © 2017 HyprLoco, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HLLogManager : NSObject

/**
 Enable or disables logging to the console.

 Set to `YES`/`true` to enable HyprLoco logging. Set to `NO`/`false` to disable logging.

 Logging is enabled by default.
 */
@property (nonatomic) BOOL loggingEnabled;

- (void)logMessage:(NSString *)message;
- (void)logError:(NSError *)error;
- (void)logMessage:(NSString *)message error:(NSError *)error;

@end
