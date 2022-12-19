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

int itemIn3backpacks(char *buff1, char *buff2, char *buff3){
    int l1 = strlen(buff1);
    int l2 = strlen(buff2);
    int l3 = strlen(buff3);
    printf("%s, %s, %s", buff1, buff2, buff3);
    printf("%d, %d, %d\n", l1, l2, l3);
    for (int i=0; i<l1; i++){
        for (int j=0; j<l2; j++){
	    if (buff1[i] == buff2[j]){
		for (int k=0; k<l3; k++){
		if (buff3[k] == buff1[i]){
		    printf("%c", buff1[i]);
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
    int i = 0;
    int elves = 0;

    input = fopen("input", "r");

    while (fgets(buff, 255, input) != NULL){
        char elf1[255], elf2[255], elf3[255];
	if (i%3 == 0){
	    strcpy(elf1, buff);
	} else if (i%3 == 1){
	    strcpy(elf2, buff);
	} else {
	    strcpy(elf3, buff);
            elves += itemIn3backpacks(elf1, elf2, elf3);
	}
	int buffLen = strlen(buff);
	char buff1[buffLen], buff2[buffLen];
	divideCompartments(buff, buff1, buff2, buffLen);
	p += itemIn2comp(buff1, buff2, buffLen/2);
	i++;
    }

    fclose(input);
    printf("%d\n", p);
    printf("%d\n", elves);


    return 0;
}
