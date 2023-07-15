#pragma warning(disable:4996)

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

using namespace std;

struct Node {
    int value;
    string violation;
    Node* parent;
    Node* left;
    Node* right;
};

class Tree {
    Node* root;
public:
    Tree() {
        root = nullptr;
    }

    Node* Search(Node* elem, int key) {
        while (elem != nullptr && key != elem->value) {
            if (key < elem->value) {
                elem = elem->left;
            }
            else {
                elem = elem->right;
            }
        }
        return elem;
    }

    Node* Min(Node* elem) {
        if (elem != nullptr) {
            while (elem->left != nullptr) {
                elem = elem->left;
            }
        }
        return elem;
    }

    Node* Max(Node* elem) {
        if (elem != nullptr) {
            while (elem->right != nullptr) {
                elem = elem->right;
            }
        }
        return elem;
    }

    Node* Next(Node* elem) {
        if (elem->right != nullptr) {
            return Min(elem->right);
        }
        while (elem->parent != nullptr && elem->parent->right == elem) {
            elem = elem->parent;
        }
        return elem->parent;
    }

    Node* Back(Node* elem) {
        if (elem->left != nullptr) {
            return Max(elem->left);
        }
        while (elem->parent != nullptr && elem->parent->left == elem) {
            elem = elem->parent;
        }
        return elem->parent;
    }

    void Insert(Node* elem,string v = "none") {
        Node* temp = new Node;
        temp->value = elem->value;
        temp->violation = v;
        temp->left = nullptr;
        temp->right = nullptr;

        if (root == nullptr) {
            root = temp;
            temp->parent = nullptr;
            return;
        }

        Node* place = root;
        Node* newparent = nullptr;

        while (place != nullptr) {
            newparent = place;
            if (temp->value < place->value) {
                place = place->left;
            }
            else {
                place = place->right;
            }
        }

        temp->parent = newparent;
        if (temp->value < newparent->value) {
            newparent->left = temp;
        }
        else {
            newparent->right = temp;
        }

    }

    void Del(Node* elem = nullptr) {
        if (elem != nullptr) {
            Node* none;
            Node* child;

            if (elem->right == nullptr || elem->right == nullptr) {
                none = elem;
            }
            else {
                none = Next(elem);
            }

            if (none->left != nullptr) {
                child = none->left;
            }
            else {
                child = none->right;
            }

            if (child != nullptr) {
                child->parent = none->parent;
            }

            if (none->parent == nullptr) {
                root = child;
            }
            else if (none->parent->left == none) {
                none->parent->left = child;
            }
            else {
                none->parent->right = child;
            }

            if (elem != none) {
                elem->value = none->value;
            }

            delete none;
        }
        else {
            while (root != nullptr) {
                Del(root);
            }
        }
    }

    Node* GetRoot() {
        return root;
    }

    void Print(Node* elem) {
        if (elem != nullptr) {
            Print(elem->left);
            cout << "Num: " << elem->value << "\n";
            cout << "Violation: " << elem->violation << "\n" << endl;
            Print(elem->right);
        }
    }


    ~Tree() {
        Del();
    }
};

int main()
{
    setlocale(0, "");

    Tree groot;


    for (int i = 0; i < 5; i++) {
        Node* elem = new Node;
        elem->value = rand() % 100;
        cout << elem->value << " ";
        groot.Insert(elem,"Parking");
    }
    for (int i = 0; i < 5; i++) {
        Node* elem = new Node;
        elem->value = rand() % 100;
        cout << elem->value << " ";
        groot.Insert(elem,"Tonirovka");
    }
    for (int i = 0; i < 5; i++) {
        Node* elem = new Node;
        elem->value = rand() % 100;
        cout << elem->value << " ";
        groot.Insert(elem, "Dangerous driving");
    }
    cout << endl;
    groot.Print(groot.GetRoot());

}
