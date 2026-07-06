#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthofans(vector<int>& nums){
        vector<int> ans;
        for (int i =0;i<nums.size();i++){
            
            int left=0;
            int right= ans.size();

            while (left <right) {
                int mid = left +(right-left)/2;

                if(ans[mid]<nums[i]){
                    left =mid +1;
                }else{
                    right=mid;
                }
            }

    if(left==ans.size()){
         ans.push_back(nums[i]);
      }else{
      ans[left]=nums[i];
         }       
    }
     return ans.size();
}
};

int main(){

    Solution obj;
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i=0;i<n;i++)
        cin >>nums[i];

    cout<<obj.lengthofans(nums);

    return 0;
}
