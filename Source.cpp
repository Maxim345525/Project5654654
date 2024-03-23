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
class LinkedList {
private:
    Node<T>* head;
public:
    LinkedList() : head(nullptr) {}
    ~LinkedList() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void addNode(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (!head) {
            head = newNode;
        }
        else {
            Node<T>* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    LinkedList<T>* clone() {
        LinkedList<T>* clonedList = new LinkedList<T>();
        Node<T>* temp = head;
        while (temp) {
            clonedList->addNode(temp->data);
            temp = temp->next;
        }
        return clonedList;
    }
    LinkedList<T>* operator+(const LinkedList<T>& otherList) {
        LinkedList<T>* newList = clone();
        Node<T>* temp = otherList.head;
        while (temp) {
            newList->addNode(temp->data);
            temp = temp->next;
        }
        return newList;
    }
    LinkedList<T>* operator*(const LinkedList<T>& otherList) {
        LinkedList<T>* newList = new LinkedList<T>();
        Node<T>* temp1 = head;
        while (temp1) {
            Node<T>* temp2 = otherList.head;
            while (temp2) {
                if (temp1->data == temp2->data) {
                    newList->addNode(temp1->data);
                    break;
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return newList;
    }
    void display() {
        Node<T>* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    LinkedList<int> list1;
    list1.addNode(1);
    list1.addNode(2);
    list1.addNode(3);
    LinkedList<int> list2;
    list2.addNode(2);
    list2.addNode(3);
    list2.addNode(4);
    cout << "List 1: ";
    list1.display();
    cout << "List 2: ";
    list2.display();
    LinkedList<int>* clonedList = list1.clone();
    cout << "Cloned List 1: ";
    clonedList->display();
    LinkedList<int>* combinedList = list1 + list2;
    cout << "Combined List: ";
    combinedList->display();
    LinkedList<int>* intersectedList = list1 * list2;
    cout << "Intersected List: ";
    intersectedList->display();
    delete clonedList;
    delete combinedList;
    delete intersectedList;
    return 0;
}
