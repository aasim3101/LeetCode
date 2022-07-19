class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > ans;
        vector<int> v;
        v.push_back(1);
        ans.push_back(v);
        for(int row=1; row<numRows; row++){
            vector<int> temp;
            for(int i=0; i<=row; i++){
                if(i == 0){
                    temp.push_back(ans[row-1][i]);
                }
                else if(i == row){
                    temp.push_back(ans[row-1][i-1]);
                }
                else{
                    temp.push_back(ans[row-1][i-1]+ans[row-1][i]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};