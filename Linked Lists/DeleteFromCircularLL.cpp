void deleteNode(Node** head, int key)
{
     
    if (*head == NULL)
        return;
         
    if((*head)->data==key && (*head)->next==*head)
    {
        free(*head);
        *head=NULL;
        return;
    }
     
    Node *last=*head,*d;
     
    if((*head)->data==key)
    {
         
        while(last->next!=*head)
            last=last->next;

        last->next=(*head)->next;
        free(*head);
        *head=last->next;
    }
     
    while(last->next!=*head&&last->next->data!=key)
    {
        last=last->next;
    }

    if(last->next->data==key)
    {
        d=last->next;
        last->next=d->next;
        free(d);
    }
    else
        cout<<"no such keyfound";
    }
 