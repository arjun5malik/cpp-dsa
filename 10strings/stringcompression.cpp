#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    vector<char> chars={'a','a','b','b','c','c','c'};
    int idx=0;
    int n=chars.size();
    for(int i=0;i<n;i++){
        char ch=chars[i];
        int count=0;
        while(i<n && chars[i]==ch){
            count++;
            i++;
        }
        if(count==1){
            chars[idx++]=ch;
        }else{
            chars[idx++]=ch;
            string str=to_string(count);
            for(char dig:str){
                chars[idx++]=dig;
            }
        }
        i--;
    }
    chars.resize(idx);
    cout<<idx;

    return 0;
}