#include "header.h"

int main(int argc, char** argv) {

    FILE* file = fopen(FILE_NAME, "r");

    if(fopen(FILE_NAME, "r") == NULL) {
        printf("Error handling\n");
    } else printf("File opened correctly !\n");

    char* line;
    size_t len = 0;
    ssize_t read;
    int nbLigne = 1;

    while((read = getline(&line, &len, file)) != -1) {
        printf("%d. Ligne de taille %zu : %s\n", nbLigne, read, line);
        nbLigne++;
    }

    fclose(file);

    return 0;
}