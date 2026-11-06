#include<iostream>
#include<stack>
#include<string>
using namespace std;

string reverseString(string s){// TC:O(N) & SC:O(N)
    string ans;
    stack<char> str;

    for(int i=0;i<s.size();i++){
        str.push(s[i]);
    }

    while(!str.empty()){
        char top = str.top();
        ans+=top;
        str.pop();
    }

    return ans;
}

int main(){
    string s="ARJUN";

    cout<<reverseString(s)<<"\n";

    return 0;
}
