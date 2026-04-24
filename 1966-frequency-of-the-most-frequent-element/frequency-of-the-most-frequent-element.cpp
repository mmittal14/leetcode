class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        if(nums.size()>=1 && nums.size()<=100000 && k>=1 && k<=100000){
            sort(nums.begin(),nums.end());
            long long left=0,ans=0;
            long long sum=0;
            for(int right=0;right<nums.size();right++){
                sum+=nums[right];
                while((long long)(nums[right]*(right-left+1)-sum)>k){
                    sum-=nums[left];
                    left ++;
                }
                ans=max(ans,right-left+1);
            }
            return ans;
        }
        return -1;
    }
};