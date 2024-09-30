# Monopoly Board Linked-List

## Overview
This project implements an understanding of abstract data types through the implementation of linked list. This is designed to perform multiple operations (Insert at head, tail, and position; Delete at head, tail, and position; search for a specific position; display elmeents of the list)   on a linked list.. The program is written in C++ and can be
executed from your local terminal. 

## How to Run the Code
### Prerequisites
- Ensure you have a C++ compilier installed in your file path. For instructions on installation of each see:
  
  [Linux / Mac](https://siytek.com/how-to-compile-cpp-on-a-mac/)

  [Windows](https://learn.microsoft.com/en-us/cpp/build/walkthrough-compiling-a-native-cpp-program-on-the-command-line?view=msvc-170) 

### Instructions 
- Open up your local terminal and change to the directory with your file.cpp
- Next execute the compile command
    :g++ filepath/filename.cpp -o filename.exe
- Finally run your file with the following command 
    :./filename.exe
  
## Operations
1. **insertAtHead**<br/>
Description: This method creates a new node and inserts at the beginning of the list. The method must traverse the entire list to find the tail node to update the next pointer. <br/>
**Time Complexity:** <br/>
Best case: O([N)<br/>
Worst case: O(N)<br/>
List all Operations implemented in your project using the above format.<br/>

3. **insertAtTail**<br/>
Description: This method creates a new node and inserts at the ned of the tail.<br/>
**Time Complexity:** <br/>
Best case: O(N)<br/>
Worst case: O(N)<br/>
List all Operations implemented in your project using the above format.<br/>

4. **insertAtPosition**<br/>
Description: This method create a new node and inserts directly after the position found by<br/> searching the list for the position passed in by the method call.<br/> 
**Time Complexity:** <br/> 
Best case: O(N)<br/>
Worst case: O(N)<br/>
List all Operations implemented in your project using the above format.<br/>

5. **deleteAtHead**<br/>
Description: This method goes through the list to find the tail node to update it's next pointer to the new headNode, then deletes the old headNode.<br/>
**Time Complexity:** <br/> 
Best case: O(N)<br/>
Worst case: O(N)<br/>
List all Operations implemented in your project using the above format.<br/>

6. **deleteAtTail**<br/>
Description: This method travereses the list and finds the tail node, reassigns the preceeding node as the new tail, then deletes the existing node.<br/>
**Time Complexity:** <br/> 
Best case: O(N)<br/>
Worst case: O(N)<br/>
List all Operations implemented in your project using the above format.<br/>

5. **deleteAtPosition**<br/>
Description: This method travereses the list and finds the position to delete, reassigns the preceedings Node's next pointer, then deletes the positioned Node.<br/> 
**Time Complexity:** <br/> 
Best case: O(N)<br/>
Worst case: O(N)<br/>
List all Operations implemented in your project using the above format.<br/>

6. **search** <br/>
Description: This method travereses the list and finds the node associated with the value passed into the method call.<br/> 
**Time Complexity:** <br/> 
Best case: O(N)<br/>
Worst case: O(N)<br/>
List all Operations implemented in your project using the above format.<br/>

7. **printList**<br/>
Description: This method loops through the list and prints each node's data values.<br/> 
**Time Complexity:** <br/> 
Best case: O(N)<br/>
Worst case: O(N)<br/>
List all Operations implemented in your project using the above format.<br/>





