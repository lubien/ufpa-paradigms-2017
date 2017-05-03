/*
Trabalho I: em dupla. 

Dada as funções da classe abaixo implemente-as no paradigmas
imperativo, como do programa acima; não use recursividade, 
caminhe na lista com comandos iterativos; 

programe o imprimir lista, com esta saida: [1,3,4,5,7,9]; 
depois responda as perguntas abaixo.
antes de cada uma destas perguntas exiba a lista; 
depois rode a ação; 
se ação é sobre a lista exiba novamente a lista;

1) cria a lista com insere inicio [1,3,4,5,7,9];
2) mostre o tamanho da lista;
3) remova o fim;
4) insira o 11 no final;
5) mostre qual é a posição do valor 5; 
6) insira o 6 na sua posição mantendo a ordem da lista;
7) remova o item valor 4;
8) remova duas vezes inicio;
9) cria a lista com insere fim[1,3,4,5,7,9];
10)inverta a lista;
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node * next;
} node;

void shift(node * head) {
	node * ref = head;
	node * temp = ref->next->next;
	
	free(ref->next);
	ref->next = temp;
}

void unshift(node * head, int x) {
	node * to_add = malloc(sizeof(node));
	to_add->value = x;
	to_add->next = head->next;
	head->next = to_add;
}

void push(node * head, int x) {
	node * to_add = malloc(sizeof(node));
	to_add->value = x;
	to_add->next = NULL;
	
	node * ref = head;
	
	while (ref->next != NULL)
		ref = ref->next;

	ref->next = to_add;
}

void pop(node * head) {
	node * ref = head->next;
	node * before = head;
	
	while (ref->next != NULL) {
		before = ref;
		ref = ref->next;
	}

	free(ref);
	before->next = NULL;
}

void insert_sorted(node * head, int x) {
	node * to_add = malloc(sizeof(node));
	to_add->value = x;
	
	node * ref = head;
	
	while (ref->next != NULL)
		if (ref->next->value <= x)
			ref = ref->next;
		else
			break;
	
	to_add->next = ref->next;
	ref->next = to_add;
}

int remove_by_value(node * head, int x) {
	int pos = 0;
	node * ref = head;
	
	while (ref->next != NULL)
		if (ref->next->value == x) {
			node * temp = ref->next->next;
			free(ref->next);
			ref->next = temp;
			return pos;	
		}
		else {
			ref = ref->next;
			++pos;
		}
			
		
	return -1;
}

void reverse(node * head) {
	node * ref = head;
	node * reversed = NULL;
	reversed = malloc(sizeof(node));
	reversed->next = NULL;
	
	while ((ref = ref->next) != NULL)
		unshift(reversed, ref->value);
		
	head->next = reversed->next;
	free(reversed);
}

int find(node * head, int x) {
	int pos = 0;
	node * ref = head;
	
	while ((ref = ref->next) != NULL)
		if (ref->value == x)
			return pos;
		else
			++pos;
		
	return -1;
}

int length(node * head) {
	int len = 0;
	node * ref = head;
	
	while ((ref = ref->next) != NULL)
		++len;
		
	return len;
}

void print_list(node * head) {
	node * ref = head;
	
	while ((ref = ref->next) != NULL)
		printf("%d ", ref->value);
		
	printf("\n");
}

int main() {
	node * head = malloc(sizeof(node));
	head->next = NULL;
	
	unshift(head, 9);
	unshift(head, 7);
	unshift(head, 5);
	unshift(head, 4);
	unshift(head, 3);
	unshift(head, 1);
	print_list(head);
	
	printf("Current length %d\n", length(head));
	
	pop(head);
	print_list(head);
	
	push(head, 11);
	print_list(head);
	
	printf("5 is at %d\n", find(head, 5));
	
	insert_sorted(head, 6);
	print_list(head);
	
	printf("4 was removed at %d\n", remove_by_value(head, 4));
	print_list(head);
	
	shift(head);
	shift(head);
	print_list(head);
	
	printf("\n");
	
	// last two
	
	node * h2 = malloc(sizeof(node));
	h2->next = NULL;
	
	push(h2, 1);
	push(h2, 3);
	push(h2, 4);
	push(h2, 5);
	push(h2, 7);
	push(h2, 9);
	print_list(h2);
	
	reverse(h2);
	print_list(h2);
}
