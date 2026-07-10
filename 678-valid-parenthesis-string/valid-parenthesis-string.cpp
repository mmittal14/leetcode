class Solution {
public:
    bool checkValidString(string s) {
        int minp=0,maxp=0; //minp is min open brackets possible and maxp is max possible
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                minp++;
                maxp++;
            }
            else if(s[i]==')'){
                minp--;
                maxp--;
                minp=max(0,minp);
            }
            else if(s[i]=='*'){
                minp--;
                maxp++;
                minp=max(0,minp);
            }
            if(maxp<0){
                return false;
            }
        }
        return minp==0;
    }
};