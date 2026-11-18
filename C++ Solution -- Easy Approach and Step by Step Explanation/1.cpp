class Solution {
  public:
    int findXOR(int l, int r) {
        // code here
        int ans1=0;

                for(int b=0;b<31 && (1LL<<b)<=l-1;b++){

                    int cyc=(1LL<<(b+1));

                    int full_cyc=( (l-1)/cyc);
                    int remaind=(l-1)%cyc;

                    int maxi=max(0LL, remaind-(1LL<<b) +1 );

                    int cur= full_cyc*(1LL<<b)+maxi;

                    if( cur&1){
                        ans1=ans1 | (1LL<<b);
                    }
                }

                int ans2=0;

                for(int b=0; b<31 && (1LL<<b) <=r ; b++ ){

                    int cyc=(1LL<<(b+1));

                    int full_cyc= r/cyc;
                    int remaind = (r%cyc);

                    int maxi=max(0LL, remaind - (1LL<<b) +1 );

                    int cur= (full_cyc)*(1LL<<b) + maxi;

                    if(cur&1){
                        ans2 = ans2 | (1LL<<b);
                    }
                }
                return ans1^ans2;
    }
};