class Solution {
public:
    void backtrack(string cur, int open, int close, int n, vector<string>& res){
        if(cur.length() == 2*n){
            res.push_back(cur);
            return;
        }
        if(open<n){
            backtrack(cur+'(',open+1,close,n,res);
        }
        if(close<open){
            backtrack(cur+')',open,close+1,n,res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack("",0,0,n,res);
        return res;
    }
};