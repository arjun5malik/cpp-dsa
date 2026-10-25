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

Node* merge(Node* left,Node* right){
    List ans;
    Node* i=right;
    Node* j=left;

    while(i!=NULL && j!=NULL){
        if(i->data <= j->data){
            ans.push_back(i->data);
            i=i->next;
        }else{
            ans.push_back(j->data);
            j=j->next;
        }
    }

    while(i!=NULL){
        ans.push_back(i->data);
        i=i->next;
    }

    while(j!=NULL){
        ans.push_back(j->data);
        j=j->next;
    }

    return ans.head;
}

Node* splitAtMid(Node* head){
    Node*slow=head;
    Node* fast=head;
    Node* prev=NULL;
    while(fast!=NULL && fast->next==NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(prev!=NULL){
        prev->next=NULL;//split at mid
    }
    return slow;//righthead=slow
}

Node* mergeSort(Node* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node* rightHead=splitAtMid(head);
        
        Node* left=mergeSort(head);//left Head
        Node* right=mergeSort(rightHead);//right Head

        return merge(left,right);//head of sorted LL
}

int main(){
    List ll;
    
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5);
    
    print(ll.head);

    ll.head=mergeSort(ll.head);
    print(ll.head);
    
    return 0;
}