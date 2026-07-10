class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int gsize=g.size();
        int ssize=s.size();
        int gptr=0,sptr=0;
        while(gptr<gsize && sptr<ssize){
            if(s[sptr]>=g[gptr]){
                gptr++;
            }
            sptr++;
        }
        return gptr;
    }
};