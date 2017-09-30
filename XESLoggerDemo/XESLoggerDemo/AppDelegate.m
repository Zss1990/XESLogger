//
//  AppDelegate.m
//  XESLoggerDemo
//
//  Created by luoshuai on 2017/7/18.
//  Copyright © 2017年 luoshuai. All rights reserved.
//

#import "AppDelegate.h"
#import "XESLogger.h"
#import "XESLogFormatter.h"
@interface AppDelegate ()<XESLoggerDataSource>

@end

@implementation AppDelegate

//- (id<DDLogFormatter>)loggerCustomFileFormatter{
//    return [[XESLogFormatter alloc]init];
//}
//- (id<DDLogFormatter>)loggerCustomFormatter{
//    return [[XESLogFileFormatter alloc]init];
//}


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    
    
    XESLogger *logger = [XESLogger sharedInstance];
//    logger.dataSoutce = self;
    [logger setUserID:@"userid"];
    [logger setNetWorkStatus:@"netWorkStatus"];
    [logger setToken:@"token"];
    
    [logger setLeveLog:XESLogLevelAll];
    
    [logger saveFileName:@"呵呵哒"];
    [logger setFileLeveLog:XESLogLevelWarning];

    NSSetUncaughtExceptionHandler(&UncaughtExceptionHandle);

    
    
    XESLogError(@"错误日志");
    XESLogWarn(@"警告日志");
    XESLogInfo(@"信息日志");
    XESLog(@"调试  日志存放地址：%@",logger.loggerFolderPath);
    NSLog(@"调试  日志存放地址：%@",logger.loggerFolderPath);
    return YES;
}


void UncaughtExceptionHandle(NSException *exception){
    
    
    NSArray *callStack = [exception callStackSymbols];
    NSString *reason = [exception reason];
    NSString *name = [exception name];
    NSString *content = [NSString stringWithFormat:@"========异常错误报告========\nname:%@\nreason:\n%@\ncallStackSymbols:\n%@",name,reason,[callStack componentsJoinedByString:@"\n"]];
    NSMutableString *mailUrl = [NSMutableString string];
    [mailUrl appendString:@"mailto:1056063547@qq.com"];
    [mailUrl appendString:@"?subject=程序异常崩溃，请配合发送异常报告，谢谢合作！"];
    [mailUrl appendFormat:@"&body=%@",content];
    XESLogError(mailUrl);
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}


@end
