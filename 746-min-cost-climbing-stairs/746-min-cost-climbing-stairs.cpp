class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=0;
        for(int i=2; i<=n; i++){
            int op1=dp[i-2]+cost[i-2],op2=dp[i-1]+cost[i-1];
            dp[i]=min(op1, op2);
        }
        return dp[n];
    }
};