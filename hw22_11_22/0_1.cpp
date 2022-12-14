//回溯法求01背包
#include "bits/stdc++.h"
using namespace std;

//定义物品价值和重量
vector<int> v;
vector<int> w;
//物品价值和重量的前缀和
vector<int> sumv;
vector<int> sumw;

//定义最大价值和最大重量物品个数
int maxv=0;
int maxw=0;
int maxn=0;

//剪枝函数
//1 背包放满 左子树
//2 物品可以放完 右子树
//3 物品价值和大于剩余最大价值 右子树

//dfs函数
void dfs(int number,int weight,int value){
//    如果
   if(value>maxv){
       maxv=value;
   }
   if(number==maxn){
       return;
   }
//   物品可以放入
   if(weight+w[number]<=maxw){
//       如果把剩下物品全部放入背包
         if(weight+sumw[maxn-1]-(number-1>0?sumw[number-1]:0)<=maxw){
//             如果剩下物品的价值和大于剩余最大价值
             if(value+sumv[maxn-1]-(number-1>0?sumv[number-1]:0)>maxv){
                 maxv=value+sumv[maxn-1]-(number-1>0?sumv[number-1]:0);
             }
             return;
         }
       dfs(number+1,weight+w[number],value+v[number]);
   }
//   右子树
   if(weight+w[number]>maxw||v[number]<sumv[maxn-1]-sumv[number])
    dfs(number+1,weight,value);
}

//70 3
//71 100
//69 1
//1 2

int main(){
//    输入背包容量和物品个数
    cin>>maxw>>maxn;
//    输入物品价值和重量并计算前缀和
    for (int i = 0; i < maxn; ++i) {
        int a,b;
        cin>>b>>a;
        v.push_back(a);
        w.push_back(b);
        if(i==0){
            sumv.push_back(a);
            sumw.push_back(b);
        }
        else{
            sumv.push_back(sumv[i-1]+a);
            sumw.push_back(sumw[i-1]+b);
        }
    }
    dfs(0,0,0);
    cout<<maxv<<endl;
}
