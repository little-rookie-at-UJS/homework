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
