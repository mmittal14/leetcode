class Solution {
public:
    int solve(string &s, int i, long long result, int sign){
        if(i>=s.size() || !isdigit(s[i])){
            return sign*result;
        }
        int digit=s[i]-'0';
        if(result>(INT_MAX-digit)/10){
            return (sign==1)? INT_MAX : INT_MIN;
        }
        return solve(s, i + 1, result * 10 + digit, sign);
    }
    int myAtoi(string s) {
        int i=0;
        int n=s.size();
        while(i<n && s[i]==' '){
            i++;
        }
        int sign=1;
        if(i<n && (s[i]=='+' || s[i]=='-')){
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        if (i >= n || !isdigit(s[i])) return 0;
        while(i<n && s[i]=='0'){
            i++;
        }
        return solve(s,i,0,sign);

    }
};