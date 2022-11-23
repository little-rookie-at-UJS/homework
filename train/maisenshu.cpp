//
// Created by DELLPC on 2022/11/22.
//
#include<iostream>
#include<cstdio>

int main(){

}
//using namespace std;
//int g[105],f[105],a[105],s[105];
//int main()
//{
//    int n;
//    cin>>n;
//    for(int i=1;i<=n;i++)
//    {
//        cin>>a[i];
//        f[i]=1;
//        g[i]=1;
//    }//输入并赋初值
//    for(int i=n-1;i>=1;i--)
//    {
//        for(int j=i+1;j<=n;j++)
//        {
//            if(a[i]>a[j]&&f[i]<=f[j]+1)
//            {
//                f[i]=f[j]+1;
//            }
//        }
//    }//从右往左，按左高右低顺序找出每一个位置右边有几个从高到低的数 （包括自己）
//    for(int i=2;i<=n;i++)
//    {
//        for(int j=1;j<i;j++)
//        {
//            if(a[i]>a[j]&&g[i]<=g[j]+1)
//            {
//                g[i]=g[j]+1;
//            }
//        }
//    }//从左往右，按左低右高顺序找出每一个位置左边有几个从低到高的数 （包括自己）
//    int maxx=0;
//    for(int i=1;i<=n;i++)
//    {
//        s[i]=f[i]+g[i]-1;//把每个数的左边从低到高的数和右边从高到低的数相加
//        //注意！！自己加了两次要-1
//        if(s[i]>maxx)
//        {
//            maxx=s[i];
//        }
//    }
//    cout<<n-maxx;//是求出列的人数
//}
//#include "bits/stdc++.h"
//using namespace std;
//int main(){
//    priority_queue<int> q;
//    int n,s;
//    cin>>n;
//    for (int i = 0; i < n; ++i) {
//        cin>>s;
//        q.push(s);
//    }
//    cout<<n;
//    for (int i = 0; i < ; ++i) {
//
//    }
//}
//#include "bits/stdc++.h"
//using namespace std;
//bool isp[10000004];
//int sum=0;
////len 遍历的下标 n抽的个数 m总数 number 目前的个数 s目前的总和
//void dfs(vector<int> v,int len,int n,int m,int number,int s){
//
//    if(n==number){
//        if(isp[s]){
//            sum+=1;
//        }
//        return;
//    }
//    if(len==m-1)return;
//    for (int i = len+1; i < m; ++i) {
//        dfs(v,i,n,m,number+1,s+v[i]);
//    }
//    return;
//}
//int main(){
//    memset(isp, true,sizeof(isp));
//    for (int i = 2; i < 10000000; ++i) {
//        if(isp[i]){
//            for (int j = 2; j <= 10000000/i; ++j) {
//                isp[i*j]= false;
//            }
//        }
//    }
//    int m,n,s;
//    vector<int>v;
//    cin>>m>>n;
//    for (int i = 0; i < m; ++i) {
//        cin>>s;
//        v.push_back(s);
//    }
//    dfs(v,-1,n,m,0,0);
//    cout<<sum;
//}
//#include<cstdio>
//double a,b,c,d;
//double fc(double x)
//{
//    return a*x*x*x+b*x*x+c*x+d;
//}
//int main()
//{
//    double l,r,m,x1,x2;
//    int s=0,i;
//    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);  //输入
//    for (i=-100;i<100;i++)
//    {
//        l=i;
//        r=i+1;
//        x1=fc(l);
//        x2=fc(r);
//        if(!x1)
//        {
//            printf("%.2lf ",l);
//            s++;
//        }      //判断左端点，是零点直接输出。
//
//        //不能判断右端点，会重复。
//        if(x1*x2<0)                             //区间内有根。
//        {
//            while(r-l>=0.001)                     //二分控制精度。
//            {
//                m=(l+r)/2;  //middle
//                if(fc(m)*fc(r)<=0)
//                    l=m;
//                else
//                    r=m;   //计算中点处函数值缩小区间。
//            }
//            printf("%.2lf ",r);
//            //输出右端点。
//            s++;
//        }
//        if (s==3)
//            break;
//        //找到三个就退出大概会省一点时间
//    }
//    return 0;
//}

//#include<iostream>
//#include<fstream>
//#include<cstdio>
//#include<algorithm>
//#include<cmath>
//#include<string>
//using namespace std;
//int pd[10002][202],a[10002][202];
//int main()
//{
//    //freopen("treasure.in","r",stdin);
//    //freopen("treasure.out","w",stdout);
//    int n,m,x,i,j,ans=0,l=0;
//    scanf("%d%d",&n,&m);//以下的读入不说了
//    for(i=1;i<=n;i++)
//    {
//        l=0;
//        for(j=0;j<m;j++)
//        {
//            scanf("%d%d",&pd[i][j],&a[i][j]);
//            if(pd[i][j]==1) l++;//记录该层楼有楼梯的门数
//        }
//        pd[i][m]=l;
//    }
//    scanf("%d",&x);
//    i=1;
//    while(i<=n)
//    {
//        ans+=a[i][x];
//        ans%=20123;//根据规律，边加边模，值不变，不用long long
//        int k=0;
//        for(j=x;;j++)
//        {
//            if(j==m) j=0;
//            if(pd[i][j]==1) k++;
//            if(k==(a[i][x]-1)%pd[i][m]+1) break;//最关键的停止条件，循环找对，取模，都靠它。
//        }
//        x=j;
//        i++;
//    }
//    printf("%d",ans);//小小的输出优化~
//    return 0;
//}
//#include "bits/stdc++.h"
//using namespace std;
//typedef struct number{
//    int n;
//    int grade;
//    number(int n,int grade):n(n),grade(grade){}
//};
//bool cmp1(number n1,number n2){
//    return n1.grade<n2.grade;
//};
//bool cmp2(number n1,number n2){
//    return n1.n<n2.n;
//}
//
//int main(){
//    int n,x;
//
//    vector<number >v,v1,v2;
//    cin>>n;
//    for (int i = 0; i < n; ++i) {
//        cin>>x;
//
//        v.push_back(number(i,x));
//
//    }
//
//    sort(v.begin(),v.end(), cmp1);
//    int grade;
//    cin>>grade;
//    int r=v.size()-1;
//    if(v[r].grade<grade){
//        sort(v.begin(),v.end(), cmp2);
//        for (auto j = v.begin(); j!=v.end() ; ++j) {
//            cout<<(*j).grade<<" ";
//        }
//        cout<<endl;
//        return 0;
//    }
//
//    int i;
//    if(v[0].grade<grade) {
//        v1.push_back(v[0]);
//        for (i = 1; i < n; ++i) {
//            v1.push_back(v[i]);
//            if (v[i].grade >= grade && v[i - 1].grade < grade) {
//                v1.pop_back();
//                break;
//            }
//        }
//    }
//    else i=0;
//
//    for ( i ; i <n ; ++i) {
//       v2.push_back(v[i]);
//    }
//    sort(v1.begin(),v1.end(), cmp2);
//
//    sort(v2.begin(),v2.end(), cmp2);
//    for (auto j = v1.begin(); j!=v1.end() ; ++j) {
//        cout<<(*j).grade<<" ";
//    }
//    for (auto j = v2.begin(); j!=v2.end() ; ++j) {
//        cout<<(*j).grade<<" ";
//    }
//    cout<<endl;
//    sort(v2.begin(),v2.end(), cmp1);
//    for (auto j = v2.begin(); j!=v2.end() ; ++j) {
//        cout<<(*j).grade<<" ";
//    }
//
//}
//#include <iostream>
//#define maxn 55
//using namespace std;
//int f[maxn][maxn][maxn][maxn],a[maxn][maxn];
//int n,m;
//int max_ele(int a,int b,int c,int d){
//    if (b>a)
//        a = b;
//    if (c>a)
//        a = c;
//    if (d>a)
//        a = d;
//    return a;
//}
//int main(){
//    cin >> n >> m;
//    for (int i=1;i<=n;i++)
//        for (int j=1;j<=m;j++)
//            cin >> a[i][j];
//    for (int i=1;i<=n;i++)
//        for (int j=1;j<=m;j++)
//            for (int k=1;k<=n;k++)
//                for (int l=j+1;l<=m;l++)
//                    f[i][j][k][l]=max_ele(f[i][j-1][k-1][l],f[i-1][j][k][l-1],f[i][j-1][k][l-1],f[i-1][j][k-1][l])+a[i][j]+a[k][l];
//    cout << f[n][m-1][n-1][m] << endl;
//    return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//int f[31][31],i,j,m,n;
//int main()
//{
//    cin>>n>>m;
//    f[0][1]=1;
//    for(int i=1; i<=m; i++)
//        for(int j=1; j<=n; j++)
//            if(j==1)
//                f[i][j]=f[i-1][n]+f[i-1][2];
//            else if(j==n)
//                f[i][j]=f[i-1][1]+f[i-1][n-1];
//            else
//                f[i][j]=f[i-1][j-1]+f[i-1][j+1];
//    cout<<f[m][1]<<endl;
//    return 0;
//}
//typedef struct node{
//    int x;
//    int n=0;
//   bool operator >(const node x)const{
//       return n>x.n;
//    }
//};
//bool cmp(node n1,node n2){
//    return n1>n2;
//}
//bool cmp1(node n1,node n2){
//    return n1.x<n2.x;
//}
//int main(){
//    node x[1003];
//    node y[1003];
//    int mx,my,m,n,d;
//    cin>>mx>>my>>m>>n>>d;
//    int x1,x2,y1,y2;
//    for (int i = 0; i < d; ++i) {
//        cin>>x1>>y1>>x2>>y2;
//        if(x1==x2){
//            if(y1>y2) y1=y2;
//            y[y1].x=y1;
//            y[y1].n++;
//        } else{
//            if(x1>x2)x1=x2;
//            x[x1].x=x1;
//            x[x1].n++;
//        }
//    }
//    sort(x,x+1003,cmp);
//    sort(y,y+1003,cmp);
//    sort(x,x+m,cmp1);
//    sort(y,y+n,cmp1);
//    for (int i = 0; i < m; ++i) {
//        cout<<x[i].x<<" ";
//    }
//    cout<<endl;
//    for (int i = 0; i < n; ++i) {
//        cout<<y[i].x<<" ";
//    }
//}



//#include<cstdio>
//#include<cmath>
//#include<cstring>
//using namespace std;
//int f[1001],p,res[1001],sav[1001];//乘法要开两倍长度
//void result_1()
//{
//    memset(sav,0,sizeof(sav));
//    for(register int i=1;i<=500;i+=1)
//        for(register int j=1;j<=500;j+=1)
//            sav[i+j-1]+=res[i]*f[j];//先计算每一位上的值（不进位）
//    for(register int i=1;i<=500;i+=1)
//    {
//        sav[i+1]+=sav[i]/10;//单独处理进位问题，不容易出错
//        sav[i]%=10;
//    }
//    memcpy(res,sav,sizeof(res));//cstring库里的赋值函数，把sav的值赋给res
//}
//void result_2()//只是在result_1的基础上进行了细微的修改
// {
//    memset(sav,0,sizeof(sav));
//    for(register int i=1;i<=500;i+=1)
//        for(register int j=1;j<=500;j+=1)
//            sav[i+j-1]+=f[i]*f[j];
//    for(register int i=1;i<=500;i+=1)
//    {
//        sav[i+1]+=sav[i]/10;
//        sav[i]%=10;
//    }
//    memcpy(f,sav,sizeof(f));
//}
//int main()
//{
//    scanf("%d",&p);
//    printf("%d\n",(int)(log10(2)*p+1));
//    res[1]=1;
//    f[1]=2;//高精度赋初值
//    while(p!=0)//快速幂模板
//    {
//        if(p%2==1)result_1();
//        p/=2;
//        result_2();
//    }
//    res[1]-=1;
//    for(register int i=500;i>=1;i-=1)//注意输出格式，50个换一行，第一个不用
//        if(i!=500&&i%50==0)printf("\n%d",res[i]);
//        else printf("%d",res[i]);
//    return 0;
//}