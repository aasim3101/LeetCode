class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n == 0){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int ans=1;
        int i=0;
        while(i < n){
            int j=i+1;
            int curr_ans=1;
            while(j<n && nums[j]-nums[j-1]<=1){
                if(nums[j]-nums[j-1] == 1){
                    curr_ans++;
                }
                j++;
            }
            ans=max(ans, curr_ans);
            i=j;
        }
        return ans;
    }
};