#ifndef  BINARYSEARCHTREE_H
#define  BINARYSEARCHTREE_H
#include <iostream>
#include <utility>
template <typename Comparable>

class BinarySearchTree{

public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree& rhs);
    BinarySearchTree(BinarySearchTree && rhs);
    ~BinarySearchTree();

    const Comparable& findMin() const;
    const Comparable& findMax() const;
    bool contains(const Comparable& x) const;
    bool isEmpty() const; 
    void printTree(std::ostream & out = std::cout) const ;

    void makeEmpty();
    void insert(const Comparable& x);
    void insert(Comparable && x);
    void remove(const Comparable& x);

    BinarySearchTree& operator=(const BinarySearchTree& rhs);
    BinarySearchTree& operator=(BinarySearchTree&& rhs);

/*  */
private:
    struct BinaryNode{
        BinaryNode* left;
        Comparable element;
        BinaryNode* right;

        BinaryNode(const Comparable & theElement, BinaryNode* lt, BinaryNode* rt)
             : element{theElement}, left{lt}, right{rt} {} // 构造函数

        BinaryNode(Comparable && theElement, BinaryNode* lt, BinaryNode* rt)
             : element{std::move(theElement)}, left{lt}, right{rt} {} // 构造函数 
    };

    BinaryNode* root;

    void insert(const Comparable& x, BinaryNode* & t);
    void insert(Comparable&& x, BinaryNode* & t);
    void remove(const Comparable& x, BinaryNode* & t);
    BinaryNode* findMin (BinaryNode* t) const;
    BinaryNode* findMax (BinaryNode* t) const;
    bool contains(const Comparable& x, BinaryNode* t) const;
    void makeEmpty(BinaryNode* & t);
    void printTree(BinaryNode* t, std::ostream& out) const;
    BinaryNode* clone(BinaryNode* t) const;
};



#endif