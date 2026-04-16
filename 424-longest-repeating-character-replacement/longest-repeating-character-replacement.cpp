class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0,right=0;
        int maxLen=0,maxFreq=0;
        map<int,int> mp;
        int n=s.size();
        while(right<n){
            mp[s[right]-'A']++;
            maxFreq=max(maxFreq,mp[s[right]-'A']);
            if((right-left+1-maxFreq)>k){
                mp[s[left]-'A']--;
                left++;
            }
            if((right-left+1-maxFreq)<=k){
                maxLen=max(maxLen,right-left+1);
            }
            right++;
        }
        return maxLen;
    }
};