#ifndef SINGLETON_H
#define SINGLETON_H
#include <mutex>

class Singleton{
private:
    static Singleton* instance; //静态的成员变量
    static std::mutex _mutex;  // 互斥锁，用于线程安全
    Singleton() {} //私有的构造函数，防止外部实例化

public:
    static Singleton* getInstance();
    void printMessage();

};


#endif