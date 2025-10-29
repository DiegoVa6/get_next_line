// tester.c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int   fd;
    char *line;
    int   n = 1;

    if (argc != 2) {
        fprintf(stderr, "Uso: %s <archivo>\n", argv[0]);
        return 1;
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }
    while ((line = get_next_line(fd)) != NULL) {
        printf("%3d: %s", n++, line);  // la línea ya debe llevar '\n' si aplica
        free(line);
    }
    close(fd);
    return 0;
}

