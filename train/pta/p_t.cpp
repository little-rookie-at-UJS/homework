#include "bits/stdc++.h"
//#include "stdlib.h"
//#include "iostream"

using namespace std;
long long c1;
long long c2;
int d[1000066];
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
//    for (int i = 0; i < n-1; ++i) {
//        for (int j = 0; j < n-1-i; ++j) {
//            if (++c1&&a[j]>a[j+1]){
//                swap(a[j],a[j+1]);
//                c2+=3;
//            }
//        }
//    }


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
                j--;
            if(++c1&&i < j) {
                c2++;
                s[i++] = s[j];
            }

            while(i < j && s[i] < x) // ���������ҵ�һ�����ڵ���x����
                i++;
            if(++c1&&i < j) {
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


    for (int i = 0; i < n; ++i) {
        d[i]=n-i;

//        d[i]=i;
        d[i]=rand();
//        if(i<n*0.9)
//
    }
    maopao(d,n);
    cout<<"ð�����������"<<c1<<"�αȽ�\n"<<"ִ��"<<c2<<"��\n";
    c1=0,c2=0;
    for (int i = 0; i < n; ++i) {
        d[i]=n-i;
//        d[i]=i;
        d[i]=rand();
    }
    quick_sort(d,0,n);
    cout<<"���Ž�����"<<c1<<"�αȽ�\n"<<"ִ��"<<c2<<"��";
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