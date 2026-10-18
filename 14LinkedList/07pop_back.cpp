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
public:
      Node* head;
      Node* tail;
public:
     List(){
        head=NULL;
        tail=NULL;
     } 
     
     void push_back(int val){
        Node* newNode=new Node(val);

        if(tail==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
     }

     void pop_back(){
        Node* temp=head;

        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        temp->next=NULL;//temp = tail's prev
        delete tail;
        tail=temp;
     }

     void print(){
        Node* temp=head;

        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL";
     }
};

int main(){
    List ll;

    ll.push_back(3);
    ll.push_back(2);
    ll.push_back(1);
    ll.print();//3->2->1->NULL
    cout<<'\n';
    ll.pop_back();
    ll.print();//3->2->NULL

    return 0;
}