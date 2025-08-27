#include "include/link.h"
#include <stdio.h>
#include <unistd.h>

int main() {
	t_node *curr = NULL;
	int val = 0;
	char buff = 0;

	curr = init_nodes();

	printf(WELCOME_MSG);
	while(1) {
		print_menu();
		print_node(curr);
		scanf(" %c", &buff);
		switch (buff) {
			case '1':
				print_list(curr);
				break;
			case '2':
				add_node(curr);
				break;
			case '3':
				curr = remove_node(curr);
				break;
			case '4':
				curr = next_node(curr);
				break;
			case '5':
				curr = previous_node(curr);
				break;
			case '6':
				if (scanf(" %d", &val) != 1) {
					printf("wtf u mean\n");
					while(getchar() != '\n');
				}
				change_value(curr, val);
				break;
			case 'q':
				exit(0);
			default:
				printf("Unrecognized key, please try again...");
				while(getchar() != '\n');
		}
		buff = 0;
	}

	printf(BYE_MSG);
}
