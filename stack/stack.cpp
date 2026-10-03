#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Stack {
    Node* top;

public:

    Stack() {
        top = NULL;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void push(int val) {
        Node* newNode = new Node(val);

        newNode->next = top;
        top = newNode;
    }

    int peek() {
        if (isEmpty()) {
            return 0;
        }

        return top->data;
    }

    int pop() {
        if (isEmpty()) {
            return 0;
        }

        Node* temp = top;
        int value = top->data;

        top = top->next;

        delete temp;

        return value;
    }
};

int main() {

    Stack st;

    st.push(10);
    st.push(20);

    cout << st.peek() << endl;
    cout << st.pop() << endl;
    cout << st.peek() << endl;

    return 0;
}