#include <iostream>
#include "singleton.h"

using namespace std;

Singleton* Singleton::instance = nullptr;
std::mutex Singleton::_mutex;

// 获取单例实例的静态方法
Singleton* Singleton::getInstance() {
    if (instance == nullptr) {
        std::lock_guard<std::mutex> lock(_mutex);  // 加锁，自动释放
        if(instance == nullptr){
            instance = new Singleton();
        }
    }
    return instance;
}

// 示例方法的实现
void Singleton::printMessage() {
    // 实现方法的具体逻辑
    // ...
    // 示例输出
    std::cout << "Hello, Singleton!" << std::endl;
}