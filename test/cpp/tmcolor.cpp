

#include "tmcolor.h"

// 设置字体粗细
string setFontThickness(string str, FontThickness flag)
{
    string result;
    result = "\033[" + to_string(flag) + "m" + str + "\033[0m";
    return result;
}

// 设置字体颜色
string setFontColor(string str, FontColor flag)
{
    string result;
    result = "\033[" + to_string(flag) + "m" + str + "\033[0m";
    return result;
}

// 设置背景颜色
string setBgColor(string str, BgColor flag)
{
    string result;
    result = "\033[" + to_string(flag) + "m" + str + "\033[0m";
    return result;
}