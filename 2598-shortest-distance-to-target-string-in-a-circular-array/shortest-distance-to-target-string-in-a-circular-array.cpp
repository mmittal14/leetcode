class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        if(words[startIndex]==target){
            return 0;
        }
        int n=words.size();
        int steps=0;
        int l=startIndex,r=startIndex;
        int ll=0,rl=0;
        while(steps<(n/2)){
            l=(l+1)%n;
            ll++;
            r=(r-1+n)%n;
            rl++;
            steps++;
            if(words[l]==target){
                break;
            }
            if(words[r]==target){
                break;
            }
        }
        if(words[l]==target || words[r]==target){
            return (min(ll,rl));
        }
        return -1;
    }
};