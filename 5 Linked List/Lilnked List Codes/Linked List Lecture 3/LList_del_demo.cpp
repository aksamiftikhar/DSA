/******************************************************************************

LINKED LIST implementation in C++

*******************************************************************************/

#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};

class LList
{
    private:
        Node* head;
    public:
        LList()
        {
            head=NULL;
        }
        int deleteStart()
        {
            if(head == NULL)
                return -1;
            else
            {
                Node *temp = head;
                int data = temp->data;

                head = head -> next; // move head to the next node

                return data;
            }
        }
        Node* delete_val(int val)
        {
            if(head == NULL)
                return NULL;
            else
            {
                Node *temp = head;
                while(temp->data != val)
                {
                    temp = temp->next;
                }
                // ???
                // temp points to the node, which should be deleted, but
                // to delete it, we need pointer to previous of this node.

                if(head->data==val)
                {
                    deleteStart();
                }
                Node* curr=head->next, *prev=head;
                while(curr!=NULL)
                {
                    if(curr->data==val) // value matches, we have to delete curr node
                    {
                        prev->next = curr->next;
                    }
                    else
                    {

                    }
                }

                //return data;
            }
        }
        void insertStart(int V)
        {
            struct Node *newNode = new Node;
            newNode->data = V;
            newNode->next = NULL;

            insertStartNode(newNode);
        }
        void insertStartNode(struct Node *newNode)
        {
            if(head == NULL)
            {
                head = newNode;
            }
            else
            {
                newNode->next = head;
                head = newNode;
            }
        }
        void insertMiddle1(int loc, int V)
        {
            struct Node *newNode = new Node;
            newNode->data = V;
            newNode->next = NULL;


            if(head == NULL)
            {
                head = newNode;
            }
            // The following is a special case, because in this case head
            // should also be updated.
            else if(loc==1)
            {
                newNode->next = head;
                head = newNode;
            }
            else
            {
                struct Node *curr = head;
                struct Node *prev = NULL;
                int nodeCount=0;
                while(curr!=NULL)
                {
                    nodeCount = nodeCount+1;
                    if(nodeCount==loc)
                    {
                        newNode->next = curr;
                        prev->next = newNode;
                        break;
                    }
                    prev = curr;
                    curr = curr->next;
                }

            }
        }



        void createList()
        {
            Node *n1 = new Node;
            n1->data = 15;
            Node *n2  = new Node;
            n2->data = 78;
            Node *n3 = new Node;
            n3->data = 8;


            n1->next = n2;
            n2->next = n3;

            head = n1;
        }



        void display()
        {
            cout<<"display method"<<endl;
            Node* temp = head;

            while(temp!=NULL)
            {
                cout<<temp->data<<endl;
                temp = temp->next;
            }
        }
};
int main()
{
    LList l1;
    l1.insertStart(30);

    struct Node *newNode = new Node;
    newNode->data = 65;
    newNode->next = NULL;


    l1.insertStartNode(newNode);
    l1.insertStart(50);
    l1.insertStart(90);
    l1.insertStart(60);
    l1.insertMiddle1(4, 100);

    l1.display();

    int del = l1.deleteStart();
    cout<<"Deleted: "<< del << endl;
    del = l1.deleteStart();
    cout<<"Deleted: "<< del << endl;



    return 0;
}

