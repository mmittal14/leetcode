class Solution {
public:
    int reverse(int x) {
        if (x <= INT_MIN || x >= (INT_MAX-1)){
            return 0;
        }
        int rev = 0;
        int sign = 1;
        if(x<0){
            sign = -1;
        }
        int r=0;
        x = abs(x);
        while (x > 0)
        {
            r = x % 10;
             if ((rev> INT_MAX / 10) || (rev < INT_MIN / 10)) 
                return 0;
            rev = (rev * 10) + r;
            x = x / 10;
        }
        rev= rev*sign;
        return rev;
    }
};