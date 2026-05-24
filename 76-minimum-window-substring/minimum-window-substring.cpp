class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, right = 0, minLen = INT_MAX, sInd = -1, count = 0;
        vector<int> hash(58, 0);
        for (int i = 0; i < t.size(); i++) {
            hash[t[i] - 'A']++;
        }
        while (right < s.size()) {
            if (hash[s[right] - 'A'] > 0) {
                count++;
            }
            hash[s[right] - 'A']--;
            while (count == t.size()) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    sInd = left;
                }
                hash[s[left] - 'A']++;
                if (hash[s[left] - 'A'] > 0) {
                    count--;
                }
                left++;
            }
            right++;
        }
        return (sInd == -1) ? "" : s.substr(sInd, minLen);
    }
};