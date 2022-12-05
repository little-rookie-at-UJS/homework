
#include "bits/stdc++.h"
using namespace std;

//定义数组
int a[100],dp[100];
//计数变量
int c1,c2;

//蛮力

int max_baoli(int a[],int n){
//    定义子串
    int max_of_child=0;
    int sum_of_all;
//    从第i个开始
    for (int i = 0; i < n; ++i) {
        sum_of_all=0;
//        到了第j个
        for (int j = i; j < n; ++j) {
            sum_of_all+=a[j];
//            找到更大的子串
            if(c1++&&max_of_child<sum_of_all) {
                c2++;
                max_of_child = sum_of_all;
            }
        }
    }
    return max_of_child;
}

//分治

int max(int a,int b,int c){  //求出a,b,c三者中的最大值
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
    //当子序列只有一个元素时
    if(left==right){
        c1++;
        c2++;
        //元素大于0的时候返回它
        if(a[left]>0)
            return a[left];
            //小于或等于0的时候返回0
        else return 0;
    }
    int mid=(left+right)/2;
    //求左边的最大连续子序列的和
    maxLeftSum=maxSubArray(a,left,mid);
    //求右边的最大连续子序列之和
    maxRightSum=maxSubArray(a,mid+1,right);
    maxLeftBorderSum=0,leftBorderSum=0;
    //求出以左边加上a[mid]元素构成的序列的最大和
    for(i=mid;i>=left;i--){
        leftBorderSum+=a[i];
        if(++c1&&leftBorderSum>maxLeftBorderSum) {
            c2++;
            maxLeftBorderSum = leftBorderSum;
        }
    }
    maxRightBorderSum=0,rightBorderSum=0;
    //求出a[mid]右边元素构成的序列的最大和
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
//求较大数
int max_double(int a,int b){
    return a>b?a:b;
}

int max_dp(int a[],int n)  //求解算法
{
//初始化result结果
    int result;
    dp[0]=0;
    result=dp[0];
//    遍历
    for(int j=1;j<=n;j++){
//        计数++
        c1++;
//        在本身数以及与前一个数中找一个较大值
        dp[j]=max_double(dp[j-1]+a[j],a[j]);
//        dp[j]与之前的最大值进行比较
        result=max_double(result,dp[j]);
    }
    return result;
}




int main(){
    int n;
    cin>>n;
//    随机数种子
    srand(time(NULL));
//    随机出数
    for (int i = 0; i < n; ++i) {
        a[i]=rand()%50-20;
    }
//    输出结果
    for (int i = 0; i < n; ++i) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    c1=0,c2=0;
    cout<<"暴力搜索 最大值为"<<max_baoli(a,n)<<" 进行了"<<c1<<"次计算 更新了"<<c2<<"次结果"<<endl;
    c1=0,c2=0;
    cout<<"分治法 最大值为"<<maxSubArray(a,0,n-1)<<" 进行了"<<c1<<"次计算 更新了"<<c2<<"次结果"<<endl;
    c1=0,c2=0;
    cout<<"动态规划 最大值为"<<max_dp(a,n)<<" 进行了"<<c1<<"次计算"<<endl;
}
