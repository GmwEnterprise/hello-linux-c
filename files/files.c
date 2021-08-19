#include "stdio.h"

int main() {
    char *filepath = "D:\\Projects\\hello-linux-c\\files\\words.txt";

    // 如果这里使用相对路径，由于执行文件在cmake-build-debug文件夹里，所以要用 ..\\words.txt 才能访问
    FILE *fp = fopen(filepath, "rb");
    int ch;
    while ((ch = getc(fp)) != -1) {
        if (ch == '\r' || ch == '\n') {
            // 打印 \r \n 的ascii码值，结果为 13 10
            printf(" [%d]\n", ch);
        } else if (ch < 128) {
            printf("%c", ch);
        } else {
            printf("%x", ch);
        }
    }
    fclose(fp);
    return 0;
}

/*
D:\Projects\hello-linux-c\files\cmake-build-debug\files.exe
hello world! [13]
 [10]
fxxk [13]
 [10]
e4bda0e5a5bd [13]
 [10]
$$$
Process finished with exit code 0
*/
