class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size();
        if (n == 0) return 0;
        
        int low = 0, high = n;
        
        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = n - cut1;
            int L1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
            int L2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
            int R1 = (cut1 == n) ? INT_MAX : arr1[cut1];
            int R2 = (cut2 == n) ? INT_MAX : arr2[cut2];
            
            if (L1 <= R2 && L2 <= R1) {
                return max(L1, L2) + min(R1, R2);
            } else if (L1 > R2) {
               
                high = cut1 - 1;
            } else {
                
                low = cut1 + 1;
            }
        }
        return 0;  
    }
};
