//
//  LJFileOperation.cpp
//  MutableDemo
//
//  Created by LiJie on 2017/8/14.
//  Copyright © 2017年 LiJie. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void operatorFile(){
    
    /** 数据类型
         ofstream  写文件
         ifstream  读文件
         fstream   读写文件*/
    
    fstream outfile;
    
    /**  打开的模式
        ios::app    追加模式
        ios::ate    打开后定位在末尾
        ios::in     用于读取
        ios::out    用于写入
        ios::trunc  如果文件已存在，文件长度设为0*/
    fstream fout("file1.txt");
    
    if (fout) {
        cout << "创建文件 file.txt" << endl;
    }else{
        cout << "创建文件 file.txt  失败" << endl;
    }
    
    outfile.open("file.txt", std::ios::out | std::ios::trunc);
    
    
    /**  重定位指针位置 
        seekg(n), seekg(n, model)    get
        seekp(n), seekp(n, model)    put
     
        mode   ios::cur 当前位置 向后移   ios::end结束位置开始 往回移*/
    
    outfile.seekg(10, ios::cur);
    outfile.seekp(10);
    
    
    
    /**  最好不用时关闭。 */
    outfile.close();
    
    
    
    string data;
    
    //写模式打开文件
    std::ofstream writeFile;
    writeFile.open("~/file.txt");
    
    data = "new Data write to file.txt";
    
    writeFile << data << endl;
    writeFile.close();
    
    
    /**  异常处理 */
    /**  
     std::exception     该异常是所有标准 C++ 异常的父类。
     std::bad_alloc     该异常可以通过 new 抛出。
     std::bad_cast      该异常可以通过 dynamic_cast 抛出。
     std::bad_exception	这在处理 C++ 程序中无法预期的异常时非常有用。
     std::bad_typeid	该异常可以通过 typeid 抛出。
     std::logic_error	理论上可以通过读取代码来检测到的异常。
     std::domain_error	当使用了一个无效的数学域时，会抛出该异常。
     std::invalid_argument	当使用了无效的参数时，会抛出该异常。
     std::length_error	当创建了太长的 std::string 时，会抛出该异常。
     std::out_of_range	该异常可以通过方法抛出，例如 std::vector 和 std::bitset<>::operator[]()。
     std::runtime_error	理论上不可以通过读取代码来检测到的异常。
     std::overflow_error	当发生数学上溢时，会抛出该异常。
     std::range_error	当尝试存储超出范围的值时，会抛出该异常。
     std::underflow_error	当发生数学下溢时，会抛出该异常。 */
    try {
        int a = 0;
        if (a > 0) {
            throw "Division by zero condition!";
        }
    } catch (bad_exception) {
        
    }
    
    /**  也可以自定义异常，继承exception，即可 */
    
}














