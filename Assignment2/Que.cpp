// DSA
// 1 Print the Elements of a Linked List
void printLinkedList(SinglyLinkedListNode *head)
{
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}

// 2 Insert a Node at the Tail of a Linked List
SinglyLinkedListNode *insertNodeAtTail(SinglyLinkedListNode *head, int data)
{
    SinglyLinkedListNode *newNode = new SinglyLinkedListNode(data);
    SinglyLinkedListNode *temp = head;
    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newNode->data = data;
    newNode->next = NULL;
    temp->next = newNode;

    return head;
}

// 3 Insert a node at the head of a linked list
SinglyLinkedListNode *insertNodeAtHead(SinglyLinkedListNode *llist, int data)
{
    SinglyLinkedListNode *newNode = new SinglyLinkedListNode(data);
    SinglyLinkedListNode *temp = llist;
    newNode->next = llist;
    llist = newNode;
    return llist;
}

// 4 Insert a node at a specific position in a linked list
SinglyLinkedListNode *insertNodeAtPosition(SinglyLinkedListNode *llist, int data, int position)
{
    SinglyLinkedListNode *newNode = new SinglyLinkedListNode(data);
    SinglyLinkedListNode *temp = llist;
    int i = 0;
    while (i < position - 1)
    {
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;

    return llist;
}

// 5 Delete a Node
SinglyLinkedListNode *deleteNode(SinglyLinkedListNode *llist, int position)
{
    SinglyLinkedListNode *temp = llist;
    SinglyLinkedListNode *ptr = NULL;
    int i = 0;
    if (position == 0)
    {
        ptr = llist;
        llist = ptr->next;
        delete ptr;
    }
    else
    {
        while (i < position - 1)
        {
            temp = temp->next;
            i++;
        }
        ptr = temp->next;
        temp->next = ptr->next;

        ptr->next = NULL;
        delete ptr;
    }

    return llist;
}

// 6 Get Node Value
int getNode(SinglyLinkedListNode *llist, int positionFromTail)
{
    SinglyLinkedListNode *temp = llist;
    SinglyLinkedListNode *ptr = llist;
    int count = 0, i = 0, chk;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    chk = count - positionFromTail;
    while (i < chk - 1)
    {
        ptr = ptr->next;
        i++;
    }
    return ptr->data;

    cout << temp->data << endl;
    return 0;
}

// 7 Inserting a Node Into a Sorted Doubly Linked List
DoublyLinkedListNode *sortedInsert(DoublyLinkedListNode *llist, int data)
{
    DoublyLinkedListNode *newNode = new DoublyLinkedListNode(data);
    DoublyLinkedListNode *temp = llist;
    DoublyLinkedListNode *hold;
    if (data < llist->data)
    {
        newNode->next = llist;
        llist->prev = newNode;
        llist = newNode;
        return llist;
    }
    while (temp != NULL && temp->data < data)
    {
        hold = temp;
        temp = temp->next;
    }
    // newNode->data=data;
    newNode->next = hold->next;
    newNode->prev = hold;
    hold->next = newNode;

    return llist;
}

// 8 Reverse Doubly Link list
DoublyLinkedListNode *reverse(DoublyLinkedListNode *llist)
{
    DoublyLinkedListNode *currNode, *nextNode, *Nllist;
    currNode = llist;
    if (llist->next == NULL)
        return llist;
    while (currNode != NULL)
    {
        nextNode = currNode->next;
        Nllist = currNode->prev;
        currNode->next = currNode->prev;
        currNode->prev = nextNode;
        currNode = nextNode;
    }
    return Nllist->prev;
}

// 9 Cycle Detection
SinglyLinkedListNode *temps = head;
SinglyLinkedListNode *tempf = head;
if (head == NULL)
{
    return 0;
}
while (tempf != NULL && tempf->next != NULL)
{
    temps = temps->next;
    tempf = tempf->next->next;
    if (temps == tempf)
    {
        return 1;
    }
}
return 0;
}