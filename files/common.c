//
// Created by Gmw on 2021/8/20.
//

#include "common.h"

void printPosition(FILE *fp) {
    long pos = ftell(fp);
    printf("Current position = %ld\n", pos);
}

void sizeCheck() {
    printf("sizeof(char) = %lu\n", sizeof(char));
    printf("sizeof(short) = %lu\n", sizeof(short));
    printf("sizeof(int) = %lu\n", sizeof(int));
    printf("sizeof(long) = %lu\n", sizeof(long));
    printf("sizeof(long long) = %lu\n", sizeof(long long));
}

void printChar(int ch) {
    if (ch != EOF) {
        printf("char = [%c] and ascii code = [%d]\n", ch, ch);
    } else {
        printf("EOF\n");
    }
}
