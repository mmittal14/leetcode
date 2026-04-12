class Solution {
public:
    vector<int> NSE(vector<int>& arr){ //next smallest element
        int n=arr.size();
        stack<int> s;
        vector<int> res(n,n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>=arr[i]){ //equal to is important because of duplicate values
                s.pop();
            }
            if(!s.empty()){
                res[i] = s.top();
            }
            s.push(i);
        }
        return res;
    }
    vector<int> PSE(vector<int>& arr){
        int n=arr.size();
        stack<int> s;
        vector<int> res(n,-1);
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[i]<arr[s.top()]){  
                s.pop();
            }
            if(!s.empty()){
                res[i] = s.top();
            }
            s.push(i);
        }
        return res;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse=NSE(heights);
        vector<int> pse=PSE(heights);
        int mx=0;
        for(int i=0;i<heights.size();i++){
            mx=max(mx,(heights[i]*(nse[i]-pse[i]-1)));
        }
        return mx;
    }
};