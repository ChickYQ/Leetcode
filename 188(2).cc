#include<vector>
#include<array>
#include<iostream>
using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& v) {
        int n=v.size();
        if(n==0) return 0;
        int f[1005][1005]={0}, g[1005];
        g[0]=-v[0];
        for(int j=1;j<=n;j++) g[j]=-0x3f3f3f3f;

        int ans=0;
        for(int i=2;i<=n;i++) {
            f[i][0]=0;
            for(int j=1;j<=i/2;j++) {
                f[i][j]=f[i-1][j];
                f[i][j]=max(f[i][j],g[j-1]+v[i-1]);
                if(j<=k) ans=max(ans,f[i][j]);
            }
            for(int j=0;j<=(i-1)/2;j++) {
                g[j]=max(g[j],f[i-1][j]-v[i-1]);
            }

            /*printf("%d\n",i);
            for(int i=0;i<=n;i++) {
                printf("%d ",g[i]);
            }
            printf("\n");*/
        }

        /*for(int i=0;i<=n;i++) {
            for(int j=0;j<=n;j++) printf("%d ", f[i][j]);
            printf("\n");
        }

        for(int i=0;i<=n;i++) {
            printf("%d ",g[i]);
        }
        printf("\n");*/

        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> prices{3,3,5,0,0,3,1,4};
    cout << solution.maxProfit(2, prices) << endl;

    return 0;
}