//
//  LJFileOperation.cpp
//  MutableDemo
//
//  Created by LiJie on 2017/8/14.
//  Copyright © 2017年 LiJie. All rights reserved.
//

#include "LJFileOperation.hpp"

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
    
    
}














