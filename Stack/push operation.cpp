void push(int data) {
   if(!isFull()){
      // increment top by 1 and insert data 
      intArray[++top] = data;
   } else {
      printf("Cannot add data. Stack is full.\n");
   }      
}