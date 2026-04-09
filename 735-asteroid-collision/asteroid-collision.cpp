class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        list<int> lt;
        vector<int> res;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]>0){
                lt.push_back(asteroids[i]);
            }
            else{
                while(!lt.empty()&&lt.back()>0&&lt.back()<abs(asteroids[i])){
                    lt.pop_back();
                }
                if(!lt.empty()&&lt.back()==abs(asteroids[i])){
                    lt.pop_back();
                }
                else if(lt.empty()||lt.back()<0){
                    lt.push_back(asteroids[i]);
                }
            }
        }
        while(!lt.empty()){
            res.push_back(lt.front());
            lt.pop_front();
        }
        return res;
    }
};