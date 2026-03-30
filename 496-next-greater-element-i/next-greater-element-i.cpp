class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        vector<int> res;
        unordered_map<int,int> mp;
        for(int i=0;i<nums2.size();i++){
            int current=nums2[i];
            mp[current]=-1;
            while(!s.empty() && current>s.top()){
                mp[s.top()]=current;
                s.pop();
            }
            s.push(current);
        }
        for(int i=0;i<nums1.size();i++){
            res.push_back(mp[nums1[i]]);
        }
        return res;
    }
};