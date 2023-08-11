class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        int n = s.length();
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        vector<pair<int,char>>v;
        for(auto x:mp){
            v.push_back(make_pair(x.second, x.first));
        }
        sort(v.begin(),v.end());
        string seq="";
        for(int i=v.size()-1;i>=0;i--){
            int freq = v[i].first;
            char ch = v[i].second;
            seq.append(freq, ch);
        }
        return seq;
    }
};