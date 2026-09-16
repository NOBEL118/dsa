#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* prev;

    Node(int value){
        data = value;
        next = NULL;
        prev = NULL;
    };
};

// for pushFront make the head -> prev = newNode and newNode -> next = head and then head = newNode
void pushFront(Node*& head, int value){
    Node* newNode = new Node(value);
    if (head == NULL){
        head = newNode;
    } else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    };
}

void pushBack(Node*& head, int value){
    Node* newNode = new Node(value);
    if (head == NULL){
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        };
        temp->next = newNode;
        newNode->prev = temp;
    };
};

void popBack(Node*& head) {
    if (head == NULL){
        cout << "LL is empty";
    } else if (head->next == NULL) {
        delete head;
        head = NULL;
    } else {
        Node* temp = head;
        while (temp->next->next != NULL){
            temp = temp->next;
        };
        delete temp->next;
        temp->next = NULL; 
    };
};

void popFront(Node*& head) {
    Node* temp = head;

    if (head == NULL){
        cout << "LL is empty";
    } else if (temp->next == NULL) {
        delete temp;
        head = NULL;
    } else {
        temp->next->prev = NULL;
        head = temp->next;
        delete temp;
    };
};

int main(){
    Node* head = NULL;
    // pushFront(head,10);
    // pushFront(head,20);
    pushBack(head,30);
    pushBack(head,40);
   // cout<< head->data<< head->next << head->prev;
    cout<< head->next->prev->data;
    return 0;
}
