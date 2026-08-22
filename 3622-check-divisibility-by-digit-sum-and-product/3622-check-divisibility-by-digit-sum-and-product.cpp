class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        int sum = 0;
        int prod = 1;
        while(n>0){
            int digit = n%10;
            sum += digit;
            prod = prod * digit;
            n = n/10;
        }
        int total = sum + prod;
        if(temp%total==0){
            return true;
        }
        else{
            return false;
        }
    }
};