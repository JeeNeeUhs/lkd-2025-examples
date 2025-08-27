#include <stdio.h>
#include <stdlib.h>

#define NODE_INIT_SIZE 5
#define NODE_INIT_VAL 125
#define WELCOME_MSG "Welcome to list\n"
#define BYE_MSG "Please Subscribe\r\n"

typedef struct s_node {
	struct s_node* next;
	struct s_node* prev;
	int data;
} t_node;

t_node* init_nodes();
void print_menu();
void print_list(t_node* head);
void add_node(t_node* head);
t_node* remove_node(t_node* head);
t_node* next_node(t_node* head);
t_node* previous_node(t_node* head);
void change_value(t_node* head, int val);
void print_node(t_node* curr);
