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

Status List_init(SqListPtr l)
{
    Status s = success;
}

