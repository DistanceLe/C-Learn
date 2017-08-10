//
//  NSMutableDictionary+Extends.h
//  就医160
//
//  Created by lixiaolong on 15/6/2.
//  Copyright (c) 2015年 meng. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSMutableDictionary (Extends)

- (void)ny_setObject:(id)anObject forKey:(id<NSCopying>)aKey;

@end
