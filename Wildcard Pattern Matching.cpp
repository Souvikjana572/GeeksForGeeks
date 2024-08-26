class Solution {
  public:
    /*You are required to complete this method*/
     bool f(int i,int j,string pat,string str,vector<vector<int>>&dp){
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(i>=0 && j<0){
            for(int k=0;k<=i;k++){
                if(pat[k]!='*') return false;
            }
            return true;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(pat[i]==str[j] || pat[i]=='?'){
            return dp[i][j]= f(i-1,j-1,pat,str,dp);
        }
        if(pat[i]=='*'){
            return dp[i][j]= f(i,j-1,pat,str,dp)|| f(i-1,j,pat,str,dp);
        }
    }
    int wildCard(string pattern, string str) {
           int n=pattern.length();
        int m=str.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,pattern,str,dp);
    }
};
