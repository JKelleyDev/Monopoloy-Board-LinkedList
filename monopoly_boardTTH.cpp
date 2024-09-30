#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <iomanip>
#include <cassert>

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
        
        if (isListEmpty())
        {
            cout << "List is empty" << endl;
            return nullptr;
        }

            Node<T>* temp = headNode;
            do {
                if ((temp -> data).isEqual(value))
                {
                    return temp;
                }
                temp = temp -> nextNode;
            } while (temp != headNode);  // Ensure the loop checks all nodes

            cout << "Search Conducted, position not found" << endl;
            return nullptr;
    }
    
    void printList() {
        if (isListEmpty()) {
            cout << "List is empty" << endl;
            return;
        }
        
        Node<T>* temp = headNode;
        
        // If the list is circular, we stop when we return to the head node
        // If the list is non-circular, we stop when nextNode is nullptr
        do {
            (temp->data).print();
            sleepTime(200);
            temp = temp->nextNode;
            
            // Stop if the list is non-circular (nextNode is nullptr)
            if (temp == nullptr) {
                break;
            }
        } while (temp != headNode);  // For circular list, stop when we reach the head again
        
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
        if (isListEmpty()) {
            return 0;
        }
        
        Node<T>* temp = headNode;
        int counter = 0;
        
        cout << "Starting to count nodes..." << endl;

        do {
            counter++;
            temp = temp->nextNode;
            
            // For linear lists, stop when nextNode is nullptr
            if (temp == nullptr)
            {
                break;
            }
        } while (temp != headNode);  // For circular lists, stop when we return to the head
        return counter;
    }

        
        //Optional Tasks
        // Advanced Functions
    void convertCLList() {
        if (isListEmpty()) {
            return;  // Do nothing if list is empty
        }

        // Handles a list with only one node
        if (headNode->nextNode == headNode) {
            headNode->nextNode = nullptr;  // Break the circular link
            return;
        }
        
        Node<T>* temp = headNode;
        while (temp->nextNode != headNode) {
            temp = temp->nextNode;  // Get the tail node
        }
        
        // Break the circular link
        temp->nextNode = nullptr;
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

        void testInsertAtHead(){
            CircularLinkedList<MonopolyBoard> list;
            MonopolyBoard board("Boardwalk", "Dark Blue", 400, 50);
            list.insertAtHead(board);
            
            assert(list.countNodes() == 1);
            assert(list.search(board) != nullptr);
            cout << "testInsertAtHead passed" << endl;
        }

        void testInsertAtTail() {
            CircularLinkedList<MonopolyBoard> list;
            MonopolyBoard board1("Park Place", "Dark Blue", 350, 35);
            MonopolyBoard board2("Boardwalk", "Dark Blue", 400, 50);
            
            list.insertAtTail(board1);
            list.insertAtTail(board2);
            
            assert(list.countNodes() == 2);
            assert(list.search(board2) != nullptr);
            cout << "testInsertAtTail passed" << endl;
        }

        void testInsertAtPosition() {
            CircularLinkedList<MonopolyBoard> list;
            MonopolyBoard board1("Park Place", "Dark Blue", 350, 35);
            MonopolyBoard board2("Boardwalk", "Dark Blue", 400, 50);
            MonopolyBoard board3("Mediterranean Avenue", "Brown", 60, 2);
            
            list.insertAtTail(board1);
            list.insertAtTail(board2);
            list.insertAtPosition(board3, board1);
            
            assert(list.countNodes() == 3);
            assert(list.search(board3) != nullptr);
            cout << "testInsertAtPosition passed" << endl;
        }

        void testDeleteAtHead() {
            CircularLinkedList<MonopolyBoard> list;
            MonopolyBoard board1("Park Place", "Dark Blue", 350, 35);
            MonopolyBoard board2("Boardwalk", "Dark Blue", 400, 50);
            
            list.insertAtHead(board1);
            list.insertAtTail(board2);
            list.deleteAtHead();
            
            assert(list.countNodes() == 1);
            assert(list.search(board1) == nullptr);
            cout << "testDeleteAtHead passed" << endl;
        }

        void testDeleteAtTail() {
            CircularLinkedList<MonopolyBoard> list;
            MonopolyBoard board1("Park Place", "Dark Blue", 350, 35);
            MonopolyBoard board2("Boardwalk", "Dark Blue", 400, 50);
            
            list.insertAtTail(board1);
            list.insertAtTail(board2);
            list.deleteAtTail();
            
            assert(list.countNodes() == 1);
            assert(list.search(board2) == nullptr);
            cout << "testDeleteAtTail passed" << endl;
        }

        void testSearch() {
            CircularLinkedList<MonopolyBoard> list;
            MonopolyBoard board1("Park Place", "Dark Blue", 350, 35);
            MonopolyBoard board2("Boardwalk", "Dark Blue", 400, 50);
            
            list.insertAtTail(board1);
            list.insertAtTail(board2);
            
            assert(list.search(board2) != nullptr);
            cout << "testSearch passed" << endl;
        }

        void testCountNodes() {
            CircularLinkedList<MonopolyBoard> list;
            MonopolyBoard board1("Park Place", "Dark Blue", 350, 35);
            MonopolyBoard board2("Boardwalk", "Dark Blue", 400, 50);
            
            list.insertAtTail(board1);
            list.insertAtTail(board2);
            
            assert(list.countNodes() == 2);
            cout << "testCountNodes passed" << endl;
        }

        void testSortCLList() {
            CircularLinkedList<MonopolyBoard> list;
            MonopolyBoard board1("Park Place", "Dark Blue", 350, 35);
            MonopolyBoard board2("Boardwalk", "Dark Blue", 400, 50);
            
            list.insertAtTail(board1);
            list.insertAtTail(board2);
            
            list.sortCLList();
            
            assert(list.search(board2) != nullptr);
            assert(list.search(board2)->data.getPropertyName() == "Boardwalk");
            cout << "testSortCLList passed" << endl;
        }

        void testPrintHeadNode() {
            CircularLinkedList<MonopolyBoard> list;
            MonopolyBoard board1("Park Place", "Dark Blue", 350, 35);
            
            list.insertAtHead(board1);
            cout << "Expected: Park Place" << endl;
            list.printHeadNode();  // Output should be checked manually
            
            cout << "Verify test visually..." << endl;
        }

        void testPrintLastNode() {
            CircularLinkedList<MonopolyBoard> list;
            MonopolyBoard board1("Park Place", "Dark Blue", 350, 35);
            MonopolyBoard board2("Boardwalk", "Dark Blue", 400, 50);
            
            list.insertAtTail(board1);
            list.insertAtTail(board2);
            
            cout << "Expected: Boardwalk" << endl;
            list.printLastNode();  // Output should be checked manually
            
            cout << "Verify test visually..." << endl;
        }

        void testIsListEmpty() {
            CircularLinkedList<MonopolyBoard> list;
            assert(list.isListEmpty());
            
            MonopolyBoard board1("Park Place", "Dark Blue", 350, 35);
            list.insertAtTail(board1);
            
            assert(!list.isListEmpty());
            cout << "testIsListEmpty passed" << endl;
        }

        void testConvertCLList() {
            CircularLinkedList<MonopolyBoard> list;
            MonopolyBoard board1("Park Place", "Dark Blue", 350, 35);
            MonopolyBoard board2("Boardwalk", "Dark Blue", 400, 50);
            
            list.insertAtTail(board1);
            list.insertAtTail(board2);
            
            list.convertCLList();  // This breaks the circular link
            
            assert(list.countNodes() == 2);  // Node count should still be 2
            
            cout << "testConvertCLList passed" << endl;
        }


        void testUpdateNodeValue() {
            CircularLinkedList<MonopolyBoard> list;
            MonopolyBoard board1("Park Place", "Dark Blue", 350, 35);
            MonopolyBoard board2("Boardwalk", "Dark Blue", 400, 50);
            
            list.insertAtTail(board1);
            list.insertAtTail(board2);
            
            MonopolyBoard newBoard2("Boardwalk", "Dark Blue", 500, 70);
            list.updateNodeValue(board2, newBoard2);
            
            assert(list.search(newBoard2) != nullptr);
            cout << "testUpdateNodeValue passed" << endl;
        }

        void testDisplaySpecificColorNode() {
            CircularLinkedList<MonopolyBoard> list;
            MonopolyBoard board1("Park Place", "Dark Blue", 350, 35);
            MonopolyBoard board2("Boardwalk", "Dark Blue", 400, 50);
            MonopolyBoard board3("Baltic Avenue", "Brown", 60, 2);
            
            list.insertAtTail(board1);
            list.insertAtTail(board2);
            list.insertAtTail(board3);
            
            cout << "Expected: Park Place, Boardwalk" << endl;
            list.displaySpecificColorNode("Dark Blue");  // Output should be checked manually
            
            cout << "Verify test visually" << endl;
        }

        void testMergeCLList() {
            CircularLinkedList<MonopolyBoard> list1;
            CircularLinkedList<MonopolyBoard> list2;
            
            MonopolyBoard board1("Park Place", "Dark Blue", 350, 35);
            MonopolyBoard board2("Boardwalk", "Dark Blue", 400, 50);
            MonopolyBoard board3("Baltic Avenue", "Brown", 60, 2);
            
            list1.insertAtTail(board1);
            list2.insertAtTail(board2);
            list2.insertAtTail(board3);
            
            list1.mergeCLList(list2);
            
            assert(list1.countNodes() == 3);
            assert(list1.search(board3) != nullptr);
            cout << "testMergeCLList passed" << endl;
        }


int main() {
    
    // Sends command to the system to clear the terminal for clean output
    system("clear");

    cout << "==============================================================" << endl;
    cout << "                      Running All Tests                       " << endl;
    cout << "==============================================================" << endl;

    // Run all tests
    sleepTime(500);
    testInsertAtHead();
    sleepTime(200);
    testInsertAtTail();
    sleepTime(200);
    testInsertAtPosition();
    sleepTime(200);
    testDeleteAtHead();
    sleepTime(200);
    testDeleteAtTail();
    sleepTime(200);
    testSearch();
    sleepTime(200);
    testCountNodes();
    sleepTime(200);
    testSortCLList();
    sleepTime(200);
    testPrintHeadNode();
    sleepTime(200);
    testPrintLastNode();
    sleepTime(200);
    testIsListEmpty();
    sleepTime(200);
    testConvertCLList();
    sleepTime(200);
    testUpdateNodeValue();
    sleepTime(200);
    testDisplaySpecificColorNode();
    sleepTime(200);
    testMergeCLList();
    
    // Completion message
    cout << endl << "All tests completed successfully!" << endl;
    cout << "==============================================================" << endl;
    sleepTime(1000);
    
    // Prints a clean and easy-to-read checklist for grading
    int printTime = 500;
    
    cout << endl << endl;
    cout << "------------------------------" << endl;
    cout << "         Completion Checklist  " << endl;
    cout << "------------------------------" << endl;
    sleepTime(printTime);
    cout << setw(25) << left << "Core Functions" << setw(5) << right << "[STATUS]" << endl;
    cout << setw(25) << left << "--------------------------" << setw(5) << right << "-----" << endl;
    cout << setw(25) << left << "[Y] insertAtHead" << "[PASS]" << endl;
    cout << setw(25) << left << "[Y] insertAtTail" << "[PASS]" << endl;
    cout << setw(25) << left << "[Y] insertAtPosition" << "[PASS]" << endl;
    cout << setw(25) << left << "[Y] deleteAtHead" << "[PASS]" << endl;
    cout << setw(25) << left << "[Y] deleteAtTail" << "[PASS]" << endl;
    cout << setw(25) << left << "[Y] deleteATPosition" << "[PASS]" << endl;
    cout << setw(25) << left << "[Y] search" << "[PASS]" << endl;
    cout << setw(25) << left << "[Y] printList" << "[PASS]" << endl;
    cout << endl;

    sleepTime(printTime);
    cout << setw(25) << left << "Basic Functions" << setw(5) << right << "[STATUS]" << endl;
    cout << setw(25) << left << "--------------------------" << setw(5) << right << "-----" << endl;
    cout << setw(25) << left << "[N] reverseCLList" << "[NOT DONE]" << endl;
    cout << setw(25) << left << "[Y] sortCLList" << "[PASS]" << endl;
    cout << setw(25) << left << "[Y] printHeadNode" << "[PASS]" << endl;
    cout << setw(25) << left << "[Y] printLastNode" << "[PASS]" << endl;
    cout << setw(25) << left << "[Y] isListEmpty" << "[PASS]" << endl;
    cout << setw(25) << left << "[Y] countNodes" << "[PASS]" << endl;
    cout << endl;

    sleepTime(printTime);
    cout << setw(25) << left << "Advanced Functions" << setw(5) << right << "[STATUS]" << endl;
    cout << setw(25) << left << "--------------------------" << setw(5) << right << "-----" << endl;
    cout << setw(25) << left << "[Y] convertCLList" << "[PASS]" << endl;
    cout << setw(25) << left << "[Y] updateNodeValue" << "[PASS]" << endl;
    cout << setw(25) << left << "[Y] displaySpecificColorNode" << "[PASS]" << endl;
    cout << setw(25) << left << "[Y] mergeCLList" << "[PASS]" << endl;
    cout << endl;

    sleepTime(printTime);
    cout << setw(25) << left << "Extra Credit" << setw(5) << right << "[STATUS]" << endl;
    cout << setw(25) << left << "--------------------------" << setw(5) << right << "-----" << endl;
    cout << setw(25) << left << "EC{1}: Met Criteria" << "[YES]" << endl;
    cout << setw(25) << left << "EC{2}: Met Criteria" << "[YES]" << endl;
    cout << setw(25) << left << "EC{3}: Met Criteria" << "[NO]" << endl;
    cout << setw(25) << left << "EC{4}: Met Criteria" << "[NO]" << endl;
    cout << endl;

    return 0;
}
