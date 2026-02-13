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

        int deleteStart()
        {
            if(head!=NULL)
            {
                Node* Temp = head;
                int x = Temp->data;
                head = head->next;
                delete Temp;
                return x;
            }
        }
        void deleteLast()
        {
            if(head==NULL)
                cout<<"empty list";
            else
            {
                if(head->next==NULL)
                {
                    deleteStart();
                }
                else
                {
                    Node *curr=head->next, *prev=head;
                    while(curr->next!=NULL)
                    {
                        prev = curr;
                        curr = curr->next;
                    }
                    delete curr;
                    prev->next = NULL;
                }
            }
        }
        void deleteMiddle(int loc, int V)
        {
            struct Node *newNode = new Node;
            newNode->data = V;
            newNode->next = NULL;

            Node*temp = head;
            int i=1;
            while(i<loc-1)
            {
                temp = temp->next;
                i++;
            }
            // temp will be pointing to predecessor
            Node* todel = temp->next;
            temp->next = todel->next;
            delete temp->next;

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
class stack
{
    LList sList;
    public:
         void push(int v)
        {
             sList.insertStart(v);
        }

        int pop()
        {
            return sList.deleteStart();
        }
        void display()
        {
            sList.display();
        }
};
int main()
{
    stack s1;
    s1.push(10);
    s1.push(15);
    s1.push(20);
    s1.push(26);
    cout<<s1.pop();
    cout<<s1.pop();
    cout<<s1.pop();
/*LList l1;
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

    l1.deleteLast();
    l1.deleteLast();
    l1.deleteLast();
    l1.deleteLast();
l1.deleteLast();
l1.deleteLast();

    l1.display();

*/
    return 0;
}

