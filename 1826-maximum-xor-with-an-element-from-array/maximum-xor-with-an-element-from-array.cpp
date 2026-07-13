class Node{
public:
    Node* links[2];
    Node(){
        links[0]=links[1]=nullptr;
    }
    bool containsKey(int bit){
        return links[bit]!=nullptr;
    }
    void put(int bit, Node* node){
        links[bit]=node;
    }
    Node* get(int bit){
        return links[bit];
    }
};
class Trie{
private:
    Node* root;
public:
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    int getMax(int num){
        Node* node=root;
        int maxi=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->containsKey(1-bit)){
                maxi |=(1<<i);
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return maxi;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
         vector<pair<int,pair<int,int>>> off;
         int n=nums.size();
         int  q=queries.size();
         for(int i=0;i<q;i++){
            off.push_back({queries[i][1],{queries[i][0],i}});

        }
        sort(off.begin(),off.end());
        vector<int> ans(q,0);
        int ind=0;
        Trie trie;
        for(int i=0;i<q;i++){
            int ai=off[i].first;
            int xi=off[i].second.first;
            int qInd=off[i].second.second;
            while(ind<n && nums[ind]<=ai){
                trie.insert(nums[ind++]);
            }
            if(ind==0){
                ans[qInd]=-1;
            }
            else{
                ans[qInd]=trie.getMax(xi);
            }
        }
        return ans;
    }
};