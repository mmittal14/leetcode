class Solution {
public:
    int count(vector<int>& nums, int goal){
        if(goal<0){
            return 0;
        }
        int left=0,right=0;
        int n=nums.size();
        int count=0,sum=0;
        while(right<n){
            sum+=nums[right];
            while(sum>goal){
                sum-=nums[left];
                left++;
            }
            count+=right-left+1;
            right++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return(count(nums,goal)-count(nums,goal-1));
    }
};