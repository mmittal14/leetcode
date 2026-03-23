class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int maxSum=nums[0], currentMaxSum=nums[0];
        for(int i=1; i<size; i++){
            if(nums[i] <= 10000 && nums[i] >= -10000){
                maxSum = max(nums[i], maxSum + nums[i]);
                currentMaxSum = max(currentMaxSum, maxSum);
            }
        }
        return currentMaxSum;
    }
};