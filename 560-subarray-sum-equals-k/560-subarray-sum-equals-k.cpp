class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mp;
        mp[0] = 1;
        int prefixSum = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            prefixSum += nums[i];
            ans += mp[prefixSum - k];
            mp[prefixSum]++;
        }
        return ans;
    }
};