#include "stdio.h"
#include "common.h"

#define End(method) printf("################################### 函数[%s] End\n", method);

/**
 * 文本只读模式
 */
void mode_r(char *path) {
    FILE *fp;
    if ((fp = fopen(path, "r")) != NULL) {
        int ch;
        while ((ch = getc(fp)) != EOF) {
            printf("%c", ch);
        }
        fclose(fp);
    }
    End("mode_r")
}

/**
 * 文本写模式，文件不存在则创建；文件存在则将现有文件长度截为0
 */
void mode_w() {
    FILE *fp = fopen("mode_w.bak", "w");
    char *input = "Hello world!\nI am Mrag\n";
    unsigned char ch;
    int i = 0;
    while ((ch = *(input + i++)) != 0) {
        putc(ch, fp);
        printf("%c", ch);
    }
    fclose(fp);
    End("mode_w")
}

/**
 * 文本写模式，往末尾追加内容；不存在则创建文件
 */
void mode_a() {
    FILE *fp = fopen("mode_a.bak", "a");
    char *add = "add content\n";
    unsigned char ch;
    int i = 0;
    while ((ch = *(add + i++)) != 0) {
        putc(ch, fp);
    }
    fclose(fp);
    End("mode_a")
}

/**
 * a+ 模式，更新模式，可以读整个文件，只能从末尾添加文件内容
 */
void mode_aplus(char *path) {
    FILE *fp = fopen(path, "a+");

    // a+ 模式下直接写入流，内容指针会直接指向末尾
    putc('A', fp);
    printPosition(fp);

    // 中间定位函数，内容指针指向内容末尾
    fseek(fp, 0L, SEEK_END);
    printPosition(fp);

    // 此时尝试读取EOF
    printChar(getc(fp));
    printPosition(fp);

    fclose(fp);
    End("mode_aplus")
}

int main(int argc, char **argv) {
    sizeCheck();
    End("pre");
    if (argc > 1) {
        char *path = *(argv + 1);
        mode_r(path);
        mode_aplus(path);
    }
    mode_w();
    mode_a();
}
