// Make head as the current node.
//Run a loop until the current node is NULL because the last element points to NULL.
//In each iteration, check if the key of the node is equal to item. If it the key matches the item, return true otherwise return false.


bool searchNode(struct Node** head_ref, int key) {
  struct Node* current = *head_ref;

  while (current != NULL) {
    if (current->data == key) return true;
      current = current->next;
  }
  return false;
} 