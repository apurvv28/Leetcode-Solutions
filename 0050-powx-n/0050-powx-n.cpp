class Solution {
public:
    double myPow(double x, int n){
        if(n==0)
        {
            return 1;
        }
        if(n==1)
        {
            return x;
        }
        long long N=n;
        if(N<0){
            x = 1/x;
            N = abs((long long)n);
        }
        double half = myPow(x,N/2); 
        if((int)N % 2 != 0){
            return x * (half*half);
        }
        return half*half;
    }
};