#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct Node
{
    struct Node* next;
    struct Node* prev;
    char elem;
}Node;

typedef struct Linked_List
{
    Node* Header;
    Node* trailer;
    int n; //노드의 개수 (헤더와 트레일러 노드 제외)
}List;

void initList(List* list);
void freeList(List* list);
void add(List* list, int r, char e);
void addBeforeNode(Node* p, char e);
char delete(List* list, int r);
char deleteNode(Node* p);
char get(List* list, int r);
void printList(List* list);

int main()
{
    int N_oper = 0;
    int rank = 0;
    char oper;
    char elem;
    char tmp;

    List lList;
    initList(&lList);

    scanf("%d", &N_oper);
    getchar();
    for (int i = 0; i < N_oper; i++)
    {
        scanf("%c", &oper);
        getchar();

        switch (oper)
        {
        case 'A':
            scanf("%d %c", &rank, &elem);
            getchar();
            add(&lList, rank, elem);
            break;
        case 'D':
            scanf("%d", &rank);
            getchar();
            tmp = delete(&lList, rank);
            break;
        case 'G':
            scanf("%d", &rank);
            getchar();
            tmp = get(&lList, rank);
            if (tmp != 1)
                printf("%c\n", tmp);
            break;
        case 'P':
            printList(&lList);
            break;
        default:
            break;
        }
    }
    return 0;
}

void initList(List* list) //초기화
{
    list->Header = (Node*)malloc(sizeof(Node));
    list->trailer = (Node*)malloc(sizeof(Node));
    list->Header->next = list->trailer;
    list->trailer->prev = list->Header;
    list->n = 0;
}
void freeList(List* list)
{
    Node* ptr = list->Header->next;
    Node* pnext = NULL;
    while (ptr != list->trailer)
    {
        pnext = ptr->next;
        free(ptr);
        ptr = pnext;
    }
    free(list->Header);
    free(list->trailer);
}
void add(List* list, int r, char e)
{
    if ((r < 1) || (r > list->n + 1))
    {
        printf("invalid position\n");
        return;
    }
    Node* ptr = list->Header;
    for (int i = 0; i < r; i++)
        ptr = ptr->next;
    addBeforeNode(ptr, e);
    list->n += 1;
}
void addBeforeNode(Node* p, char e)
{
    Node* new_Node = (Node*)malloc(sizeof(Node));
    new_Node->elem = e;
    new_Node->next = p;
    new_Node->prev = p->prev;
    (p->prev)->next = new_Node;
    p->prev = new_Node;
}
char delete(List* list, int r)
{
    if ((r < 1) || (r > list->n))
    {
        printf("invalid position\n");
        return 1;
    }
    char elem;

    Node* ptr = list->Header;
    for (int i = 0; i < r; i++)
        ptr = ptr->next;
    elem = deleteNode(ptr);
    list->n -= 1;
    return elem;
}
char deleteNode(Node* p)
{
    char elem = p->elem;
    (p->prev)->next = p->next;
    (p->next)->prev = p->prev;
    free(p);
    return elem;
}
char get(List* list, int r)
{
    if ((r < 1) || (r > list->n))
    {
        printf("invalid position\n");
        return 1;
    }
    Node* ptr = list->Header;
    for (int i = 0; i < r; i++)
        ptr = ptr->next;
    return ptr->elem;
}
void printList(List* list)
{
    Node* ptr = list->Header->next;
    while (ptr != list->trailer)
    {
        printf("%c", ptr->elem);
        ptr = ptr->next;
    }
    printf("\n");
}