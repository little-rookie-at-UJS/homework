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
            //Swap(s[l], s[(l + r) / 2]); //���м��������͵�һ�������� �μ�ע1
            int i =no.l, j = no.r, x = s[no.l];
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
            stack.push(node(no.l,i-1));
            stack.push(node(i+1,no.r));

        }
    }

}
void quick_sort(int s[], int l, int r)
{
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
//#include <algorithm>
//#include <iostream>
//using namespace std;
//long long sta[2005], sit[2005], f[15][2005][105];
//int n, k, cnt;
//
//void dfs(int x, int num, int cur) {
//    if (cur >= n) {  // ���µĺϷ�״̬
//        sit[++cnt] = x;
//        sta[cnt] = num;
//        return;
//    }
//    dfs(x, num, cur + 1);  // curλ�ò��Ź���
//    dfs(x + (1 << cur), num + 1,
//        cur + 2);  // curλ�÷Ź������������ڵ�λ�ò����ٷŹ���
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
//    dfs(0, 0, 0);  // ��Ԥ����һ�е����кϷ�״̬
//    for (int j = 1; j <= cnt; j++) f[1][j][sta[j]] = 1;
//    for (int i = 2; i <= n; i++)
//        for (int j = 1; j <= cnt; j++)
//            for (int x = 1; x <= cnt; x++) {
//                if (!compatible(j, x)) continue;  // �ų����Ϸ�ת��
//                for (int l = sta[j]; l <= k; l++) f[i][j][l] += f[i - 1][x][l - sta[j]];
//            }
//    long long ans = 0;
//    for (int i = 1; i <= cnt; i++) ans += f[n][i][k];  // �ۼӴ�
//    cout << ans << endl;
//    return 0;
//}