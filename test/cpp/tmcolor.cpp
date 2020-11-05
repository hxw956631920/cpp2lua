

#include "tmcolor.h"

enumMapping tmcolorMap[] = {
    {BOLD, "BOLD"}, {NORMAL, "NORMAL"}, 
    {FC_BLACK, "FC_BLACK"}, {FC_RED, "FC_RED"}, {FC_GREEN, "FC_GREEN"}, 
    {FC_BROWN, "FC_BROWN"}, {FC_BLUE, "FC_BLUE"}, {FC_PURPLE, "FC_PURPLE"},
    {FC_CYAN, "FC_CYAN"}, {FC_WHITE, "FC_WHITE"},
    {BC_BLACK, "BC_BLACK"}, {BC_RED, "BC_RED"}, {BC_GREEN, "BC_GREEN"},
    {BC_BROWN, "BC_BROWN"}, {BC_BLUE, "BC_BLUE"}, {BC_PURPLE, "BC_PURPLE"},
    {BC_CYAN, "BC_CYAN"}, {BC_WHITE, "BC_WHITE"}, {BC_DEFAULT, "BC_DEFAULT"}
};

// 根据枚举值获取枚举名
string getEnumName(int flag)
{
    for (int i = 0; i < sizeof(tmcolorMap)/sizeof(enumMapping); i++)
    {
        if (flag == tmcolorMap[i].value)
        {
            return tmcolorMap[i].name;
        }
    }
    return "";
}

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