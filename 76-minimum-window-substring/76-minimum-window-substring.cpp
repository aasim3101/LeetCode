class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size(),m=t.size();
        map<char,int> mpT;
        for(auto c : t){
            mpT[c]++;
        }
        map<char,int> mp;
        for(auto c : s){
            mp[c]++;
        }
        for(auto c : t){
            if(mp[c] < mpT[c]){
                return "";
            }
        }
        int mnLength=n;
        string ans=s;
        map<char,int> mpS;
        int matchCount=0;
        int i=0,j=0;
        while(i < n){
            while(matchCount != m && i < n){
                mpS[s[i]]++;
                if(mpS[s[i]] <= mpT[s[i]]){
                    matchCount++;
                }
                i++;
            }
            while(matchCount == m && j < n){
                if((i-j) <= mnLength){
                    mnLength=i-j;
                    ans=s.substr(j,(i-j));
                }
                mpS[s[j]]--;
                if(mpS[s[j]] < mpT[s[j]]){
                    matchCount--;
                }
                j++;
            }
        }
        return ans;
    }
};