class Solution {
  public:
    vector<int> findPairs(vector<int>& arr) {
       vector<int>ans={-1,-1,-1,-1};
        unordered_map<int,pair<int,int>>m;
        int n=arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sum=arr[i]+arr[j];
                if(m.find(sum)!=m.end()){
                    vector<int>temp;
                    if(m[sum].first!=i&&m[sum].second!=j&&m[sum].first!=j&&m[sum].second!=i)temp={m[sum].first,m[sum].second,i,j};
                    if(temp.size()!=0){
                        if(ans[0]==-1||ans>temp)ans=temp;
                    }
                }
                else m[sum]={i,j};
            }
        }
        return ans;
    }
};