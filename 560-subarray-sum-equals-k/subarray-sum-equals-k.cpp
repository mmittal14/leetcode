class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //sort(nums.begin(),nums.end());
        int sum=0;
        int count=0,i=0;
        int n=nums.size();
        for(int j=0;j<n;j++){
            i=j;
            sum=0;
            while(i<n){
                sum=sum+nums[i];
                if(sum==k){
                    count++;
                }
                i++;
            }
        }
        return count;
    }
};