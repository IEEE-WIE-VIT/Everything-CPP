# Linked List

## What is a Linked List?

### Definition
A linked list is a set of dynamically allocated nodes, arranged in such a way that each node contains one value and one pointer. The pointer always points to the next member of the list. Linked lists function as an array that can grow and shrink as needed, from any point in the array. A linked list is a linear data structure used for storing data or collection of data.

<img align="centre" alt="Linked List" width="100%" src="https://github.com/A-GHOSH-dev/Everything-CPP/blob/new-user/Assets/linked-list-concept-1.png" />

## Why need a linked list?

### Disadvantages of arrays
- Need to reserve the space of the array at the beginning. Sometimes it is not possible to get memory for a complete array if the array size is too large.
- The size of the array is fixed.
- To insert an element at the middle position requires shifting of existing elements

### Advantages of Linked Lists
We often face situations, where the data is dynamic in nature and number of data can’t be predicted or the number of data keeps changing during program execution. Linked lists are very useful in this type of situations.
- Items can be added or removed from the middle of the list
- There is no need to define an initial size
- The list is not required to be contiguously present in the memory. The node can reside any where in the memory and linked together to make a list. This achieves optimized utilization of space.
- list size is limited to the memory size and doesn't need to be declared in advance.
- Empty node can not be present in the linked list.
- We can store values of primitive types or objects in the singly linked list.

### Dsadvantages of Linked Lists
- There is no "random" access - it is impossible to reach the nth item in the array without first iterating over all items up until that item. This means we have to start from the beginning of the list and count how many times we advance in the list until we get to the desired item.
- Dynamic memory allocation and pointers are required, which complicates the code and increases the risk of memory leaks and segment faults.
- Linked lists have a much larger overhead over arrays, since linked list items are dynamically allocated (which is less efficient in memory usage) and each item in the list also must store an additional pointer.

## Types of Linked List

### Singly Linked List
A node in the singly linked list consist of two parts: data part and link part. Data part of the node stores actual information that is to be represented by the node while the link part of the node stores the address of its immediate successor. Singly linked list can be traversed only in one direction. In other words, we can say that each node contains only next pointer, therefore we can not traverse the list in the reverse direction.

<img align="centre" alt="Singly Linked List" width="100%" src="https://github.com/A-GHOSH-dev/Everything-CPP/blob/new-user/Assets/single-linked-list.png" />

### Doubly Linked List
Doubly linked list is a complex type of linked list in which a node contains a pointer to the previous as well as the next node in the sequence. Therefore, in a doubly linked list, a node consists of three parts: node data, pointer to the next node in sequence (next pointer) , pointer to the previous node (previous pointer). 

<img align="centre" alt="doubly Linked List" width="100%" src="https://github.com/A-GHOSH-dev/Everything-CPP/blob/new-user/Assets/doubly-linked-list.png" />


### Singly and Doubly Circular Linked List
Circular Linked List is a variation of Linked list in which the first element points to the last element and the last element points to the first element. The last link's next points to the first link of the list in both cases of singly as well as doubly linked list.The first link's previous points to the last of the list in case of doubly linked list.

<img align="centre" alt="Singly Circular Linked List" width="100%" src="https://github.com/A-GHOSH-dev/Everything-CPP/blob/new-user/Assets/singly_circular_linked_list.png" />

<img align="centre" alt="Doubly Circular Linked List" width="100%" src="https://github.com/A-GHOSH-dev/Everything-CPP/blob/new-user/Assets/doubly_circular_linked_list.jpg" />


## Operations in Linked List

- Create Node - Creating a node.
- Insertion − add an element at the beginning of the list.
Insert node at the beginning of the list | Insert node at the end of the list | Insert node at the specified position
- Deletion − delete an element at the beginning of the list. 
Delete a node from front | Delete the last node | Delete a node from the specific position | Delete entire list
- Display − displaying complete list.
- Traversing - visit each node of the list at least once.
- Search − search an element using given key.
- Sort
- Reverse
