class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,-1);
        stack<int> s;
        for(int i=0;i<2*n-1;i++){
            int index=i%n;
            while(!s.empty() && nums[index]>nums[s.top()]){
                res[s.top()]=nums[index];
                s.pop();
            }
            if(i<n){
                s.push(index);
            }
        }
        return res;       
    }
};