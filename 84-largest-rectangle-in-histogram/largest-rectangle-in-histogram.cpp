class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea=0;
        int n=heights.size();
        int nse,pse,element;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){ //we getting nse
                element=heights[st.top()];
                st.pop();
                nse=i;
                pse=st.empty()?-1:st.top();
                maxArea=max(maxArea,(element*(nse-pse-1)));
            } 
            st.push(i);
        }
        while(!st.empty()){
            nse=n;
            element=heights[st.top()];
            st.pop();
            pse=st.empty()?-1:st.top();
            maxArea=max(maxArea,(nse-pse-1)*element);
        }
        return maxArea;
    }
};