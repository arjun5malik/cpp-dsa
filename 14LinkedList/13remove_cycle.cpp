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
        Node* newNode=new Node(val);

        if(head==NULL){
            head=tail=newNode;
        }else{
            newNode->next=head;
            head=newNode;
        }
    }
};

void printLL(Node* head){
    Node* temp=head;

    while(temp!=NULL){
       cout<<temp->data<<" -> ";
       temp=temp->next;
    }
    cout<<"NULL";
}

void removeCycle(Node* head){
    Node* slow=head;
    Node* fast=head;
    bool IsCycle=false;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;//+1;
        fast=fast->next->next;//+2

        if(slow==fast){
            cout<<"cycle exist\n";
            IsCycle=true;
            break;
        }
    }
    
    if(!IsCycle){
        cout<<"cycle doesn't exist";
        return;
    }

    slow=head;
    if(slow==fast){//special case: tail->head
        while(fast->next!=slow){
           fast=fast->next;
        }
        fast->next=NULL;
    }else{
        Node* prev=fast;

        while(slow!=fast){
            slow=slow->next;//+1
            prev=fast;
            fast=fast->next;//+1
        }

        prev->next=NULL;
    }

}

int main(){
    List ll;

    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.tail->next=ll.head;

    removeCycle(ll.head);
    printLL(ll.head);
    cout<<"\n";

    return 0;
}
