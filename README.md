
### 一、安装
##### 1.1、Installation with CocoaPods
    1、在 `Podfile` 中添加 `pod 'XESLogger'`。
    2、执行 `pod install` 或 `pod update`。    
    3、导入 `"XESLogger.h"`。

##### 1.2、手动安装（不推荐）
    1、下载XESLogger文件夹内的所有内容。
    2、将XESLogger内的源文件添加（拖放）到你的工程。
    3、导入XESLogger.h。 

---


### 二、XESLogger介绍
##### 2.1、简介
XESLogger是学而思基础架构组为组件化开发提供的日志模块,提供了自定义输出格式和自定义输出到本地日志格式。


### 三、XESLogger 提供了哪些服务

##### 3.1、提供打印台和本地日志存储
&emsp;&emsp; 3.1.1 日志相关属性
    
 ```
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
                                            
 ```
    
&emsp;&emsp; 3.1.2 示例代码


```
//初始化并且设置本地存储参数
XESLogger *logger = [XESLogger sharedInstance];
[logger setUserID:@"userid"];
[logger setNetWorkStatus:@"netWorkStatus"];
[logger setToken:@"token"];

//设置输出台打印级别
[logger setLeveLog:XESLogLevelOff];

//设置本地存储名称和级别
[logger saveFileName:@"呵呵哒"];
[logger setFileLeveLog:XESLogLevelWarning];

//设置冷却时间 默认0.5秒
[XESRouter filterRouterTime:0.3];

```    
##### 3.2 、提供日志级别

&emsp;&emsp; 3.2.1 提供的接口

```
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
 - (void)setFileLeveLog:(XESLogLevel)levelLog
```

&emsp;&emsp; 3.2.2 示例代码

```
XESLogger *logger = [XESLogger sharedInstance];
[logger setFileLeveLog:XESLogLevelWarning];
```
##### 3.3 、提供打印格式
&emsp;&emsp;提供四种打印格式

&emsp;&emsp; 3.3.1 提供的接口

```
暂无接口   
                                           
```

&emsp;&emsp; 3.3.2 示例代码

```
XESLogError(@"错误日志");
XESLogWarn(@"警告日志");
XESLogInfo(@"信息日志");
XESLog(@"debug日志");
```


### 四、XESLogger API分为以下几个分类

* `XESLogger`
* `XESLogFormatter`
* `XESLogFileManager`

##### 4.1、XESLogger

 &emsp;&emsp;4.1.1、介绍
 &emsp;&emsp;&emsp;&emsp;  `XESRouter`类是私有一个单例类，所有的日志设置有此类提供。
  
&emsp;&emsp;4.1.2、接口
&emsp;&emsp;&emsp;&emsp;此类为单例，不允许使用init、new方法创建实例对象

```
/**
 不允许init和new

 @return self
 */
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

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

```


---


##### 4.2、XESLogFileManager

 &emsp;&emsp;4.3.1、介绍
   &emsp;&emsp; &emsp;&emsp; 设置日志文件格式和参数类继承于`DDLog/DDLogFileManagerDefault`。
   
 &emsp;&emsp;4.3.2、接口

```
/**
 初始化文件路径

 @param logsDirectory 文件路径
 @param fileName 日志名称
 @return self
 */
- (instancetype)initWithLogsDirectory:(NSString *)logsDirectory fileName:(NSString *)fileName;
                           
```
---

### 历史版本
* 0.5.0
  * 初始化提交
  * 制作pod源

---
### 系统要求
该项目最低支持 iOS 7.0 和 Xcode 7.0。


