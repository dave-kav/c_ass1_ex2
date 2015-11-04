
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "visible.h"

//--------------------------------------------------
// is_pal
//--------------------------------------------------

int is_pal(int* a, int size_num) {
	if (size_num == 0)
		return 1;
	if (size_num == 1)
		return 1;
	int* b = a + size_num - 1;
	while (b >= a) {
		if (*a != *b)
			return 0;
		else {
			a++;
			b--;
		}
	}
	return 1;
}

//--------------------------------------------------
// ask_for_command
//--------------------------------------------------

char ask_for_command(char c[], int size) {
	char move = ' ';
	printf("\nNEW MOVEMENT: Enter a valid command by keyword:");
	printf("\nValid commands : a\td\tw\tx\th\tk\tu\tm\n");
	char temp = my_get_char();
	if (memchr(c, temp, size))
			return temp;
}

//--------------------------------------------------
// process_movement
//--------------------------------------------------

void process_movement(int* a, int size_num, int** p, int* num_mov, char c) {

	switch (c)	{
	case 'a': 
		if (*p != a + 0) {
			*num_mov = *num_mov + 1;
			*p = (*p - 1);
		}
		break;
	
	case 'd': 
		if (*p != a + size_num-1) {
			*num_mov = *num_mov + 1;
			*p = (*p + 1);
		}
		break;
	case 'x': 
		if (**p != 0) {
			*num_mov = *num_mov + 1;
			**p = (**p - 1);
		}
		break;
	case 'w' : 
		if (**p != 9) {
			*num_mov = *num_mov + 1;
			**p = (**p + 1);
		}
		break;
	case 'h': 
		if (*p != a + 0) {
			*num_mov = *num_mov + 1;
			*p = (a + 0);
		}
		break;
	case 'k': 
		if (*p != a + size_num-1) {
			*num_mov = *num_mov + 1;
			*p = (a + size_num-1);
		}
		break;
	case 'u': 
		if (**p != 9) {
			*num_mov = *num_mov + 1;
			**p = (9);
		}
		break;
	case 'm': 
		if (**p != 0) {
			*num_mov = *num_mov + 1;
			**p = (0);
		}
		break;
	default:
		break;
	}
}

//--------------------------------------------------
// print_arrow
//--------------------------------------------------

void print_arrow(int* a, int* p, int size_num) {
	int gap = p - a;
	printf("\n");
	for (int i = 0; i < gap; i++) {
		printf("  ");
	}
	printf("           ^");
}

//--------------------------------------------------
// print_status
//--------------------------------------------------

void print_status(int* a, int size_num, int* p, int num_mov) {
	printf("------ Game Status -------\n");
	printf("Number = { ");
	for (int i = 0; i < size_num; i++)
		printf("%d ", a[i]);
	printf("}\n");
	print_arrow(a, p, size_num);
	printf("\nNumber of moves = %d", num_mov);
	printf("\n---------------------------\n");
}

//--------------------------------------------------
// user_game_palindrome
//--------------------------------------------------

void user_game_palindrome(int pal_num, int num_size, char commands[], int command_size) {
	srand(time(NULL));
	int* a;
	a = malloc(num_size*sizeof(int));
	int num_moves = 0;
	int index = gen_num(0, num_size);
	int* index_ptr = &a[index];
	

	//convert pal_num to array
	int rem = pal_num;
	for (int i = num_size-1; i >= 0; i--) {
		a[i] = rem % 10;
		rem = rem / 10;
	}

	int bool = 0;
	while (bool != 1) {
		bool = is_pal(a, num_size);
		print_status(a, num_size, index_ptr, num_moves);
		if (bool == 1) {
			printf("----------SOLVED!----------\n");
			printf("---------------------------\n");
		}
		else {
			char c = ask_for_command(commands, command_size);
			process_movement(a, num_size, &index_ptr, &num_moves, c);
		}
	}
}