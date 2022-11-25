#include <iostream>
#include <cstring>

#include <cstdio>
using namespace std;
char a[4005],b[4005];
int lena,lenb,f[4005][4005],k;//f(i,j)表示将A串前i个字符改为B串前j个字符需要的步数
int main() {
    cin>>a>>b;
    lena=strlen(a);lenb=strlen(b);
    for(int i=lena;i>=1;i--) a[i]=a[i-1];
    for(int i=lenb;i>=1;i--) b[i]=b[i-1];//初始化
    for(int i=0;i<=lena;i++) f[i][0]=i;
    for(int i=0;i<=lenb;i++) f[0][i]=i;//边界状态 因为将A串无字符变到B串i个字符时需要加i个字符 B串无字符时同理
    for(int i=1;i<=lena;i++){
        for(int j=1;j<=lenb;j++){
            k=1;//在后面会用到 方便‘改’的操作
            if(a[i]==b[j]) k=0;

            f[i][j]=min(min(f[i-1][j]+1,f[i][j-1]+1),f[i-1][j-1]+k);//若当前A、B串指向字符相等则不进行‘改’的操作
        }
    }
    printf("%d",f[lena][lenb]);//就是将A串前lena个数变为B串前lenb个数
    return 0;
}

//#include <stdio.h>
//int main()
//{
//    char c;
//    int blank=0,digit=0,other=0;
//    scanf("%c",&c);
//    while(c!='\n'){
//
//        if(c==' ')
//            blank++;
//        else if(c>='0'&&c<='9')
//            digit++;
//        else
//            other++;
//        scanf("%c",&c);
//    }
//    printf("blank = %d, digit = %d, other = %d",blank,digit,other);
//    return 0;
//}


//#include "bits/stdc++.h"
//using namespace std;
//int main(){
//    int dp[21];
//    int ans[21];
//    int map[21][21];
//
//}
//#include<bits/stdc++.h>
//#include<cctype>
////#pragma GCC optimize(2)
//#define ll long long
//#define rg register
//#define New int
////上面这些花里胡哨的东西请忽略
//using namespace std;
//inline New read()//快速读入
//{
//    New X = 0,w = 0;
//    char ch = 0;
//    while(!isdigit(ch))
//    {
//        w |= ch == '-';
//        ch=getchar();
//    }
//    while(isdigit(ch))
//    {
//        X = (X << 3) + (X << 1) + (ch ^ 48);
//        ch = getchar();
//    }
//    return w ? -X : X;
//}
//char F[200] ;
//inline void write(New x) //快速输出
//{
//    if(x == 0)
//    {
//        putchar('0');
//        return;
//    }
//    New tmp = x > 0 ? x : -x;
//    int cnt = 0;
//    if(x < 0)
//        putchar( '-' );
//    while(tmp > 0)
//    {
//        F[cnt++] = tmp % 10 + '0';
//        tmp /= 10;
//    }
//    while(cnt > 0)
//        putchar(F[--cnt]) ;
//}
//const int N = 5e3 + 2; //定义常量大小
//const int mod = 80112002; //定义最终答案mod的值
//
//int n, m; //n个点 m条边
//int in[N], out[N]; //每个点的入度和出度
//vector<int>nei[N]; //存图，即每个点相邻的点
//queue<int>q; //拓扑排序模板所需队列
//int ans; //答案
//int num[N]; //记录到这个点的类食物连的数量，可参考图
//
//
//signed main()
//{
//    n = read(), m = read();
//    for(rg int i = 1; i <= m; ++i)
//    { //输入边
//        int x = read(), y = read();
//        ++in[y], ++out[x]; //右节点入度+1,左节点出度+1
//        nei[x].push_back(y); //建立一条单向边
//    }
//    for(rg int i = 1; i <= n; ++i) //初次寻找入度为0的点(最佳生产者)
//        if(!in[i])
//        { //是最佳生产者
//            num[i] = 1; //初始化
//            q.push(i); //压入队列
//        }
//    while(!q.empty())
//    { //只要还可以继续Topo排序
//        int tot = q.front();//取出队首
//        q.pop();//弹出
//        int len = nei[tot].size();
//        for(rg int i = 0;i < len; ++i)
//        { //枚举这个点相邻的所有点
//            int next = nei[tot][i]; //取出目前枚举到的点
//            --in[next];//将这个点的入度-1(因为目前要删除第tot个点)
//            num[next] = (num[next] + num[tot]) % mod;//更新到下一个点的路径数量
//            if(in[next] == 0)q.push(nei[tot][i]);//如果这个点的入度为0了,那么压入队列
//        }
//    }
//    for(rg int i = 1; i <= n; ++i) //寻找出度为0的点(最佳消费者)
//        if(!out[i]) //符合要求
//            ans = (ans + num[i]) % mod;//累加答案
//    write(ans);//输出
//    return 0;//end
//}
//#include "bits/stdc++.h"
//using namespace std;
//
//typedef struct node{
//    int t;
//    int value;
//    node(int t,int value):t(t),value(value){}
//};
//bool cmp(node n1,node n2){
//    return n1.value*n2.t>n1.t*n2.value;
//}
//
//int main()
//{
//    vector<node>v;
//    int t,m;
//    cin>>t>>m;
//    int t_,v_;
//    for (int i = 0; i < m; ++i) {
//        cin>>t_>>v_;
//        if(t_<t)
//            v.push_back(node(t_,v_));
//    }
//    sort(v.begin(),v.end(), cmp);
//    long long values=0;
//    int len=0;
//    int t_sum=0;
//
//    while(t_sum!=t){
////        if(t-t_sum < v.end()->t)
////            break;
//        values+=1ll*((t-t_sum)/v[len].t)*v[len].value;
//        t_sum+=(t-t_sum)/v[len].t;
//        for (; len < v.size(); ++len) {
//            if(v[len].t < t-t_sum)break;
//        }
//        if(len==v.size())break;
//    }
//    cout<<values;
//}

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