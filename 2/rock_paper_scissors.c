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

int scoreFromMatch(char p1, char p2){
    if (p1 == 'A'){
        if (p2 == 'X'){
	    return 3;
	} else if (p2 == 'Y') {
	    return 6;
	} else {
	    return 0;
	}
    } else if (p1 == 'B'){
        if (p2 == 'X'){
	    return 0;
	} else if (p2 == 'Y') {
	    return 3;
	} else {
	    return 6;
	}
    } else {
        if (p2 == 'X'){
	    return 6;
	} else if (p2 == 'Y') {
	    return 0;
	} else {
	    return 3;
	}
    }
    return 0;
}

char symbolFromScore(char p1, char sc){
    if (p1 == 'A'){
        if (sc == 'X'){
	    return 'Z';
	} else if (sc == 'Y') {
	    return 'X';
	} else {
	    return 'Y';
	}
    } else if (p1 == 'B'){
        if (sc == 'X'){
	    return 'X';
	} else if (sc == 'Y') {
	    return 'Y';
	} else {
	    return 'Z';
	}
    } else {
        if (sc == 'X'){
	    return 'Y';
	} else if (sc == 'Y') {
	    return 'Z';
	} else {
	    return 'X';
	}
    }
    return 'A';
}




int main() {

    FILE *input;
    char buff[5];

    input = fopen("input", "r");
    int N = 0;

    while (fgets(buff, 5, (FILE*)input) != NULL){
	char p1 = buff[0];
	char sc = buff[2];
	char p2 = symbolFromScore(p1, sc);
	int sc1 = scoreFromSymbol(p2);
	int sc2 = scoreFromMatch(p1, p2);
	//printf("%s", buff);
        //printf("%s, %d, %d, %d\n", buff, sc1, sc2, sc1+sc2);
	//printf("%d\n", sc1+sc2);
	N += sc1 + sc2;
    }
    fclose(input);

    printf("total score: %d\n", N);

    return 0;
}
