/*
 *计算字符串最后一个单词的长度，单词以空格隔开，字符串长度小于5000
 *
 *
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[5000] = {0};
    char *str_p = str;
    int count = 0;
    fgets(str, sizeof(str), stdin);

    int str_len = strlen(str) - 1;//减去换行符
    if (str_len <= 0) {
        printf("0\n");
        return 0;
    }

    str_p = str_p + str_len - 1;
    for (int i = 0; i < str_len; i++) {
        if (*str_p != ' ')
            count++;
        else
            break;
        str_p--;
    }

    printf("%d\n", count);
    return 0;
}
