

#include "tmcolor.h"

// 设置字体粗细
char* setFontAttribute(char *str, FontThickness flag)
{
    char *result = new char[strlen(str)+20];
    sprintf(result, "\033[%dm%s\033[0m", flag, str);
    return result;
}

// 设置字体颜色
char* setFontAttribute(char *str, FontColor flag)
{
    char *result = new char[strlen(str)+20];
    sprintf(result, "\033[%dm%s\033[0m", flag, str);
    return result;
}

// 设置背景颜色
char* setFontAttribute(char *str, BgColor flag)
{
    char *result = new char[strlen(str)+20];
    sprintf(result, "\033[%dm%s\033[0m", flag, str);
    return result;
}