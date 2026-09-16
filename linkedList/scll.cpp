#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

    Node(int value){
        data = value;
        next = NULL;
    };
};

void pushFront(Node*& head , Node*& tail , int value){
    Node* newNode = new Node(value);
    if (head == NULL){
        head = tail = newNode;
    } else {
        newNode->next = head; // connecting node to prev node
        head = newNode;  // updating head
        tail->next = head;  // now connecting tail to head 
    };
};

void pushBack(Node*& head , Node*& tail , int value) {
    Node* newNode = new Node(value);
    if (head == NULL){
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
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
        tail->next = head;
    };
};

void popBack(Node*& head , Node*& tail) {
    if (head == NULL){
        cout << "LL is empty";
    } else if (head->next == head) { // only one node in the list
        delete head;
        head = NULL;
        tail = NULL;
    } else {
        Node* temp = head;
        while (temp->next->next != head){
            temp = temp->next;
        };
        tail = temp; // updating tail to the second last node
        delete temp->next;
        tail->next = head; // connecting tail to head
    };
};

void print(Node* head , Node* tail){
    if (head == NULL){
        cout << "LL is empty";
    } else {
        Node* temp = head;
        do {
            cout << temp->data << " --> ";
            temp = temp->next;
        } while (temp != head);
        cout << "NULL";
    };
};

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    // 1. Test pushFront
    pushFront(head, tail, 10);
    pushFront(head, tail, 20);
    pushFront(head, tail, 30);

    cout << "After pushFront: ";
    print(head, tail);

    // 2. Test pushBack
    pushBack(head, tail, 40);
    pushBack(head, tail, 50);

    cout << "After pushBack: ";
    print(head, tail);

    // 3. Check circular connection
    cout << "Tail points to head: "
         << tail->next->data << endl;

    // 4. Test popFront
    popFront(head, tail);

    cout << "After popFront: ";
    print(head, tail);

    // 5. Test popBack
    popBack(head, tail);

    cout << "After popBack: ";
    print(head, tail);

    // 6. Check circular connection again
    cout << "Tail points to head: "
         << tail->next->data << endl;

    return 0;
}