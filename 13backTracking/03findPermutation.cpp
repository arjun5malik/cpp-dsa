#include<iostream>
#include<string>
using namespace std;

void nextPermutation(string str,string ans){
    if(str.length()==0){
        cout<<ans<<endl;
        return;
    }
    int n=str.length();
    for(int i=0;i<str.length();i++){
      char ch=str[i];
      string nextString=str.substr(0,i)+str.substr(i+1,n-1);
      nextPermutation(nextString,ans+str[i]);
    }
}

int main(){
    string str="abc";
    string ans="";

    nextPermutation(str,ans);

    return 0;
}