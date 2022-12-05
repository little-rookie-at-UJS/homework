
#include "bits/stdc++.h"
using namespace std;

//��������
int a[100],dp[100];
//��������
int c1,c2;

//����

int max_baoli(int a[],int n){
//    �����Ӵ�
    int max_of_child=0;
    int sum_of_all;
//    �ӵ�i����ʼ
    for (int i = 0; i < n; ++i) {
        sum_of_all=0;
//        ���˵�j��
        for (int j = i; j < n; ++j) {
            sum_of_all+=a[j];
//            �ҵ�������Ӵ�
            if(c1++&&max_of_child<sum_of_all) {
                c2++;
                max_of_child = sum_of_all;
            }
        }
    }
    return max_of_child;
}

//����

int max(int a,int b,int c){  //���a,b,c�����е����ֵ
    if(a<b) a=b;
    if(a>c) return a;
    else return c;
}
int maxSubArray(int a[],int left,int right)
{
    int i,j;
    int maxLeftSum,maxRightSum;
    int maxLeftBorderSum,leftBorderSum;
    int maxRightBorderSum,rightBorderSum;
    //��������ֻ��һ��Ԫ��ʱ
    if(left==right){
        c1++;
        c2++;
        //Ԫ�ش���0��ʱ�򷵻���
        if(a[left]>0)
            return a[left];
            //С�ڻ����0��ʱ�򷵻�0
        else return 0;
    }
    int mid=(left+right)/2;
    //����ߵ�������������еĺ�
    maxLeftSum=maxSubArray(a,left,mid);
    //���ұߵ��������������֮��
    maxRightSum=maxSubArray(a,mid+1,right);
    maxLeftBorderSum=0,leftBorderSum=0;
    //�������߼���a[mid]Ԫ�ع��ɵ����е�����
    for(i=mid;i>=left;i--){
        leftBorderSum+=a[i];
        if(++c1&&leftBorderSum>maxLeftBorderSum) {
            c2++;
            maxLeftBorderSum = leftBorderSum;
        }
    }
    maxRightBorderSum=0,rightBorderSum=0;
    //���a[mid]�ұ�Ԫ�ع��ɵ����е�����
    for(j=mid+1;j<=right;j++){
        rightBorderSum+=a[j];
        if(++c1&&rightBorderSum>maxRightBorderSum) {
            c2++;
            maxRightBorderSum = rightBorderSum;
        }
    }
    return max(maxLeftSum,maxRightSum,maxLeftBorderSum+maxRightBorderSum);

}

//dp
//��ϴ���
int max_double(int a,int b){
    return a>b?a:b;
}

int max_dp(int a[],int n)  //����㷨
{
//��ʼ��result���
    int result;
    dp[0]=0;
    result=dp[0];
//    ����
    for(int j=1;j<=n;j++){
//        ����++
        c1++;
//        �ڱ������Լ���ǰһ��������һ���ϴ�ֵ
        dp[j]=max_double(dp[j-1]+a[j],a[j]);
//        dp[j]��֮ǰ�����ֵ���бȽ�
        result=max_double(result,dp[j]);
    }
    return result;
}




int main(){
    int n;
    cin>>n;
//    ���������
    srand(time(NULL));
//    �������
    for (int i = 0; i < n; ++i) {
        a[i]=rand()%50-20;
    }
//    ������
    for (int i = 0; i < n; ++i) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    c1=0,c2=0;
    cout<<"�������� ���ֵΪ"<<max_baoli(a,n)<<" ������"<<c1<<"�μ��� ������"<<c2<<"�ν��"<<endl;
    c1=0,c2=0;
    cout<<"���η� ���ֵΪ"<<maxSubArray(a,0,n-1)<<" ������"<<c1<<"�μ��� ������"<<c2<<"�ν��"<<endl;
    c1=0,c2=0;
    cout<<"��̬�滮 ���ֵΪ"<<max_dp(a,n)<<" ������"<<c1<<"�μ���"<<endl;
}
