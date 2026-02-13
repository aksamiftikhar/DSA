/******************************************************************************

LINKED LIST implementation in C++

*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int rollnumber;
    string name;
public:
    Student()
    {

    }
    Student(int id, string n)
    {
        rollnumber = id;
        name = n;
    }
};

template<class T>
class Node
{
    private:
        T data;
        Node* next;
    public:
        Node(T d)     { data = d; next = NULL; }
        void setData(T d)     { data = d; }
        void setNext(Node* newestNode)     { next = newestNode; }
        T getData()     { return data; }
        Node* getNext()     { return next; }
};

template<class T>
class LList
{
    private:
        Node<T>* head;
        Node<T>* tail;
    public:
        LList()
        {
            head=NULL;
            tail=NULL;
        }

        void createIntegerList()
        {
            Node<T> *n1 = new Node<T>(15);

            Node<T> *n2  = new Node<T>(78);

            Node<T> *n3 = new Node<T>(50);

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


        void insertStart(T V)
        {
            Node<T> *newNode = new Node<T>(V);

            if(head == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                newNode->setNext(head);
                head = newNode;
                // no need to disturb tail
            }
        }

        T deleteStart()
        {
            if(head==NULL)
            {
                cout<<"empty list";
            }
            else if(head==tail) // 1 node case
            {
                delete head;
                head = NULL;
                tail = NULL;
            }
            else // more than 1 nodes case
            {
                Node<T>*temp = head;
                T v = temp->getData();
                head = temp->getNext();
                delete temp;
                return v;
            }
        }

        /*
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

        int deleteStart()
        {
            if(head==NULL)
            {
                cout<<"empty list";
            }
            else
            {
                Node*temp = head;
                int v = temp->data;
                head = temp->next;
                delete temp;
                return v;
            }
        }
        int deleteLast()
        {
            if(head==NULL)
            {
                cout<<"empty list";
            }
            else
            {
                Node* temp = head;
                while(temp->next->next!=NULL)
                {
                    temp = temp->next;
                }
                int data = (temp->next)->data;
                delete temp->next;
                temp->next = NULL;
                return data;
            }
        }

        void deleteMiddle(int pos)
        {
            Node* curr=head->next, *prev=head;
            int i=0;
            while(i<pos)
            {
                i++;
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            delete curr;

        }
        */

};
/*
class stack
{
    LList<string> sList;
    public:
         void push(string v)
        {
             sList.insertStart(v);
        }

        string pop()
        {
            return sList.deleteStart();
        }
        void display()
        {
            sList.display();
        }
};
*/
int main()
{
    /*
    stack s1;
    s1.push("abc");
    s1.push("def");
    s1.push("ghi");

    cout<<s1.pop();
*/
    LList<Student> l1;

    Student s1(123, "abc");
    Student s2(123, "abc");
    Student s3(123, "abc");

    l1.insertStart(s1);
    l1.insertStart(s2);
    l1.insertStart(s3);
    //l1.display();

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

    int d = l1.deleteStart();
    cout<<"deleted "<<d<<endl;
    int d2 = l1.deleteLast();
    cout<<"deleted "<<d2<<endl;

    l1.display();
    */


    return 0;
}

