#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isMatch(const string A, const string B) {
    int la = A.length();
    int lb = B.length();
    vector<vector<int> > dp(la + 1, vector<int>(lb + 1, 0));
    for(int i = 0 ; i < la + 1 ; i++) {
        for(int j = 0 ; j < lb + 1 ; j++) {
            if(i == 0 && j == 0) {
                dp[i][j] = 1;
            }else if(j == 0) {
                dp[i][j] = 0;
            }else if(i == 0) {
                if(B[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2];
                }
            }else {
                if(A[i - 1] == B[j - 1] || B[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }else if(B[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2];
                    if(A[i - 1] == B[j - 2] || B[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }else {
                    dp[i][j] = 0;
                }
            }
        }
    }
    return dp[la][lb];
}

};

int main(){
   string s,p;
   cin>>s>>p;
   Solution x;
   cout<<x.isMatch(s,p)<<endl;
}
