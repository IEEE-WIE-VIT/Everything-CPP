// create a node using struct - using struct as by default struct members are public
struct stNode{
    int data;
    stNode *m_pNext;
};

// create a node using class
class Node {
public:
	int data;
	Node* next;
};

//head node can be created using stNode.

stNode *m_pHead = NULL;