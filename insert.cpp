
#pragma warning(disable:4996)

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node* back;
};

class List {
    Node* head;
    Node* tail;
public:
    List() {

        head = tail = nullptr;
    }

    void PushTail(int x) {
        Node* temp = new Node;

        temp->val = x;
        temp->next = nullptr;
        temp->back = tail;

        if (head == nullptr) {
            head = temp;
        }
        else {
            tail->next = temp;
        }

        tail = temp;
    }

    void PushHead(int x) {
        Node* temp = new Node;

        temp->val = x;
        temp->next = head;
        temp->back = nullptr;

        if (tail == nullptr) {
            tail = temp;
        }
        else {
            head->back = temp;
        }

        head = temp;
    }

    void Insert(int pos,int x) {
        Node* ins = head;
        for (int i = 0; i < pos; i++) {
            ins = ins->next;
        }
        ins->back = ins->next;
        ins->val = x;
        head = ins;
    }

    void PopHead() {
        if (head != nullptr) {
            Node* copyhead = head;
            head = head->next;
            delete copyhead;
            if (head != nullptr) {
                head->back = nullptr;
            }
            else {
                tail = nullptr;
            }
        }
    }

    void PopTail() {
        if (tail != nullptr) {
            Node* copytail = tail;
            tail = tail->back;
            delete copytail;
            if (tail != nullptr) {
                tail->next = nullptr;
            }
            else {
                head = nullptr;
            }
        }
    }

    void Clear() {
        while (head != nullptr) {
            PopHead();
        }
        tail = nullptr;
    }

    void printHead() {
        Node* copyhead = head;
        while (copyhead != nullptr) {
            cout << copyhead->val << " ";
            copyhead = copyhead->next;
        }
        cout << endl;
    }

    void printTail() {
        Node* copytail = tail;
        while (copytail != nullptr) {
            cout << copytail->val << " ";
            copytail = copytail->back;
        }
        cout << endl;
    }

    int getElem(int n) {
        int ind = 0;
        Node* copyhead = head;
        while (copyhead != nullptr) {
            if (ind != n) {
                ind++;
                copyhead = copyhead->next;
            }
            else {
                return copyhead->val;
            }
        }
        return -1;
    }

    void setElem(int n, int x) {
        int ind = 0;
        Node* copyhead = head;
        while (copyhead != nullptr) {
            if (ind != n) {
                ind++;
                copyhead = copyhead->next;
            }
            else {
                copyhead->val = x;
            }
        }
    }

    void Del(int pos) {
        if (pos == 0) {
            PopHead();
            return;
        }

        Node* copyhead = head;

        for (int i = 0; i < pos; i++) {
            copyhead = copyhead->next;
        }

        Node* Next = copyhead->next;
        Node* Back = copyhead->back;

        Back->next = Next;

        if (Next != nullptr) {
            Next->back = Back;
        }
        else {
            tail = Back;
        }

        delete copyhead;
    }


    ~List() {
        Clear();
    }

    int operator[](int n) const {
        int ind = 0;
        Node* copyhead = head;
        while (copyhead != nullptr) {
            if (ind != n) {
                ind++;
                copyhead = copyhead->next;
            }
            else {
                return copyhead->val;
            }
        }
        return -1;
    }

    int& operator[](int n) {
        int ind = 0;
        Node* copyhead = head;
        while (copyhead != nullptr) {
            if (ind != n) {
                ind++;
                copyhead = copyhead->next;
            }
            else {
                return copyhead->val;
            }
        }
        int a = -1;
        return a;
    }



};



int main() {

    setlocale(0, "");
    srand(time(NULL));

    List l2;

    for (int i = 0; i < 5; i++) {
        l2.PushHead(rand() % 20);
    }
    l2.printHead();
    l2.printTail(); cout << endl;

    l2.PopTail(); l2.printHead(); l2.printTail(); cout << endl;
    

    l2.Clear(); l2.printHead();

    for (int i = 0; i < 20; i++) {
        l2.PushTail(rand() % 20);
    }
    l2.printHead();
    cout << "(10) - " << l2.getElem(10) << endl;
    l2[2] = 5;
    l2.printHead();
    l2.Del(2);
    l2.printHead();

    l2.Insert(2, 5);
    l2.printHead();
}
