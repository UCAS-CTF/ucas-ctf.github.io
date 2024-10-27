#include <stdio.h>
#include <string.h>

void read(char *str) {                          // 将字符串读入到从str开始的一段内存中
    int i = 0;
    char c;     
    while ((c = getchar()) != '\n') {           // 检查读入的字符是否等于约定的字符串结尾字符，这里是'\n'
        str[i++] = c;
    }
    str[i] = '\0';                              // 注意字符串总是以'\0'作为结束
}

int main() {
    char str2[10], str1[10];
    puts("Please input the first string:");
    read(str1);
    puts("Please input the second string:");
    read(str2);
    char *res = strstr(str1, str2);
    if (res == NULL) {
        puts("Not Found.");
    } else {
        printf("Found at %d.\n", (int)(res - str1));
    }
    return 0;
}