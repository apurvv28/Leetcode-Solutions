class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>t(amount+1,amount+1);
        int count = 0;
        t[0]=0;

        for(int i=0;i<=amount;i++)
        {
            for(int c:coins)
            {
                if(c<=i)
                {
                    t[i]=min(t[i-c]+1,t[i]);
                }
            }
        }

        return t[amount]>amount?-1:t[amount];
    }
};