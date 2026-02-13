/******************************************************************************

LINKED LIST implementation in C++

*******************************************************************************/

#include <iostream>
using namespace std;

template <class T>
class Node
{
    private:
        T data;
        Node* next;
    public:
        Node(T d)
        {
            data = d;
            next = NULL;
        }
        void setData(T d)         { data = d; }
        T getData()               { return data; }
        void setNext(Node *newNode) { next = newNode; }
        Node* getNext()             { return next;}
};

template <class T>
class LList
{
    private:
        Node<T>* head;
    public:
        LList()
        {
            head=NULL;
        }
        void insertStart(T V)
        {
            Node <T> *newNode = new Node<T>(V);
            newNode->setData(V);
            newNode->setNext(NULL);
            if(head == NULL)
            {
                head = newNode;
            }
            else
            {
                newNode->setNext(head);
                head = newNode;
            }
        }
        /* void insertStartNode(struct Node *newNode)
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
        */
        int deleteStart()
        {
            if(head!=NULL)
            {
                Node<T>* Temp = head;
                int x = Temp->getData();
                head = head->getNext();
                delete Temp;
                return x;
            }
        }

        void createIntegersList()
        {
            Node<int> *n1 = new Node<int>(15);
            Node<int> *n2  = new Node<int>(78);
            Node<int> *n3 = new Node<int>(8);

            n1->setNext(n2);
            n2->setNext(n3);

            head = n1;
        }


        void display()
        {
            cout<<"display method"<<endl;
            Node<T>* temp = head;

            while(temp!=NULL)
            {
                cout<<temp->getData()<<endl;
                temp = temp->getNext();
            }
        }
};

template<class T>
class stack
{
    LList<T> sList;
    public:
         void push(T v)
        {
             sList.insertStart(v);
        }

        T pop()
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

    stack<int> s1;
    s1.push(10);
    s1.push(15);
    s1.push(20);
    s1.push(26);
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;

    LList<int> l1;
    l1.createIntegersList();
    l1.insertStart(50);l1.insertStart(150);
    l1.display();
/*
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

