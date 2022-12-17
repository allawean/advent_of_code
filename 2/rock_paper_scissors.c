#include <stdio.h>


int scoreFromSymbol(char pl2){
    if (pl2 == 'X'){
        return 1;
    } else if (pl2 == 'Y'){
	return 2;
    } else if (pl2 == 'Z'){
	return 3;
    }
    return 0;
}

int scoreFromMatch(char *buff){
    if (buff[0] == 'A'){
        if (buff[2] == 'X'){
	    return 3;
	} else if (buff[2] == 'Y') {
	    return 6;
	} else {
	    return 0;
	}
    } else if (buff[0] == 'B'){
        if (buff[2] == 'X'){
	    return 0;
	} else if (buff[2] == 'Y') {
	    return 3;
	} else {
	    return 6;
	}
    } else {
        if (buff[2] == 'X'){
	    return 6;
	} else if (buff[2] == 'Y') {
	    return 0;
	} else {
	    return 3;
	}
    }
    return 0;
}

int main() {

    FILE *input;
    char buff[5];

    input = fopen("input", "r");
    int N = 0;

    while (fgets(buff, 5, (FILE*)input) != NULL){
	char pl2 = buff[2];
	int sc1 = scoreFromSymbol(pl2);
	int sc2 = scoreFromMatch(buff);
	//printf("%s", buff);
        //printf("%s, %d, %d, %d\n", buff, sc1, sc2, sc1+sc2);
	//printf("%d\n", sc1+sc2);
	N += sc1 + sc2;
    }
    fclose(input);

    printf("total score: %d\n", N);

    return 0;
}
