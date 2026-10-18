class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tg = 0;
        int tc = 0;
        int g = 0;
        int start = 0;
        for(int i = 0; i< n;i++){
            tg+=gas[i];
            tc+=cost[i];
            g+=gas[i]-cost[i];
            if(g<0){
                start=i+1;
                g=0;
            }
        }
        return (tg<tc)?-1:start;
    }
};