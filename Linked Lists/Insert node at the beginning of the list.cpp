/*Create an empty node and assign values
Link empty node to head node of the linked list
Change head node pointer to the newly created node*/

void SingleList::addAtBegin(int data)
{
    // create node and attach to head
    stNode *pNode = new stNode();
    pNode->data = data;
    pNode->m_pNext = m_pHead;
    
    //reset head
    m_pHead = pNode;              
}