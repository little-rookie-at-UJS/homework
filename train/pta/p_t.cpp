#include "bits/stdc++.h"
//#include "stdlib.h"
//#include "iostream"
//#include "stack"
using namespace std;
//���� c1 c2;
long long c1;
long long c2;
int d[10000066];
//ð������
void maopao(int a[],int n){
    int j,bd,ex=n-1;
//    �ҵ�����ı߽���Դ�����Ż������ٶ�
    while (ex){
//        ��ȡ����߽�
        bd=ex;
        ex=0;
//        ����
        for ( j = 0; j < bd; ++j) {
//            ����
            if(++c1&&a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                c2+=3;
//                �ض���߽�
                ex=j;
            }
        }
    }
}
//����ڵ�ṹ��
typedef struct node{
    int l;
    int r;
    node(int l,int r):l(l),r(r){}
};
//�����Ż��㷨 (��ֹջ���������)
void quick_sort2(int s[], int n){
//    ����stlջ
    std::stack<node> stack;
//    �ѿ�������ѹ��ջ
    stack.push(node(0,n-1));
//ջ��Ϊֹ
    while (!stack.empty()){
//        ��ȡջ��
        node no=stack.top();
//        ��ջ
        stack.pop();
//        �Ƚ�
        if(no.l<no.r){
            int i =no.l, j = no.r, x = s[no.l];
//            ���Ű���
            while (i < j)
            {
                while(i < j && s[j] >= x) // ���������ҵ�һ��С��x����
                {
                    ++c1;
                    j--;
                }
                if(i < j) {
                    c2++;
                    s[i++] = s[j];
                }

                while(i < j && s[i] < x) // ���������ҵ�һ�����ڵ���x����
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
//            ���Ҳ�����ջ
            stack.push(node(no.l,i-1));
            stack.push(node(i+1,no.r));
        }
    }
}
//���ţ����ݽϴ�ʱ�������
void quick_sort(int s[], int l, int r)
{
//    ���Ű���
    if (l < r)
    {
        //Swap(s[l], s[(l + r) / 2]); //���м��������͵�һ�������� �μ�ע1
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x) // ���������ҵ�һ��С��x����
            {
                ++c1;
                j--;
            }
            if(i < j) {
                c2++;
                s[i++] = s[j];
            }

            while(i < j && s[i] < x) // ���������ҵ�һ�����ڵ���x����
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
        quick_sort(s, l, i - 1); // �ݹ����
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
    cout<<"ð������(��������)������"<<c1<<"�αȽ�  "<<"ִ��"<<c2<<"��\n";
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
    cout<<"ð������(˳������)������"<<c1<<"�αȽ� "<<"ִ��"<<c2<<"��\n";
    c1=0,c2=0;
    for (int i = 0; i < n; ++i) {
        d[i]=rand();
//        if(i>n*0.1)
//            d[i]=max+1;
//        if(d[i]>max)max=d[i];
//
    }
    maopao(d,n);
    cout<<"ð������(ȫ�������)������"<<c1<<"�αȽ� "<<"ִ��"<<c2<<"��\n";
    c1=0,c2=0;
    for (int i = 0; i < n; ++i) {
        d[i]=rand();
        if(i>n*0.5)
            d[i]=max+1;
        if(d[i]>max)max=d[i];
//
    }
    maopao(d,n);
    cout<<"ð������(50%�����������)������"<<c1<<"�αȽ� "<<"ִ��"<<c2<<"��\n";
    max=0;
    c1=0,c2=0;
    for (int i = 0; i < n; ++i) {
        d[i]=n-i;
    }
    quick_sort2(d,n);
    cout<<"��������(��������)������"<<c1<<"�αȽ� "<<"ִ��"<<c2<<"��\n";
    max=0;
    c1=0,c2=0;
    for (int i = 0; i < n; ++i) {
        d[i]=i;
    }
    quick_sort2(d,n);
    cout<<"��������(˳������)������"<<c1<<"�αȽ� "<<"ִ��"<<c2<<"��\n";
    c1=0,c2=0;
    for (int i = 0; i < n; ++i) {
        d[i]=rand();
    }
    quick_sort2(d,n);
    cout<<"��������(ȫ�������)������"<<c1<<"�αȽ� "<<"ִ��"<<c2<<"��\n";
    c1=0,c2=0;
    for (int i = 0; i < n; ++i) {
        d[i]=rand();
        if(i>n*0.5)
            d[i]=max+1;
        if(d[i]>max)max=d[i];
//
    }
    quick_sort2(d,n);
    cout<<"��������(50%�����������)������"<<c1<<"�αȽ� "<<"ִ��"<<c2<<"��\n";

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
//ll dp[20][10][2];//������λΪj��iλ����������ö�ٽ��,3ά��ʾǰ׺(0��ʾ����ǰ׺1��ʾ��ǰ׺)
////�����ַ�λ
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
////���仯����
////pos��ʾ��ǰλ�ã�limit��ʾ��ǰλö���Ƿ����ƣ�key��ʾ��Ҫ���������֣�highest��ʾ�ǲ��ǵ�ǰλ�ǲ������λ
////number��������
//ll dfs(int pos, bool limit, bool highest, int key, ll number)
//{
//    if(pos == -1)//�ݹ��յ�
//        return 0;
//    ll ans = 0, n;
//    limit ? n=shu[pos] : n=9;//��ǰλö�ٵ��Ͻ�
//
//    //������ǰλ��ͳ��ÿһλ��ö�ٽ��dp[pos][i],���û���������ȥdfs
//    for(int i=0; i<=n; i++)
//    {
//        if(dp[pos][i][1]!=-1 && i==0&&highest)//ǰ׺����������
//        {
//            ans += dp[pos][i][1];
//            continue;
//        }
//        if(dp[pos][i][0]!=-1 && !limit)//֮ǰ�Ѿ��������ˣ�ֻ�������ƵĽ�����ܲ�,dp������û�б��������ƵĽ��
//        {
//            ans += dp[pos][i][0];
//            continue;
//        }
//        if(limit && i==shu[pos])//��һλ�����ƣ�����һ������ǰ����
//            ans += dfs(pos-1, true, false, key, number);
//        else if(i==0 && highest)//����һλ�����ƣ�������ǰ����
//            ans += dp[pos][i][1] = dfs(pos-1, false, true, key, number);
//        else//�Ȳ���ǰ���㣬Ҳ����һλ������
//            ans += (dp[pos][i][0] = dfs(pos-1, false, false, key, number));
//        if(i==key && !(i==0&&highest))//�����λ������ö�ٵ�����ͬ�����Ҳ���ǰ����,���м���
//        {
//            ll m = round(pow(10, pos));
//            //ö�ٱ�λ�Ժ�������������������������ֱ����
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
////            sum+=a[i];//��ͣ�
////        }
////        memset(dp,0,sizeof(dp));
////        for(int i=1;i<=n;i++){
////            for(int j=sum/2;j>=a[i];j--){
////                //j�ԣ�sum+1��/2��(sum)/2�����ԣ�ֻ�Ǻ������ĸĶ���
////                dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
////            }
////        }
////        int ans=sum-dp[sum/2]*2;//�������ľ���ֵ��
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
////            //Swap(s[l], s[(l + r) / 2]); //���м��������͵�һ�������� �μ�ע1
////            int i =no.l, j = no.r, x = s[no.l];
////            while (i < j)
////            {
////                while(i < j && s[j] >= x) // ���������ҵ�һ��С��x����
////                {
////                    ++c1;
////                    j--;
////                }
////                if(i < j) {
////                    c2++;
////                    s[i++] = s[j];
////                }
////
////                while(i < j && s[i] < x) // ���������ҵ�һ�����ڵ���x����
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
////        //Swap(s[l], s[(l + r) / 2]); //���м��������͵�һ�������� �μ�ע1
////        int i = l, j = r, x = s[l];
////        while (i < j)
////        {
////            while(i < j && s[j] >= x) // ���������ҵ�һ��С��x����
////            {
////                ++c1;
////                j--;
////            }
////            if(i < j) {
////                c2++;
////                s[i++] = s[j];
////            }
////
////            while(i < j && s[i] < x) // ���������ҵ�һ�����ڵ���x����
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
////        quick_sort(s, l, i - 1); // �ݹ����
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
////    cout<<"ð������(��������)������"<<c1<<"�αȽ�  "<<"ִ��"<<c2<<"��\n";
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
////    cout<<"ð������(˳������)������"<<c1<<"�αȽ� "<<"ִ��"<<c2<<"��\n";
////    c1=0,c2=0;
////    for (int i = 0; i < n; ++i) {
////        d[i]=rand();
//////        if(i>n*0.1)
//////            d[i]=max+1;
//////        if(d[i]>max)max=d[i];
//////
////    }
////    maopao(d,n);
////    cout<<"ð������(ȫ�������)������"<<c1<<"�αȽ� "<<"ִ��"<<c2<<"��\n";
////    c1=0,c2=0;
////    for (int i = 0; i < n; ++i) {
////        d[i]=rand();
////        if(i>n*0.5)
////            d[i]=max+1;
////        if(d[i]>max)max=d[i];
//////
////    }
////    maopao(d,n);
////    cout<<"ð������(50%�����������)������"<<c1<<"�αȽ� "<<"ִ��"<<c2<<"��\n";
////    max=0;
////    c1=0,c2=0;
////    for (int i = 0; i < n; ++i) {
////        d[i]=n-i;
////    }
////    quick_sort2(d,n);
////    cout<<"��������(��������)������"<<c1<<"�αȽ� "<<"ִ��"<<c2<<"��\n";
////    max=0;
////    c1=0,c2=0;
////    for (int i = 0; i < n; ++i) {
////        d[i]=i;
////    }
////    quick_sort2(d,n);
////    cout<<"��������(˳������)������"<<c1<<"�αȽ� "<<"ִ��"<<c2<<"��\n";
////    c1=0,c2=0;
////    for (int i = 0; i < n; ++i) {
////        d[i]=rand();
////    }
////    quick_sort2(d,n);
////    cout<<"��������(ȫ�������)������"<<c1<<"�αȽ� "<<"ִ��"<<c2<<"��\n";
////    c1=0,c2=0;
////    for (int i = 0; i < n; ++i) {
////        d[i]=rand();
////        if(i>n*0.5)
////            d[i]=max+1;
////        if(d[i]>max)max=d[i];
//////
////    }
////    quick_sort2(d,n);
////    cout<<"��������(50%�����������)������"<<c1<<"�αȽ� "<<"ִ��"<<c2<<"��\n";
////
////}
////#include <algorithm>
////#include <iostream>
////using namespace std;
////long long sta[2005], sit[2005], f[15][2005][105];
////int n, k, cnt;
////
////void dfs(int x, int num, int cur) {
////    if (cur >= n) {  // ���µĺϷ�״̬
////        sit[++cnt] = x;
////        sta[cnt] = num;
////        return;
////    }
////    dfs(x, num, cur + 1);  // curλ�ò��Ź���
////    dfs(x + (1 << cur), num + 1,
////        cur + 2);  // curλ�÷Ź������������ڵ�λ�ò����ٷŹ���
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
////    dfs(0, 0, 0);  // ��Ԥ����һ�е����кϷ�״̬
////    for (int j = 1; j <= cnt; j++) f[1][j][sta[j]] = 1;
////    for (int i = 2; i <= n; i++)
////        for (int j = 1; j <= cnt; j++)
////            for (int x = 1; x <= cnt; x++) {
////                if (!compatible(j, x)) continue;  // �ų����Ϸ�ת��
////                for (int l = sta[j]; l <= k; l++) f[i][j][l] += f[i - 1][x][l - sta[j]];
////            }
////    long long ans = 0;
////    for (int i = 1; i <= cnt; i++) ans += f[n][i][k];  // �ۼӴ�
////    cout << ans << endl;
////    return 0;
////}