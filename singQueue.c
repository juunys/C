/*
@Juunys
*/


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct str {
	int key;
	struct str* next;
} NO;

typedef struct {
	NO* ini;
	NO* end;
} Queue;

//initialize a dinamic queue
void Iniq(Queue* q) {
	q->ini = NULL;
	q->end = NULL;
} 

//Count element
int Count(Queue q) {
	NO* p;
	int count = 0;
	p = q.ini;
	while(p) {
		count++;
		p = p->prox;
	}
	return count;
}

//insert element in the end
void Insert(Queue* q, int key) {
	NO* p;
	P = (NO*)malloc(sizeof(NO));
	p->key = key;
	p->next = NULL;
	if(q->end) q->end->next = p;
	else q->ini = p;
	q->end = p;
}

//remove element in the beginning
bool Remove(Queue* q) {
	NO* p = q->ini;
	if(!q->ini) return false;
	q->ini = p->next;
	free(p);
	(!q->ini) q->end = NULL;
	return true;
}