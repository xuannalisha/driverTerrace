//
//  ViewSetting.h
//  driverTerrace
//
//  Created by 关云秀 on 2019/3/13.
//  Copyright © 2019 xuannalisha. All rights reserved.
//

#ifndef ViewSetting_h
#define ViewSetting_h
//默认UITableViewCell
#define UITableViewCellNone [[UITableViewCell alloc]initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@""]


#define kStatusBarHeight [[UIApplication sharedApplication] statusBarFrame].size.height
#define kNavBarHeight 44.0
#define kTabBarHeight ([[UIApplication sharedApplication] statusBarFrame].size.height>20?83:49)
#define kTopHeight (kStatusBarHeight + kNavBarHeight)

#define kBottomSafeHeight ((isIPhoneX())?34:0)

#define  adjustsScrollViewInsets_NO(scrollView,vc)\
do { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
if ([UIScrollView instancesRespondToSelector:NSSelectorFromString(@"setContentInsetAdjustmentBehavior:")]) {\
[scrollView   performSelector:NSSelectorFromString(@"setContentInsetAdjustmentBehavior:") withObject:@(2)];\
} else {\
vc.automaticallyAdjustsScrollViewInsets = NO;\
}\
_Pragma("clang diagnostic pop") \
} while (0)

// 屏宽
#define kScreenWidth \
([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)] ? [UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale : [UIScreen mainScreen].bounds.size.width)
// 屏高
#define kScreenHeight \
([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)] ? [UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale : [UIScreen mainScreen].bounds.size.height)
// 屏的size(宽、高)
#define kScreenSize \
([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)] ? CGSizeMake([UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale,[UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale) : [UIScreen mainScreen].bounds.size)

// 计算高度
#define kSTRING_HEIGHT(_width_, _string_, _fsize_) [_string_ boundingRectWithSize:CGSizeMake(_width_, MAXFLOAT) options:NSStringDrawingUsesLineFragmentOrigin attributes:@{NSFontAttributeName: [UIFont systemFontOfSize:_fsize_]} context:nil].size.height

// 计算宽度
#define kSTRING_WIDTH(_height_, _string_, _fsize_) [_string_ boundingRectWithSize:CGSizeMake(MAXFLOAT, _height_) options:NSStringDrawingUsesLineFragmentOrigin attributes:@{NSFontAttributeName: [UIFont systemFontOfSize:_fsize_]} context:nil].size.width


//适配不同机型的View大小
#define kWidth(R) (R)*(kScreenWidth)/375 //这里的320我是针对5s为标准适配的,如果需要其他标准可以修改
#define kHeight(R) (R)*(kScreenHeight)/667
#define font(R) (R)*(kScreenWidth)/375.0

// 颜色
#define kRGBColor(r, g, b) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]
#define kRGBAColor(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(r)/255.0 blue:(r)/255.0 alpha:a]
#define kRandomColor kRGBColor(arc4random_uniform(256),arc4random_uniform(256),arc4random_uniform(256))



// 16进制形式
#define kColorWithHex(hexValue) \
[UIColor colorWithRed:((float)((hexValue & 0xFF0000) >> 16)) / 255.0 \
green:((float)((hexValue & 0xFF00) >> 8)) / 255.0 \
blue:((float)(hexValue & 0xFF)) / 255.0 alpha:1.0]



#define SHOW_ALERT(_TITLE_,_MSG_,_CANCEL_,_OTHER_)  UIAlertView *alert = [[UIAlertView alloc] initWithTitle:_TITLE_ message:_MSG_ delegate:nil cancelButtonTitle:_CANCEL_ otherButtonTitles:_OTHER_, nil];\
[alert show];
#define kIMAGE(A) [UIImage imageWithContentsOfFile:[NSBundle mainBundle] pathForResource:A ofType:nil]
#define kImageNamed(_name_) [UIImage imageNamed:_name_]

// APP对象 （单例对象）
#define kApplication [UIApplication sharedApplication]
// 主窗口 （keyWindow）
#define kKeyWindow [UIApplication sharedApplication].keyWindow
// APP对象的delegate
#define kAppDelegate [UIApplication sharedApplication].delegate
// NSUserDefaults实例化
#define kUserDefaults [NSUserDefaults standardUserDefaults]
// 通知中心 （单例对象）
#define kNotificationCenter [NSNotificationCenter defaultCenter]


#define kAppVersion [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]

#define kSystemVersion [[[UIDevice currentDevice] systemVersion] doubleValue]

#define kISiPhone (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define kISiPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

// 沙盒的Document路径
#define kDocumentPath [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
// 沙盒的temp路径
#define kTempPath NSTemporaryDirectory()

// 获取沙盒的Cache路径
#define kCachePath [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]

#if TARGET_OS_IPHONE
// 真机
#endif
#if TARGET_IPHONE_SIMULATOR
// 模拟器
#endif


#define kWeakSelf(type)  __weak typeof(type) weak##type = type;
#define kStrongSelf(type) __strong typeof(type) type = weak##type;

#define kDegreesToRadian(x) (M_PI * (x) / 180.0)
#define kRadianToDegrees(radian) (radian * 180.0) / (M_PI)




#endif /* ViewSetting_h */
