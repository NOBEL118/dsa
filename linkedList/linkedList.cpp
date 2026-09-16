// linked list in which node added to front 

#include <iostream>
using namespace std;

class Node {
    public :
        int data;
        Node* next;  // neighbour
    Node(int value) {
        data = value;
        next = NULL;
    }
};

void print(Node* head) {
    if (head == NULL){
        cout << "Empty☠️";
    } else {
        Node* temp = head;
        while (temp != NULL){
            cout<< temp->data ;
            if (temp->next != NULL) {
                cout << " --> ";
            }
            temp = temp->next;
        };
    };
};

void pushFront(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;  // attaching the new node to the older previous node 
    head = newNode;   // making the new node as head of the linked list
};

void pushBack(Node*& head , int value) {
    Node* newNode = new Node(value);
    Node* temp = head;
    if(head == NULL){
        head = newNode;
    } else {
        while (temp->next != NULL){
            temp = temp->next;   
        };
        temp->next = newNode;
    };
};

void popFront(Node*& head) {
    if (head == NULL){
        cout << "LL is empty ";
    } else {
        Node* temp = head->next;
        delete head;
        head = temp;
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
        temp->next = NULL; // good practice to avoid dangling pointer
    };
};

void term(Node* head , int n) {
    Node* temp = head;
    for (int i = 1 ; i < n ; i++){
        temp = temp->next;
    };
    cout<< "Term " << n << " is: " << temp->data << endl;
};

int main() {
    Node* head = NULL;

    pushFront(head, 1);
    
    pushBack(head,2);
    pushBack(head,3);

    //print(head);
    //popFront(head);

   // print(head);
    popBack(head);
    print(head);

    return 0;
}