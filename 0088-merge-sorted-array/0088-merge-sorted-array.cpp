class Solution {
public:
    void merge(vector<int>& n1, int m, vector<int>& n2, int n) {
        int *a = new int[m+n];
        int i=0, j=0,k=0;
        while(i<m && j<n){
            if(n1[i]<n2[j]){
                a[k]=n1[i];
                k++;i++;
            }else{
                a[k]=n2[j];
                k++;j++;
            }
        }
        while(i<m){
            a[k]=n1[i];
            k++;i++;
        }
        while(j<n){
            a[k]=n2[j];
            k++;j++;
        }
        for(int i=0;i<n1.size();i++){
            n1[i]=a[i];
        }
    }
};