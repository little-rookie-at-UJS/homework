//
// Created by DELLPC on 2022/11/25.
//
#include<bits/stdc++.h>
#define up(l,r,i) for(int i=l,END##i=r;i<=END##i;++i)
#define dn(r,l,i) for(int i=r,END##i=l;i>=END##i;--i)
using namespace std;
typedef long long i64;
const int INF =2147483647;
const int MAXN=1e5+3;
int n,t,H[MAXN],F[MAXN];
int main(){
    while(~scanf("%d",&H[++n])); --n;
    t=0,memset(F,0,sizeof(F)),F[0]=INF;
    up(1,n,i){
        int l=0,r=t+1;
        while(r-l>1){
            int m=l+(r-l)/2;
            if(F[m]>=H[i]) l=m;
            else r=m;
        }
        int x=l+1;  // dp[i]
        if(x>t) t=x;
        F[x]=H[i];
    }
    printf("%d\n",t);
    t=0,memset(F,0,sizeof(F)),F[0]=0;
    up(1,n,i){
        int l=0,r=t+1;
        while(r-l>1){
            int m=l+(r-l)/2;
            if(F[m]<H[i]) l=m; else r=m;
        }
        int x=l+1;
        if(x>t) t=x; F[x]=H[i];
    }
    printf("%d\n",t);
    return 0;
}
//#include "bits/stdc++.h"
//using namespace std;
//
//
//const int N = 5e3 + 2; //定义常量大小
//const int mod = 80112002; //定义最终答案mod的值
//vector<int> maps[N];//连接表 100个边 平均 减少计算数目
//int in[N],out[N];//入度出度个数
//int dp_trees[N];//树状dp
//int m,n;//m种类 n被吃关系
//queue<int> q;//队列
//
//int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cin>>m>>n;
//    int b,e;//起始节点 结束节点
//    for (int i = 0; i < n; ++i) {
//        cin>>b>>e;
////        b->e的链接图
//        maps[b].push_back(e);
////        入度 出度 +1
//        in[e]++;
//        out[b]++;
//    }
//    for (int i = 1; i <= m; ++i) {
////        找到生产者 入队 层次遍历
//        if(in[i]==0) {
//            q.push(i) ;
//            dp_trees[i]=1;
//        }
//    }
////    进行层次遍历
//    while (!q.empty()){
//        b=q.front();
//        q.pop();
////       规划所有节点
//        for (int i = 0; i <out[b]; ++i) {
////            获取下标
//            int len = maps[b][i];
////            入度减一
//            in[len]--;
////            食物链加上底层食物链的数目
//            dp_trees[len] += dp_trees[b];
////            取模
//            dp_trees[len] %= mod;
////            无再次入度 入队防止重复计算
//            if (!in[len]) q.push(len);
//        }
//    }
//    int ans=0;
//    for (int i = 1; i <=m; ++i) {
//        if(out[i]==0){
//            ans+=dp_trees[i];
//            ans%=mod;
//        }
//    }
//    cout<<ans;
//}
//#include <cstdio>
//#include <iostream>
//using namespace std;
//int dp[1100];
//int win[1100],lose[1100],use[1100];
//int main()
//{
//    int n,m;
//    scanf("%d%d",&n,&m);
//    for(int i=1;i<=n;i++)
//        scanf("%d%d%d",lose+i,win+i,use+i);
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=m;j>=use[i];j--)
//            dp[j]=max(dp[j]+lose[i],dp[j-use[i]]+win[i]);
//        for(int j=use[i]-1;j>=0;j--)
//            dp[j]+=lose[i];
//    }
//    printf("%lld",5ll*dp[m]);
//}
//#include "bits/stdc++.h"
//using namespace std;
//
//int dp[1003];
//int wins[1003],loses[1003],users[1003];
//
//int main(){
////    n个人 x瓶药
//    int n,x;
//    cin>>n>>x;
////    输入相关的数据
//    for (int i = 1; i <= n ; ++i) {
//        cin>>loses[i]>>wins[i]>>users[i];
//    }
//    for (int i = 1; i <= n; ++i) {
////        喝了x瓶
//        for (int j = x; j >=0 ; j--) {
////            喝了能打过 如果胜利价值多 喝药 否则不喝
//            if(j>=users[i]) dp[j]= max(dp[j]+loses[i],dp[j-users[i]]+wins[i]);
////            喝了打不过 就不喝
//            else dp[j]+=loses[i];
//        }
//    }
//    cout<<5ll*dp[x];
//}