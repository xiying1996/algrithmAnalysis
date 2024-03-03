#include <iostream>

using namespace std;
int Getsize(int date[])
{
    return sizeof(date);
}

int main()
{
    int date1[] = {1,2,3,4};
    int size1 = sizeof(date1);

    int* date2 =  date1;
    int size2 = sizeof(date2);

    int size3 = Getsize(date1);

    char str1[] = "hello world!";
    char str2[] = "hello world!";

    char* str3 = "hello world";
    char* str4 = "hello world";

    if(str1 == str2){
        cout << "str1 and str2 are same" << endl;
    }
    else{
        cout << "str1 and str2 not are same" << endl;
    }
    if(str3 == str4){
        cout << "str3 and str4 are same" << endl;
    }
    else{
        cout << "str3 and str4 not are same" << endl;
    }
    int size4 = sizeof(str1);
    int size5 = sizeof(str3);
    std::cout << size1 << ", "
              << size2 << ", "
              << size3 << ", " 
              << size4 << ", " 
              << size5 << std::endl;
}