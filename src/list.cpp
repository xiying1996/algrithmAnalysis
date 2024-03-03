#include <cmath>
#include <iostream>
#include <iterator>
#include <stack>
#include <stack>
#include <vector>

struct ListNode{
    int m_iValue;
    ListNode* m_pNext;
};
// 尾插法
void AddToTail (ListNode** pHead, int iValue){
    ListNode* pNew = new ListNode();
    pNew->m_iValue = iValue;
    pNew->m_pNext = nullptr;
    // std::cout << iValue << " ";
    if (*pHead == nullptr) {
        *pHead = pNew;
    }
    else {
        ListNode* pNode = *pHead;

        while (pNode->m_pNext != nullptr) {
            pNode = pNode->m_pNext;
        }
        pNode->m_pNext = pNew;
    }
}
// 头插法
void AddToHead (ListNode** pHead, int iValue){
    ListNode* pNew = new ListNode();
    // std::cout << iValue;
    pNew->m_iValue = iValue;
    pNew->m_pNext = *pHead;  // Point the new node's next pointer to the current head
    
    *pHead = pNew;  // Update the actual head to the new node
}

// 逆序打印

void printListReversingly(ListNode * pHead){
    ListNode* pNode = pHead;
    if (nullptr == pHead){
        std::cout << "pHead is NULL!" << std::endl;
        return;
    }
    // 入栈
    std::stack<ListNode*> nodes;
    while (pNode) {
        // std::cout<< pNode->m_iValue;
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }

    // 打印

    while (!nodes.empty()) {

        std::cout<<nodes.top()->m_iValue<<std::endl;
        nodes.pop();
    }

}

void printListReversingly_recursely(ListNode* pHead)
{
    if (nullptr == pHead)
    {
        return;
    }
    if (pHead->m_pNext) {
        printListReversingly_recursely(pHead->m_pNext);
    }
    std::cout<<pHead->m_iValue<< std::endl;
}

int main(){
    std::vector<int> nums = {1,2,3,4,5};
    ListNode* pHead = nullptr;
    // AddToHead(&pHead, 6);
    // AddToTail(&pHead, 4 );
    // for(const auto& n : nums){
    //     AddToHead(&pHead,n);
    //     // AddToTail(&pHead, n);
    // }
    printListReversingly_recursely(pHead);
    // while (pHead) {
    //    std::cout << pHead->m_iValue<< std::endl;
    //    pHead = pHead->m_pNext;
    // }
    std::cout << "hello    workd" << std::endl;
}