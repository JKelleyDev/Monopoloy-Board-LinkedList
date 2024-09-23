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
        return(propertyName == other.propertyName &&
               propertyColor == other.propertyColor &&
               value == other.value &&
               rent == other.rent);
    }



    void print() {
        cout << "Property Information:" << endl;
        cout << "  Property Name:   "   << propertyName  << endl;
        cout << "  Property Color:  "   << propertyColor << endl;
        cout << "  Property Value: $"   << value         << endl;
        cout << "  Property Rent:  $"   << rent          << endl;
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
            
            if(headNode == nullptr){
                cout << " The list is empty, cannot delete at head." << endl;
                return;
            }
            
            if(headNode -> nextNode == headNode){
                delete headNode;
                headNode = nullptr;
                cout << "Head node was the only node. Head node deleted and the list is now empty." << endl;
                return;
            }
            
            Node<T>* temp = headNode;
            Node<T>* tempForDelete = headNode;
            
            while(temp -> nextNode != headNode) // Find the last node of the list
            {
                temp = temp -> nextNode;
            }
            // Point tail to second node, then change headnode to second node
            temp -> nextNode = headNode -> nextNode;
            headNode = headNode -> nextNode;
            // Delete the old headnode.
            delete tempForDelete;
        
            cout << "Head node deleted." << endl;
        }
        
        
        void deleteAtTail() {
            
            if(headNode == nullptr){
                cout << " The list is empty, cannot delete at tail." << endl;
                return;
            }
            
            if(headNode -> nextNode == headNode){
                delete headNode;
                headNode = nullptr;
                cout << "Only one node in list, node deleted. List is now empty." << endl;
                return;
            }
            
            Node<T>* temp = headNode;
            
            //First find the tail node
            while(temp -> nextNode != headNode)
            {
                temp = temp -> nextNode;
            }
            
            //Store the node for delete
            Node<T>* tail = temp;
            
            //Find the node before tail
            while(temp -> nextNode != tail)
            {
                temp = temp -> nextNode;
            }
            
            // Make the second to last node the new tail and delete old tail
            temp -> nextNode = headNode;
            delete tail;
        
            cout << "Deleted at Tail." << endl;
        }
        
        void deleteAtPosition(T position) {
            Node<T>* tempPosition = search(position);
            if(tempPosition == nullptr)
            {
                cout << "Property cannot be found, no deletion made." << endl;
                return;
            }else if(tempPosition == headNode)
            {
                deleteAtHead();

            }else{
                Node<T>* beforeTemp = headNode;
                while(beforeTemp -> nextNode != tempPosition)
                {
                    beforeTemp = beforeTemp -> nextNode;
                }
                beforeTemp -> nextNode = tempPosition -> nextNode;
                delete tempPosition;
            }
            cout<<"Deleted at Position."<<endl;
        }
        
        
        Node<T>* search(T value){
            Node<T>* temp = headNode;
            do {
                if(temp -> data == value)
                {
                    return temp;
                }
                temp = temp -> nextNode;
            } while (temp -> nextNode != headNode);
            
            cout<< "Search Conducted, position not found position" <<endl;
            return nullptr;
        }
        void printList() {
            Node<T>* temp = headNode;
            int counter = 0;
            if(headNode == nullptr)
            {
                cout << "List is empty" << endl;
                return;
            }
            do {
                cout << "     Item: " << counter << endl;
                cout << "------------------------------" << endl;
                (temp -> data).print();
                cout << "------------------------------" << endl;
                temp = temp -> nextNode;
                counter++;
            } while (temp != headNode);
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
        
        MonopolyBoard* spot1 = new MonopolyBoard("A Street", "White", 1254, 120000);
        MonopolyBoard* spot2 = new MonopolyBoard("B Street", "Green", 1123, 155000);
        
        // Insert elements at the end
        list.insertAtHead(*spot1);
        
        list.insertAtTail(*spot2);

        //list.insertAtPosition();
      
        list.deleteAtHead();
        
        list.deleteAtTail();
        
        list.printList();
    //    list.deleteAtPosition();
        
        //Optional Basic Tasks
   /*
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

