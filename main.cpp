#include "bits/stdc++.h"
using namespace std;

typedef struct node{
    int t;
    int value;
    node(int t,int value):t(t),value(value){}
};
bool cmp(node n1,node n2){
    return n1.value*n2.t>n1.t*n2.value;
}

int main()
{
    vector<node>v;
    int t,m;
    cin>>t>>m;
    int t_,v_;
    for (int i = 0; i < m; ++i) {
        cin>>t_>>v_;
        if(t_<t)
            v.push_back(node(t_,v_));
    }
    sort(v.begin(),v.end(), cmp);
    long long values=0;
    int len=0;
    int t_sum=0;

    while(t_sum!=t){
        if(t-t_sum < v.end()->t)
            break;
        values+=1ll*((t-t_sum)/v[len].t)*v[len].value;
        t_sum+=(t-t_sum)/v[len].t;
        for (; len < v.size(); ++len) {
            if(v[len].t < t-t_sum)break;
        }
        if(len==v.size())break;
    }
    cout<<values;
}

//#include<bits/stdc++.h>
//#define MAXN 3010
//#define N 310
//#define INF 0x3f3f3f3f
//
//using namespace std;
//
//int V,P,X[MAXN],dp[MAXN][N],w[MAXN][MAXN],d[MAXN][N];
//
//void init() {
//    for(int l=1;l<=V;l++) {
//        w[l][l]=0;
//        for(int r=l+1;r<=V;r++) {
//            w[l][r]=w[l][r-1]+X[r]-X[l+r>>1];
//        }
//    }
//}
//
//int main() {
//    cin>>V>>P;
//    for(int i=1;i<=V;i++) cin>>X[i];
//    init();
//    sort(X+1,X+V+1);
//    memset(dp,0x3f,sizeof(dp));
//    dp[0][0]=0;
//    for(int j=1;j<=P;j++) {
//        d[V+1][j]=V;
//        for(int i=V;i>=1;i--) {
//            int minn=INF,minid;
//            for(int k=d[i][j-1];k<=d[i+1][j];k++) {
//                if(dp[k][j-1]+w[k+1][i]<minn) {
//                    minn=dp[k][j-1]+w[k+1][i];
//                    minid=k;
//                }
//            }
//            dp[i][j]=minn;
//            d[i][j]=minid;
//        }
//    }
//
//    cout<<dp[V][P]<<endl;
//
//    return 0;
//}
//
//int main() {
//    std::cout << "Hello, World!" << std::endl;
//    return 0;
//}
//#include "bits/stdc++.h"
//using namespace std;
//int e[203];
//int dp[203][203];
//int main(){
//    int n;
//    int maxn=-1;
//    cin>>n;
//    for (int i = 1; i <=n; ++i) {
//        cin>>e[i];
//        e[i+n]=e[i];
//    }
//    for (int i = 1; i <2*n; ++i) {
//        for (int j = i-1; j >0&&i-j<n; j--) {
//            for (int k = j; k < i; ++k) {
//                dp[j][i]= max(dp[j][i],dp[j][k]+dp[k+1][i]+e[j]*e[k+1]*e[i+1]);
//            }
//            if(dp[j][i]>maxn)maxn=dp[j][i];
//        }
//    }
//    cout<<maxn;
//}








//#include<bits/stdc++.h>
//using namespace std;
//int n,e[300],s[300][300],maxn=-1;
//int main(){
//    cin>>n;
//    for(int i=1;i<=n;i++){cin>>e[i];e[i+n]=e[i];}
//    //珠子由环拆分为链，重复存储一遍
//    for(int i=2;i<2*n;i++){
//        for(int j=i-1;i-j<n&&j>=1;j--){//从i开始向前推
//            for(int k=j;k<i;k++)//k是项链的左右区间的划分点
//                s[j][i]=max(s[j][i],s[j][k]+s[k+1][i]+e[j]*e[k+1]*e[i+1]);
//            //状态转移方程：max(原来能量，左区间能量+右区间能量+合并后生成能量）
//            if(s[j][i]>maxn)maxn=s[j][i];//求最大值
//        }
//    }
//    cout<<maxn;
//    return 0;
//}