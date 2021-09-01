//
// Created by Gmw on 2021/9/1.
//
#include <malloc.h>
#include "stdio.h"
#include "math.h"

typedef struct version_node {
    int value;
    struct version_node *next;
} VersionNode;

int makeInt(const char *str, int start, int end) {
    // ascii码中48-57代表数字0-9

    int bitLen = end - start, sum = 0;
    for (int bit = bitLen - 1; bit >= 0; bit--, start++) {
        int asciiNumber = (*(str + start) - 48);
        sum += ((int) pow(10, bit)) * asciiNumber;
    }
    return sum;
}

VersionNode *newNode(int val, VersionNode *next) {
    VersionNode *node = (VersionNode *) calloc(1, sizeof(VersionNode *));
    node->value = val;
    node->next = next;
    return node;
}

void freeNode(VersionNode *head) {
    VersionNode *p = head, *q = p->next;
    while (p != NULL) {
        free(p);
        p = q;
        q = q == NULL ? NULL : q->next;
    }
}

VersionNode *makeNode(const char *str) {
    VersionNode *head = NULL, *p = NULL;
    int start = 0, index = 0;
    for (; *(str + index) != 0; index++) {
        if (*(str + index) == '.') {
            int val = makeInt(str, start, index);
            start = index + 1;
            if (p == NULL) {
                p = newNode(val, NULL);
                head = p;
            } else {
                p->next = newNode(val, NULL);
                p = p->next;
            }
        }
    }
    int val = makeInt(str, start, index);
    if (p == NULL) {
        p = newNode(val, NULL);
        head = p;
    } else {
        p->next = newNode(val, NULL);
    }
    return head;
}

/**
 * https://leetcode-cn.com/problems/compare-version-numbers/
 */
int compareVersion(char *version1, char *version2) {
    VersionNode *one = makeNode(version1), *two = makeNode(version2), *p = one, *q = two;
    int result = 0;
    while (1) {
        if (one->value == two->value) {
            if (one->next == NULL && two->next == NULL)
                break;
            else if (one->next == NULL)
                one->next = newNode(0, NULL);
            else if (two->next == NULL)
                two->next = newNode(0, NULL);
            one = one->next;
            two = two->next;
        } else if (one->value > two->value) {
            result = 1;
            break;
        } else {
            result = -1;
            break;
        }
    }
    freeNode(p);
    freeNode(q);
    return result;
}

int main() {
    printf("%d\n", compareVersion("1.01", "1.0000000000000001"));
}
