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
  
## Operations and Time Complexities

### `insertAtHead`
**Description:**  
Inserts a node at the beginning of the list. To complete the operation, the method has to traverse the entire list to find the tail node and update its `nextNode` pointer.  

**Time Complexity:**  
- **Best case:** `O(N)` — because even in the best case, the tail node has to be found to correctly link the list to the new head.  
- **Worst case:** `O(N)` — same as the best case, since traversal of the list to update the tail pointer is necessary.  

---

### `insertAtTail`
**Description:**  
Inserts a new node at the end of the list. The method traverses the list to find the tail node and then appends the new node.  

**Time Complexity:**  
- **Best case:** `O(N)` — regardless of the input size, traversal is required to find the last node.  
- **Worst case:** `O(N)` — same as the best case, because of the full list traversal.  

---

### `insertAtPosition`
**Description:**  
Inserts a new node after a given position by searching through the list for the specified position.  

**Time Complexity:**  
- **Best case:** `O(N)` — even in the best scenario, the list must be searched to find the position, so it depends on the list length.  
- **Worst case:** `O(N)` — same as the best case, since traversal is required to locate the position.  

---

### `deleteAtHead`
**Description:**  
Deletes the head node and reassigns the new head. The method traverses the entire list to find the tail node and updates its `nextNode` pointer to the new head.  

**Time Complexity:**  
- **Best case:** `O(N)` — finding the tail node requires traversal of the list.  
- **Worst case:** `O(N)` — same as the best case, since the traversal is necessary.  

---

### `deleteAtTail`
**Description:**  
Deletes the last node in the list, requiring traversal to find the tail and update the second-to-last node's pointer to become the new tail.  

**Time Complexity:**  
- **Best case:** `O(N)` — traversal to find the tail node is required.  
- **Worst case:** `O(N)` — same as the best case, because traversal through the list is unavoidable.  

---

### `deleteAtPosition`
**Description:**  
Deletes a node at a specified position by searching for that position and updating the preceding node’s pointer.  

**Time Complexity:**  
- **Best case:** `O(N)` — traversal to locate the position is needed in all cases.  
- **Worst case:** `O(N)` — same as the best case, since finding the node requires traversing the list.  

---

### `search`
**Description:**  
Searches for a node containing a value by traversing the list.  

**Time Complexity:**  
- **Best case:** `O(N)` — even in the best case, the entire list may need to be traversed to find the value.  
- **Worst case:** `O(N)` — same as the best case, since traversal through the list is required to perform the search.  

---

### `printList`
**Description:**  
Loops through the entire list to print each node’s data.  

**Time Complexity:**  
- **Best case:** `O(N)` — all nodes need to be traversed to print the list.  
- **Worst case:** `O(N)` — same as the best case, because each node must be printed in both cases.  
