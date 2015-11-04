
#include "pal.h"

int main() {
	int pal_num = 1234453;
	int num_size = 7;
	char commands[] = { 'a','d','w','x', 'h', 'k', 'u', 'm' };
	int commands_size = 8;

	user_game_palindrome(pal_num, num_size, commands, commands_size);

	return 0;
}

