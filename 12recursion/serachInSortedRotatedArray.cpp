#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums,int t,int start,int end){
    if(start>end) return -1;

    int mid=start+(end-start)/2; 
    if(nums[mid]==t) return mid;
    if(nums[start]<=nums[mid]){//LINE 1
        if(nums[start]<=t && t<=nums[mid]){//LEFT
            search(nums,t,start,mid-1);
        }else{//RIGHT
            search(nums,t,mid+1,end);
        }
    }else{//LINE 2
        if(nums[mid]<=t && t<=nums[end]){//RIGHT
            search(nums,t,mid+1,end);
        }else{//LEFT
            search(nums,t,start,mid-1);
        }
    }
}

int main(){
    vector<int> nums={4,5,6,7,0,1,2};
    int n=nums.size();
    int target=0;

    search(nums,target,0,n-1);

    return 0;
}