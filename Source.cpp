#include <iostream>
using namespace std;
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node(T data) : data(data), next(nullptr) {}
};
template <typename T>
class Stack {
private:
    Node<T>* top;
    int size;
public:
    Stack() : top(nullptr), size(0) {}
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
    bool isEmpty() const {
        return size == 0;
    }
    void push(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (isEmpty()) {
            top = newNode;
        }
        else {
            newNode->next = top;
            top = newNode;
        }
        size++;
    }
    T pop() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty");
        }
        Node<T>* temp = top;
        T poppedData = temp->data;
        top = top->next;
        delete temp;
        size--;
        return poppedData;
    }
    T peek() const {
        if (isEmpty()) {
            throw runtime_error("Stack is empty");
        }
        return top->data;
    }
    int getSize() const {
        return size;
    }
};
int main() {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << "Stack size: " << stack.getSize() << endl;
    cout << "Top element: " << stack.peek() << endl;
    cout << "Pop: " << stack.pop() << endl;
    cout << "Pop: " << stack.pop() << endl;
    cout << "Stack size: " << stack.getSize() << endl;
    cout << "Top element: " << stack.peek() << endl;
    return 0;
}
