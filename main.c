#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[]) {
	if (argc != 2)
	{
		printf("Usage: %s <mailto>\n");
		return 1;
	}
	if (execlp("balsa", "balsa", "-m", argv[1], NULL) == -1) {
	fprintf(stderr, "Error executing balsa: %s\n", strerror(errno));
		return 1;
	}
	return 0;	
}
