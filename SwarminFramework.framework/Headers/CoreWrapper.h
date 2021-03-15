//
//  CoreWrapper.h
//  swarmin-cpp-demo
//
//  Created by Manoj Sukhavasi on 24/02/21.
//

#ifndef CoreWrapper_h
#define CoreWrapper_h


#import <Foundation/Foundation.h>
#import "Core.hpp"

@interface CoreWrapper : NSObject

+ (NSString*) runSwarminNode:(NSString*)myString;

@end

#endif /* CoreWrapper_h */
