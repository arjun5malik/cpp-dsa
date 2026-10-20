#include<iostream>
using namespace std;

class Node{
public:    
    int data;
    Node* next;

public:
  Node(int val){
    data=val;
    next=NULL;
  }    
};

class List{   
    Node* head;
    Node* tail;

public:
    List(){
        head=NULL;
        tail=NULL;
    }

    void push_back(int val){
        Node* newNode=new Node(val);//dynamic

        if(head==NULL){
           head=tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }

    void print(){
        Node* temp=head;

        while(temp!=NULL){
            cout<<temp->data<<" --> ";
            temp=temp->next;
        }
        cout<<"NULL";
    }
    

    void reverseLL(){
        Node* curr=head;
        Node* prev=NULL;
        
        while(curr!=NULL){
            Node* next=curr->next;
            curr->next=prev;

            //updating for next itr
            prev=curr;
            curr=next;
        }
        head=prev;
    }
};

int main(){
    List ll;

   
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.print();//1->2->3->4->5->NULL
    cout<<"\n";

    ll.reverseLL();
    ll.print();//5->4->3->2->1->NULL
    
    return 0;
}