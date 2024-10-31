#include <stdio.h>
#include <string.h>

void myRead(char *str) {                        // 将字符串读入到从str开始的一段内存中
    int i = 0;
    char c;     
    while ((c = getchar()) != '\n') {           // 检查读入的字符是否等于约定的字符串结尾字符，这里是'\n'
        str[i++] = c;
    }
    str[i] = '\0';                              // 注意字符串总是以'\0'作为结束
}

int main() {
    char str2[10], str1[10];
    printf("str1 = %p\nstr2 = %p\n", str1, str2);
    puts("Please input the first string:");
    myRead(str1);
    puts("Please input the second string:");
    myRead(str2);
    printf("Content of the second string: %s\n", str2);
    strcpy(str1, str2);
    printf("Result: %s\n", str1);
    printf("Content of the second string: %s\n", str2);
    return 0;
}