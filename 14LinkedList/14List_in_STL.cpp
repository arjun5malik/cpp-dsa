#include<iostream>
#include<list>
#include<iterator>
#include<vector>
using namespace std;

void print(list<int> ll){
    list<int>::iterator itr;
    for(itr=ll.begin();itr!=ll.end();itr++){
        cout<<(*itr)<<"->";
    }
    cout<<"NULL\n";
}

int main(){
    list<int> ll;
    
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.push_back(4);
    ll.push_back(5);
    
    print(ll);
    cout<<ll.size()<<endl;

    cout<<ll.front()<<endl;
    cout<<ll.back()<<endl;

    ll.pop_front();
    print(ll);

    ll.pop_back();
    print(ll);

    ll.insert(++ll.begin(),15);
    print(ll);

    ll.insert(++ll.begin(),2,30);
    print(ll);

    vector<int> n={202,45};
    ll.insert(ll.end(),n.begin(),n.end());
    print(ll);
    
    return 0;
}