class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n=s.size();
        int ans=0;
        map<char,queue<string> > mp;
        for(auto &word : words){
            mp[word[0]].push(word);
        }
        // for(auto &pr : mp){
        //     auto st=pr.second;
        //     for(auto word : st){
        //         cout<<word<<" ";
        //     }
        //     cout<<"\n";
        // }
        for(auto c : s){
            if(mp.find(c) == mp.end()){
                continue;
            }
            auto &q = mp[c];
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto word = q.front();
                q.pop();
                reverse(word.begin(), word.end());
                word.pop_back();
                if(word.size() == 0){
                    ans++;
                }
                else{
                    reverse(word.begin(), word.end());
                    mp[word[0]].push(word);
                }
            }
            // for(auto &pr : mp){
            //     auto qu=pr.second;
            //     auto temp=qu;
            //     cout<<pr.first<<" ";
            //     while(!temp.empty()){
            //         cout<<temp.front()<<" ";
            //         temp.pop();
            //     }
            //     cout<<"\n";
            // }
        }
        return ans;
    }
};