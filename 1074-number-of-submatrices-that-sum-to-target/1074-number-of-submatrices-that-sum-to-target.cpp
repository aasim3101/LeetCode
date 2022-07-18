class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=1; j<m; j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }
        int ans = 0;
        map<int,int> mp;
        for(int colStart=0; colStart<m; colStart++){
            for(int colEnd=colStart; colEnd<m; colEnd++){
                mp = {{0,1}};
                int currSum = 0;
                for(int row=0; row<n; row++){
                    currSum += matrix[row][colEnd] - (colStart ? matrix[row][colStart-1] : 0);
                    ans += mp[currSum - target];
                    mp[currSum]++;
                }
            }
        }
        return ans;
    }
};