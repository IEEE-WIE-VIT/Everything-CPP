/*Create a temporary node that points to the head node
Move head node to next
Delete the temporary node*/

void SingleList::deleteFirstNode()
{
    if(m_pHead != NULL)
    {
        stNode *pNext = m_pHead;
        m_pHead = m_pHead->m_pNext;        
        delete pNext;        
    }
    else
    {
        cout<<"list is empty"<<endl;
    }
} 