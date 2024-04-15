#include <stdio.h>
#include <stdlib.h>
#include<assert.h>

typedef char ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode* next;        //ָ���̽��
} LinkNode;                     //������������

/**
 * ͷ�巨����������
 */
void CreateListF(LinkNode*& L, ElemType a[], int n);

/**
 * β�巨����������
 */
void CreateListR(LinkNode*& L, ElemType a[], int n);

/**
 * ��ʼ�����Ա�
 */
void InitList(LinkNode*& L);

/**
 * �������Ա�
 */
void DestroyList(LinkNode*& L);

/**
 * �����Ա��Ƿ�Ϊ�ձ��ձ���true�����򷵻�false��
 */
bool ListEmpty(LinkNode* L);

/**
 * �����Ա�ĳ���
 */
int ListLength(LinkNode* L);

/**
 * ������Ա�: ÿ�����ݺ���һ���ո�
 */
void DispList(LinkNode* L);

/**
 * �����Ա��е�i��Ԫ��ֵ��
 * ���ڵ�i�����ݽ��,��ֵ����e,Ȼ�󷵻�true��
 * �����ڵ�i�����ݽ��,����false��
 */
bool GetElem(LinkNode* L, int i, ElemType& e);

/**
 * ���ҵ�һ��ֵ��Ϊe��Ԫ����š�
 * �����ڣ��������߼���ţ��������ڣ�����0��
 */
int LocateElem(LinkNode* L, ElemType e);

/**
 * �����i��Ԫ�ء�
 * ����ɹ�������true�����벻�ɹ�������false��
 */
bool ListInsert(LinkNode*& L, int i, ElemType e);

/**
 * ɾ����i��Ԫ�ء�
 * �����i��Ԫ�ش��ڣ���ֵ����e������true��
 * �����i��Ԫ�ز����ڣ�����false��e
 */
bool ListDelete(LinkNode*& L, int i, ElemType& e);

int main() {
    LinkNode* h;
    ElemType e;
    printf("������Ļ�����������:\n");
    printf("  (1)��ʼ��������h\n");
    InitList(h);
    printf("  (2)���β���β�巨����a,b,c,d,eԪ��\n");
    ListInsert(h, 1, 'a');
    ListInsert(h, 2, 'b');
    ListInsert(h, 3, 'c');
    ListInsert(h, 4, 'd');
    ListInsert(h, 5, 'e');
    printf("  (3)���������h:");
    DispList(h);
    printf("  (4)������h����:%d\n", ListLength(h));
    printf("  (5)������hΪ%s\n", (ListEmpty(h) ? "��" : "�ǿ�"));
    GetElem(h, 3, e);
    printf("  (6)������h�ĵ�3��Ԫ��:%c\n", e);
    printf("  (7)Ԫ��a��λ��:%d\n", LocateElem(h, 'a'));
    printf("  (8)�ڵ�4��Ԫ��λ���ϲ���fԪ��\n");
    ListInsert(h, 4, 'f');
    printf("  (9)���������h:");
    DispList(h);
    printf("  (10)ɾ��h�ĵ�3��Ԫ��\n");
    ListDelete(h, 3, e);
    printf("  (11)���������h:");
    DispList(h);
    printf("  (12)�ͷŵ�����h\n");
    DestroyList(h);
    return 0;
}

/* ����������д���� */
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