//
//  XESLogFileManager.h
//  XESCommon
//
//  Created by luoshuai on 2017/6/14.
//  Copyright © 2017年 luoshuai. All rights reserved.
//

#import <CocoaLumberjack/CocoaLumberjack.h>

@interface XESLogFileManager : DDLogFileManagerDefault

/**
 初始化文件路径

 @param logsDirectory 文件路径
 @param fileName 日志名称
 @return self
 */
- (instancetype)initWithLogsDirectory:(NSString *)logsDirectory fileName:(NSString *)fileName;
@end
