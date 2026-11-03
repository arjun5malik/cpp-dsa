#include<iostream>
#include<stack>

using namespace std;

int main(){
    // STL stack
    stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    while(!s.empty()){
        cout<<s.top()<<" ";//1,2,3
        s.pop();
    }
    cout<<endl;

    return 0;
}

