# Stacks

## Definition
A stack is a linear data structure that follows the principle of Last In First Out (LIFO). This means the last element inserted inside the stack is removed first. You can think of the stack data structure as the pile of plates on top of another. In programming terms, putting an item on top of the stack is called push and removing an item is called pop.

## Stack Operations
- Push − push an element at the top of the stack.
- Pop − pop an element from the top of the stack.
- Peek − get the top element of the stack.
- isFull − check if stack is full.
- isEmpty − check if stack is empty.

## Time Complexities of operations on stack:
push(), pop(), isEmpty() and peek() all take O(1) time. 

## Applications of stack:
- Infix to Postfix /Prefix conversion
- Balancing of symbols
- Redo-undo features at many places like editors, photoshop.
- Tower of Hanoi
- tree traversals
- stock span problem
- histogram problem
- Knight-Tour problem
- N-Queen problem
- Topological Sorting
- In Memory management, any modern computer uses a stack as the primary management for a running purpose.
- String reversal
- Forward and backward feature in web browsers

## Implementation: 
- Using array
- Using linked list

## Working of Stack Data Structure
- A pointer called TOP is used to keep track of the top element in the stack.
- When initializing the stack, we set its value to -1 so that we can check if the stack is empty by comparing TOP == -1.
- On pushing an element, we increase the value of TOP and place the new element in the position pointed to by TOP.
- On popping an element, we return the element pointed to by TOP and reduce its value.
- Before pushing, we check if the stack is already full
- Before popping, we check if the stack is already empty

## Operations
### Push Operation
Whenever an element is pushed into stack, stack stores that element at the top of the storage and increments the top index for later use. If storage is full then an error message is usually shown.

### Pop Operation
Whenever an element is to be popped from stack, stack retrives the element from the top of the storage and decrements the top index for later use.

### Algorithm
A program that implements a stack using array is given as follows.

Input: Push elements 11, 22, 33, 44, 55, 66
Output: Pop elements 66, 55, 44, 33, 22, 11

push(item)
Begin
   increase the top pointer by 1
   insert item into the location top
End
pop()
Begin
   item = top element from stack
   reduce top pointer by 1
   return item
End
peek()
Begin
   item = top element from stack
   return item
End
 

