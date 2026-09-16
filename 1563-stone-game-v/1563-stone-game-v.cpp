class Solution {
public:
    int dp[501][501];
    int rs(int s,int e,vector<int>&ps){
        if(s>=e)return 0;
        int res=0;
        if(dp[s][e] != -1) return dp[s][e];
        for(int i=s;i<e;i++){
            int ls=ps[i]-(s>0 ? ps[s-1] : 0);
            int ris=ps[e]-ps[i];
            if(ls>ris){
                res=max(res, ris+rs(i+1,e,ps));
            }
            else if(ris>ls){
                res=max(res,ls+rs(s,i,ps));
            }
            else res=max({res,ris+rs(i+1,e,ps),ris+rs(s,i,ps)});
        }
        return dp[s][e] = res;
    }
    int stoneGameV(vector<int>& stoneValue) {
        memset(dp, -1, sizeof(dp));
        int n=stoneValue.size();
        vector<int>ps(n);
        ps[0]=stoneValue[0];
        for(int i=1;i<n;i++){
            ps[i]=ps[i-1]+stoneValue[i];
        }
        int ans=rs(0,n-1,ps);
        return ans;
    }
};