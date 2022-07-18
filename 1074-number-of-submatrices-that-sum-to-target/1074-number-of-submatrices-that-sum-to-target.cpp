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
        for(int colStart=0; colStart<m; colStart++){
            for(int colEnd=colStart; colEnd<m; colEnd++){
                for(int rowStart=0; rowStart<n; rowStart++){
                    int sum = 0;
                    for(int rowEnd=rowStart; rowEnd<n; rowEnd++){
                        sum += matrix[rowEnd][colEnd] - (colStart ? matrix[rowEnd][colStart-1] : 0);
                        if(sum == target){
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};