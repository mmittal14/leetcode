class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        int minLen=INT_MAX;
        int cursum=0;
        for(int i=0;i<nums.size();i++){
            cursum+=nums[i];
            while(cursum>=target){
                minLen=min(minLen,i-l+1);
                cursum-=nums[l++];
            }
        }
        if(minLen==INT_MAX){
            return 0;
        }
        return minLen;
    }
};