#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 4) {
        printf("Usage: %s <mailto> [subject] [body]\n", argv[0]);
        return 1;
    }

    char *mailto = argv[1];
    char *subject = argc > 2 ? argv[2] : NULL;
    char *body = argc > 3 ? argv[3] : NULL;

    if (subject && body) {
        if (execlp("balsa", "balsa", "-m", mailto, "-s", subject, "-b", body, NULL) == -1) {
            fprintf(stderr, "Error executing balsa: %s\n", strerror(errno));
            return 1;
        }
    } else if (subject) {
		 if (execlp("balsa", "balsa", "-m", mailto, "-s", subject, NULL) == -1) {
            fprintf(stderr, "Error executing balsa: %s\n", strerror(errno));
            return 1;
    }
    } else {
        if (execlp("balsa", "balsa", "-m", mailto, NULL) == -1) {
            fprintf(stderr, "Error executing balsa: %s\n", strerror(errno));
            return 1;
        }
    }

    return 0;
}
