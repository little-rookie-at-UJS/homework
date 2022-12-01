#include "bits/stdc++.h"
//#include "stdlib.h"
//#include "iostream"
//#include "stack"
using namespace std;
typedef struct node{
    int l;
    int r;
    node(int l,int r):l(l),r(r){}
};
long long c1;
long long c2;
int d[10000066];
void maopao(int a[],int n){

    int j,temp,bd,ex=n-1;
    while (ex){
        bd=ex;
        ex=0;
        for ( j = 0; j < bd; ++j) {
            if(++c1&&a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                c2+=3;
                ex=j;
            }
        }
    }
}
void quick_sort2(int s[], int n){
    std::stack<node> stack;
    stack.push(node(0,n-1));

    while (!stack.empty()){
        node no=stack.top();
        stack.pop();
        if(no.l<no.r){
            //Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1
            int i =no.l, j = no.r, x = s[no.l];
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
            stack.push(node(no.l,i-1));
            stack.push(node(i+1,no.r));

        }
    }

}
void quick_sort(int s[], int l, int r)
{
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
//#include <algorithm>
//#include <iostream>
//using namespace std;
//long long sta[2005], sit[2005], f[15][2005][105];
//int n, k, cnt;
//
//void dfs(int x, int num, int cur) {
//    if (cur >= n) {  // 有新的合法状态
//        sit[++cnt] = x;
//        sta[cnt] = num;
//        return;
//    }
//    dfs(x, num, cur + 1);  // cur位置不放国王
//    dfs(x + (1 << cur), num + 1,
//        cur + 2);  // cur位置放国王，与它相邻的位置不能再放国王
//}
//
//bool compatible(int j, int x) {
//    if (sit[j] & sit[x]) return false;
//    if ((sit[j] << 1) & sit[x]) return false;
//    if (sit[j] & (sit[x] << 1)) return false;
//    return true;
//}
//
//int main() {
//    cin >> n >> k;
//    dfs(0, 0, 0);  // 先预处理一行的所有合法状态
//    for (int j = 1; j <= cnt; j++) f[1][j][sta[j]] = 1;
//    for (int i = 2; i <= n; i++)
//        for (int j = 1; j <= cnt; j++)
//            for (int x = 1; x <= cnt; x++) {
//                if (!compatible(j, x)) continue;  // 排除不合法转移
//                for (int l = sta[j]; l <= k; l++) f[i][j][l] += f[i - 1][x][l - sta[j]];
//            }
//    long long ans = 0;
//    for (int i = 1; i <= cnt; i++) ans += f[n][i][k];  // 累加答案
//    cout << ans << endl;
//    return 0;
//}