lass Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        map<int,int>mp;
        vector<pair<int,int>>v;
        vector<int>ans;
        for(auto i:arr) mp[i]++;
        for(auto i:mp){
            v.push_back({i.second,i.first});
        }
        sort(v.begin(),v.end(),[&](pair<int,int>&a,pair<int,int>&b){if(a.first==b.first)return a.second<b.second; return a.first>b.first;});
        for(auto i:v){
            int cnt=i.first;
            int num=i.second;
            while(cnt--){
                ans.push_back(num);
            }
        }
        return ans;
    }
};
