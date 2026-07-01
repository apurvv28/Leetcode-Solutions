class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int maxScore = 0;
        int score = 0;
        sort(tokens.begin(),tokens.end());
        int i = 0;
        int j = n-1;
        while(i<=j){
            if(power>=tokens[i]){
                power -= tokens[i];
                score++;
                maxScore = max(maxScore,score);
                i++;
            }else if(score>=1){
                power += tokens[j];
                j--;
                score--;
            }else{
                return maxScore;
            }
        }
        return maxScore;
    }
};