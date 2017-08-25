//
//  ViewController.m
//  MutableDemo
//
//  Created by LiJie on 2017/7/21.
//  Copyright © 2017年 LiJie. All rights reserved.
//

#import "ViewController.h"
#import "NSMutableDictionary+Extends.h"


#import "LJCPlus.hpp"

#include <fstream>

@interface ViewController ()

@property(nonatomic, strong)NSRecursiveLock* recursiveLock;
@property(nonatomic, assign)NSInteger num;

@end



@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    
    
    [self helloCPuls];
    
//    self.recursiveLock = [[NSRecursiveLock alloc]init];
//    [self doSomething];
}
- (IBAction)tapClick:(UITapGestureRecognizer *)sender {
    NSLog(@"VC tap Click");
}

/**   调用C++ 代码 */
-(void)helloCPuls{
    //hello();
    
    
//    operatorFile();
    
    memoryFunc();
    
//    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
//    NSString *documentsDirectory = [paths objectAtIndex:0];
//    NSString *path = [documentsDirectory stringByAppendingPathComponent:@"file1.txt"];
//    
//    std::fstream fout([path UTF8String]);
//    
//    if (fout) {
//        NSLog(@"创建文件 file.txt");
//    }else{
//        NSLog(@"创建文件 file.txt  失败");
//    }
}










-(void)doSomething{
    dispatch_queue_t anyncQueue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
    
    dispatch_sync(anyncQueue, ^{
        [self.recursiveLock lock];
        sleep(1);
        NSLog(@"...%ld", self.num++);
        if (self.num < 4) {
            [self doSomething];
            [self.recursiveLock unlock];
        }
    });
    
}





@end
