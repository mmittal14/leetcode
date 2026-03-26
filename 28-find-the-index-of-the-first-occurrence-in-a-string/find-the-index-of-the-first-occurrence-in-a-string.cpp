class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = -1;
        int count = 0;
        for (int i = 0; i < haystack.length(); i++) {
            count = 0;
            if (haystack[i] == needle[0]) {
                count++;
                if (i + needle.length() - 1 < haystack.length()) {
                    for (int j = 1; j < needle.length(); j++) {
                        if (haystack[i + j] == needle[j]) {
                            count++;
                        }
                    }
                }
                if (count == needle.length()) {
                    index = i;
                    break;
                }
            }
        }
        return index;
    }
};