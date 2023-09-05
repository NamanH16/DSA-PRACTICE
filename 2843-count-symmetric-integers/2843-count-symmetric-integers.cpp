class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int nas=0;
        for(int i=low;i<=high;i++){
            string x = to_string(i);
            if(x.length()==1)continue;
            int f=0, s=0;
            for(int j=0;j<x.length()/2;j++){
                f+=x[j]-'0';
                s+=x[x.length()-j-1]-'0';
            }
            if(x.length()%2==0 && f==s)nas++;
        }
        return nas;
    }
};