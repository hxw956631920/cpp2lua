
/*    
    Copyright (c) 2012-2020
    TODO:    待书写
    Author:  Baldwey(黄新伟)
    Date:    2020.11.1
*/
   
/*
 * 此文件封装了设置终端字体颜色的库
*/

#ifndef __TERMINALCOLOR_H_
#define __TERMINALCOLOR_H_

#include <iostream>

using namespace std;
// 字体粗细
enum FontThickness{
    BOLD            = 1,//粗体
    NORMAL            = 0,//正常
};

// 字体颜色
enum FontColor{
    FC_BLACK        = 30,//黑色
    FC_RED          = 31,//红色
    FC_GREEN        = 32,//绿色
    FC_BROWN        = 33,//棕色
    FC_BLUE         = 34,//蓝色
    FC_PURPLE       = 35,//紫色
    FC_CYAN         = 36,//青色
    FC_WHITE        = 37,//白色
};

// 背景颜色
enum BgColor{
    BC_BLACK        = 40,//黑色
    BC_RED          = 41,//红色
    BC_GREEN        = 42,//绿色
    BC_BROWN        = 43,//棕色
    BC_BLUE         = 44,//蓝色
    BC_PURPLE       = 45,//紫色
    BC_CYAN         = 46,//青色
    BC_WHITE        = 47,//白色
    BC_DEFAULT         = 49,//缺省黑色背景
};

// 枚举映射表
typedef struct enumMapping{
    int value;
    string name;
}enumMapping;

extern enumMapping tmcolorMap[];

// 根据枚举值获取枚举名
string getEnumName(int flag);

// 设置字体粗细
string setFontThickness(string str, FontThickness flag = NORMAL);

// 设置字体颜色
string setFontColor(string str, FontColor flag = FC_CYAN);

// 设置背景颜色
string setBgColor(string str, BgColor flag = BC_BLACK);
#endif