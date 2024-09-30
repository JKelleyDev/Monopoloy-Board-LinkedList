#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>

using namespace std;

// Data class to store a string and an integer
class MonopolyBoard {
public:
    string propertyName;
    string propertyColor;
    int value;
    int rent;

    /**
        Purpose: Creates an object with default of no values
     */
    MonopolyBoard()
    {
        propertyName = "";
        propertyColor = "";
        value = 0;
        rent = 0;
    }
    
    /**
        Purpose: Creates an object with passed in values
        @Param Property's Name
        @Param Property's Color
        @Param Property's Value
        @Param Property's Rent
     */
    //Overload constructor
    MonopolyBoard(string propertyName,string propertyColor,int value, int rent){
        this->propertyName = propertyName;
        this->propertyColor = propertyColor;
        this->value = value;
        this->rent = rent;
    }

    /**
        Purpose: Checks if two board objects variables are the same
        @param Another board object
        @Return true, if both boards are the same. false, if the boards are different
     */
    bool isEqual(MonopolyBoard other) {
        return(propertyName == other.propertyName &&
               propertyColor == other.propertyColor &&
               value == other.value &&
               rent == other.rent);
    }

    string getColor()
    {
        return propertyColor;
    }
    
    string getPropertyName()
    {
        return propertyName;
    }

    /**
        Purpose: Prints the board object's variables to the console
     */
    void print() {
        cout << propertyName << endl
             << "Color: " << propertyColor << endl
             << "Value $" << value << " | Rent $" << rent << endl
             << " " << endl;
             
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
    
    /**
        Purpose: creates a sleep function to be used to make the terminal output more astetic
        @param some value of time in milliseconds (ms)
     */
    void sleepTime(int time)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
    }
    
    /**
        Purpose: Creates a new node with passed in data value and prepends to the beginning of linked list
        @param some data value of type "T"
     */
    void insertAtHead(T value) {
        
        Node<T>* newNode = new Node<T>(value);
        
        if (isListEmpty())
        {
            // If the list is empty, the newNode becomes the headNode
            headNode = newNode;
            newNode -> nextNode = headNode;
        } else {
            // The new node points to the old headNode and will become new head.
            newNode -> nextNode = headNode;
            // Store the  headNode's address in a tmpPtr
            Node<T>* temp = headNode;
            // Retrieve the tail node's pointer
            while( temp -> nextNode != headNode)
            {
                temp = temp -> nextNode;
            }
            // Point the tail to the new headNode
            temp -> nextNode = newNode;
            // Assign the newNode as the headnode.
            headNode = newNode;
        }
    }
    
    /**
        Purpose: Creates a new node with passed in data value and appends to the end of linked list
        @param some data value of type "T"
     */
    void insertAtTail(T value) {
        
        Node<T>* newNode = new Node<T>(value);
        
        if(isListEmpty()){
            headNode = newNode;
            newNode -> nextNode = headNode;
        }else {
            Node<T>* temp = headNode; // Store the  headNode's address in a tmpPtr
            while( temp -> nextNode != headNode){
                temp = temp -> nextNode;
            }
            temp -> nextNode = newNode;
            newNode -> nextNode = headNode;
            
        }
    }
    
    /**
        Purpose: Creates a new node with passed in data value and appends after position given
        @param some object value of type "T
        @param some other object value to be reference as the position
     */
    void insertAtPosition(T value, T position) {
        Node<T>* newNode = new Node<T>(value);
        
        if(isListEmpty()){
            cout << "List is empty" << endl;
            return;
        }else {
            Node<T>* temp = headNode;
            do {
                if((temp -> data).isEqual(position))
                {
                    newNode -> nextNode = temp -> nextNode;
                    temp -> nextNode = newNode;
                    return;
                }
                temp = temp -> nextNode;
            } while (temp != headNode);
            cout<< "Position value not found. Insertion failed" <<endl;
        }
    }
        
    void deleteAtHead() {
            
        if(isListEmpty()){
            cout << "List is empty" << endl;
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
    }
        
        
    void deleteAtTail() {
            
        if(isListEmpty()){
            cout << "List is empty" << endl;
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
        while(temp -> nextNode != headNode){
            temp = temp -> nextNode;
        }
            
        //Store the node for delete
        Node<T>* tail = temp;
            
        //Find the node before tail
        while(temp -> nextNode != tail){
            temp = temp -> nextNode;
        }
            
        // Make the second to last node the new tail and delete old tail
        temp -> nextNode = headNode;
        delete tail;
    }
        
    void deleteAtPosition(T position) {
        Node<T>* tempPosition = search(position);
        if(tempPosition == nullptr){
            cout << "Property cannot be found, no deletion made." << endl;
            return;
        }else if(tempPosition == headNode){
            deleteAtHead();
        }else{
            Node<T>* beforeTemp = headNode;
            while(beforeTemp -> nextNode != tempPosition){
                beforeTemp = beforeTemp -> nextNode;
            }
            beforeTemp -> nextNode = tempPosition -> nextNode;
            delete tempPosition;
        }
    }
        
        
    Node<T>* search(T value){
        
        Node<T>* temp = headNode;
        
        do {
            if((temp -> data).isEqual(value))
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
        
        if(isListEmpty()){
            cout << "List is empty" << endl;
            return;
        }
        
        do {
            cout << "----------------------------" << endl;
            (temp -> data).print();
            temp = temp -> nextNode;
            sleepTime(200);
        } while (temp != headNode);
        
        cout << "----------------------------" << endl;
    }
        
        //Optional Tasks
        //Basic Funtions
        void reverseCLList() {
            cout << "Reverse List unwritten" << endl;
        }
    
    void sortCLList() {
        if(isListEmpty() or headNode -> nextNode == headNode)
        {
            return; // Nothing to sort or list only has one element
        }
        
        bool swapped;
        Node<T>* temp;
        Node<T>* lastNode = nullptr;
        
        do {
            swapped = false;
            temp = headNode;
            int cmp;
            
            // Traverse the circular list
            while (temp -> nextNode != headNode && temp -> nextNode != lastNode)
            {
                cmp = strcmp(temp->data.getPropertyName().c_str(), temp->nextNode->data.getPropertyName().c_str());

                if (cmp > 0)
                {
                    // Swap the data of the nodes if they are in the wrong order
                    T tempData = temp -> data;
                    temp -> data = temp -> nextNode -> data;
                    temp -> nextNode -> data = tempData;
                    swapped = true;
                }
                temp = temp -> nextNode;
                lastNode = temp; // Reduce the range for sorting (bubble sort optimization)
            }
        } while (swapped);
    }
    
    void printHeadNode() {
        if(isListEmpty())
        {
            cout << "List empty." << endl;
            return;
        }
        (headNode -> data).print();
    }
    
    void printLastNode() {
        
        if(isListEmpty())
        {
            cout << "List empty." << endl;
            return;
        }
        
        Node<T>* temp = headNode;
        while(temp -> nextNode != headNode){
            temp = temp -> nextNode;
        }
        (temp -> data).print();
    }
    
        bool isListEmpty() {
            return(headNode == nullptr);
        }
    
        int countNodes() {
            Node<T>* temp = headNode;
            int counter = 0;
            
            if(isListEmpty()){
                return 0;
            }
            do{
                counter++;
                temp = temp -> nextNode;
            }while(temp != headNode);
            return counter;
        }
        
        //Optional Tasks
        // Advanced Functions
        void convertCLList() {

            if(isListEmpty())
            {
                return; // Do nothing if list is empty
            }
            
            // Handles a list with only one node
            if(headNode -> nextNode == headNode)
            {
                headNode -> nextNode = nullptr;
            }
            
            Node<T>* temp = headNode;
            while(temp -> nextNode != headNode)
            {
                temp = temp -> nextNode; // Get the tail node
            }
            temp -> nextNode = nullptr; // Point the tail to null
        }
    
        void updateNodeValue(T objectValue, T newValue) {
            Node<T>* temp = search(objectValue);
            if(temp){
                temp -> data = newValue;
            }else{
                cout << "Node to be changed not found" << endl;
            }
        }
    
    void displaySpecificColorNode(string color) {
            
        if(isListEmpty())
        {
            cout << "List empty." << endl;
            return;
        }else{
            Node<T>* temp = headNode;
            cout << "-----------------------------" << endl
                 << "Printing all " << color << " properties" << endl
                 << "-----------------------------" << endl;
            do{
                if((temp -> data).getColor() == color)
                {
                    (temp -> data).print();
                }
                temp = temp -> nextNode;
            }while( temp != headNode);
        }
    }
    
    void mergeCLList(CircularLinkedList<T> otherList) {
        
        Node<T>* temp1 = headNode;
        Node<T>* temp2 = otherList.headNode;
        
        if(isListEmpty())
        {
            headNode = otherList.headNode;
        }
        
        if(otherList.isListEmpty())
        {
            return; // Nothing in the other list to merge
        }
        
        // Retrieve the tail of the first list
        while( temp1 -> nextNode != headNode)
        {
            temp1 = temp1 -> nextNode;
        }
        
        // Retrieve the tail of the second list
        while( temp2 -> nextNode != otherList.headNode)
        {
            temp2 = temp2 -> nextNode;
        }
        
        //First list tail points to the second list headNode
        temp1 -> nextNode = otherList.headNode;
        //Second list tail points to first list head
        temp2 -> nextNode = headNode;
    }
};

        void sleepTime(int time)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
        }


    // Main function to demonstrate the LinkedList class
    int main() {
        
        // Sends command to the system to clear the terminal for clean output
        system("clear");
        
        // Create a LinkedList of Data objects
        CircularLinkedList<MonopolyBoard> list;
        CircularLinkedList<MonopolyBoard> list2;
        // Create each node to be used and store inside a vector for easy access
        std::vector<MonopolyBoard> spots;
        spots.push_back(MonopolyBoard("Mediterranean Avenue", "Brown", 30, 2));
        spots.push_back(MonopolyBoard("Baltic Avenue", "Brown", 30, 4));
        spots.push_back(MonopolyBoard("St.James Place", "Orange", 90, 14));
        spots.push_back(MonopolyBoard("Tennessee Avenue", "Orange", 90, 14));
        spots.push_back(MonopolyBoard("New York Avenue", "Orange", 100, 16));
        spots.push_back(MonopolyBoard("Oriental Avenue", "Light Blue", 50, 6));
        spots.push_back(MonopolyBoard("Vermont Avenue", "Light Blue", 50, 6));
        spots.push_back(MonopolyBoard("Connecticut Avenue", "Light Blue", 60, 8));
        spots.push_back(MonopolyBoard("Kentucky Avenue", "Red", 110, 18));
        spots.push_back(MonopolyBoard("Indiana Avenue", "Red", 110, 18));
        spots.push_back(MonopolyBoard("Illinois Avenue", "Red", 120, 20));
        spots.push_back(MonopolyBoard("St.Charles Place", "Pink", 70, 10));
        spots.push_back(MonopolyBoard("States Avenue", "Pink", 70, 10));
        spots.push_back(MonopolyBoard("Virginia Avenue", "Pink", 80, 12));
        spots.push_back(MonopolyBoard("Atlantic Avenue", "Yellow", 1123, 155000));
        spots.push_back(MonopolyBoard("Ventor Avenue", "Yellow", 1123, 155000));
        spots.push_back(MonopolyBoard("Marvin Gardens", "Yellow", 1123, 155000));
        spots.push_back(MonopolyBoard("Pacific Avenue", "Green", 1123, 155000));
        spots.push_back(MonopolyBoard("North Carolina Avenue", "Green", 1123, 155000));
        spots.push_back(MonopolyBoard("Pennsylvania Avenue", "Green", 1123, 155000));
        spots.push_back(MonopolyBoard("Park Place", "Dark Blue", 1123, 155000));
        spots.push_back(MonopolyBoard("Boardwalk", "Dark Blue", 1123, 155000));
        
        // Inserts all of the items into the linkedlist. Inserting each at the tail
        cout << "Initializing List..." << endl;
        sleepTime(200);
        for(int i = 0; i < spots.size(); i++)
        {
            list.insertAtTail(spots[i]);
            sleepTime(50);
        }

        // Insert Core Functions
        list.insertAtHead(spots[1]);
        list.insertAtTail(spots[1]);
        list.insertAtPosition(spots[3], spots[2]);
      
        // Deletion Core Functions
        list.deleteAtHead();
        list.deleteAtTail();
        list.deleteAtPosition(spots[5]);
        
        //Optional Basic Tasks
        list.reverseCLList();
        list.sortCLList();
        list.printHeadNode();
        list.printLastNode();
        list.isListEmpty();
        list.countNodes();
        
        //Optional Advanced Tasks
        list.convertCLList();
        list.updateNodeValue(spots[1], spots[2]);
        list.displaySpecificColorNode("Pink");
        list.mergeCLList(list2);
    
        
        //Prints a quick and easy to read checklist for TA to grade
        int printTime = 500;
        cout << "                     " << endl
             << "---------------------" << endl
             << "Completion CheckList:" << endl
             << "---------------------" << endl;
        sleepTime(printTime);
        cout << "   Core Functions    " << endl
             << "[Y] insertAtHead     " << endl
             << "[Y] insertAtTail     " << endl
             << "[Y] insertAtPosition " << endl
             << "[Y] deleteAtHead     " << endl
             << "[Y] deleteAtTail     " << endl
             << "[Y] deleteATPosition " << endl
             << "[Y] search           " << endl
             << "[Y] printList        " << endl
             << "                     " << endl;
        sleepTime(printTime);
        cout << "   Basic Functions   " << endl
             << "[N] reverseCLList    " << endl
             << "[Y] sortCLList       " << endl
             << "[Y] printHeadNode    " << endl
             << "[Y] printLastNode    " << endl
             << "[Y] isListEmpty      " << endl
             << "[Y] countNodes       " << endl
             << "                     " << endl;
        sleepTime(printTime);
        cout << "  Advanced Functions " << endl
             << "[Y] convertCLList    " << endl
             << "[Y] updateNodeVaue   " << endl
             << "[Y] displaySpecficColorNode   " << endl
             << "[Y] mergeCLList      " << endl;
        sleepTime(printTime);
        cout << "                     " << endl
             << "  Extra Credit       " << endl
             << "EC{1}: Met Criteria  " << endl
             << "EC{2}: Met Criteria  " << endl
             << "EC{3}: Not Met       " << endl
             << "EC{4}: Not Met       " << endl;
        
        return 0;
    }

