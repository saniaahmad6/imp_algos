class Solution{
  public:
    int lcs(string s1,string  s2,int n){
        vector <vector <int>> dp (n+1,vector <int> (n+1,0));
        int ans=0,x=0,y=0;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
    int longestPalinSubseq(string s) {
        string s1=s;
        int n=s.size();
        reverse(s1.begin(),s1.end());
        
        return lcs(s,s1,n);
    }
};
