class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.length(),mod=1e9+7;
        vector<long long> sum(n+1,0),cnt(n+1,0),val(n+1,0);
        for(int i=1;i<=n;i++){
            int digit=s[i-1]-'0';
            sum[i]=(sum[i-1]+digit)%mod;
            cnt[i]=(cnt[i-1]+(digit!=0))%mod;
            if(!digit){
                val[i]=val[i-1];
            }
            else{
                val[i]=((val[i-1]*10)%mod+digit)%mod;
            }
        }
        vector<long long> pw(n+1,0);
        pw[0]=1;
        for(int i=1;i<pw.size();i++){
            pw[i]=(pw[i-1]*10)%mod;
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            long long l=queries[i][0],r=queries[i][1];
            long long len=cnt[r+1]-cnt[l];
            long long start=val[l];
            long long end=val[r+1];
            long long total=sum[r+1]-sum[l];
            total=(total+mod)%mod;
            long long x=(end-(start*pw[len])%mod+mod)%mod;
            long long num=(x*total)%mod;
            ans.push_back(num);
        }
        return ans;
    }
};