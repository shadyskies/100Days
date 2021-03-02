#include<bits/stdc++.h>
using namespace std;

class sll_node
{
    public:
        int data;
        sll_node *next;

    sll_node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class SLL
{
    public:
        sll_node *head;
        sll_node *tail;

        SLL()
        {
            this->head = nullptr;
            this->tail = nullptr;
        }

    void insert(int data)
    {
    sll_node* new_node = new sll_node(data);
    cout<<this->head->data;
    if (!this->head)
        this->head = new_node;
    else
        this->tail->next = new_node;
    this->tail = new_node;
    }

    // void display()
    // {
    //     while()
    // }
};

// void display_sll(sll_node* node)
// {
//     while(node)
//     {
//         cout<<node->data;
//         node = node->next;
//     }
// }


int main()
{
    SLL *tmp = new SLL();
    tmp->insert(1);
    tmp->insert(2);
    tmp->insert(3);
    tmp->insert(4);
    // display_sll(this->head);
    return 1;

}