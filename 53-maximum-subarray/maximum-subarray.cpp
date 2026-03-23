class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int maxSum=nums[0], currentMaxSum=nums[0];
        for(int i=1; i<size; i++){
            maxSum = max(nums[i], maxSum + nums[i]);
            currentMaxSum = max(currentMaxSum, maxSum);   
        }
        return currentMaxSum;
    }
};