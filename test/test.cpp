#include "../src/singleton.h"
#include <iostream>
#include <thread>
#include <iostream>
#include "../src/2D_array.h"
#include "../src/binarySearchTree.h"
using namespace std;
int main(){
    int i = 43;
    int x = 5;
    BinarySearchTree<int> tree;
    tree.insert(10);
    tree.insert(100);
    tree.insert(i);
    tree.insert(5);
    tree.insert(20);
    tree.printTree();
    tree.remove(20);
    tree.printTree();
    tree.remove(x);
    tree.printTree();
    return 0;
}