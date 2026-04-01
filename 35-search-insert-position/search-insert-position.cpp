class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1,mid,pos=-1;
        while(left<=right){
            mid=left+(right-left)/2;
            if(target==nums[mid]){
                pos=mid;
                break;
            }
            else if(target>nums[mid]){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        if(pos==-1){
            return left;
        }
        return pos;
    }
};