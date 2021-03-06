//
//  CustomKeyBoardView.h
//  KeyBoardDemo
//
//  Created by Rain on 2018/8/1.
//  Copyright © 2018年 Rain. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, KeyBoardType) {
    KeyBoardTypeNormal,             //普通数字键盘        不带小数点、不可以为负
    KeyBoardTypePoint,              //数字键盘           带小数点
    KeyBoardTypeNegavite,           //数字键盘           带正负
    KeyBoardTypeCalcuateNormal,     //普通计算数字键盘     不带小数点 、不可以为负
    KeyBoardTypeCalcuatePoint,      //计算数字键盘        带小数点
    KeyBoardTypeCalcuateNegavite,   //计算数字键盘        带正负
};

typedef void(^CloseKeyboardBlock)(void);//关闭自定义键盘block
typedef void(^ConfirmBlock)(void);//点击确定按钮block
typedef void(^DeleteBlock)(void);//点击删除按钮block
typedef void(^ClearBlock)(void);//点击清空按钮block

@protocol CustomKeyBoardViewDelegate <NSObject>
@required
/**
 发送TextFiled要显示的内容
 */
- (void)senderTextFieldContent:(NSString *)value close:(BOOL)close;
@optional
/**
 点击确定按钮回调代理方法
 */
- (void)clickSureAction;
/**
 清空内容
 */
- (void)clearContent;

@end

@interface CustomKeyBoardView : UIView
/**
 传入正在输入的文本框
 */
@property (nonatomic, strong) UIView *inputSource;

/**
 数据源
 */
@property (nonatomic, strong) NSArray *dataSource;
/**
 输入框内容
 */
@property (nonatomic, copy) NSString *inputText;
/**
 键盘类型
 */
@property (nonatomic, assign) KeyBoardType keyboardType;
/**
 代理
 */
@property (nonatomic, weak) id<CustomKeyBoardViewDelegate>delegate;

@property (nonatomic, copy) CloseKeyboardBlock closeKeyboardBlock;

@property (nonatomic, copy) ConfirmBlock confirmBlock;

@property (nonatomic, copy) DeleteBlock deleteBlock;

@property (nonatomic, copy) ClearBlock clearBlock;
/**
 初始化键盘view
 */
- (instancetype)initWithFrame:(CGRect)frame keyBoardType:(KeyBoardType)keyBoradType;
/**
 初始化键盘view
 
 @param keyBoradType 键盘类型
 @return view
 */
- (instancetype)initWithKeyboardType:(KeyBoardType)keyBoradType;
/**
 初始化键盘view
 
 @param keyBoradType 键盘类型
 @return view
 */
- (instancetype)initWithKeyboardType:(KeyBoardType)keyBoradType inputSource:(UIView *)inputSource;
@end
