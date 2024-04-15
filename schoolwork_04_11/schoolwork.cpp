#include <stdio.h>
#include <stdlib.h>
#include<assert.h>

typedef char ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode* next;        //指向后继结点
} LinkNode;                     //单链表结点类型

/**
 * 头插法建立单链表
 */
void CreateListF(LinkNode*& L, ElemType a[], int n);

/**
 * 尾插法建立单链表
 */
void CreateListR(LinkNode*& L, ElemType a[], int n);

/**
 * 初始化线性表
 */
void InitList(LinkNode*& L);

/**
 * 销毁线性表
 */
void DestroyList(LinkNode*& L);

/**
 * 判线性表是否为空表。空表返回true，否则返回false。
 */
bool ListEmpty(LinkNode* L);

/**
 * 求线性表的长度
 */
int ListLength(LinkNode* L);

/**
 * 输出线性表: 每个数据后面一个空格
 */
void DispList(LinkNode* L);

/**
 * 求线性表中第i个元素值。
 * 存在第i个数据结点,其值存入e,然后返回true。
 * 不存在第i个数据结点,返回false。
 */
bool GetElem(LinkNode* L, int i, ElemType& e);

/**
 * 查找第一个值域为e的元素序号。
 * 若存在，返回其逻辑序号；若不存在，返回0。
 */
int LocateElem(LinkNode* L, ElemType e);

/**
 * 插入第i个元素。
 * 插入成功，返回true；插入不成功，返回false。
 */
bool ListInsert(LinkNode*& L, int i, ElemType e);

/**
 * 删除第i个元素。
 * 如果第i个元素存在，其值存入e，返回true；
 * 如果第i个元素不存在，返回false。e
 */
bool ListDelete(LinkNode*& L, int i, ElemType& e);

int main() {
    LinkNode* h;
    ElemType e;
    printf("单链表的基本运算如下:\n");
    printf("  (1)初始化单链表h\n");
    InitList(h);
    printf("  (2)依次采用尾插法插入a,b,c,d,e元素\n");
    ListInsert(h, 1, 'a');
    ListInsert(h, 2, 'b');
    ListInsert(h, 3, 'c');
    ListInsert(h, 4, 'd');
    ListInsert(h, 5, 'e');
    printf("  (3)输出单链表h:");
    DispList(h);
    printf("  (4)单链表h长度:%d\n", ListLength(h));
    printf("  (5)单链表h为%s\n", (ListEmpty(h) ? "空" : "非空"));
    GetElem(h, 3, e);
    printf("  (6)单链表h的第3个元素:%c\n", e);
    printf("  (7)元素a的位置:%d\n", LocateElem(h, 'a'));
    printf("  (8)在第4个元素位置上插入f元素\n");
    ListInsert(h, 4, 'f');
    printf("  (9)输出单链表h:");
    DispList(h);
    printf("  (10)删除h的第3个元素\n");
    ListDelete(h, 3, e);
    printf("  (11)输出单链表h:");
    DispList(h);
    printf("  (12)释放单链表h\n");
    DestroyList(h);
    return 0;
}

/* 请在下面填写代码 */
void CreateListF(LinkNode*& L, ElemType a[], int n)
{
    assert(L);
    for (int i = 0; i < n; i++)
    {
        LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
        newnode->data = a[i];
        i++;
        newnode->next = L;
        newnode = L;
    }
}

void CreateListR(LinkNode*& L, ElemType a[], int n)
{
    assert(L);
    for (int i = 0; i < n; i++)
    {
        LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
        newnode->data = a[i];
        i++;
        L->next = newnode;
        newnode = L;
    }
}

void InitList(LinkNode*& L)
{
    L = NULL;
}

void DestroyList(LinkNode*& L)
{
    assert(L);
    LinkNode* cur = L;
    while (cur)
    {
        LinkNode* next = cur->next;
        free(cur);
        cur = next;
    }
}

bool ListEmpty(LinkNode* L)
{
    assert(L);
    LinkNode* cur = L->next;
    if (cur == NULL && cur->next == NULL)
        return true;
    else
        return false;
}

int ListLength(LinkNode* L)
{
    assert(L);
    LinkNode* cur = L;
    int i = 0;
    while (cur)
    {

        i++;
        cur = cur->next;
    }
    return i;
}

void DispList(LinkNode* L)
{
    assert(L);
    LinkNode* cur = L;
    while (cur)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
}

bool GetElem(LinkNode* L, int i, ElemType& e)
{
    assert(L);
    LinkNode* cur = L;
    int j = ListLength(L);
    if (j < i)
        return false;
    else
    {
        for (int t = 0; t < j; i++)
        {
            if (t == i)
            {
                e = cur->data;
            }
            cur = cur->next;
        }
    }
}

int LocateElem(LinkNode* L, ElemType e)
{
    assert(L);
    LinkNode* cur = L;
    int t = 0;
    int i = ListLength(L);
    while (cur->data != e)
    {
        t++;
        cur = cur->next;
    }
    if (t == i)
        return 0;
    else
        return t;
}

bool ListInsert(LinkNode*& L, int i, ElemType e)
{
    if (L == NULL)
        return false;
    LinkNode* cur = L;
    LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
    int t = 1;
    if (i == 1)
    {
        newnode->next = L;
        newnode = L;
    }
    for (t; t <= i-1; t++)
    {
        cur = cur->next;
    }
    LinkNode* next = cur->next;
    cur->next = newnode;
    newnode->next = next;
    return true;
}

bool ListDelete(LinkNode*& L, int i, ElemType& e)
{
    if (L == NULL)
        return false;
    LinkNode* cur = L;
    int t = 0;
    int a = 0;
    int j = ListLength(L);
    for (t; t < i-1; t++)
    {
        a++;
        cur = cur->next;
    }
    if (a == (j - 1))
        return false;
    else
    {
        LinkNode* next = cur->next->next;
        cur->next = next;
        free(cur->next);
    }

}