class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
           priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
        }
        for(int i=1;i<k;i++){
            pq.pop();
        }
        return pq.top();
    }
};
