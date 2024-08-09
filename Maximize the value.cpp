class Solution {
  public:
    int Maximize(vector<int> arr) {
         int n = arr.size();
        sort(arr.begin(), arr.end());
        long long ans = 0;
        long long mod = 1000000000 + 7;
        
        for (int i = 0; i < n; i++) {
            long long temp = (arr[i] * (long long)i) % mod;
            ans = (ans + temp) % mod;
        }
        
        return (int)ans;
    }
};
