class Solution {
public:
    int fib(int n) {
        if(n == 0){
            return 0;
        }
        int last=1;
        int lastToLast=0;
        int ans=1;
        for(int i=2; i<=n; i++){
            ans=last+lastToLast;
            lastToLast=last;
            last=ans;
        }
        return ans;
    }
};