class Solution {
public:
    const int maxCost = 1000001;
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int> > > dp(m, vector<vector<int> > (target+1, vector<int> (n,maxCost)));
        for(int color=1; color<=n; color++){
            if(houses[0] == color){
                dp[0][1][color-1]=0;
            }
            else if(!houses[0]){
                dp[0][1][color-1]=cost[0][color-1];
            }
        }
        for(int house=1; house<m; house++){
            for(int neighbourhood=1; neighbourhood<=min(house+1, target); neighbourhood++){
                for(int color=1; color<=n; color++){
                    if(houses[house] && color!=houses[house]){
                        continue;
                    }
                    int currCost=maxCost;
                    for(int prevColor=1; prevColor<=n; prevColor++){
                        if(color == prevColor){
                            currCost=min(currCost, dp[house-1][neighbourhood][prevColor-1]);
                        }
                        else{
                            currCost=min(currCost, dp[house-1][neighbourhood-1][prevColor-1]);
                        }
                    }
                    int costToPaint=houses[house] ? 0 : cost[house][color-1];
                    dp[house][neighbourhood][color-1]=currCost + costToPaint;
                }
            }
        }
        int ans=maxCost;
        for(int color=1; color<=n; color++){
            ans=min(ans, dp[m-1][target][color-1]);
        }
        return ans == maxCost ? -1 : ans;
    }
};