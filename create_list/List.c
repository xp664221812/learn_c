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
enum Status List_Retrival(SqListPtr L, int pos, ElemType *elem)
{
    enum Status s = range_error;
    if (L)
    {
        if ((pos - 1) >= 0 && (pos - 1) < L->length)
        {
            *elem = L->elem[pos - 1];
            s = success;
        }
    }
    else
    {
        s = fatal;
    }

    return s;
}

//按值查找位置
enum Status List_Locate(SqListPtr L, int *pos, ElemType *elem)
{
    enum Status s = range_error;
    for (int i = 0; i < L->length; i++)
    {
        if (L->elem[i] == elem)
        {
            *elem = i + 1;
            s = success;
            break;
        }
    }
    return s;
}

//插入数据
enum Status List_Insert(SqListPtr L, int pos, ElemType elem)
{
    enum Status s = range_error;
    if ((pos - 1) > 0 && (pos - 1) <= L->length)
    {
        if (L && L->length < L->list_size)
        {
            for (int i = L->length; i > (pos - 1); i--)
            {
                L->elem[i + 1] = L->elem[i];
            }
            L->elem[pos - 1] = enum;
            L->length++;
            s = success;
        }
    }
    else
    {
        s = fail;
    }

    return s;
}