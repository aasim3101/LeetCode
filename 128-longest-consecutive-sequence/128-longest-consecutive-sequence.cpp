class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n == 0){
            return 0;
        }
        unordered_set<int> st;
        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }
        int ans=1;
        for(int i=0; i<n; i++){
            if(st.find(nums[i] - 1) != st.end()){
                continue;
            }
            int curr_ans=0;
            int num=nums[i];
            while(st.find(num) != st.end()){
                curr_ans++;
                num++;
            }
            ans=max(ans, curr_ans);
        }
        return ans;
    }
};