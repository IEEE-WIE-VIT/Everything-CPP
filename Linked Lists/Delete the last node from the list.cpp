/*Traverse the list till the last node of the list and while traversing maintain previous node.
Update previous node link to NULL
Delete last node*/

void SingleList::deleteLastNode()
{
    // if list is empty
    if(m_pHead == NULL)
    {
        cout<<"list is empty"<<endl;
    }
    else
    {
        // if the list has only one element
        if(m_pHead->m_pNext == NULL)
        {
            delete m_pHead;
            m_pHead = NULL;
        }
        else
        {
            stNode *pTemp = m_pHead;
            stNode *pPrev = NULL;

            //iterate list till end and maintain previous node
            while(pTemp->m_pNext != NULL)
            {
                //maintain previous node
                pPrev = pTemp;
                pTemp = pTemp->m_pNext;
            }            
            //update previous node link to NULL
            pPrev->m_pNext = NULL;            
            //delete last node
            delete pTemp;
        }
    } 
} 