bool isCircular(struct Node *head){
    struct Node* ptr=head->next;
    
    while(ptr!=NULL){
        if(ptr==head){
            break;
        }
        ptr=ptr->next;
    }
    if(ptr==head){
            return true;
        }
        else
        return false;
}