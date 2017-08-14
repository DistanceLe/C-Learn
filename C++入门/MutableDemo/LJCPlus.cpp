//
//  LJCPlus.cpp
//  MutableDemo
//
//  Created by LiJie on 2017/8/3.
//  Copyright © 2017年 LiJie. All rights reserved.
//

#include "LJCPlus.hpp"
#include <iostream>

#include <string>
#include <ctime>

using namespace std;
void printBook(struct Books book);

/**  结构体 Book */
struct Books{
    char title[50];
    char author[50];
    char subject[100];
    int bookID;
};

/**  使用typedef 更简单的结构定义，定义时不再使用struct */
typedef struct {
    char title[40];
    char author[40];
    char subject[100];
    int bookID;
}EasyBooks;

int hello(){
    
    cout << "hello world C++";
    
    /**  endl  表示在末尾加入一个换行 */
    cout << "size of char:" << sizeof(char) << endl;
    cout << "size of int:" << sizeof(int) << endl;
    cout << "size of short int:" << sizeof(short) << endl;
    cout << "size of long int:" << sizeof(long) << endl;
    cout << "size of float:" << sizeof(float) << endl;
    cout << "size of double:" << sizeof(double) << endl;
    cout << "size of wchar_t:" << sizeof(wchar_t) << endl;
    
    /**  取个别名 */
    typedef int LJInt;
    
    
    /**  枚举 */
    enum LJColor{
        red,
        green,
        blue
    };
    
    LJColor colorName = blue;
    cout << colorName << endl;
    
    
    /**  限定符 */
    const int constValue = 4; //常量
    volatile int volatileValue = 7;//类型可能会变的类型
    //restrict  未知 ：由 restrict 修饰的指针是唯一一种访问它所指向的对象的方式。只有 C99 增加了新的类型限定符 restrict。
    
    
    /**  存储类 */
    //auto
    {
        auto int mount; //auto 定义只能在函数内，即修饰局部变量
    }
    //register
    {
        //最大尺寸等于寄存器的大小（通常是一个词），且不能对它应用一元的 '&' 运算符（因为它没有内存位置）
        register int miles;//存储在寄存器中，而不是RAM中
    }
    //static
    {
        //修饰局部变量的时候，每次进入时，不会重新创建和销毁。
        //修饰全局变量的时候，作用域限制在它的文件内。
        static int  count = 10;
    }
    
    //extern
    {
        //用于提供一个全局变量的引用，全局变量对所有的程序文件都是可见的
        //是用来在另一个文件中声明一个全局变量或函数
    }
    //mutable
    {
        //仅适用于类的对象  它允许对象的成员替代常量。也就是说，mutable 成员可以通过 const 成员函数修改
    }
    
    
    
    /**  .（点）和 ->（箭头） 	  成员运算符用于引用类、结构和共用体的成员。 */
    /**  &  求地址符 */
    /**  *  指针，*var 指向变量var */
    int var = 10;
    int *ip = &var;
    cout << "指针" << ip << " " << *ip << "  " << &ip << endl;
    
    
    
    /**  随机数 */
    cout << "随机数：" << rand() << endl;
    cout << "系统时间戳：" << time(NULL) << endl;
    
    
    
    /**  数组 */
    double balance[10];
    double balanceFive[5] = {100.0, 2.0, 49, 42.1, 1};
    double balanceArray[] = {13, 242, 131.0, 44};
    
    balance[4] = 409.0;
    double firstBalance = balance[0];
    cout << firstBalance << "  " <<  balance << endl;
    
    
    
    /**  字符串  1.C风格， 2.string类型 */
    //C风格
    char greeting[] = "Hello";
    char greetingArray[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
    // \0表示字符串结束，所以，如果输出的\0在 中间的话，后面的字符串就不会输出。包括后面的另外的cout方法
    //cout << "字符串最后一个字符,空字符" << greeting << greeting[5] << "第二个" << greetingArray[5] <<endl;
    
    
    //string 类
    string str1 = "hello";
    string str2 = "world";
    string str3 = str1 + str2;
    cout << "str.size():"  << str1.size() << endl;
    
    
    
    
    /**  结构体 */
    struct Books book1;
    struct Books book2;
    
    EasyBooks book3;
    
    //book1.title = "Learn C++ Programming";  不行
    strcpy(book1.title, "Learn C++ Programming");
    strcpy(book1.author, "Chand Miyan");
    strcpy(book1.subject, "C++ Programming");
    book1.bookID = 49223;
    
    cout << "book1:" << book1.title << endl;
    printBook(book1);
    
    
    /**  结构指针，指向结构体的指针 */
    struct Books *structPointer;
    structPointer = &book1;
    //必须使用 -> 运算符
    cout <<"pointer struct: " << structPointer->title << endl;
    
    
    
//    char name[50];
//    cout << "请输入您的名称： ";
//    cin.clear();
//    cin.sync();
//    cin >> name;
//    cout << "您的名称是： " << name << endl;
    
    /**  范围解析运算符 ::   */
    //成员函数可以定义在类定义内部，或者单独使用范围解析运算符 :: 来定义
    //在类定义中定义的成员函数把函数声明为内联的，即便没有使用 inline 标识符
    
    
    
    
    
    
    return 0;
}

void printBook(struct Books book){
    cout << "BookTitle:  " << book.title << endl;
    cout << "BookAuthor:  " << book.author << endl;
    cout << "BookSubject:  " << book.subject << endl;
    cout << "BookID:  " << book.bookID << endl;
}

class FriendClass{
private:
    int people;
    void getFriend(){
        cout << "friend Class" << endl;
    }
};

/**  类 */
class Box{
   
    /**  声明 FriendClass 为 Box的友元类 */
    friend class FriendClass;
    
    //保护的  成员函数 和 子类  可以访问
protected:
    double area;
    
    //默认就是 private的属性。 只有成员函数 和 友元函数可以访问。
private:
    double width;
    
public:
    double length;
    double height;
    double breadth;
    
    //构造函数声明
    Box();
    
    //带参数的构造函数声明
    Box(double len);
    
    //析构函数声明
    ~Box();
    
    
    //内联函数 inline, 会把函数里的代码直接贴到使用的地方。
    inline double getArea(void){
        return length * width;
    }
    
    
    //定义在类定义内部   默认也是内联函数 不需要加inline
    double getVolume(void){
        return length*height*breadth;
    }
    //在类外面定义， 这里先声明函数
    void setLength(double len);
    
    
    //Box的友元函数， 可以访问Box的私有成员和保护的成员。并且不属于任何一个类。
    friend void printWidth(Box box);
    
    
    //this 指针的使用
    int compare(Box box){
        //this 指针是所有成员函数的隐含参数
        //只有成员函数才有 this 指针。
        //友元函数没有 this 指针，因为友元不是类的成员
        return this->getVolume() > box.getVolume();
    }
    
};

//使用范围解析运算符 :: 来定义
void Box::setLength(double len){
    length = len;
}

// 请注意：printWidth() 不是任何类的成员函数
void printWidth(Box box){
    /* 因为 printWidth() 是 Box 的友元，它可以直接访问该类的任何成员 */
    cout << "Width of box : " << box.width <<endl;
}


/**  继承 */

//公有继承， 基类的公有成员，保护成员 也是子类的公有成员和保护成员，私有成员不能访问
//私有继承， 基类的公有成员，保护成员  都是子类的私有成员
//保护继承， 基类的公有成员，保护成员  都是子类的保护成员
class BlueBox: public Box{
    
public:
    string getName(){
        return "Blue Box";
    }
};



class Shape{
public:
    int len;
    void getShape(void){
        cout << "your shape is Rectangle" << endl;
    }
    
    /**  多态 */
    //加上virtual后，派生类中的相同函数，就不会调用父类的方法。
    //这种操作称为 动态链接，或后期绑定
    //静态链接，表示函数在编译期间就已经设置好了，也叫早绑定，静态多态、就会直接调用父类的方法，而忽略子类方法
    virtual double area(double len, double width){
        return len * width;
    }
    
    //纯虚函数， 没有主体的虚函数  = 0 告诉编译器，函数没有主体。
    //有一个纯虚函数 就是抽象类。
    virtual double area() = 0;
};


/**  多继承 */
class MultiClass: public Box, public Shape{
    string getName(){
        return "Multi Class";
    }
    
    /**  多态，重写父类方法 */
    double area(){
        cout << "这个是 子类函数的area" << endl;
        return len*0.8;
    }
    
    
    //重载，
    //1. 函数重载， 参数必须不同
    //2. 运算符重载。
    MultiClass operator+(const MultiClass& s){
        MultiClass shape;
        shape.len = this->len + s.len;
        return shape;
    }
};
















