class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count=0,prevEnd=intervals[0][1],n=intervals.size();
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=prevEnd){
                prevEnd=intervals[i][1];
            }
            else{
                count++;
                prevEnd=min(prevEnd,intervals[i][1]);
            }
        }
        return count;
    }
};