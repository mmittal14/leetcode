class Solution {
public:
    int count(vector<int>& nums,int k){ //helper funtion
        int left=0,count=0;
        map<int,int> mpp;
        for(int right=0;right<nums.size();right++){
            mpp[nums[right]]++;
            while(mpp.size()>k){
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0){
                    mpp.erase(nums[left]);
                }
                left++;
            }
            count+=right-left+1;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return (count(nums,k)-count(nums,k-1));
    }
};