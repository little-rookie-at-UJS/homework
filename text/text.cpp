//#include <iostream>
//#include <stdio.h>
//#include <string.h>
//#define ll long long
//using namespace std;
//const int Mod = 1e9+7;
//ll dp[100010];
//int main(){
//    int p[15] = {1,2,5,10,20,50,100,200,500,1000,2000,5000,10000};
//    int n;
//    cin>>n;
//        memset(dp,0,sizeof(dp));
//        dp[0] = 1;
//        for(int i = 0; i < 13; i ++){
//            for(int j = p[i]; j <= n; j ++){
//                dp[j] = (dp[j]+dp[j-p[i]])%Mod;
//            }
//        }
//        printf("%lld\n",dp[n]);
//
//    return 0;
//}


//#include <iostream>
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#define int long long
//#define eps 1e-10
//
//using namespace std;
//
//const int N=5e5+5;
//int w[N],v[N],f[N],n,m,ans;
//
//inline int read(){
//    int x=0,f=1;
//    char ch=getchar();
//    while(ch<'0' || ch>'9'){
//        if(ch=='-')
//            f=-1;
//        ch=getchar();
//    }
//    while(ch>='0' && ch<='9'){
//        x=(x<<3)+(x<<1)+ch-'0';
//        ch=getchar();
//    }
//    return x*f;
//}
//
//inline bool check(int x){
//    memset(f,0,sizeof(f));
//    for(int i=1;i<=n;i++){
//        int l=1,r=x,mid;
//        while(l<=r){
//            mid=(l+r)>>1;
//            if(f[mid]<=f[mid-1])
//                l=mid+1;
//            else
//                r=mid-1;
//        }
//        for(int j=l;j<=x;j++){
//            if(j-w[i]>=0)
//                f[j]=max(f[j],f[j-w[i]]+v[i]);
//        }
//    }
//    return f[x]>=m;
//}
//
//signed main(){
//    n=read(),m=read();
//    for(int i=1;i<=n;i++){
//        w[i]=read(),v[i]=read();
//    }
//    int l=1,r=n*10000,mid;
//    while(l<=r){
//        mid=(l+r)>>1;
//        if(check(mid)){
//            ans=mid;
//            r=mid-1;
//        }
//        else
//            l=mid+1;
//    }
//    printf("%lld\n",ans);
//    return 0;
//}





//导入万能头
//#include "bits/stdc++.h"
//using namespace std;
//
//int dp[1000000];
//
////01背包问题
//int main(){
////    输入物品个数和背包容量
//    int n,w;
//    cin>>n>>w;
////    定义物品重量和价值
//    vector<int> v(n+1);
//    vector<int> c(n+1);
////    输入物品重量和价值
//    for (int i = 0; i < n; ++i) {
//        cin>>v[i];
//        cin>>c[i];
//    }
////    初始化dp数组
//    for (int i = 0; i <=w; ++i) {
//        dp[i]=0;
//    }
////    01背包问题
//    for (int i = 0; i < n; ++i) {
//        for (int j = w; j >=v[i] ; --j) {
//            dp[j]=max(dp[j],dp[j-v[i]]+c[i]);
//        }
//    }
////    输出最大价值
//    cout<<dp[w];
//    return 0;
//}