//
//  XESLogFormatter.h
//  XESCommon
//
//  Created by luoshuai on 2017/7/4.
//  Copyright © 2017年 luoshuai. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CocoaLumberjack.h"
@interface XESLogFormatter : NSObject<DDLogFormatter>


@end


@interface XESLogFileFormatter : NSObject <DDLogFormatter>


/**
 token
 */
@property (nonatomic, strong) NSString *token;

/**
 网络状态
 */
@property (nonatomic, strong) NSString *netWorkStatus;

/**
 用户ID
 */
@property (nonatomic, strong) NSString *userID;

/**
 加密KEY 如果穿空字符串等于是不加密
 */
@property (nonatomic, strong) NSString *AESKey;
@end
