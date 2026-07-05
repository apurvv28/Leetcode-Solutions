class Solution {
public:
    pair<int,int> func(int i,int j,vector<string> &board,vector<vector<pair<int,int>>> &dp){
        int mod=1e9+7;
        if(i<0 || j<0) return {-1e9,0};
        if(board[i][j]=='X') return {-1e9,0};
        if(i==0 && j==0) return {0,1};
        if(dp[i][j].first!=-1) return dp[i][j];
        pair<int,int> up=func(i-1,j,board,dp);
        pair<int,int> left=func(i,j-1,board,dp);
        pair<int,int> diag=func(i-1,j-1,board,dp);
        int cost=max({up.first,left.first,diag.first});
        int paths=0;
        if(cost==up.first) paths=(paths+up.second)%mod;
        if(cost==left.first) paths=(paths+left.second)%mod;
        if(cost==diag.first) paths=(paths+diag.second)%mod;
        int cur_val=0;
        if(board[i][j]!='S' && board[i][j]!='E') cur_val+=(board[i][j]-'0');
        return dp[i][j]={cost+cur_val,paths};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n,{-1,-1}));
        pair<int,int> result=func(n-1,n-1,board,dp);
        if(result.first<0) return {0,0};
        return {result.first,result.second};
    }
};