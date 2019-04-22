//
// Created by Bam89 on 4/22/2019.
//

#ifndef MAIN_CPP_CONTAINER_H
#define MAIN_CPP_CONTAINER_H

#include <iostream>
#include <cstdlib>

using namespace std;
// container is a simple container class

//relational opeator >, <, and == must be overriden to work

template<class ItemType>
class container {
public:
    container() = default;

    ~container() {
        makeempty();
    }

    void makeempty();

    void addEntry(ItemType item);

private:
    struct ListNode {
        ItemType data = NULL;
        ListNode *next = NULL;
    };

    ListNode *root = NULL;


};

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
}

#endif //MAIN_CPP_CONTAINER_H
