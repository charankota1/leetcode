class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>res;
        int i=0,j=0;
        while(n>1 && m>1){
            for(int k=1;k<=m-1;k++){
                res.push_back(matrix[i][j]);
                j++;    
            }
            for(int k=1;k<=n-1;k++){
                res.push_back(matrix[i][j]);
                i++;
            }
            for(int k=1;k<=m-1;k++){
                res.push_back(matrix[i][j]);
                j--;
            }
            for(int k=1;k<=n-1;k++){
                res.push_back(matrix[i][j]);
                i--;
            }
            m-=2;
            n-=2;
            i++;j++;
        }
        if(m==n && n!=0) res.push_back(matrix[i][j]);
        else if(n==1){
            for(int k=0;k<m;k++){
                res.push_back(matrix[i][j]);
                j++;
            }
        }
        else if(m==1){
            for(int k=0;k<n;k++){
                res.push_back(matrix[i][j]);
                i++;
            }
        }
        return res;
    }
};