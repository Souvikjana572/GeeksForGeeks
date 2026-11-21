class Solution {
  public:
    void sortIt(vector<int>& arr) {
       int l = 0;
               int n = arr.size();
               for(int i=0;i<n;i++)if(arr[i]%2)swap(arr[i],arr[l++]);
               sort(arr.begin(),arr.begin()+l,greater<int>());
               sort(arr.begin()+l,arr.end());
               return;
    }
};