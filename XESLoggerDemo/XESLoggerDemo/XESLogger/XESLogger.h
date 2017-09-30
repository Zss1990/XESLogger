//
//  XESLogger.h
//  XESCommon
//
//  Created by luoshuai on 2017/6/14.
//  Copyright © 2017年 luoshuai. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CocoaLumberjack.h"
#ifdef DEBUG
static const int ddLogLevel = DDLogLevelDebug;
#else
static const int ddLogLevel = DDLogLevelOff;
#endif

//NSLog( @"[%@ in line %d] ===============>%@", [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, [NSString stringWithFormat:(s), ##__VA_ARGS__] )

//错误Log
#define XESLogError(frmt, ...)   LOG_MAYBE(NO,                LOG_LEVEL_DEF, DDLogFlagError,   0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
//警告Log
#define XESLogWarn(frmt, ...)     LOG_MAYBE(LOG_ASYNC_ENABLED, LOG_LEVEL_DEF, DDLogFlagWarning, 0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
//详细信息日志
#define XESLog(frmt, ...)  LOG_MAYBE(LOG_ASYNC_ENABLED, LOG_LEVEL_DEF, DDLogFlagDebug,   0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)

#define XESLogInfo(frmt, ...) LOG_MAYBE(LOG_ASYNC_ENABLED, LOG_LEVEL_DEF, DDLogFlagInfo,    0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)


typedef NS_ENUM(NSUInteger, XESLogLevel){
    /**
     *  关闭
     */
    XESLogLevelOff       = 0,
    
    /**
     *  输出:错误
     */
    XESLogLevelError,
    
    /**
     *  输出:错误、警告
     */
    XESLogLevelWarning,
    /**
     *  输出:Info、警告、错误
     */
    XESLogLevelInfo,
    
    /**
     *   输出:Debug、Info、错误、警告
     */
    XESLogLevelDebug,
    
    /**
     *  全部输出
     */
    XESLogLevelAll
};


@protocol XESLoggerDataSource;
@interface XESLogger : NSObject

//可保存用户信息状态
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
 数据源
 */
@property (nonatomic,weak) id<XESLoggerDataSource>dataSoutce;

/**
 存放日志文件夹路径地址
 */
@property (nonatomic, copy ,readonly) NSString *loggerFolderPath;
/**
 设置时间 默认为一天
 */
@property (nonatomic) NSTimeInterval rollingFrequency;

/**
 设置文件个数，默认为7个,最大数量为20，超过7个文件，删除时间最后的一个
 */
@property (nonatomic) NSInteger maximumNumberOfLogFiles;


/**
 不允许init和new

 @return self
 */
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 单利

 @return slef
 */
+ (instancetype)sharedInstance;


/**
  设置保存文件名称

 @param fileName 文件名，默认已.log为后缀
 */
- (void)saveFileName:(NSString *)fileName;
/**
 设置保存文件夹路径和文件名称

 @param filePath 文件夹路径
 @param fileName 文件名称
 */
- (void)saveFilePath:(NSString *)filePath fileName:(NSString *)fileName;


/**
 设置需要保存文件日志等级

 @param levelLog 错误，警告，消息
 */
- (void)setFileLeveLog:(XESLogLevel)levelLog;
/**
 设置需要在打印台日志等级
 
 @param levelLog 错误，警告，消息
 */
- (void)setLeveLog:(XESLogLevel)levelLog;


/**
 清除日志
 */
- (BOOL)clearAllLogger;
@end









@protocol XESLoggerDataSource <NSObject>

/**
 自定义打印格式 如果不需要默认为  XESLogFormatter

 @return 实现  DDLogFormatter 协议 即可
 */
- (id <DDLogFormatter>)loggerCustomFormatter;

/**
 自定义保存格式 如果不需要默认为  XESLogFileManager
 
 @return 实现  DDLogFormatter 协议 即可
 */
- (id <DDLogFormatter>)loggerCustomFileFormatter;


@end





