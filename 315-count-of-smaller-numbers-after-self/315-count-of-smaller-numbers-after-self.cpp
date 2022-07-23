class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<pair<int,int> > v;
        for(int i=0; i<n; i++){
            v.push_back({nums[i], i});
        }
        mergeSort(0, n-1, v, ans);
        return ans;
    }
    void mergeSort(int l, int r, vector<pair<int,int> > &v, vector<int> &ans){
        if(l == r){
            return;
        }
        int mid=(l+r)/2;
        mergeSort(l, mid, v, ans);
        mergeSort(mid+1, r, v, ans);
        merge(l,r,mid,v, ans);
    }
    void merge(int l, int r, int mid, vector<pair<int,int> > &v, vector<int> &ans){
        vector<pair<int,int> > temp;
        int i=l,j=mid+1;
        while(i <= mid && j <= r){
            if(v[i].first > v[j].first){
                ans[v[i].second]+=r-j+1;
                temp.push_back({v[i].first,v[i].second});
                i++;
            }
            else{
                temp.push_back({v[j].first, v[j].second});
                j++;
            }
        }
        while(i <= mid){
            temp.push_back({v[i].first, v[i].second});
            i++;
        }
        while(j <= r){
            temp.push_back({v[j].first, v[j].second});
            j++;
        }
        for(int i=l; i<=r; i++){
            v[i]=temp[i-l];
        }
        // for(auto pr : v){
        //     cout<<pr.first<<" "<<pr.second<<"\n";
        // }
        // cout<<"\n";
    }
};