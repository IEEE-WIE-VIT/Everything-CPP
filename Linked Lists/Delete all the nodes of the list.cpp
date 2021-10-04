/*Iterate all the nodes till last and maintain temporary node
While iterating next node delete temporary node.
After deleting all the node reset header to NULL*/


void SingleList::deleteAll()
{
    while(m_pHead != NULL){
        stNode *pNode = m_pHead;
        m_pHead = m_pHead->m_pNext;
        delete pNode;        
    }
}