#include "bits/stdc++.h"
using namespace std;
int dp[2003];
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int len1=s1.length(),len2=s2.length();

//  匹配到s2第i个位置最少的操作
    for (int i = 0; i < len2; ++i) {
//  从第0个开始匹配
        for (int j = 0; j < len1; ++j) {

        }

    }
}
//#include<iostream>
//#include<algorithm>
//using namespace std;
//long int n,k,sum[10001],num=1,f[10001];
//struct ren//结构体，一起排序 ，从大到小
//{
//    long int ks,js;
//};
//ren z[10001];
//int cmp(ren a,ren b){
//    return a.ks>b.ks;
//}
//int main(){
//    long int i,j;
//    cin>>n>>k;
//    for(i=1;i<=k;i++)
//    {
//        cin>>z[i].ks>>z[i].js;
//        sum[z[i].ks]++;
//    }
//    sort(z+1,z+k+1,cmp);
//    for(i=n;i>=1;i--)//倒着搜
//    {
//        if(sum[i]==0)
//            f[i]=f[i+1]+1;
//        else for(j=1;j<=sum[i];j++)
//        {
//            if(f[i+z[num].js]>f[i])
//                f[i]=f[i+z[num].js];
//            num++;//当前已扫过的任务数
//        }
//    }
//    cout<<f[1]<<endl;
//}
//#include<iostream>
//#include<cstdio>
//using namespace std;
//int a[100001],b[100001],map[100001],f[100001];
//int main()
//{
//    int n;
//    cin>>n;
//    for(int i=1;i<=n;i++){
//        scanf("%d",&a[i]);
//        map[a[i]]=i;
//    }
//    for(int i=1;i<=n;i++){
//        scanf("%d",&b[i]);
//        f[i]=0x7fffffff;
//    }
//    int len=0;
//    f[0]=0;
//    for(int i=1;i<=n;i++)
//    {
//        int l=0,r=len,mid;
//        if(map[b[i]]>f[len])
//            f[++len]=map[b[i]];
//        else
//        {
//            while(l<r)
//            {
//                mid=(l+r)/2;
//                if(f[mid]>map[b[i]])
//                    r=mid;
//                else l=mid+1;
//            }
//            f[l]=min(map[b[i]],f[l]);
//        }
//    }
//    cout<<len;
//    return 0;
//}

//#include <cstdio>
//#include <algorithm>
//#define MAX_N 1000001
//#define INF 2147483647
//using namespace std;
//int N, s[MAX_N], t[MAX_N];
//int dp[MAX_N], top = 0;
//int q;
//void solve () {
//    fill(dp, dp + top, INF);
//    for (int i = 0;i < top; i++) {
//        *lower_bound(dp, dp + top, t[i]) = t[i];
//    }
//    printf("%d\n", lower_bound(dp, dp + top, INF) - dp);
//}
//int main() {
//    scanf("%d", &N);
//    for(int i = 1;i <= N; i++) {scanf("%d", &q); s[q] = i;}
//    for(int i = 1;i <= N; i++) {scanf("%d", &q); if(s[q] > 0) t[top++] = s[q];}
//    solve();
//    return 0;
//}
//#include<iostream>
//#include<cstdio>
//#include<cstdlib>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//int n;
//int a1[100010],a2[100010];
//int belong[100010];
//int f[100010],b[100010],len;
//int main()
//{
//    freopen("a.in","r",stdin);
//    scanf("%d",&n);
//    for(int i=1;i<=n;i++)
//    {
//        scanf("%d",&a1[i]);
//        belong[a1[i]]=i;
//    }
//    for(int i=1;i<=n;i++)
//        scanf("%d",&a2[i]);
//    for(int i=1;i<=n;i++)
//    {
//        if(belong[a2[i]]>b[len])
//        {
//            b[++len]=belong[a2[i]];
//            f[i]=len;
//            continue;
//        }
//        int k=lower_bound(b+1,b+len+1,belong[a2[i]])-b;
//        b[k]=belong[a2[i]];
//        f[i]=k;
//    }
//    printf("%d\n",len);
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    char c;
//    int blank=0,digit=0,other=0;
//    scanf("%c",&c);
//    while(c!='\n'){
//        scanf("%c",&c);
//        if(c==' ')
//            blank++;
//        else if(c>='0'&&c<='9')
//            digit++;
//        else
//            other++;
//
//    }
//    printf("blank = %d, digit = %d, other = %d",blank,digit,other);
//    return 0;
//}


////
//// Created by DELLPC on 2022/11/23.
////
//#include "bits/stdc++.h"
//using namespace std;
//int mx=0;
////完全背包问题 a数组 t种票子 最大m个
//int dp(int a[],int t,int m){
//    int f[5001];
//
////    调最大值
//    memset(f,8000,sizeof(f));
//    f[0]=0;
////   t个物品进行变量
//    for (int i = 1; i <= t; ++i) {
////    背包问题
//        for (int j = a[i]; j <=a[t]*m ; ++j) {
//            f[j]=min(f[j],f[j-a[i]]+1);
//        }
//    }
//    for (int i = 0; i <=a[t]*m ; ++i) {
//        if(f[i]>m)
//            return i-1;
//    }
//    return a[t]*m;
//
//}
////m个邮票最大 n个种类 找到了k种 max目前最大值 a[]面值 as[]最好面值
//void dfs(int m,int n,int k,int max,int a[],int as[]){
//    if(k==n+1){
//        if(max>mx){
//            for (int i = 1; i <= n; ++i)
//                as[i]=a[i];
//            mx=max;
//
//        }
//        return;
//    }
//    for (int i = a[k-1]+1; i <=max+1; ++i) {
//        a[k]=i;
//        int mas= dp(a,k,m);
//        dfs(m,n,k+1,mas,a,as);
//    }
//}
//int main(){
//    int m,n;//m个邮票 n个种类
//    int a[20]={0};
//    int as[20]={0};
//    cin>>m>>n;
//    dfs(m,n,1,0,a,as);
//    for (int i = 1; i <=n; ++i) {
//        cout<<as[i]<<" ";
//    }
//    cout<<endl;
//    cout<<"MAX="<<mx;
//}

//#include<iostream>
//#include<cstring>//头文件
//using namespace std;
//int n,k,maxn;//a【】表示这种方法的邮票，ans【】表示如今取得的解即要输出的
//int dp(int a[],int ans[],int t,int mx){
//    int f[50000];//f[i]为拼i所需的最少数的个数
//    f[0]=0;//边界
//    for(int i=1;i<=a[t]*n;i++)
//        f[i]=50000;//赋初值赋一个尽可能地大就可以了
//    for(int i=1;i<=t;i++)            //从第一位找到目前的位数把所有已找的邮票都枚举
//        for(int j=a[i];j<=a[t]*n;j++)   //因为不可能找到比自己小的数，所以从自己开始找
//            f[j]=min(f[j],f[j-a[i]]+1);    //比较上几次已找到的最小需要位数和即将要找的相比较，取较小值
//    for(int i=1;i<=a[t]*n;i++)
//        if(f[i]>n)//如果所需最小的个数大于n就意味着这种情况不符合，但f【i-1】是符合的不然f【i-1】就会判断所以不符合返回i-1
//            return i-1;
//    return a[t]*n;//如果到a【t】*n的f【i】都满足意味着能取到的最大连续数就是a【t】*n
//}
//void dfs(int a[],int ans[],int t,int mx){              // 为什么全部找完：因为多几张邮票肯定比少几张邮票可能的情况多，所以全部找完是最好的
//    if(t==k+1){        //如果所有邮票数已经找完，那么就和 maxn比较谁更大
//        if(mx>maxn){
//            maxn=mx;
//            for(int i=1;i<=t-1;i++)
//                ans[i]=a[i];
//        } //保存所需要的邮票面值
//        return;
//    }
//    for(int i=a[t-1]+1;i<=mx+1;i++){  //继续找：为了避免重复，下一张邮票要比上一张邮票大，所以上边界是a[t-1]+1，同时它不能比最大连续值+1还大，不然最大连续值的下一个数就永远连不起来了
//        a[t]=i;
//        int x=dp(a,ans,t,mx);   //动归寻找此时的最大连续数
//        dfs(a,ans,t+1,x);
//    }
//}
//int main(){
//    cin>>n>>k;
//    int a[17],ans[17];
//    memset(a,0,17*4);
//    memset(ans,0,17*4);
//    dfs(a,ans,1,0);  //先从第一张开始找，第一张前面没有数，所以所连续的最大数为 0
//    for(int i=1;i<=k;i++)//输出 注意打空格以及大写换行即可
//        cout<<ans[i]<<" ";
//    cout<<endl;
//    cout<<"MAX="<<maxn<<endl;
//    return 0;
//}