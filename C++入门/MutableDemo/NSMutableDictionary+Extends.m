//
//  NSMutableDictionary+Extends.m
//  就医160
//
//  Created by lixiaolong on 15/6/2.
//  Copyright (c) 2015年 meng. All rights reserved.
//

#import "NSMutableDictionary+Extends.h"

@implementation NSMutableDictionary (Extends)

- (void)ny_setObject:(id)anObject forKey:(id<NSCopying>)aKey
{
    NSAssert(anObject != nil, @"anObject for setObjectEX occurs nil");
    if (anObject != nil) {
        [self setObject:anObject forKey:aKey];
    }
}

@end
