class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int c = 0;
        int left = 0;
        int right = n-1;
        sort(people.begin(),people.end());
        while(left<=right){
            if(people[right]+people[left]<=limit){
                left++;
            }
            right--;
            c++;
        }
        return c;
    }
};