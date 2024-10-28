/**
 * Done by:
 * Student Name: Malinovskyi Vlad
 * Student Group: 121
 * Lab 2.5
 **/

#include <iostream>
#include <cstdlib>

struct FirstList {
    double data = 0;
    FirstList* next = nullptr;

    void push(int element) {
        FirstList* processingElement = this;

        while (processingElement->next != nullptr) {
            processingElement = processingElement->next;
        }

        FirstList* temp = new FirstList;
        temp->data = element;
        processingElement->next = temp;
    }
};

inline bool isNonZero(FirstList* list) {
    return list->data != 0;
}

struct SecondList {
    double data = 0;
    SecondList* next = nullptr;

    void push(double element) {
        SecondList* temp = new SecondList;
        temp->data = element;

        SecondList* processingElement = this;

        while (processingElement->next != nullptr) {
            processingElement = processingElement->next;
        }

        processingElement->next = temp;
    }
};

void initList(FirstList* list);
void makeSecondList(FirstList* list, SecondList* newList);

int main() {
    FirstList* sampleList1 = new FirstList;
    sampleList1->data = 1;
    sampleList1->push(7);
    sampleList1->push(-12);
    sampleList1->push(-42);
    sampleList1->push(98);
    sampleList1->push(22);

    SecondList* sampleList2 = new SecondList;
    makeSecondList(sampleList1, sampleList2);

    std::cout << "FirstList: ";
    FirstList* temp1 = sampleList1;
    while (temp1 != nullptr) {
        std::cout << temp1->data << " ";
        temp1 = temp1->next;
    }
    std::cout << "\nSecondList (negative non-zero values): ";
    SecondList* temp2 = sampleList2;
    while (temp2 != nullptr) {
        std::cout << temp2->data << " ";
        temp2 = temp2->next;
    }
    std::cout << std::endl;

    return 0;
}

void initList(FirstList* list) {
    for (int i = 0; i < 7; i++) {
        int randInt = rand() % 200;

        if (i == 0) {
            list->data = randInt;
            continue;
        }

        list->push(randInt);
    }
}

void makeSecondList(FirstList* list, SecondList* newList) {
    FirstList* processingElement = list;
    bool isInited = false;

    while (processingElement != nullptr) {
        if (isNonZero(processingElement) && processingElement->data < 0) {
            if (!isInited) {
                newList->data = processingElement->data;
                isInited = true;
            }
            else {
                newList->push(processingElement->data);
            }
        }
        processingElement = processingElement->next;
    }
}