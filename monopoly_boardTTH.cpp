#include <iostream>
#include <string>

using namespace std;

// Data class to store a string and an integer
class MonopolyBoard {
public:
    string propertyName;
    string propertyColor;
    int value;
    int rent;


    MonopolyBoard(string propertyName,string propertyColor,int value, int rent){
        /*Define overloaded constructor here*/
    }


    bool isEqual(MonopolyBoard other) {
        /*Define is equal here*/
    }


    void print() {
        /*Define Print Here*/
    }
};

// Template Node class
template <typename T> class Node {
public:
    T data;
    Node* nextNode;

    Node(T value) {
        data = value;
        nextNode = nullptr;
    }
};

// Template LinkedList class
template <typename T> class CircularLinkedList {
private:
    Node<T>* headNode;

public:
    CircularLinkedList() {
        headNode = nullptr;
    }

// Mandatory Tasks
    void insertAtHead() {
        cout<<"Insert at head unwritten"<<endl;
    }


    void insertAtTail() {
        cout<<"Insert at Tail unwritten"<<endl;
    }

    void insertAtPosition() {
        cout<<"Insert at Position unwritten"<<endl;
    }
    void deleteAtHead() {
        cout<<"Delete at head unwritten"<<endl;
    }


    void deleteAtTail() {
        cout<<"Delete at Tail unwritten"<<endl;
    }

    void deleteAtPosition() {
        cout<<"Delete at Position unwritten"<<endl;
    }


    void search(T value) {

        cout<<"Search unwritten"<<endl;
    }
    void printList() {
        cout << "Print List unwritten" << endl;
    }

    //Optional Tasks
    //Basic Funtions
    void reverseCLList() {
        cout << "Reverse List unwritten" << endl;
    } void sortCLList() {
        cout << "Sort List unwritten" << endl;
    } void printHeadNode() {
        cout << "Print Head Node unwritten" << endl;
    } void printLastNode() {
        cout << "Print Last Node unwritten" << endl;
    } void isListEmpty() {
        cout << "Is List Empty unwritten" << endl;
    }
    void countNodes() {
        cout << "Count Nodes unwritten" << endl;
    }

    //Optional Tasks
    // Advanced Functions
    void convertCLList() {
        cout << "Convert Circular List Unwritten." << endl;
    } void updateNodeValue() {
        cout << "update Node value unwritten" << endl;
    } void displaySpecificColorNode() {
        cout << "Display Specific color Node" << endl;
    } void mergeCLList() {
        cout << "Merge Circular Linked List Unwritten" << endl;
    }

};

// Main function to demonstrate the LinkedList class
int main() {
    // Create a LinkedList of Data objects
    CircularLinkedList<MonopolyBoard> list;

    // Insert elements at the end
    list.insertAtHead();

    list.insertAtTail();

    list.insertAtPosition();

    list.deleteAtHead();

    list.deleteAtTail();

    list.deleteAtPosition();

    //Optional Basic Tasks

    list.reverseCLList();
    list.sortCLList();
    list.printHeadNode();
    list.printLastNode();
    list.isListEmpty();
    list.countNodes();

    //Optional Advanced Tasks
    list.convertCLList();
    list.updateNodeValue();
    list.displaySpecificColorNode();
    list.mergeCLList();

    return 0;
}