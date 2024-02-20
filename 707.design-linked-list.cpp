/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] Design Linked List
 */
#include "General.h"

// @lc code=start
class MyLinkedNode 
{
private:
    int val;
    MyLinkedNode* next;

public:
    MyLinkedNode(int val)
    {
        this->val = val;
        this->next = nullptr;
    }

    int& getVal()
    {
        return this->val;
    }

    MyLinkedNode*& getNext()
    {
        return this->next;
    }

    void linkNext(MyLinkedNode* node)
    {
        if (this->next != nullptr)
        {
            node->getNext() = this->next;
        }
        this->next = node;
    }

    void linkNext(int val)
    {
        this->linkNext(new MyLinkedNode(val));
    }

    int removeNext()
    {
        MyLinkedNode* temp = this->next;
        int tempVal = temp == nullptr ? -1 : temp->val;
        this->next = this->next == nullptr ? nullptr : this->next->next;
        delete temp;
        return tempVal;
    }
};

class MyLinkedList 
{
private:
    MyLinkedNode* head;
    MyLinkedNode* get(int index, bool magic)
    {
        MyLinkedNode* tempHead = this->head;
        int val = -1;
        for (int i = 0; i < index + 1; i++)
        {
            if (tempHead->getNext() == nullptr)
            {
                tempHead = nullptr;
                break;
            }
            tempHead = tempHead->getNext();
        }
        return tempHead;
    }
public:
    MyLinkedList() {
        head = new MyLinkedNode(-1);
    }
    
    int get(int index) {
        MyLinkedNode* result = this->get(index, true);
        return result == nullptr ? -1 : result->getVal();
    }
    
    void addAtHead(int val) {
        head->linkNext(val);
    }
    
    void addAtTail(int val) {
        if (head->getNext() == nullptr)
        {
            head->linkNext(val);
            return;
        }
        MyLinkedNode* tempHead = this->head;
        while(tempHead->getNext() != nullptr)
        {
            tempHead = tempHead->getNext();
        }
        tempHead->linkNext(val);
    }
    
    void addAtIndex(int index, int val) {
        MyLinkedNode* node = this->get(index - 1, true);
        if (node != nullptr) node->linkNext(val);
    }
    
    void deleteAtIndex(int index) {
        MyLinkedNode* pre = this->get(index - 1, true);
        if (pre != nullptr) pre->removeNext();
    }

    ~MyLinkedList() {
        while (this->head->getNext() != nullptr)
        {
            head->removeNext();
        }
        delete head;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

void test_MyLinkedList() {
    // 创建链表
    MyLinkedList* obj = new MyLinkedList();

    // 在头部添加元素1
    obj->addAtHead(1);
    assert(obj->get(0) == 1);

    // 在尾部添加元素3
    obj->addAtTail(3);
    assert(obj->get(1) == 3);

    // 在索引3处添加元素2
    obj->addAtIndex(3, 2);
    assert(obj->get(3) == -1);

    delete obj;
}

int main(int argc, char const *argv[])
{
    test_MyLinkedList();
    std::cout << "All test cases passed for MyLinkedList\n";
    return 0;
}


