//
//  LJMemory.cpp
//  MutableDemo
//
//  Created by LiJie on 2017/8/15.
//  Copyright © 2017年 LiJie. All rights reserved.
//

#include <stdio.h>

#include <iostream>
#include <string>
#include <vector>
#include <csignal>
#include <unistd.h>

#include <pthread.h>

//#include <cstdlib>
//#include <stdexcept>


using namespace std;

//只打算使用std中的 cout部分。
//using std::cout;

namespace first_space {
    void memoryFunc(){
        cout << "第一个命名空间" << endl;
    }
}

class MemClass{
public:
    MemClass(){
        cout << "调用了构造函数！" << endl;
    }
    
    ~MemClass(){
        cout << "调用了析构函数！" << endl;
    }
};



/**  模板， 泛型 */
template <typename E>
inline E const& Max(E const& a, E const& b){
    return a<b ? b : a;
}

/**  类模板 */
template <class T>
class Stack {
private:
     vector<T>  elems;
    
public:
    void push(T const&);
    void pop();
    T top() const;
    bool empty() const{
        return  elems.empty();
    }
};

template <class T>
void Stack<T>::push( T const& elem){
    //追加元素
    
    elems.push_back(elem);
}

template <class T>
void Stack<T>::pop(){
    if (elems.empty()) {
        throw out_of_range("Stack<>::pop():empty stack");
    }
    
    //删除最后一个元素
    elems.pop_back();
}

template <class T>
T Stack<T>::top() const{
    if (elems.empty()) {
        throw out_of_range("Stack<>::top(): empty stack");
    }
    
    //返回最后一个元素副本
    return elems.back();
}

/**  信号处理： */
/**  
 SIGABRT	程序的异常终止，如调用 abort。
 SIGFPE	错误的算术运算，比如除以零或导致溢出的操作。
 SIGILL	检测非法指令。
 SIGINT	接收到交互注意信号。
 SIGSEGV	非法访问内存。
 SIGTERM	发送到程序的终止请求。 */

void signalHandler(int signum){
    cout << "interrupt signal (" << signum << ")received.\n";
    
    exit(signum);
}


void* sayHello(void* args){
    cout << "Hello  我是多线程" << endl;
    cout << "args: " << *((int*)args) << endl;
    return 0;
}

void memoryFunc(){
    MemClass* memArray = new MemClass[4];
    
    delete [] memArray;
    
    
    int i = 30;
    int j = 20;
    cout << "max(i, j):" << Max(i, j) << endl;
    
    try{
        Stack<int> intStack;
        Stack<string> stringStack;
        
        intStack.push(4);
        cout << intStack.top() << endl;
        
        stringStack.push("hello");
        cout << stringStack.top() << endl;
    }
    catch(exception const& ex){
        
    }
    
    
    /**  注册信号 SIGINT 和信号处理程序 */
//    int k = 1;
//    signal(SIGINT, signalHandler);
//    while (k++) {
//        cout << "going to sleep..." << endl;
//        sleep(1);
//        if (k == 3) {
//            raise(SIGINT);//发送信号
//        }
//    }
    
    
    /**  多线程 */
    pthread_t tids[5];
    int index [5];
    
    // 初始化并设置线程为可连接的（joinable）
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    
    
    for (int i=0; i<5; i++) {
        index [i] = i+19;
        
        /**  pthread_create (thread, attr, start_routine, arg) 
         thread	一个不透明的、唯一的标识符，用来标识例程返回的新线程。
         attr	一个不透明的属性对象，可以被用来设置线程属性。您可以指定线程属性对象，也可以使用默认值 NULL。
         start_routine	C++ 例程，一旦线程被创建就会执行。
         arg	一个可能传递给 start_routine 的参数。它必须通过把引用作为指针强制转换为 void 类型进行传递。如果没有传递参数，则使用 NULL。*/
        int ret = pthread_create(&tids[i], NULL, sayHello, (void*)&(index[i]));
        if (ret != 0) {
            cout << "线程创建错误：" << ret << endl;
        }
    }
    
    
    // 删除属性，并等待其他线程
    pthread_attr_destroy(&attr);
    
    
    
    
    
    
    
    //等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来；
    pthread_exit(NULL);
    
    
}














