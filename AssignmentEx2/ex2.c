
#include "pal.h"

int main(int argc, char* argv[]) {
	int pal_num = 0;
	pal_num = atoi(argv[1]);
	//int pal_num = 12345;
	printf("%d", pal_num);
	int num_size = atoi(argv[2]);
	//int num_size = 5;
	char commands[] = { 'a','d','w','x', 'h', 'k', 'u', 'm' };
	int commands_size = 8;

	user_game_palindrome(pal_num, num_size, commands, commands_size);

	return 0;
}

