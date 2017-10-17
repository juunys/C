/*
###############################

- William Jun Yamada 9037564 -

##############################
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h> 

typedef struct str {
    char* child;
    struct str* next;
} NO;
 
typedef struct {
    NO* head;
} LIST;
 
 
//Retorna o tamanho da lista
int SizeList(LIST *l) {
    NO* p = l->head->next;
    int tam = 0;
    while (p != l->head)
    {
        tam++;
        p = p->next;
    }
    return(tam);
}

//Imprime os nomes da lista 
void showList(LIST *l) {
    printf("\n\n");
    NO* p = l->head;
    while(p->next != l->head)
    {
        p = p->next;
	if (p->next == l->head) printf("%s", p->child);
	else
        printf("%s->", p->child);
    }
    printf("\n\n");
}

//Inicializa a lista circular 
void IniList(LIST* l) {
    l->head = (NO*)malloc(sizeof(NO));
    l->head->next = l->head;
 
    //assim mesmo que imprima o valor do head não estara a aceder a uma zona de memoria invalida
    l->head->child = malloc(sizeof(char)); 
    *(l->head->child) = '\0';
}

//Retorna o enesimo elemento se houver 
NO* nChild(LIST *l, int n, NO** bef) {
    NO* p = l->head->next;
    *bef = l->head;
    int i = 0;
    while ((p != l->head) && (i < n))
    {
        *bef = p;
        p = p->next;
        i++;
    }
 
    return i >= SizeList(l) ? NULL : p;
}

//Retorna ultimo elemento 
NO* LastChild(LIST *l) {
    NO* p = l->head->next;
    if(p == l->head) return l->head;
    while(p->next != l->head)
    {
        p = p->next;
    }
    return p;
}

//Insere nova crianca 
void insChild(LIST* l, char name[]) {
    NO* p = LastChild(l);
    NO* newnode = (NO*)malloc(sizeof(NO));
    newnode->child = malloc((strlen(name)+1)*sizeof(char)); 
    strcpy(newnode->child, name);
    newnode->next = l->head;
    p->next = newnode;
}

//Remove uma crianca aleatoria conforme funcao random 
void DelChild (LIST* l)
{
    int slist = SizeList(l);
    if (slist == 1 )
    {
        NO* p = l->head->next;
	printf("\n\n#################################");
	printf("\n#\t\t\t\t#");
        printf("\n\n    CRIANCA VENCEDORA: %s\n", p->child);
	printf("\n#\t\t\t\t#");
	printf("\n#################################\n\n");
        return;
    }
    else
    {
	srand(time(0));//Usado para rand nao repetir
        int del = rand() % slist;
 
        NO* bef;
        NO* p = nChild(l, del, &bef);
        if (p)
        {
            bef->next = p->next;
	    printf("\n\n#################################");
	    printf("\n#\t\t\t\t#");
	    printf("\n\n   CRIANCA REMOVIDA: %s\n", p->child);
	    printf("\n#\t\t\t\t#");
	    printf("\n#################################\n\n");
            free(p);
        } 
    }
}
 
int main() {
    LIST l;
    IniList(&l);
    int op = 0;
 
    while (op != 4)
    {
	printf("\n\n---------------------------------------");
        printf("\nDigite o numero a operacao desejada:\n");
        printf("\n\n1.Inserir Crianca\t\t2.Remover Crianca\t\t3.Mostrar Lista\t\t4.Sair\n\n");
        scanf("%d", &op);
 
        char name[100];
        switch(op)
        {
 
        case 1:
            printf("\nDigite o nome a inserir:\n");
            scanf("%s", name);
            insChild(&l, name);
            break;
        case 2:
            DelChild(&l);
            break;
	case 3:
	    showList(&l);
	    break;
        case 4:
            break;
        default:
            printf("\nDigite uma opção válida!\n");
        }
    }
    return 0;
}
