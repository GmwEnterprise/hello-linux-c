//
// Created by Gmw on 2021/8/20.
//

#include "common.h"

void printPosition(FILE *fp) {
    long pos = ftell(fp);
    printf("Current position = %ld\n", pos);
}

void sizeCheck() {
    printf("sizeof(char) = %llu\n", sizeof(char));
    printf("sizeof(short) = %llu\n", sizeof(short));
    printf("sizeof(int) = %llu\n", sizeof(int));
    printf("sizeof(long) = %llu\n", sizeof(long));
    printf("sizeof(long long) = %llu\n", sizeof(long long));
}

void printChar(int ch) {
    if (ch != EOF) {
        printf("char = [%c] and ascii code = [%d]\n", ch, ch);
    } else {
        printf("EOF\n");
    }
}
