class Solution {
public:
    int countSubaraysWithAtmostKSum(vector<int>& nums, int k){
        if(k<0){
            return 0;
        }
        int n=nums.size();
        int left=0,count=0,sum=0;
        for(int right=0;right<n;right++){
            sum+=(nums[right]%2);
            while(sum>k){
                sum-=(nums[left]%2);
                left++;
            }
            count+=right-left+1;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return(countSubaraysWithAtmostKSum(nums,k)-countSubaraysWithAtmostKSum(nums,k-1));
    }
};