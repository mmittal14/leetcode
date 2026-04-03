class Solution {
public:
    vector<int> NSE(vector<int>& arr){
        int n=arr.size();
        stack<int> s;
        vector<int> res(n,n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>=arr[i]){
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
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse=NSE(arr);
        vector<int> pse=PSE(arr);
        int sum=0,mod=(int)(1e9+7);
        for(int i=0;i<arr.size();i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            sum=(sum+(right*left*1ll*arr[i])%mod)%mod;
        }
        return sum;
    }
};