class Solution {
public:
//     int ans=0;
//     void help(int i,int j,int m,int n){
//         if(i<0 || j<0 || i>=m || j>=n){
//             return;
//         }
//         if(i==m-1 && j==n-1){
//             ans++;
//             return;
//         }
//         help(i+1,j,m,n);
//         help(i,j+1,m,n);
        
//     }
    int uniquePaths(int m, int n) {
        // int i=0,j=0;
        // help(i,j,m,n);
        // return ans;
        int dp[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0){
                    dp[i][j]=1;
                }
                else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};
