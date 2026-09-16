// doubly circular linked list implementation in C++

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

void pushFront(Node*& head,Node*& tail, int value){
    Node* newNode = new Node(value);
    if (head == NULL){
        head = tail = newNode;
        head->prev = head;
        head->next = head;
    } else {
        head->prev = newNode;
        newNode->next = head;
        newNode->prev = tail;
        head = newNode;
        tail->next = head;
    };
};

void pushBack( Node*& head , Node*& tail, int value){
    Node* newNode = new Node(value);
    if (head == NULL){
        head = tail = newNode;
        head->prev = head;
        head->next = head;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        tail->next = head;
    };
};

void popBack(Node*& head , Node*& tail ) {
    if (head == NULL){
        cout << "LL is empty";
    } else if (head->next == head) {
        delete head;
        head = NULL;
        tail = NULL;
    } else {
        Node* temp = tail->prev;
        delete tail;
        tail = temp;
        tail->next = head; 
        head->prev = tail;
    };
};

void popFront(Node*& head , Node*& tail) {
    if (head == NULL){
        cout << "LL is empty ";
    } else if (head->next == head) { // only one node in the list
        delete head;
        head = NULL;
        tail = NULL;
    } else {
        Node* temp = head->next;
        delete head;
        head = temp;
        head->prev = tail;
        tail->next = head;
    };
};

void print(Node*& head , Node*& tail) {
    if (head == NULL) {
        cout << "LL is empty";
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " <-> ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
};

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    // 1. pushFront
    pushFront(head, tail, 10);
    pushFront(head, tail, 20);
    pushFront(head, tail, 30);

    cout << "After pushFront: ";
    print(head, tail);

    // 2. pushBack
    pushBack(head, tail, 40);
    pushBack(head, tail, 50);

    cout << "After pushBack: ";
    print(head, tail);

    // 3. Check circular connections
    cout << "Head prev: " << head->prev->data << endl;
    cout << "Tail next: " << tail->next->data << endl;

    // 4. popFront
    popFront(head, tail);

    cout << "After popFront: ";
    print(head, tail);

    // 5. popBack
    popBack(head, tail);

    cout << "After popBack: ";
    print(head, tail);

    // 6. Check circular connections again
    cout << "Head prev: " << head->prev->data << endl;
    cout << "Tail next: " << tail->next->data << endl;

    return 0;
}