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

    void push_front(int val){
        Node* newNode=new Node(val);//dynamic

        if(head==NULL){
           head=tail=newNode;
        }else{
            newNode->next=head;
            head=newNode;
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

    int getSize(){
        int sz=0;
        Node* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            sz++;
        }
        return sz;
    }

    void removeNth(int n){
        int size=getSize();
        Node* prev=head;
        for(int i=1;i<(size-n);i++){
           prev=prev->next;
        }   

        prev->next=prev->next->next;
    }    
};

int main(){
    List ll;

    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.print();
    cout<<'\n';
    ll.removeNth(3);
    ll.print();

    return 0;
}