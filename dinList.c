/*
@Juunys
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct str {
	int key;
	struct str* next;
} NO;

typedef struct {
	NO* ini;
} LIST;

//initialize a list
void iniList(LIST *l) {
	l->ini = NULL;
}

//return last element
NO* lastElem(LIST l) {
	NO* p = l.ini;
	if(p)
		while(p)
			p = p->next;
	return (p);
}

//Search int the list for a especific key
NO* Search(LIST l, int key, NO** before) {
	NO* p = l.ini;
	*before = NULL;
	while(p){
		if (p->key == key) return p;
		*before = p;
		p = p->next;
	}
	return NULL;
}

//Insert a new key
bool Insert(LIST *l, int key) {
	NO* node;
	NO* before;
	node = Search(*l, key, &before);
	if (node) return false;
	node = (NO*)malloc(sizeof(NO));
	node->key = key;
	if(!l->ini) {
		l->ini = node;
		node->next = NULL;
	}
	else {
		if (!before) {
			node->next = l->ini;
			l->ini = node;
		}
		else {
			node->next = before->next;
			before->next = node;
		}
	}
	return true;

}

//return the n-esime element 
NO* nElemList(LIST l, int n) {
	NO* p = l.ini;
	int i = 1;
	if(p) {
		while((p->next)&&(i < n)) {
			p = p->next;
			i++;
		}
	}
	if(i != n) return NULL;
	else return(p);
}

//append a new element
void appendElem(LIST* l, int key) {
	NO* node;
	node = (NO*)malloc(sizeof(NO));
	node->key = key;
	node->next = NULL;
	
	NO* p = l->ini;
	
	if(!p){
	    l->ini = node;
	    return;
	}
	
	while(p->next){
	    p = p->next;
	}
	
	p->next = node;	
}

//remove an especific element
bool removeElem(LIST* l, int key) {
	NO* before;
	NO* elem;
	elem = Search(*l, key, &before);
	if(!elem) return false;
	if(!before) l->ini = elem->next;
	else before->next = elem->next;
	free(elem);
	return(true);
}


//split one dinamic list into two list, one even and one odd
void splitList(LIST l, LIST* odd, LIST* even) {
	int i;
	NO* p = l.ini;
	while(p) {
		int key = 0;
		key = p->key;
		if (key&1) {
			appendElem(odd, key);
		}
		else {
			appendElem(even, key);
		}
		p = p->next;
	}
}

//destroy the list
void destroyList(LIST* l) {
	NO* p = l->ini;
	NO* next;
	while(p) {
		next = p->next;
		free(p);
		p = next;
	}
	l->ini = NULL;
}

//print the element of the list
void showList(LIST l) {
	NO* p = l.ini;
	while(p){
    	printf("%d->", p->key);
    	p = p->next;
	}
	if(!p) printf("NULL \n");
	printf("\n\n");
}

int main(){
	LIST l;
	LIST odd;
	LIST even;

	iniList(&l);

	/*Insert(&l, 5);
	Insert(&l, 10);
	Insert(&l, 15);
	Insert(&l, 20);
	showList(l);
	removeElem(&l, 15);
	showList(l);
	destroyList(&l);
	showList(l);
	*/

	/*iniList(&odd);
	
	iniList(&even);
    
    int key = 0;
	int op = 0;
	while (op != 3){
		printf("1.Insert key\t\t2.mergeOddEven\t\t3.Exit\n");
		scanf("%d", &op);
		switch(op) {
			case 1:
				printf("\nType the key to insert:");
				scanf("%d", &key);
				Insert(&l, key);
				showList(l);
				break;
			case 2:		
				splitList(l, &odd, &even);
				printf("Odd list:\n");
				showList(odd);
				printf("Even list:\n");
				showList(even);
				break;
			case 3:
				break;
			default:
				printf("Choose a valid option!\n");
				break;
		}
	}*/
	return 0;
}

