#include "binarySearchTree.h"
#include <iostream>

/**
* 如果在树中找到x，则返回true
*/
template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable& x) const{
    return BinarySearchTree::contains(x, root);
}

/**
* 将x插入到树中：忽略重复的元素
*/
template <typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable& x){
    std::cout << " insert " << x << std::endl;
    BinarySearchTree<Comparable>::insert(x, root);
}

/**
* 将x插入到树中：忽略重复的元素
*/
template <typename Comparable>
void BinarySearchTree<Comparable>::insert(Comparable&& x){
    std::cout << "&& insert " << x << std::endl;
    BinarySearchTree<Comparable>::insert(x, root);
}


/**
* 将x从树中删除，如果没有找到x，就什么都不做
*/
template<typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable& x){
    BinarySearchTree<Comparable>::remove(x, root);
}
/**
* 测试一项是否在子树上的内部方法，
* x是查找项，
* t是根节点
*/
template<typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable& x, BinaryNode* t)const{
    if (t == nullptr) {
        return false;
    }
    else if (x > t->element) {
        return contains(x, t->right);
    }
    else if (x < t->element){
        return contains(x, t->left);
    }
    else {
        return true; // 匹配
    }
}

/**
* 找出最小项的递归写法，内部方法
* 返回包含最小项的节点
*/
template<typename Comparable>
BinarySearchTree<Comparable>::BinaryNode* //函数的返回类型
BinarySearchTree<Comparable>::findMin(BinarySearchTree<Comparable>::BinaryNode* t)const{
    if (t == nullptr){
        return nullptr;
    }
    if(t->left == nullptr){
        return t;
    }
    return findMin(t->left);

}

/**
* 查找最大项的非递归实现，内部方法
* 返回包含最大项的节点
*/
template<typename Comparable>
BinarySearchTree<Comparable>::BinaryNode* BinarySearchTree<Comparable>::findMax(BinaryNode* t)const{
    if (t != nullptr)
        while (t->right != nullptr) {
            t = t->right;// 此处的t是安全的，因为使用了拷贝的方式
        }
    return t;
}

/**
* 向子树中插入元素的内部方法
* x是要插入的项
* t是根节点
* 置子树的新根
*/
template<typename Comparable>
void BinarySearchTree<Comparable>:: insert(const Comparable& x, BinaryNode* & t ){
    if (t == nullptr)
        t = new BinaryNode{x, nullptr, nullptr};
    else if (x < t->element)
        insert(x, t->left);
    else if (x > t->element)
        insert(x, t->right);
    else
     ;//重复元素，什么都不做

}

/**
* 向子树中插入元素的内部方法
* x是要插入的项
* t是根节点
* 置子树的新根
*/
template<typename Comparable>
void BinarySearchTree<Comparable>:: insert(Comparable&& x, BinaryNode* & t ){
    if (t == nullptr)
        t = new BinaryNode{std::move(x), nullptr, nullptr};
    else if (x < t->element)
        insert(std::move(x), t->left);
    else if (std::move(x) > t->element)
        insert(std::move(x), t->right);
    else
     ;//重复元素，什么都不做

}

/**
* 从一颗子树删除一项的内部方法
* 参数x是要被删除的项
* 参数t是该子树的根节点
* 置该子树的新根
*/
template<typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable & x, BinaryNode* & t){
    if (t == nullptr) 
        return;
    if (x < t->element)
        return remove(x, t->left);
    else if (x > t->element)
        return remove(x, t->right);
    else if (t->left != nullptr && t->right != nullptr){
        t->element = findMin(t->right)->element;
        remove(t->element, t->right);
    }
    else{
        BinaryNode* oldNode = t;
        t = (t->left != nullptr)? t->left : t->right;
        delete oldNode;
    }
}


/**
* 使子树为空的内部方法
*/
template <typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty(BinaryNode* & t){
    if (t != nullptr){
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = 0;
}

/**
* 使子树为空的外部方法
*/
template <typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty(){
    makeEmpty(this->root);
}

/**
* 析构函数
*/
template <typename Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree()
{
    makeEmpty();
}

/**
* 克隆子树的内部方法
*/
template<typename Comparable>
BinarySearchTree<Comparable>::BinaryNode* 
BinarySearchTree<Comparable>::clone(BinaryNode* t) const {
    if (t == nullptr) 
        return nullptr;
    else 
        return new BinaryNode{t->element, clone(t->left), clone(t->right)};
}

/**
*拷贝构造
*/
template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(const BinarySearchTree& rhs)
    : root{nullptr}
{
    root = clone(rhs.root);
}
// 默认构造函数
template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree()
    : root{nullptr}
{
}

template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(BinarySearchTree && rhs)
     :  root{rhs.root}
{
    rhs.root = nullptr;
}
/**
*是否是空树
*/
template <typename Comparable>
bool BinarySearchTree<Comparable>::isEmpty() const { 
    if (root == nullptr)
        return true;
    else
        return false;
}


/**
* 打印树的外部方法
*/
template <typename Comparable>
void BinarySearchTree<Comparable>::printTree(std::ostream & out) const {
    if (isEmpty())
        out << "Empty tree!" << std::endl;
    else
        printTree(root, out);
}

/**
* 打印树的外部方法
*/
template <typename Comparable>
void BinarySearchTree<Comparable>::printTree(BinaryNode* t ,std::ostream& out) const {
    if (t != nullptr){
        printTree(t->left, out);
        out << t->element << std::endl;
        printTree(t->right, out);
    }
}

template class BinarySearchTree<int>;
template class BinarySearchTree<double>;
