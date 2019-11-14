//
//  TranslateResult.h
//  ifanyi
//
//  Created by ripper on 2019/11/13.
//  Copyright © 2019 ripperhe. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TranslateLanguage.h"

NS_ASSUME_NONNULL_BEGIN

@interface TranslatePhonetic : NSObject

/// 语种的中文名称
@property (nonatomic, copy) NSString *name;
/// 此音标对应的语音地址
@property (nonatomic, copy) NSString *ttsURI;
/// 此语种对应的音标值
@property (nonatomic, copy) NSString *value;

@end

@interface TranslatePart : NSObject

/// 单词属性，例如 'n.'、'vi.' 等
@property (nonatomic, copy, nullable) NSString *part;
/// 此单词属性下单词的释义
@property (nonatomic, strong) NSArray<NSString *> *means;

@end

@interface TranslateExchange : NSObject

/// 形式的名字
@property (nonatomic, copy) NSString *name;
/// 对应形式的单词，可能是多个
@property (nonatomic, strong) NSArray<NSString *> *words;

@end

@interface TranslateWordResult : NSObject

/// 音标
@property (nonatomic, strong, nullable) NSArray<TranslatePhonetic *> *phonetics;
/// 词性词义
@property (nonatomic, strong) NSArray<TranslatePart *> *parts;
/// 其他形式
@property (nonatomic, strong, nullable) NSArray<TranslateExchange *> *exchanges;

@end

@interface TranslateResult : NSObject

/// 此次查询的文本
@property (nonatomic, copy) NSString *text;
/// 此翻译接口的在线查询地址
@property (nonatomic, copy) NSString *link;
/// 由翻译接口提供的源语种，可能会与查询对象的 from 不同
@property (nonatomic, assign) Language from;
/// 由翻译接口提供的目标语种，注意可能会与查询对象的 to 不同
@property (nonatomic, assign) Language to;
/// 如果查询的是英文单词(或某些固定词组)，翻译接口会返回这个单词的详细释义
@property (nonatomic, strong, nullable) TranslateWordResult *wordResult;
/// 普通翻译结果，可以有多条（一个段落对应一个翻译结果）
@property (nonatomic, strong, nullable) NSArray<NSString *> *normalResults;
/// 翻译接口提供的原始的、未经转换的查询结果
@property (nonatomic, strong) id raw;

@end

NS_ASSUME_NONNULL_END
