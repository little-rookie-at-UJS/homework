#include "bits/stdc++.h"
//#include "stdlib.h"
//#include "iostream"
//#include "stack"
using namespace std;
//计数 c1 c2;
long long c1;
long long c2;
int d[10000066];
//冒泡排序
void maopao(int a[],int n){
    int j,bd,ex=n-1;
//    找到无序的边界可以大幅度优化运行速度
    while (ex){
//        获取无序边界
        bd=ex;
        ex=0;
//        遍历
        for ( j = 0; j < bd; ++j) {
//            交换
            if(++c1&&a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                c2+=3;
//                重定义边界
                ex=j;
            }
        }
    }
}
//定义节点结构体
typedef struct node{
    int l;
    int r;
    node(int l,int r):l(l),r(r){}
};
//快排优化算法 (防止栈的溢出问题)
void quick_sort2(int s[], int n){
//    调用stl栈
    std::stack<node> stack;
//    把快排左右压入栈
    stack.push(node(0,n-1));
//栈空为止
    while (!stack.empty()){
//        获取栈顶
        node no=stack.top();
//        出栈
        stack.pop();
//        比较
        if(no.l<no.r){
            int i =no.l, j = no.r, x = s[no.l];
//            快排板子
            while (i < j)
            {
                while(i < j && s[j] >= x) // 从右向左找第一个小于x的数
                {
                    ++c1;
                    j--;
                }
                if(i < j) {
                    c2++;
                    s[i++] = s[j];
                }

                while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数
                {
                    ++c1;
                    i++;;
                }
                if(i < j) {
                    c2++;
                    s[j--] = s[i];
                }
            }
            s[i] = x;
//            左右部分入栈
            stack.push(node(no.l,i-1));
            stack.push(node(i+1,no.r));
        }
    }
}
//快排（数据较大时会溢出）
void quick_sort(int s[], int l, int r)
{
//    快排板子
    if (l < r)
    {
        //Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x) // 从右向左找第一个小于x的数
            {
                ++c1;
                j--;
            }
            if(i < j) {
                c2++;
                s[i++] = s[j];
            }

            while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数
            {
                ++c1;
                i++;;
            }
            if(i < j) {
                c2++;
                s[j--] = s[i];
            }
        }
        s[i] = x;
        quick_sort(s, l, i - 1); // 递归调用
        quick_sort(s, i + 1, r);
    }
}
int main(){
    int n;
    cin>>n;
    int max=0;
    c1=0,c2=0;
    for (int i = 0; i < n; ++i) {
        d[i]=n-i;
    }
    maopao(d,n);
    cout<<"冒泡排序(逆序排列)进行了"<<c1<<"次比较  "<<"执行"<<c2<<"次\n";
     max=0;
    c1=0,c2=0;
    for (int i = 0; i < n; ++i) {
        d[i]=i;
//        d[i]=rand();
//        if(i>n*0.1)
//            d[i]=max+1;
//        if(d[i]>max)max=d[i];
//
    }
    maopao(d,n);
    cout<<"冒泡排序(顺序排列)进行了"<<c1<<"次比较 "<<"执行"<<c2<<"次\n";
    c1=0,c2=0;
    for (int i = 0; i < n; ++i) {
        d[i]=rand();
//        if(i>n*0.1)
//            d[i]=max+1;
//        if(d[i]>max)max=d[i];
//
    }
    maopao(d,n);
    cout<<"冒泡排序(全随机排列)进行了"<<c1<<"次比较 "<<"执行"<<c2<<"次\n";
    c1=0,c2=0;
    for (int i = 0; i < n; ++i) {
        d[i]=rand();
        if(i>n*0.5)
            d[i]=max+1;
        if(d[i]>max)max=d[i];
//
    }
    maopao(d,n);
    cout<<"冒泡排序(50%随机数据排列)进行了"<<c1<<"次比较 "<<"执行"<<c2<<"次\n";
    max=0;
    c1=0,c2=0;
    for (int i = 0; i < n; ++i) {
        d[i]=n-i;
    }
    quick_sort2(d,n);
    cout<<"快速排序(逆序排列)进行了"<<c1<<"次比较 "<<"执行"<<c2<<"次\n";
    max=0;
    c1=0,c2=0;
    for (int i = 0; i < n; ++i) {
        d[i]=i;
    }
    quick_sort2(d,n);
    cout<<"快速排序(顺序排列)进行了"<<c1<<"次比较 "<<"执行"<<c2<<"次\n";
    c1=0,c2=0;
    for (int i = 0; i < n; ++i) {
        d[i]=rand();
    }
    quick_sort2(d,n);
    cout<<"快速排序(全随机排列)进行了"<<c1<<"次比较 "<<"执行"<<c2<<"次\n";
    c1=0,c2=0;
    for (int i = 0; i < n; ++i) {
        d[i]=rand();
        if(i>n*0.5)
            d[i]=max+1;
        if(d[i]>max)max=d[i];
//
    }
    quick_sort2(d,n);
    cout<<"快速排序(50%随机数据排列)进行了"<<c1<<"次比较 "<<"执行"<<c2<<"次\n";

}


//#include <bits/stdc++.h>
//#define re register
//#define DBG(x) cerr << #x << " = " << x << endl
//
//using namespace std;
//typedef long long LL;
//
//const int N = 5e4 + 5;
//
//int n, a[N];
//LL pre[N], ans = 9e18;
//multiset<LL> st;
//
//int main() {
//    scanf("%d", &n);
//    st.insert(0);
//    for(int i = 1; i <= n; i++) {
//        scanf("%d", &a[i]);
//        pre[i] = pre[i - 1] + a[i];
//        set<LL>::iterator it = st.lower_bound(pre[i]);
//        if(it != st.begin()) {
//            it--;
//            ans = min(ans, pre[i] - *it);
//        }
//        st.insert(pre[i]);
//    }
//    printf("%lld\n", ans);
//    return 0;
//}
//#include "bits/stdc++.h"
//using namespace std;
//int dp[100005];
//int maxs[100005];
//void init(){
//    for (int i = 0; i < 100005; ++i) {
//        if(i==0) {
//            dp[i] = 0;
//            maxs[0]=0;
//        } else if(i==1){
//            dp[i] = 1;
//            maxs[1]=1;
//        } else if(i&1){
//            dp[i]=dp[i>>1]+dp[(i>>1) +1];
//            maxs[i]=max(maxs[i-1],dp[i]);
//        } else{
//            dp[i]=dp[i>>1];
//            maxs[i]=max(maxs[i-1],dp[i]);
//        }
//    }
//}
//int main(){
//    init();
//    int t;
//    cin>>t;
//    while (t--){
//        int n;
//        cin>>n;
//        cout<<maxs[n]<<endl;
//    }
//
//}


//#include<iostream>
//#include<cstring>
//#include<math.h>
//#include<stdlib.h>
//#include<cstring>
//#include<cstdio>
//#include<utility>
//#include<algorithm>
//#include<map>
//#include<stack>
//#include<queue>
//using namespace std;
//typedef long long ll;
//const int maxn = 1e5+5;
//const int mod = 1e9+7;
//const int Hash = 10000;
//const int INF = 1<<30;
//const ll llINF = 1e18;
//
//int in;
//int shu[20];
//ll dp[20][10][2];//储存首位为j的i位数的无限制枚举结果,3维表示前缀(0表示不是前缀1表示是前缀)
////将数字分位
//int seq(ll n)
//{
//    int cnt = 0;
//    while(n)
//    {
//        shu[cnt++] = n%10;
//        n /= 10;
//    }
//    return cnt-1;
//}
////记忆化搜索
////pos表示当前位置，limit表示当前位枚举是否被限制，key表示需要计数的数字，highest表示是不是当前位是不是最高位
////number是求解的数
//ll dfs(int pos, bool limit, bool highest, int key, ll number)
//{
//    if(pos == -1)//递归终点
//        return 0;
//    ll ans = 0, n;
//    limit ? n=shu[pos] : n=9;//当前位枚举的上界
//
//    //遍历当前位，统计每一位的枚举结果dp[pos][i],如果没计算过，则去dfs
//    for(int i=0; i<=n; i++)
//    {
//        if(dp[pos][i][1]!=-1 && i==0&&highest)//前缀零的搜索结果
//        {
//            ans += dp[pos][i][1];
//            continue;
//        }
//        if(dp[pos][i][0]!=-1 && !limit)//之前已经搜索过了，只有无限制的结果才能查,dp数组中没有保存有限制的结果
//        {
//            ans += dp[pos][i][0];
//            continue;
//        }
//        if(limit && i==shu[pos])//下一位有限制，但是一定不是前导零
//            ans += dfs(pos-1, true, false, key, number);
//        else if(i==0 && highest)//对下一位无限制，但是是前导零
//            ans += dp[pos][i][1] = dfs(pos-1, false, true, key, number);
//        else//既不是前导零，也对下一位无限制
//            ans += (dp[pos][i][0] = dfs(pos-1, false, false, key, number));
//        if(i==key && !(i==0&&highest))//如果该位数与所枚举的数相同，并且不是前导零,进行计数
//        {
//            ll m = round(pow(10, pos));
//            //枚举本位对后面的有限制情况和无限制情况分别计数
//            if(!limit || i<n)
//            {
//                dp[pos][i][0] += m;
//                ans += m;
//            }
//            else
//                ans += number%m+1;
//        }
//    }
//    return ans;
//}
//int main( )
//{
//    //freopen("input.txt", "r", stdin);
//    ll a,b;
//    while(cin>>a>>b)
//    {
//        for(int i=0; i<10; i++)
//        {
//            memset(dp, -1, sizeof(dp));
//            ll ans1 = dfs(seq(a-1), true, true, i, a-1);
//            memset(dp, -1, sizeof(dp));
//            ll ans2 = dfs(seq(b), true, true, i, b);
//            cout<<ans2-ans1<<endl;
//        }
//    }
//    return 0;
//}


//#include<iostream>
//int a[1010];
//using namespace std;
//int main(){
//    a[1]=1,a[2]=2;
//    int n;
//    cin>>n;
//    for(int i=3;i<=n;i++){
//        a[i]=a[i-1]+a[i-2];
//        a[i]%=(10000007);
//    }
//    cout<<a[n]<<endl;
//
//    return 0;
//}

//#include "bits/stdc++.h"
//using namespace std;
//typedef struct node{
//    set<int>s;
//};
//int maps[101];
//int maps2[101];
//int main(){
//
//    map<int,node>ma;
//    int len=0;
//    int m,n,a,b;
//    cin>>m>>n>>a>>b;
//    memset(maps,0,sizeof(maps));
//    for (int i = 2; i < 101; ++i) {
//        if(!maps[i]){
//            node nas;
//            ma.insert(make_pair(i,nas));
//            maps[i]=i;
//            maps2[i]=1;
//            int nums=2;
//            int na=i*i;
//            while (na<100){
//                maps[na]=i;
//                maps2[na]=nums;
//                nums++;
//                na*=i;
//            }
//        }
//    }
//    for (int i = 0; i <n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            ma[maps[i+a]].s.insert(maps2[a+i]*(b+j));
//        }
//    }
//    int sum=0;
//    for (auto i= ma.begin();  i!=ma.end() ; i++) {
//        sum+=(*i).second.s.size();
//    }
//    cout<<sum;
//}
////#include<cstdio>
////#include<cstring>
////#include<algorithm>
////using namespace std;
////const int maxn=10010;
////int dp[maxn],a[maxn],b[maxn];
////int main()
////{
////    int n,sum;
////    while(scanf("%d",&n)!=EOF){
////        sum=0;
////        for(int i=1;i<=n;i++){
////            scanf("%d",&a[i]);
////            sum+=a[i];//求和；
////        }
////        memset(dp,0,sizeof(dp));
////        for(int i=1;i<=n;i++){
////            for(int j=sum/2;j>=a[i];j--){
////                //j以（sum+1）/2和(sum)/2都可以，只是后面程序的改动；
////                dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
////            }
////        }
////        int ans=sum-dp[sum/2]*2;//结果是其的绝对值；
////        printf("%d\n",(ans>0?ans:-ans));
////    }
////    return 0;
////}
////#include "bits/stdc++.h"
//////#include "stdlib.h"
//////#include "iostream"
//////#include "stack"
////using namespace std;
////typedef struct node{
////    int l;
////    int r;
////    node(int l,int r):l(l),r(r){}
////};
////long long c1;
////long long c2;
////int d[10000066];
////void maopao(int a[],int n){
////
////    int j,temp,bd,ex=n-1;
////    while (ex){
////        bd=ex;
////        ex=0;
////        for ( j = 0; j < bd; ++j) {
////            if(++c1&&a[j]>a[j+1]){
////                swap(a[j],a[j+1]);
////                c2+=3;
////                ex=j;
////            }
////        }
////    }
////}
////void quick_sort2(int s[], int n){
////    std::stack<node> stack;
////    stack.push(node(0,n-1));
////
////    while (!stack.empty()){
////        node no=stack.top();
////        stack.pop();
////        if(no.l<no.r){
////            //Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1
////            int i =no.l, j = no.r, x = s[no.l];
////            while (i < j)
////            {
////                while(i < j && s[j] >= x) // 从右向左找第一个小于x的数
////                {
////                    ++c1;
////                    j--;
////                }
////                if(i < j) {
////                    c2++;
////                    s[i++] = s[j];
////                }
////
////                while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数
////                {
////                    ++c1;
////                    i++;;
////                }
////                if(i < j) {
////                    c2++;
////                    s[j--] = s[i];
////                }
////            }
////            s[i] = x;
////            stack.push(node(no.l,i-1));
////            stack.push(node(i+1,no.r));
////
////        }
////    }
////
////}
////void quick_sort(int s[], int l, int r)
////{
////    if (l < r)
////    {
////        //Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1
////        int i = l, j = r, x = s[l];
////        while (i < j)
////        {
////            while(i < j && s[j] >= x) // 从右向左找第一个小于x的数
////            {
////                ++c1;
////                j--;
////            }
////            if(i < j) {
////                c2++;
////                s[i++] = s[j];
////            }
////
////            while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数
////            {
////                ++c1;
////                i++;;
////            }
////            if(i < j) {
////                c2++;
////                s[j--] = s[i];
////            }
////        }
////        s[i] = x;
////        quick_sort(s, l, i - 1); // 递归调用
////        quick_sort(s, i + 1, r);
////    }
////}
////int main(){
////    int n;
////    cin>>n;
////    int max=0;
////    c1=0,c2=0;
////    for (int i = 0; i < n; ++i) {
////        d[i]=n-i;
////    }
////    maopao(d,n);
////    cout<<"冒泡排序(逆序排列)进行了"<<c1<<"次比较  "<<"执行"<<c2<<"次\n";
////     max=0;
////    c1=0,c2=0;
////    for (int i = 0; i < n; ++i) {
////        d[i]=i;
//////        d[i]=rand();
//////        if(i>n*0.1)
//////            d[i]=max+1;
//////        if(d[i]>max)max=d[i];
//////
////    }
////    maopao(d,n);
////    cout<<"冒泡排序(顺序排列)进行了"<<c1<<"次比较 "<<"执行"<<c2<<"次\n";
////    c1=0,c2=0;
////    for (int i = 0; i < n; ++i) {
////        d[i]=rand();
//////        if(i>n*0.1)
//////            d[i]=max+1;
//////        if(d[i]>max)max=d[i];
//////
////    }
////    maopao(d,n);
////    cout<<"冒泡排序(全随机排列)进行了"<<c1<<"次比较 "<<"执行"<<c2<<"次\n";
////    c1=0,c2=0;
////    for (int i = 0; i < n; ++i) {
////        d[i]=rand();
////        if(i>n*0.5)
////            d[i]=max+1;
////        if(d[i]>max)max=d[i];
//////
////    }
////    maopao(d,n);
////    cout<<"冒泡排序(50%随机数据排列)进行了"<<c1<<"次比较 "<<"执行"<<c2<<"次\n";
////    max=0;
////    c1=0,c2=0;
////    for (int i = 0; i < n; ++i) {
////        d[i]=n-i;
////    }
////    quick_sort2(d,n);
////    cout<<"快速排序(逆序排列)进行了"<<c1<<"次比较 "<<"执行"<<c2<<"次\n";
////    max=0;
////    c1=0,c2=0;
////    for (int i = 0; i < n; ++i) {
////        d[i]=i;
////    }
////    quick_sort2(d,n);
////    cout<<"快速排序(顺序排列)进行了"<<c1<<"次比较 "<<"执行"<<c2<<"次\n";
////    c1=0,c2=0;
////    for (int i = 0; i < n; ++i) {
////        d[i]=rand();
////    }
////    quick_sort2(d,n);
////    cout<<"快速排序(全随机排列)进行了"<<c1<<"次比较 "<<"执行"<<c2<<"次\n";
////    c1=0,c2=0;
////    for (int i = 0; i < n; ++i) {
////        d[i]=rand();
////        if(i>n*0.5)
////            d[i]=max+1;
////        if(d[i]>max)max=d[i];
//////
////    }
////    quick_sort2(d,n);
////    cout<<"快速排序(50%随机数据排列)进行了"<<c1<<"次比较 "<<"执行"<<c2<<"次\n";
////
////}
////#include <algorithm>
////#include <iostream>
////using namespace std;
////long long sta[2005], sit[2005], f[15][2005][105];
////int n, k, cnt;
////
////void dfs(int x, int num, int cur) {
////    if (cur >= n) {  // 有新的合法状态
////        sit[++cnt] = x;
////        sta[cnt] = num;
////        return;
////    }
////    dfs(x, num, cur + 1);  // cur位置不放国王
////    dfs(x + (1 << cur), num + 1,
////        cur + 2);  // cur位置放国王，与它相邻的位置不能再放国王
////}
////
////bool compatible(int j, int x) {
////    if (sit[j] & sit[x]) return false;
////    if ((sit[j] << 1) & sit[x]) return false;
////    if (sit[j] & (sit[x] << 1)) return false;
////    return true;
////}
////
////int main() {
////    cin >> n >> k;
////    dfs(0, 0, 0);  // 先预处理一行的所有合法状态
////    for (int j = 1; j <= cnt; j++) f[1][j][sta[j]] = 1;
////    for (int i = 2; i <= n; i++)
////        for (int j = 1; j <= cnt; j++)
////            for (int x = 1; x <= cnt; x++) {
////                if (!compatible(j, x)) continue;  // 排除不合法转移
////                for (int l = sta[j]; l <= k; l++) f[i][j][l] += f[i - 1][x][l - sta[j]];
////            }
////    long long ans = 0;
////    for (int i = 1; i <= cnt; i++) ans += f[n][i][k];  // 累加答案
////    cout << ans << endl;
////    return 0;
////}