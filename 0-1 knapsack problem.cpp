class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
      vector<int>dp(W+1 , 0);
       for(int i=1; i<=n; i++){
           for(int j=W; j>=1; j--){
               if(wt[i-1]<=j)
               dp[j] = max(val[i-1] + dp[j-wt[i-1]] , dp[j]);
           }
       }
       return dp[W];
    }
};
