class Solution {
public:
    vector<int> NSE(vector<int>& arr){ //next smallest element
        int n=arr.size();
        stack<int> s;
        vector<int> res(n,n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>=arr[i]){ //equal to is important 
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
    vector<int> NGE(vector<int>& arr){
        int n=arr.size();
        stack<int> s;
        vector<int> res(n,n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]<=arr[i]){ //equal to is important 
                s.pop();
            }
            if(!s.empty()){
                res[i] = s.top();
            }
            s.push(i);
        }
        return res;
    }
    vector<int> PGE(vector<int>& arr){
        int n=arr.size();
        stack<int> s;
        vector<int> res(n,-1);
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[i]>arr[s.top()]){  
                s.pop();
            }
            if(!s.empty()){
                res[i] = s.top();
            }
            s.push(i);
        }
        return res;
    }
    long long sumSubarrayMins(vector<int>& arr) {
        vector<int> nse=NSE(arr);
        vector<int> pse=PSE(arr);
        long long sum=0;
        for(int i=0;i<arr.size();i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            sum+=right*left*1ll*arr[i];
        }
        return sum;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        vector<int> nge=NGE(arr);
        vector<int> pge=PGE(arr);
        long long sum=0;
        for(int i=0;i<arr.size();i++){
            int left=i-pge[i];
            int right=nge[i]-i;
            sum+=right*left*1ll*arr[i];
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums)-sumSubarrayMins(nums);
    }
};