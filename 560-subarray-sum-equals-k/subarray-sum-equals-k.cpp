class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //sort(nums.begin(),nums.end());
        map<int,int> mp;
        mp[0]=1;
        int count=0,preSum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            preSum+=nums[i];
            int remove =preSum-k;
            count+=mp[remove];
            mp[preSum]+=1;
        }
        return count;
    }
};