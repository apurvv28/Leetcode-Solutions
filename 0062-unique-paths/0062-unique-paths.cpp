class Solution {
public:
    int uniquePaths(int m, int n) {
        int t = n+m-2;
        int r = min(n,m)-1;
        double result = 1;
        for(int i=1;i<=r;++i,t--){
            result = (result * t)/i;
        }
        return (int)result;
    }
};