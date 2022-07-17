class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<int> > dp(n+1, vector<int> (k+1));
        int mod=1000000007;
        for(int i=1; i<=n; i++){
            dp[i][0] = 1;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=k && j<=k; j++){
                int val = (dp[i-1][j] + mod - ((j - i >= 0) ? dp[i-1][j-i] : 0))%mod;
                dp[i][j] = (dp[i][j-1] + val)%mod;
            }
        }
        return (dp[n][k] + mod - ((k > 0) ? dp[n][k-1] : 0))%mod;
    }
};