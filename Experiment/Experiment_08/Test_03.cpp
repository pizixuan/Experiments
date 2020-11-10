/*
    假设二叉树采用二叉链存储结构存储，编写一个程序实现以下功能：
        （a）求二叉树b的节点个数并输出；
        （b）求二叉树b的叶子节点个数并输出；
        （c）求二叉树b的宽度；
    二叉树为：N(a(n,C(h(H,g))),K(o(,U(I,v)),e(r(s,i),t(y))))
*/

#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 20

typedef char ElemType;

typedef struct node{
    ElemType data;
    struct node * lchild;
    struct node * rchild;
}BTNode;

struct{
    int wid = 0;
}Width[MAXSIZE];


void createBTree(BTNode * &t, ElemType * str){
    BTNode * store[MAXSIZE];
    BTNode * temp;
    int top = -1;
    int order = 0;
    t = NULL;
    for (int i = 0; str[i] != '\0'; i++){
        switch (str[i]){
            case '(':       //接下来是左节点
                top++;
                store[top] = temp;
                order = 1;
                break;
            case ',':       //接下来是右节点
                order = 2;
                break;
            case ')':       //栈顶节点的子树结束
                top--;
                break;
            default :
                temp = (BTNode *)malloc(sizeof(BTNode));
                temp->data = str[i];
                temp->lchild = temp->rchild = NULL;
                if (t == NULL)
                    t = temp;
                else{
                    if (order == 1)
                        store[top]->lchild = temp;
                    if (order == 2)
                        store[top]->rchild = temp;
                }
        }   
    }
}

void dispBTree(BTNode * t){
    if (t != NULL){
        printf("%c", t->data);
        if (t->lchild != NULL || t->rchild != NULL){
            printf("(");
            dispBTree(t->lchild);
            if (t->rchild != NULL)
                printf(",");
            dispBTree(t->rchild);
            printf(")");
        }
    }
}

void numsOfBTreeNode(BTNode * &t, int &n, int &leafn){     //求树的高度
    if (t != NULL){
        n++;                //不为空则num+1
        if (t->lchild == NULL && t->rchild == NULL){        //若为叶子节点
            leafn++;
            printf("%c ", t->data);                             //输出节点值
        }                
        numsOfBTreeNode(t->lchild, n, leafn);
        numsOfBTreeNode(t->rchild, n, leafn);

    }
}


void maxWidthOfBTree(BTNode * &t, int &h){      //求树的宽度
    if (t != NULL){
        h++;
        Width[h].wid++;
        maxWidthOfBTree(t->lchild, h);
        maxWidthOfBTree(t->rchild, h);
        h--;
    }
}

void outPut(){
    BTNode * tree;
    int num = 0;
    int leafNum = 0;
    int h = 0;      //树的高度
    ElemType str[] = "N(a(n,C(h(H,g))),K(o(,U(I,v)),e(r(s,i),t(y))))";
    createBTree(tree, str);
    printf("创建的原树：");
    dispBTree(tree);
    printf("\n二叉树的所有叶子节点为：");
    numsOfBTreeNode(tree, num, leafNum);
    printf("\n二叉树的叶子节点数量为：%d", leafNum);
    printf("\n二叉树的节点数量：%d", num);
    maxWidthOfBTree(tree, h);
    int maxWidth = 0;
    for (int i = 1; Width[i].wid != 0;i++){
        if (Width[i].wid > maxWidth)
            maxWidth = Width[i].wid;
    }
    printf("\n二叉树的最大宽度：%d", maxWidth);
}

int main(void){
    outPut();
    return 0;
}