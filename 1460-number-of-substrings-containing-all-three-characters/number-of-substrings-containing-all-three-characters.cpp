class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastSeen(3,-1);
        int minimum=-1;
        int count=0;
        for(int i=0;i<s.size();i++){
            lastSeen[s[i]-'a']=i;
            if(lastSeen[0]!=-1&&lastSeen[1]!=-1&&lastSeen[2]!=-1){
                minimum=min(lastSeen[0],lastSeen[1]);
                minimum=min(lastSeen[2],minimum);
                count+=(1+minimum);
            }
        }
        return count;
    }
};