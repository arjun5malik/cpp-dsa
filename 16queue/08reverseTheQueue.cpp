#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reversedQueue(queue<int>& q){//TC:O(N) SC:O(N)
    stack<int> s;

    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

int main(){
    queue<int> q;

    for(int i=1;i<=5;i++){
        q.push(i);
    }

    reversedQueue(q);

    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }

    return 0;
}