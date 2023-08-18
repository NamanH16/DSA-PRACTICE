class Solution {
private:
    vector<int> nextSmallerElements(vector<int>& heights, int n){
        vector<int> v(n, -1);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                v[i]=st.top();
            }
            st.push(i);
        }
        return v;
    }
    
    vector<int> prevSmallerElements(vector<int>& heights, int n){
        vector<int> v(n, -1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                v[i]=st.top();
            }
            st.push(i);
        }
        return v;
    }
    
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next(n);
        next= nextSmallerElements(heights,n);
        vector<int> prev(n);
        prev = prevSmallerElements(heights,n);
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            if(next[i]==-1){
                next[i]=n;
            }
            ans = max(ans, heights[i]*(next[i]-prev[i]-1));
        }
        return ans;
    }
};