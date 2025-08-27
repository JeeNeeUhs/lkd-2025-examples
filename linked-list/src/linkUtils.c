#include "include/link.h"

void print_list(t_node* head) { //worked
	while(head != NULL) {
		printf("Curr node: %p, next: %p, data: %d\n", head, head->next, head->data);
		head = head->next;
	}
	return;
}

void print_menu() { //worked
	printf("What do you want to do?\n");
	printf("1 -> Print Nodes\n");
	printf("2 -> Add Node\n");
	printf("3 -> Remove Node\n");
	printf("4 -> Next Node\n");
	printf("5 -> Previous Node\n");
	printf("6 -> Change Value\n");
}

t_node* create_node(int val) { // i am a genius
	t_node* new_node = (t_node*)malloc(sizeof(t_node));
	if (NULL == new_node)
		return NULL;
	new_node->data = val;
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}

t_node* init_nodes() { //rewrite worked
	t_node* head = NULL;
	head = create_node(NODE_INIT_VAL);
	t_node* curr = head;

	for(int i = 0; i < NODE_INIT_SIZE; i++) {
		curr->next = create_node(NODE_INIT_VAL);
		if (NULL == curr->next)
			return head;
		curr->next->prev = curr;
		curr = curr->next;
	}
	return head;
}

void add_node(t_node* head) { //worked
	while(NULL != head->next) {
		head = head->next;
	}
	head->next = create_node(0);
	head->next->prev = head;
	head->next->data = 0;
}

// Mevcut düğümü çıkartır
t_node* remove_node(t_node* curr) {
	t_node* temp;
	if (curr->next == NULL && curr->prev == NULL) {
		printf("I can not delete my self sry");
		return curr;
	} else if (curr->next == NULL) {
		temp = curr->prev;
	} else {
		temp = curr->next;
	}
	if (curr->prev)
		curr->prev->next = curr->next;
	if (curr->next)
		curr->next->prev = curr->prev;
	free(curr); // idk
	printf("%p",temp);
	return temp;
}

// Bir sonraki düğümü döndürür
t_node* next_node(t_node* curr) {
	if (NULL == curr->next)
		return curr;
	return curr->next;
}

// Bir önceki düğümü döndürür
t_node* previous_node(t_node* curr){
	if (NULL == curr->prev)
		return curr;
	return curr->prev;
}

// Verilen düğümün verisini değiştirir
void change_value(t_node* curr, int val){
	curr->data = val;
}

// Belli değil mi...
void print_node(t_node* curr) {
		printf("Curr Node: %p, next: %p, prev: %p, data: %d\n", curr, curr->next, curr->prev, curr->data);
}
