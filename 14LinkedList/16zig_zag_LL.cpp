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

    void push_back(int val){
        Node* newNode=new Node(val);//dynamic

        if(head==NULL){
           head=tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    
};

void print(Node* head){
        Node* temp=head;

        while(temp!=NULL){
            cout<<temp->data<<" --> ";
            temp=temp->next;
        }
        cout<<"NULL";
}

Node* reverse(Node* head){
    Node* curr=head;
    Node* prev=NULL;
    Node* next=NULL;
    
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;

        //updating for next itr
        prev=curr;
        curr=next;
    }

    return prev;
}

Node* splitAtMid(Node* head){
    Node*slow=head;
    Node* fast=head;
    Node* prev=NULL;
    while(fast!=NULL && fast->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(prev!=NULL){
        prev->next=NULL;//split at mid
    }
    return slow;//righthead=slow
}

Node* ZigZagLL(Node* head){
        
    Node* rightHead=splitAtMid(head); 
    Node* rightHeadRev=reverse(rightHead);

    //alternate merging 
    Node* left = head;
    Node* right = rightHeadRev;
    Node* tail = right;

    while(left!=NULL && right!=NULL){
        Node* Nextleft = left->next;
        Node* Nextright = right->next;

        left->next=right;
        right->next=Nextleft;
 
        tail=right;

        left=left->next;
        right=right->next; 

    }

    if(right!=NULL) tail->next=right;
    
    return head;
}

int main(){
    List ll;
    
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5);
    print(ll.head);

    cout<<"\n";

    ll.head=ZigZagLL(ll.head);
    print(ll.head);
    
    return 0;
}