//导入万能头
#include "bits/stdc++.h"
//命名空间
using namespace std;

//求最小字典序
bool cmp(string a, string b)
{
    return a + b < b + a;
}

//主函数
int main()
{
    //总数 n
    int n;
//    vector string
    vector<string> v;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
//    sort排序
    sort(v.begin(),v.end(),cmp);
//    拼接字符串
    string ans="";
    for(int i=0;i<n;i++){
        ans+=v[i];
    }
//    输出ans 每1000个换行
    int cnt=0;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
        cnt++;
        if(cnt==1000){
            cout<<endl;
            cnt=0;
        }
    }
    return 0;
}



//#include "stdio.h"
//
//int main(){
//    int n;
//    scanf("%d",&n);
//    for (int i = 0; i <n; ++i) {
//        for (int j = 1; j <=n; ++j) {
//            printf("%4d",i*n+j);
//        }
//        printf("\n");
//    }
//
//}


//#include<iostream>
//#include<stdio.h>
//#include<string>
//using namespace std;
//string arr[100];
//
//string sread() {
//    string s1;
//    char c;
//    while ((c=getchar())!='\n')
//    {
//        s1.append(1,c);
//    }
////    getchar();
//    return s1;
//}
//int main()
//{
//    int n;
//    cin >> n;
//    char c;
////     getchar();
//    getchar();
////while ((c=getchar())=='\n');
//    for (int i = 0; i < n; i++)
//    {
////        if(n==3&&i==n-3)getchar();
////        if(n==4&&i==n-4)getchar();
//        getline(cin, arr[i]);
//
////        arr[i].append(1,c);
////       // cin >> arr[i];
////        arr[i] += sread();
//
//    }
////    cout<<n<<endl;
////    for (int i = 0; i < n; i++)
////    {
////        cout << arr[i] << endl;
////    }
//    for (int i = 0; i < n; i++)
//    {
//        for (int a = 0; a < n - 1; a++)
//        {
//            if (arr[a].length() > arr[a + 1].length())
//            {
//                string temp = arr[a];
//                arr[a] = arr[a + 1];
//                arr[a + 1] = temp;
//            }
//        }
//    }
//    for (int i = 0; i < n; i++)
//    {
//        cout << arr[i] << endl;
//    }
//    return 0;
//}

//#include <cstdio>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//
//const int M = 1e2 + 5;
//int a[M];
//int pre[M];
//int f[M][M];
//
//int main() {
//    int n;
//    scanf("%d", &n);
//    memset(f, 0x3f, sizeof(f));
//    for(int i = 1; i <= n; i ++) {
//        scanf("%d", &a[i]);
//        f[i][i] = 0;
//        pre[i] = pre[i - 1] + a[i];//实现O(1)求sum(i,j)
//    }
//    for(int i = 2; i <= n; i ++) {
//        for(int l = 1; l <= n - i + 1; l ++) {
//            for(int k = l, r = l + i - 1; k < r; k ++) {
//                f[l][r] = min(f[l][k] + f[k + 1][r] + pre[r] - pre[l - 1], f[l][r]);
//            }
//        }
//    }
//    printf("%d", f[1][n]);
//    return 0;
//}

//#include "bits/stdc++.h"
//using namespace std;
//
//int main(){
//    priority_queue<int,vector<int>,greater<>> queue;
//    int n;
//    cin>>n;
//    int x;
//    for (int i = 0; i < n; ++i) {
//        cin>>x;
//        queue.push(x);
//    }
//    int a,b,sum=0;
//    for (int i = 1; i < n; ++i) {
//        a=queue.top();
//        queue.pop();
//        b=queue.top();
//        queue.pop();
//        sum+=a+b;
//        queue.push(a+b);
//    }
//    cout<<sum;
//}


//#include<iostream>
//using namespace std;
//class person
//{
//public:
//    person()
//    {
//        cout << "无参构造函数；" << endl;
//    }
//    person(int a)
//    {
//        age = a;
//        cout << "有参构造函数；" << endl;
//    }
//    person(const person& p)
//    {
//        age = p.age;
//        cout << "拷贝构造函数！" << endl;
//    }
//    ~person()
//    {
//        cout<<age<<endl;
//        cout << "析构函数！" << endl;
//    }
//    int age;
//};
//int main()
//{
//    person p1;
//    person p2(10);
//    person p3(p2);
//    /*person p1;
//    person p2 = person(10);
//    person p3 = person(p2);
//    person p1;
//    person p2 = 10;
//    person p3 = p2;*/
//    system("pause");
//    return 0;
//}
//#include "bits/stdc++.h"
//using namespace std;
//struct point {
//    double x;
//    double y;
//    point(double x, double y) :x(x), y(y) {}
//    point() { return; }
//};
//
//bool cmp_x(const point & A, const point & B)  // 比较x坐标
//{
//    return A.x < B.x;
//}
//
//bool cmp_y(const point & A, const point & B)  // 比较y坐标
//{
//    return A.y < B.y;
//}
//
//double distance(const point & A, const point & B)
//{
//    return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
//}
///*
//* function: 合并，同第三区域最近点距离比较
//* param: points 点的集合
//*        dis 左右两边集合的最近点距离
//*        mid x坐标排序后，点集合中中间点的索引值
//*/
//double merge(vector<point> & points, double dis, int mid)
//{
//    vector<point> left, right;
//    for (int i = 0; i < points.size(); ++i)  // 搜集左右两边符合条件的点
//    {
//        if (points[i].x - points[mid].x <= 0 && points[i].x - points[mid].x > -dis)
//            left.push_back(points[i]);
//        else if (points[i].x - points[mid].x > 0 && points[i].x - points[mid].x < dis)
//            right.push_back(points[i]);
//    }
//    sort(right.begin(), right.end(), cmp_y);
//    for (int i = 0, index; i < left.size(); ++i)  // 遍历左边的点集合，与右边符合条件的计算距离
//    {
//        for (index = 0; index < right.size() && left[i].y < right[index].y; ++index);
//        for (int j = 0; j < 7 && index + j < right.size(); ++j)  // 遍历右边坐标上界的6个点
//        {
//            if (distance(left[i], right[j + index]) < dis)
//                dis = distance(left[i], right[j + index]);
//        }
//    }
//    return dis;
//}
//
//
//double closest(vector<point> & points)
//{
//    if (points.size() == 2) return distance(points[0], points[1]);  // 两个点
//    if (points.size() == 3) return min(distance(points[0], points[1]), min(distance(points[0], points[2]),
//                                                                           distance(points[1], points[2])));  // 三个点
//    int mid = (points.size() >> 1) - 1;
//    double d1, d2, d;
//    vector<point> left(mid + 1), right(points.size() - mid - 1);
//    copy(points.begin(), points.begin() + mid + 1, left.begin());  // 左边区域点集合
//    copy(points.begin() + mid + 1, points.end(), right.begin());  // 右边区域点集合
//    d1 = closest(left);
//    d2 = closest(right);
//    d = min(d1, d2);
//    return merge(points, d, mid);
//}
//
//int main()
//{
//    int count;
//    printf("点个数：");
//    scanf("%d", &count);
//    vector<point> points;
//    double x, y;
//    for (int i = 0; i < count; ++i)
//    {
//        printf("第%d个点", i);
//        scanf("%lf%lf", &x, &y);
//        point p(x, y);
//        points.push_back(p);
//    }
//    sort(points.begin(), points.end(), cmp_x);
//    printf("最近点对值：%lf", closest(points));
//    return 0;
//}
