/*Iterate till specified position and maintain the previous node
Create an empty node that points to the next link of position node
Point previous node to the newly created node*/

void SingleList::addAtPos(int data, int pos)
{
    //if pos < 0 
    if(pos <= 0)
    {
        cout<<"invalid position"<<endl;
    }
    else if((m_pHead == NULL) || (pos == 1))
    {
        // create node and attach to head
        stNode *pNode = new stNode();
        pNode->data = data;
        pNode->m_pNext = m_pHead;
    
        //reset head
        m_pHead = pNode;
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
            cout<<"Position doesn't exist adding at last position"<<endl;
            stNode *p = new stNode();
            p->data = data;
            p->m_pNext = NULL;
            
            pPrev->m_pNext = p;
        }
        else
        {
            //create node
            stNode *p = new stNode();
            p->data = data;
            p->m_pNext = pTemp;
            
            pPrev->m_pNext = p;
        } 
    }
}