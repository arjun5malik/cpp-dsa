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

    void push_front(int val){
        Node* newNode=new Node(val);//dynamic

        if(head==NULL){
            head=tail=newNode;
        }else{
            newNode->next=head;
            head=newNode;
        }
    }
};

void printlist(Node* head){
        Node* temp=head;

        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL";
}

bool isCycle(Node* head){
    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;//+1
        fast=fast->next->next;//+2

        if(slow==fast){
            cout<<"Cycle exists\n";
            return true;
        }
    }

    cout<<"Cycle doesn't exists\n";
    return false;
}

int main(){
    List ll;
    
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.tail->next=ll.head;
    //1->2->3->4->5->1
    isCycle(ll.head);

    return 0;
}