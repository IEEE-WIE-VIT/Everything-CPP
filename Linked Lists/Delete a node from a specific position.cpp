/*Traverse the list till required position and while traversing maintain previous node.
Update previous node link to the next of the node which we want to delete.
Delete the node at specific position.*/

void SingleList::deleteAtPos(int pos)
{
    // if the list is empty
    if(m_pHead == NULL)
    {
        cout<<"list is empty"<<endl;
    }
    else
    {
        //if pos < 0 
        if(pos <= 0)
        {
            cout<<"invalid position"<<endl;
        }
        else if(pos == 1) // if first node
        {
            //deleteFirstNode();
            stNode *pNext = m_pHead;
            m_pHead = m_pHead->m_pNext;        
            delete pNext;
        }
        else
        {
            stNode *pTemp = m_pHead;
            stNode *pPrev = NULL;
            int counter = 1;
            // iterate till specific position and maintain prev. node
            while((pTemp != NULL) && (counter <= (pos - 1)))
            {
                //maintain prev. node
                pPrev = pTemp;
                pTemp = pTemp->m_pNext;
                counter++;
            }
            // if position beyound the list or not found
            if(pTemp == NULL)
            {
                cout<<"Position doesn't exist"<<endl;
            }
            else
            {
                //link prev. node to the next node which we want to delete
                pPrev->m_pNext = pTemp->m_pNext;
                //delete node
                delete pTemp;
            }        
        }
    }
}