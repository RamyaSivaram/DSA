// Online C++ compiler to run C++ program online
#include <iostream>
#include <stack>
using namespace std;
int total =0;
class Node
{
public: // mark as public as these data and next will be accessed outside of this class
  int data; Node *next;
  Node() // default constructor
  {
      data = 0; next = nullptr;
  }
  Node(int newdata) //parameterized constructor
  {
      data = newdata;
      next = nullptr;
  }
};
class LinkedList
{
    
    Node *head;
    public:
    LinkedList()
    {
        head = nullptr;
    }
    void creation(int data)
    {
        Node *newnode = new Node(data);
        if (head == nullptr)
        {
            head = newnode;
            return;
        }
        newnode ->next = head;
        head = newnode;
        
    }
   void  print()
    {
        Node *temp = head;
        while(temp != nullptr)
        {
            cout << temp->data;
            temp = temp->next;
        }
    }
    int length()
    {
        int c=0;
        Node *temp= head;
        while(temp != nullptr)
        {
            c++;
            temp = temp->next;
        }
        total=c;
        return c;
    }
    
    void Insert(int value, int index)
    {   Node *newnode = new Node(value);
        Node * temp = head;int c=0;
        while(temp != nullptr)
        {
            if (c == index){
             
             if (index == 0)
             {
                 newnode ->next = temp;
                 head = newnode ;
             }
             else if (index == total -1)
             {
                 temp->next = newnode;
             }
             else
             {
                 newnode->next = temp->next;
                 temp ->next = newnode;
             }
             total++;
             return;
            }
            temp = temp->next;c++;
            
        }
    }
    Node* search(int index)
    {
        Node *temp= head;int c=0;
        while (temp != nullptr){
        if (c == index )
        {
           return temp; 
        }
        temp = temp->next;
        c++;
        }
        return nullptr;
    }
    void reverse()
    {
        //important is 3 points becoz this has onl 1 next pointer. otherwise u cant change the next pointer backwards
      Node *prev = new Node();
      Node *curr= head;
      Node *nxt= new Node();
        //do{
      while(curr !=nullptr){
        nxt = curr->next;
        curr->next = prev;
        //nxt -> next = curr;
        prev= curr;
        curr= nxt;
        //nxt= nxt->next;
        
       }
       head = prev;
       
    }
    void deletion(int index)
    {
        Node* temp = head;int c=0;
        Node* temp2= head;
        
        while (temp != nullptr){
        if (c == index )
        {
        if (index == 0)
        {
            head = head->next;
            delete temp;total --;cout <<"total"<<total;return;
        }
        else if (index== total-1)
        {
            delete temp; 
            temp2->next = nullptr; total --;return;
        }
        else
        {
            temp2->next = temp->next;
            delete temp; total --; return;
        }
          
        }
        temp2= temp;
        temp = temp->next;
        c++;
        }

    }

    void Reverse_Subgroups_in_a_Singly_Linked_List_in_Groups(int k)
    {
        Node *temp= head;  Node *prev= nullptr;
        int c=0;
        //using stack
        stack <Node *> st;
        while(temp!=nullptr)
        {
           c=0;
           while(temp!=nullptr && c <= k-1  ) // 0,1 <= 1
           {   cout << "I";
               st.push(temp);
               temp = temp->next;
               c++;
           }
           cout<<"breaken";
           
           while (! st.empty() )
           {  
               if(prev == nullptr)
              { 
                  prev = st.top();
                  head = prev;
                  cout<<"head's data"<< head->data;
                  st.pop();
              }
              else
              {
                  prev-> next = st.top();
                  prev = prev->next;
                  cout<<"next after head's data"<< prev->data;
                  st.pop();
              }
              
           }
           
        }
       // Set the next pointer of the 
      // last node to NULL
    prev->next = nullptr; 
      
    }    
};
int main() {
    // Write C++ code here
    std::cout << "Linked List";
    LinkedList l;
    l.creation(5);    l.creation(6);    l.creation(7);    l.creation(8);
    l.print();
    l.length(); cout <<"l="<<total;
  
    l.Reverse_Subgroups_in_a_Singly_Linked_List_in_Groups(2);l.print();

    return 0;
}