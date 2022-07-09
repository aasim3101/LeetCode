class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> dp(n);
        dp[0]=nums[0];
        multiset<int> st;
        st.insert(nums[0]);
        for(int i=1; i<n; i++){
            auto it=st.end();
            it--;
            int mx=*(it);
            dp[i]=nums[i]+mx;
            st.insert(dp[i]);
            if((i-k) >= 0){
                int ele=dp[i-k];
                st.erase(st.find(ele));
            }
        }
        return dp[n-1];
    }
};