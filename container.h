//
// Created by Bam89 on 4/22/2019.
//

#ifndef MAIN_CPP_CONTAINER_H
#define MAIN_CPP_CONTAINER_H

#include <iostream>
#include <cstdlib>

using namespace std;
// container is a simple container class

//relational opeator >, <, and == must be overriden to work, and += with string as well.

template<class ItemType>
class container {
public:
    container() = default;

    container(const container &old);

    ~container() {
        makeempty();
    }

    void makeempty();

    void addEntry(ItemType item);

    void bubbleSort();

    void selectSort();
    string toString();


private:
    struct ListNode {
        ItemType data = NULL;
        ListNode *next = NULL;
    };

    int numNodes = 0;
    ListNode *root = NULL;


};

template<class ItemType>
container<ItemType>::container(const container &old) {
    ListNode *oldPtr = old.root;
    while (oldPtr != NULL) {
        addEntry(oldPtr->data);
        oldPtr = oldPtr->next;
    }
}

template<class ItemType>
void container<ItemType>::makeempty() {
    ListNode *ptr = root;

    while (ptr != NULL) {
        ListNode *temp = ptr;
        ptr = ptr->next;
        delete (temp);
    }

}

template<class ItemType>
void container<ItemType>::addEntry(ItemType item) {
    auto *temp = new ListNode;
    temp->data = item;
    temp->next = NULL;

    if (root == NULL) {
        root = temp;
    } else {
        ListNode *ptr = root;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }

        ptr->next = temp;
    }

    numNodes++;
}

template<class ItemType>
void container<ItemType>::bubbleSort() {

    for (int i = 0; i < numNodes; i++) {
        ListNode *ptr = root;
        while (ptr->next != NULL) {

            if (ptr->data > ptr->next->data) { //should be ascending so this means time to swap
                ItemType tmp = ptr->next->data;
                ptr->next->data = ptr->data;
                ptr->data = tmp;

            }

            ptr = ptr->next;
        }
    }

}

template<class ItemType>
void container<ItemType>::selectSort() {

}

template<class ItemType>
string container<ItemType>::toString() {
    string returnVal;
    ListNode *ptr = root;
    while (ptr != NULL) {
        returnVal += ptr->data;
        ptr = ptr->next;
    }

    return (returnVal);
}

#endif //MAIN_CPP_CONTAINER_H
