bool comp(Job a,Job b){
     return a.profit>b.profit;
}
int find(int num,vector<int>&parent){
    if(num==parent[num])
    return num;
    
    return parent[num]=find(parent[num],parent);
}
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,comp);
        int deadline=0;
        for(int i=0;i<n;i++){
            deadline=max(deadline,arr[i].dead);
        }
        vector<int> parent(deadline + 1);
        
        for(int i=0;i<=deadline;i++){
           parent[i]=i;
        }
        vector<int>ans(2,0);
        for(int i=0;i<n;i++){
         int slot=find(arr[i].dead,parent);
         if(slot>0){
             ans[0]++;
             ans[1]+=arr[i].profit;
             parent[slot]=slot-1;
         }
         }
        return ans;
    } 
};
