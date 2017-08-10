//
//  LearnC.h
//  LearnOCandCandC++
//
//  Created by 林伟池 on 16/2/23.
//  Copyright © 2016年 林伟池. All rights reserved.
//

#ifndef LearnC_h
#define LearnC_h

#include <stdio.h>

/**  C++编译器编译时生成函数名称的规则和C编译器不一样，
     如果是在C++中使用用C语言编译器编译生成的库文件，
     就需要用这个，防止C++编译器链接不到函数。 */

/**  1.c++中定义了__cplusplus，C语言中没有该定义。即：识别是c代码还是c++代码。 */
/**  2.C语言和C++编译出来的函数不同，调用extern "C"会让c++编译器按照c的编译格式来编译。多用于c++库的头文件。 */

#ifdef __cplusplus  //c++编译环境中才会定义__cplusplus (plus就是"+"的意思)
extern "C" {        //告诉编译器下面的函数是c语言函数（因为c++和c语言对函数的编译转换不一样，主要是c++中存在重载）
#endif
    
    
    
void learnCplus(int a, int b);
    
    
    
    
    
    
#ifdef __cplusplus
}
#endif

#endif /* LearnC_h */
