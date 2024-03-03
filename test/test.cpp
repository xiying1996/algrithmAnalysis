#include "../src/singleton.h"
#include <iostream>
#include <thread>
#include <iostream>
#include "../src/2D_array.h"
using namespace std;

void printSingletonMessage() {
    Singleton* singleton = Singleton::getInstance();
    singleton->printMessage();
}

 void changePtr(int* & x){
      cout << x;
      x = nullptr;
    }

int main(){
   TwoDArray<int> array = {
    {1,2,8,9},
    {2,4,9,10},
    {5,78,12,100},
    {7,20,82,200}
   };
    cout<<array.find_num_order(500)<<endl;
    cout<<array.get(1, 1)<<endl;
 // 在多个线程中获取单例实例并输出信息
    std::thread t1(printSingletonMessage);
    std::thread t2(printSingletonMessage);
    std::thread t3(printSingletonMessage);

    t1.join();
    t2.join();
    t3.join();

    // return 0;
    int i = 12;
    int i0 = 1;

    int* pi = &i;

   

    cout << "pi address:"<< pi << endl;

    changePtr(pi);

    cout << "after change pi address:"<< pi << endl;


}