//
// Created by DELLPC on 2022/11/22.
//
//
//采用二叉链表实现一个二叉排序树的应用，完成如下功能，要求实现一个简单的字符界面，根据用户选择完成相应处理，并输出处理结果。
//（1） 建立一棵二叉排序树：对从键盘输入的顺序任意的若干个正整数建立一颗二叉排序树，以-1作为结束，例如：输入 39 11 68 46 75 23 71 8 86 34 -1
//（2）中序遍历，输出遍历结果。
//（3）删除：输入一个关键字，进行删除。
//（4）编写算法，实现在给定二叉排序树中寻找两个指定结点的最近公共祖先。
//选做：编写算法，实现从大到小输出二叉排序树中所有值不小于k的关键字。

#include "bits/stdc++.h"
using namespace std;
//节点
typedef struct node{
    int n;
    int height;
    struct node *parents;
    struct node *left;
    struct node *right;
}node,*tree,*Node;



//    建树
void creat(vector<int> v,tree* t){
    Node n,pre;
    for (auto i = v.begin(); i!=v.end() ; ++i) {
        if(*t== nullptr){
            (*t)=(Node) malloc(sizeof (node));
            (*t)->parents= nullptr;
            (*t)->height=1;
            (*t)->left= nullptr;
            (*t)->right= nullptr;
            (*t)->n=(*i);
        }
        else{
//            搜索
            n=*t;
            while (n){
//                父节点
                pre=n;
                if(n->n<(*i)){
                    n=n->right;
                }
                else n=n->left;
            }

            n= (Node)malloc(sizeof(node));
            if(pre->n>(*i))pre->left=n;
            else pre->right=n;

            n->parents=pre;
            n->height=pre->height+1;
            n->left= nullptr;
            n->right= nullptr;
            n->n=(*i);
        }
    }

};
//遍历
void middle(tree t){
    if(t->left)middle(t->left);
    cout<<t->n<<" ";
    if(t->right)middle(t->right);
}

//删除
void delete_node(tree t,int n){
    Node node=t;
    Node pre;
    while (node&&node->n!=n){
        pre=node;
        if(node->n>n){
            node=node->left;
        } else{
            node=node->right;
        }
    }
    if(!node){
        cout<<"无此节点"<<endl;
    } else if((!node->left)&&(!node->right)){
        if(pre->left==node){
            pre->left= nullptr;
        } else pre->right= nullptr;
        delete(node);
    } else if((!node->left)||(!node->right)){
        if(node->left){
            if(pre->left==node){
                pre->left= node->left;
            } else pre->right= node->left;
            node->left->parents=pre;
        } else {
            if(pre->left==node){
                pre->left= node->right;
            } else pre->right= node->right;
            node->right->parents=pre;
        }
        delete(node);
    } else{
        Node  s=node->right;
        while (s->left){
            s=s->left;
        }
        node->n=s->n;
        if(!s->right){
            if(s->parents!=node)
             s->parents->left= nullptr;
            else s->parents->right= nullptr;
            delete(s);
        } else{
            s->parents->left= s->right;
            s->right->parents=s->parents;
            delete(s);
        }
    }


}

//公共祖先
void search(tree t,int n1,int n2){
    t->height=1;
    Node node1,node2;
    node1=t;
    node2=t;
    while (node1&&node1->n!=n1){
        if(node1->n>n1){
            node1=node1->left;
        } else node1=node1->right;
        if(node1)
         node1->height= node1->parents->height+1;
    }
    if(!node1) {
        cout<<n1<<"找不到"<<endl;
        return;
    }
    while (node2&&node2->n!=n2){
        if(node2->n>n2){
            node2=node2->left;
        } else node2=node2->right;
        if(node2)
            node2->height= node2->parents->height+1;
    }
    if(!node2) {
        cout<<n2<<"找不到"<<endl;
        return;
    }
    while(node1->height!=node2->height){
        if(node1->height>node2->height) node1=node1->parents;
        else node2= node2->parents;
    }
    while (node1!=node2){
        node1= node1->parents;
        node2=node2->parents;
    }
    cout<<node1->n<<endl;

}
//不小于k的关键字
void print_li(tree t,int n){
    if(t->right)print_li(t->right,n);
    if(t->n>=n)cout<<t->n<<" ";
    if(t->left)print_li(t->left,n);
}

int main(){
    int n;
    vector<int>v;
    tree t= nullptr;
    cin>>n;
    while (n!=-1){
        v.push_back(n);
        cin>>n;
    }
    creat(v,&t);
    middle(t);
    cout<<endl;
    cin>>n;
    delete_node(t,n);
    middle(t);
    cout<<endl;
    int x,y;
    cin>>x>>y;
    search(t,x,y);
    cin>>n;
    print_li(t,n);
}