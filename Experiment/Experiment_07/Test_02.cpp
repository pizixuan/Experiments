/*
    编写病人看病模拟程序。
    编写一个程序exp7-2.cpp，反映病人到医院排队看医生的情况，在病人排队过程中主要重复下面两件事，
    （1）病人到达诊室，将病历交给护士，排到等待队列中候诊。
    （2）护士从等待队列中取出下一位病人的病历，该病人进入诊室就诊。要求模拟病人等待就诊这一过程。
    具体程序功能参照上机实验题3实验题6
*/

#include <stdio.h>
#include <malloc.h>

typedef int ElemType;
typedef struct qnode{
    ElemType data;
    struct qnode * next;
}DataNode;

typedef struct{
    DataNode * front;
    DataNode * rear;
}LinkQueue;

void interface (){
    printf("操作系统：\n");
    printf("1.排队\n");
    printf("2.就诊\n");
    printf("3.查看队列\n");
    printf("4.下班\n");
}

void initQueue(LinkQueue * &q){
    q = (LinkQueue *)malloc(sizeof(LinkQueue));
    q->front = q->rear = NULL;
}

bool deQueue(LinkQueue * &q, ElemType &e){
    DataNode * temp;
    if (q->rear == NULL)
        return false;
    temp = q->front;
    if (q->front == q->rear)
        q->front = q->rear = NULL;
    else
        q->front = q->front->next;
    e = temp->data;
    free(temp);
    return true;
}
void enQueue(LinkQueue * &q, ElemType e){
    DataNode * temp = (DataNode *)malloc(sizeof(DataNode));
    temp->data = e;
    temp->next = NULL;
    if (q->rear == NULL)
        q->front = q->rear = temp;
    else{
        q->rear->next = temp;
        q->rear = temp;
    }
}

void destoryQueue(LinkQueue * &q){
    DataNode * pre = q->front, *p;
    if (pre != NULL){
        p = pre->next;
        while (p != NULL){
            free(pre);
            pre = p->next;
            p = pre->next;
        }
        free(pre);
    }
    free(q);
}

bool emptyQueue(LinkQueue * q){
    return (q->rear == NULL);
}

bool check(LinkQueue * q, ElemType e){
    DataNode * temp = q->front;
    while (temp != NULL){
        if (temp->data == e)
            return false;
        temp = temp->next;
    }
    return true;
} 

void wait (LinkQueue * &q){
    printf("已进入就诊系统\n");
    printf("请输入病历号或输入'0'返回操作界面\n");
    int waitNum;
    while (1){
        scanf("%d", &waitNum);
        if (waitNum == 0){
            printf("即将返回操作系统界面\n");
            
            break;
        }
        if (!check(q, waitNum)){
            printf("%d号病人已在队列中,请重新输入病历号或输入'0'返回操作界面\n", waitNum);
            continue;
        }
        printf("%d号病人排队成功!\n"); 
        enQueue(q, waitNum);     //指令不是0那就入队
        printf("请继续输入病历号或输入'0'返回操作界面\n");
    }
    
}
void pick (LinkQueue * &q){
    printf("已进入就诊系统\n");
    printf("请输入指令'2'选择就诊或输入'0'返回操作界面\n");
    int pickNum = 0;
    int pickOrderNum = 0;
    while (1){
        scanf("%d", &pickOrderNum);
        if (pickOrderNum == 0){
            printf("即将返回操作系统界面\n");
            break;
        }
        if (pickOrderNum == 2){
            if (emptyQueue(q)){
                printf("已无人候诊!\n");
                break;
            }
            deQueue(q, pickNum);
            printf("%d号病人就诊\n", pickNum);
            printf("请输入指令'2'选择继续就诊或输入'0'返回操作界面\n");
            continue;
        }
        else {
            printf("输入不合法，请重新输入:\n");
            continue;
        }
    }
}

void view (LinkQueue * &q){      //输出队列
    DataNode * temp = q->front;
    printf("队列中还有：");
    while (temp != NULL){
        printf("%d号  ", temp->data);
        temp = temp->next;
    }
    printf("即将返回操作界面!\n");
}


void offWork (){
    printf("下班！\n");
}

void function (){
    LinkQueue * line;
    initQueue(line);     //初始化队列
    int orderNum = 0;
    while(orderNum != 4){
        interface();        //出现操作界面
        scanf("%d", &orderNum);
        switch (orderNum){
        case 1:
            wait(line);
            break;
        case 2:
            pick(line);
            break;
        case 3:
            view(line);
            break;
        case 4:
            offWork();
            break;
        default:
            printf("无效操作，即将返回操作界面\n");
        }
    }
}

int main (){
    function();
    return 0;
}