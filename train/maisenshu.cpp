//
// Created by DELLPC on 2022/11/22.
//
#include <iostream>
#define maxn 55
using namespace std;
int f[maxn][maxn][maxn][maxn],a[maxn][maxn];
int n,m;
int max_ele(int a,int b,int c,int d){
    if (b>a)
        a = b;
    if (c>a)
        a = c;
    if (d>a)
        a = d;
    return a;
}
int main(){
    cin >> n >> m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cin >> a[i][j];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            for (int k=1;k<=n;k++)
                for (int l=j+1;l<=m;l++)
                    f[i][j][k][l]=max_ele(f[i][j-1][k-1][l],f[i-1][j][k][l-1],f[i][j-1][k][l-1],f[i-1][j][k-1][l])+a[i][j]+a[k][l];
    cout << f[n][m-1][n-1][m] << endl;
    return 0;
}
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