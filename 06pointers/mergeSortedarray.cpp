#include<iostream>
#include<vector>
using namespace std;
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int i=m-1;
       int j=n-1;
       int idx=m+n-1;
       
       while(i>=0 && j>=0){
        if(nums1[i]>=nums2[j]){
            nums1[idx]=nums1[i];
            i--;
            idx--;
        }else{
            nums1[idx]=nums2[j];
            j--;
            idx--;
        }
       }

       while(j>=0){
        nums1[idx]=nums2[j];
        j--;
        idx--;
       }
    }

int main(){
    vector<int> nums1={1,2,3,0,0,0};
    vector<int> nums2={2,5,6};
    
    merge(nums1,3,nums2,3);

    for(int i=0;i<nums1.size();i++){
        cout<<nums1[i]<<" ";
    }

    return 0;
}    