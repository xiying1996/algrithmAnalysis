#include <iostream>
#include <string>

using namespace std;

string spaceReplace(string str){
    string newString = "";
    for(auto c : str)//这种遍历string的方式需要记住
    {
        if(c == ' ')
        {
           newString += "%20"; 
        }
        else {
            newString += c;
        }
    }
    return newString;
}

// length 为数组的总长度
void spaceReplace(char string[], int length){
    if(string == NULL || length <= 0)
        return;
    int oldLength = 0;
    int numOfSpace = 0;
    int i = 0;
    while (string[i] != '\0') {
        oldLength ++;

        if (string[i] == ' ') 
            numOfSpace ++;
        
        ++ i;
    }
    int newLength = oldLength + 2*numOfSpace;
    cout << "newLength: " << newLength << endl;
    if(newLength > length)
        return;
    int j = newLength;
    while (i != j) {
        if (string[i] == ' '){
            string[j--] = '0'; //这种优雅的方式需要记住
            string[j--] = '2';
            string[j--] = '%';
        }
        else {
            string[j--] = string[i];
        }
        --i;
    }


}

int main(){
    string url = " werwejri wrweo wer w ";
    char string1[128] = " werwejri wrw22eo wer w ";
    cout << spaceReplace(url) << endl;
    spaceReplace(string1, 128);
    cout << string1 << endl;
}