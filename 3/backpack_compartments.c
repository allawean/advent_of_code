#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void divideCompartments(char* buff, char* buff1, char* buff2, int buffSize){
    int halfSize = buffSize/2;
    for (int i=0; i < halfSize; i++){
        buff1[i] = buff[i];
	buff2[i] = buff[i+halfSize];
    }
    return;
}

int priority(char c){
    int i = (int)(c);
    if (i <= 91){
        return i-65+27;
    } else {
        return i-96;
    }
}

int itemIn2comp(char *buff1, char *buff2, int buffLen){
    for (int i=0; i<buffLen; i++){
        for (int j=0; j<buffLen; j++){
	    if (buff1[i] == buff2[j]){
	        return priority(buff1[i]);
	    }
	}
    }
    return 0;
}

int itemIn3bagpacks(char *buff1, char *buff2, char *buff3, int buffLen){
    for (int i=0; i<buffLen; i++){
        for (int j=0; j<buffLen; j++){
	    if (buff1[i] == buff2[j]){
		for (k=0; k<buffLen; k++){
		if (buff3[k] == buff1[i]){
		    return priority(buff1[i]);
		}
		}
	    }
	}
    }
    return 0;
}

int main(void){
    FILE *input;
    char buff[255];
    int p = 0;

    input = fopen("input", "r");

    while (fgets(buff, 255, (FILE*)input) != NULL){
	// first part
	int buffLen = strlen(buff);
	char buff1[buffLen], buff2[buffLen];
	divideCompartments(buff, buff1, buff2, buffLen);
	p += itemIn2comp(buff1, buff2, buffLen/2);
    }

    fclose(input);
    printf("%d\n", p);


    return 0;
}
