#include<bits/stdc++.h>
using namespace std;


//day02
class SinglyLinkedListNode 
{
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data)
        {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList 
{
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }
            this->tail = node;
            cout<<"\n";
            display();
        }

        void insert(int data)
        {
            SinglyLinkedListNode* new_node = new SinglyLinkedListNode(data);
            new_node->next = NULL;
            if (head == NULL)
            {
                cout<<"Head is null so inserting: "<<data<<" ";
                head = new_node;
            }
            else
            {
                SinglyLinkedListNode* ptr = head;
                while(ptr->next!=NULL)
                    ptr = ptr->next;
                ptr->next = new_node;
            }
        }

        void insert_start(int data)
        {
            SinglyLinkedListNode* new_node = new SinglyLinkedListNode(data);
            if (head == nullptr)
                head = new_node;
            else
            {
                new_node->next = head;
                head = new_node;
            }
        }
        void display()
        {
            SinglyLinkedListNode* ptr = head;
            while(ptr!=NULL)
            {
                cout<<ptr->data<<" ";
                ptr = ptr->next;
            }
        }

};

class stack1
{
    public:
        SinglyLinkedListNode* head;
    stack1()
    {
        head = nullptr;
    }

    //similar to insert at start for sll
    void push(int data)
    {
            SinglyLinkedListNode* new_node = new SinglyLinkedListNode(data);
            if (head == nullptr)
                head = new_node;
            else
            {
                new_node->next = head;
                head = new_node;
            }
    }

    void pop()
    {
        if(head==nullptr)
        {
            cout<<"\nempty stack";
            return;
        }
        cout<<"\nValue popped is: "<<head->data;
        head = head->next;
    }
};


class queue1
{
    public:
        SinglyLinkedListNode* head;
        SinglyLinkedListNode* tail;
    queue1()
    {
        head = nullptr;
        tail = nullptr;
    }

    void enq(int data)
    {
        SinglyLinkedListNode* new_node = new SinglyLinkedListNode(data);
        new_node->next = NULL;
        if(head == NULL)
            head = tail = new_node;
        else
        {
            tail->next = new_node;
            tail = new_node;         
        }
    }
    void deq()
    {
        if (head==NULL)
        {
            "\nEmpty queue";
            return;
        }
        cout<<"\nElement dequeued is: "<<head->data;
        head = head->next;
    }
};

void display(SinglyLinkedListNode* head)
{
    cout<<"\nDisplaying elements: ";
    SinglyLinkedListNode* ptr = head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}


int main()
{
    //sll operations
    // SinglyLinkedList* sll = new SinglyLinkedList();
    // sll->insert_start(1);
    // sll->insert_start(2);
    // sll->insert_start(3);
    // sll->insert_start(4);
    // sll->insert_start(5);
    // display(sll->head);

    //stack operations
    // stack1* s = new stack1();
    // s->push(1);
    // s->push(2);
    // s->push(3);
    // s->push(4);
    // display(s->head);
    // s->pop();
    // display(s->head);

    //queue operatons
    queue1* q = new queue1;
    q->enq(1);
    q->enq(2);
    q->enq(3);
    q->enq(4);
    display(q->head);
    q->deq();
    display(q->head);

    return 1;
}