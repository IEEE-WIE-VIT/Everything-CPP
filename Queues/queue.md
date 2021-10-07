# Queue

## Defination
A queue is a useful data structure in programming. It is similar to the ticket queue outside a cinema hall, where the first person entering the queue is the first person who gets the ticket. Queue follows the First In First Out (FIFO) rule - the item that goes in first is the item that comes out first.

## Operations
- Enqueue: Add an element to the end of the queue
- Dequeue: Remove an element from the front of the queue
- IsEmpty: Check if the queue is empty
- IsFull: Check if the queue is full
- Peek: Get the value of the front of the queue without removing it

## Working of Queue
- two pointers FRONT and REAR
- FRONT track the first element of the queue
- REAR track the last element of the queue
- initially, set value of FRONT and REAR to -1
- Enqueue Operation
check if the queue is full
for the first element, set the value of FRONT to 0
increase the REAR index by 1
add the new element in the position pointed to by REAR
- Dequeue Operation
check if the queue is empty
return the value pointed by FRONT
increase the FRONT index by 1
for the last element, reset the values of FRONT and REAR to -1

## Complexity
The complexity of enqueue and dequeue operations in a queue using an array is O(1). If you use pop(N) in python code, then the complexity might be O(n) depending on the position of the item to be popped.

## Applications
1) When a resource is shared among multiple consumers. Examples include CPU scheduling, Disk Scheduling. 
2) When data is transferred asynchronously (data not necessarily received at same rate as sent) between two processes. Examples include IO Buffers, pipes, file IO, etc. 
3) In Operating systems:
       a) Semaphores
       b) FCFS ( first come first serve) scheduling, example: FIFO queue
       c) Spooling in printers
       d) Buffer for devices like keyboard
4) In Networks:
       a) Queues in routers/ switches 
       b) Mail Queues
5) Variations: ( Deque, Priority Queue, Doubly Ended Priority Queue )

## peek()
This function helps to see the data at the front of the queue. The algorithm of peek() function is as follows:

begin procedure peek
   return queue[front]
end procedure

## isfull()
As we are using single dimension array to implement queue, we just check for the rear pointer to reach at MAXSIZE to determine that the queue is full. In case we maintain the queue in a circular linked-list, the algorithm will differ. Algorithm of isfull() function −

begin procedure isfull

   if rear equals to MAXSIZE
      return true
   else
      return false
   endif
   
end procedure

## isempty()
Algorithm of isempty() function −

begin procedure isempty

   if front is less than MIN  OR front is greater than rear
      return true
   else
      return false
   endif
   
end procedure


## Enqueue Operation
Queues maintain two data pointers, front and rear. Therefore, its operations are comparatively difficult to implement than that of stacks.

The following steps should be taken to enqueue (insert) data into a queue −

Step 1 − Check if the queue is full.

Step 2 − If the queue is full, produce overflow error and exit.

Step 3 − If the queue is not full, increment rear pointer to point the next empty space.

Step 4 − Add data element to the queue location, where the rear is pointing.

Step 5 − return success.

## Dequeue Operation
Accessing data from the queue is a process of two tasks − access the data where front is pointing and remove the data after access. The following steps are taken to perform dequeue operation −

Step 1 − Check if the queue is empty.

Step 2 − If the queue is empty, produce underflow error and exit.

Step 3 − If the queue is not empty, access the data where front is pointing.

Step 4 − Increment front pointer to point to the next available data element.

Step 5 − Return success.

## Types of Queues
### Simple Queue
In a simple queue, insertion takes place at the rear and removal occurs at the front. It strictly follows the FIFO (First in First out) rule.
### Circular Queue
In a circular queue, the last element points to the first element making a circular link.
### Priority Queue
A priority queue is a special type of queue in which each element is associated with a priority and is served according to its priority. If elements with the same priority occur, they are served according to their order in the queue.
### Deque (Double Ended Queue)
In a double ended queue, insertion and removal of elements can be performed from either from the front or rear. Thus, it does not follow the FIFO (First In First Out) rule.
