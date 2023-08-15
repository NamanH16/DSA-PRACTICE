class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> ans;
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && asteroids[i]<0 && st.top()>0){
                int diff = asteroids[i]+st.top();
                if(diff>0){
                    asteroids[i]=0;
                }else if(diff<0){
                    st.pop();
                }else{
                    asteroids[i]=0;
                    st.pop();
                }
            }
            if(asteroids[i]!=0){
                st.push(asteroids[i]);                
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};