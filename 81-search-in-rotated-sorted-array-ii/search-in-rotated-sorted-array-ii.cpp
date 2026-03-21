class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        int mid=0;
        while(left<=right){
            mid=left+((right-left)/2);
            if(nums[mid]==target){
                return true;
            }
            else if(nums[mid]==nums[left] && nums[mid]==nums[right]){
                left++;
                right--;
            }
            //left side is sorted
            else if(nums[left]<=nums[mid]){
                if(target<nums[mid] && target>=nums[left]){
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
            //right side is sorted
            else{
                if(target>nums[mid] && target<=nums[right]){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
        }
        return false;
    }
};