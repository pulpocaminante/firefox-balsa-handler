#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	if (argc != 2)
	{
		printf("Usage: %s <mailto>\n");
		return 1;
	}
	execlp("balsa", "-m", argv[1], NULL);
	return 0;	
}
