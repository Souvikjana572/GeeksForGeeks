// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        int n=nums.size();
        long long int left=1,right=1;
         vector<long long int>lefti(n,1);
         vector<long long int>righti(n,1);
         vector<long long int>ans;
         for(int i=1;i<n;i++){
             left*=nums[i-1];
             lefti[i]=left;
         }
         for(int i=n-2;i>=0;i--){
             right*=nums[i+1];
             righti[i]=right;
         }
         for(int i=0;i<n;i++){
             ans.push_back(righti[i]*lefti[i]);
         }
         return ans;
    }
};
