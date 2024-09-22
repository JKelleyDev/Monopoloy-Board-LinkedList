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

    //default constructor
    MonopolyBoard()
    {
        propertyName = "";
        propertyColor = "";
        value = 0;
        rent = 0;
    }
    
    //Overload constructor
    MonopolyBoard(string propertyName,string propertyColor,int value, int rent){
        this->propertyName = propertyName;
        this->propertyColor = propertyColor;
        this->value = value;
        this->rent = rent;
    }


    bool isEqual(MonopolyBoard other) {
        /*Define is equal here*/
        return false;
    }


    void print() {
        /*Define Print Here*/
        cout << "Print not yet defined" << endl;
    }
};

// Template Node class
template <typename T> class Node {
public:
    T data;
    Node *nextNode;

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
    void insertAtHead(T value) {
        
        Node<T>* newNode = new Node<T>(value);
        
        if (headNode == nullptr)
        {
            headNode = newNode; // If the list is empty, the newNode becomes the headNode
            newNode -> nextNode = headNode; // The new node points to self, since it is circular and the only node in the list.
        } else {
            newNode -> nextNode = headNode; // The new node points to the old headNode.
            Node<T>* temp = headNode; // Store the  headNode's address in a tmpPtr
            while( temp -> nextNode != headNode)
            {
                temp = temp -> nextNode;
            }
            temp -> nextNode = newNode; // Tail now points to the new headNode
            headNode = newNode; // newNode becomes new headnode
            
        }
        cout<<"Inserted at head:" <<endl;
    }
    
    
    void insertAtTail(T value) {
        
        Node<T>* newNode = new Node<T>(value);
        
        if(headNode == nullptr)
        {
            headNode = newNode;
            newNode -> nextNode = headNode;
        }else {
            Node<T>* temp = headNode; // Store the  headNode's address in a tmpPtr
            while( temp -> nextNode != headNode)
            {
                temp = temp -> nextNode;
            }
            temp -> nextNode = newNode;
            newNode -> nextNode = headNode;
            
        }
        cout<< "Inserted at Tail:" << endl;
    }
    
    void insertAtPosition(T value, T position) {
        Node<T>* newNode = new Node<T>(value);
        
        if( headNode == nullptr)
        {
            headNode = newNode;
            newNode -> nextNode = headNode;
            
        }else {
            Node<T>* temp = headNode;
            
            do {
                if((temp -> data).isEqual(position))
                {
                    newNode -> nextNode = temp -> nextNode;
                    temp -> nextNode = newNode;
                    cout << "Inserted at Position:" << endl;
                    return;
                }
                temp = temp -> nextNode;
            } while (temp != headNode);
            
            cout<< "Position value not found. Insertion failed" <<endl;
        }
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
        list.insertAtHead(MonopolyBoard("House", "green", 122, 324));
        
     //   list.insertAtTail(20);
        
    //    list.insertAtPosition(22);
        
   /*     list.deleteAtHead();
        
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
    */
        return 0;
        
    }

