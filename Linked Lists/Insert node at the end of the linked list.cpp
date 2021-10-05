/*Store head node to the temporary node
Iterate temporary node to till the last node
Create an empty node which next pointer points to NULL
Link to new node to the temporary node at the end position*/

void SingleList::insert(int data)
{
        // store head node to temp
        stNode *pTempNode = m_pHead;

        while(pTempNode->m_pNext != NULL){
            pTempNode = pTempNode->m_pNext;
        }

        //create new node 
        stNode *pNode = new stNode();
        pNode->data = data;
        pNode->m_pNext = NULL;

        //attached new node at end
        pTempNode->m_pNext = pNode;     

} 