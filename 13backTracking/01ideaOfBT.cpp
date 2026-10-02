#include<iostream>
#include<vector>
using namespace std;

int print(vector<int>& nums,int n){
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

void change(vector<int>& nums,int n,int i){
    if(i==n){
        print(nums,n);
        return;
    }

    nums[i]=i+1;
    change(nums,n,i+1);
    nums[i]-=2;//backtrack
}

int main(){
    vector<int> nums={0};
    int n=5;

    change(nums,n,0);
    print(nums,n);

    return 0;
}