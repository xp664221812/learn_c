#include <stdio.h>

#define LIST_INIT_SIZE 100
#define LIST_INCREAMENT 10

enum Status
{
    success,
    fail,
    fatal,
    range_error
};

typedef int ElemType;

typedef struct SqList
{
    ElemType *elem;
    int length;
    int list_size;
} SqList, *Ptr;
typedef Ptr SqListPtr;

//初始化线性表
enum Status List_init(SqListPtr L)
{
    enum Status s = success;
    L->list_size = LIST_INIT_SIZE;
    L->elem = (ElemType *)malloc(sizeof(ElemType) * L->list_size);
    if (L->elem == NULL)
    {
        s = fatal;
    }
    return s;
}


//按线性表位置查找
enum Status List_Retrival(SqListPtr L,int pos,ElemType *elem)
{
    enum Status s=range_error;
    

    return s;
}


