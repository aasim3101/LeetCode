class Solution {
public:
    bool helper(int ind, vector<int>& matchsticks, int sum, int n, vector<int> &length){
        if(ind == n){
            return length[0] == length[1] && length[1] == length[2] && length[2] == length[3];
        }
        for(int i=0; i<4; i++){
            if(length[i] + matchsticks[ind] <= sum/4){
                length[i]+=matchsticks[ind];
                if(helper(ind+1, matchsticks, sum, n, length)){
                    return true;
                }
                length[i]-=matchsticks[ind];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int n=matchsticks.size();
        vector<int> length(4);
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=matchsticks[i];
        }
        if(sum%4){
            return false;
        }
        return helper(0, matchsticks, sum, n, length);
    }
};