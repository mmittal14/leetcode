class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> st;
        int left=0,maxLen=0;
        for(int right=0;right<s.size();right++){
            if(st.find(s[right])!=st.end()){
                left=max(left,st[s[right]]+1);
            }
            st[s[right]]=right;
            maxLen=max(maxLen,right-left+1);
        }
        return maxLen;
    }
};