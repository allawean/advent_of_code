#include <stdio.h>


int main() {

    FILE *input;
    char buff[4];

    input = fopen("input", "r");
    fgets(buff, 4, (FILE*)input);

    fclose(input);
    printf("%s\n", buff);

    return 0;
}
