#pragma once
#include <bits/stdc++.h>
using namespace std;
#pragma region typedef
typedef enum
{
    Black,
    Red,
    Green,
    Yellow,
    Blue,
    Magnta,
    Cyan,
    White,
    BrightBlack,
    BrightRed,
    BrightGreen,
    BrightYellow,
    BrightBlue,
    BrightMagnta,
    BrightCyan,
    BrightWhite,
} color;
typedef enum
{
    Bold,
    Dim,
    Italic,
    Underlined,
    Blink,
    Inverse,
    Hidden,
    Strike,
    DoubleUnderlined,
    Overlined,
} textStyle;
typedef unsigned char byte;
typedef byte colorRGB[3];
#pragma endregion typedef
#pragma region style
inline colorRGB *hexToRGB(unsigned int color)
{
    colorRGB rgb;
    rgb[0] = (color >> 16) & 0xFF;
    rgb[1] = (color >> 8) & 0xFF;
    rgb[2] = color & 0xFF;
    return &rgb;
}
inline string setColor(string text, colorRGB foreGround, colorRGB backGround)
{
    return "\x1b[38;2;" + to_string(foreGround[0]) + ";" + to_string(foreGround[1]]) + ";" + to_string(foreGround[2]) + ";38;2;" + to_string(backGround[0]) + ";" + to_string(backGround[1]) + ";" + to_string(backGround[2]) + "m" + text + "\x1b[0m";
}
inline string setForeGround(string text, colorRGB foreGround)
{
    return "\x1b[38;2;" + to_string(foreGround[0]) + ";" + to_string(foreGround[1]]) + ";" + to_string(foreGround[2]) + "m" + text + "\x1b[0m";
}
inline string setBackGround(string text, colorRGB backGround)
{
    return "\x1b[48;2;" + to_string(backGround[0]) + ";" + to_string(backGround[1]) + ";" + to_string(backGround[2]) + "m" + text + "\x1b[0m";
}
inline string setColor(string text, int hexForeGround, int hexBackGround)
{
    return setColor(text, *hexToRGB(hexForeGround), *hexToRGB(hexBackGround));
}
inline string setForeGround(string text, int hexForeGround)
{
    return setForeGround(text, *hexToRGB(hexForeGround));
}
inline string setBackGround(string text, int hexBackGround)
{
    return setBackGround(text, *hexToRGB(hexBackGround));
}
inline string setColor(string text, color foreGround, color backGround)
{
    return setColor(text, *hexToRGB(foreGround), *hexToRGB(backGround));
}
string setStyle(string text, textStyle style)
{
    switch (style)
    {
    case Bold:
        return "\x1b[1m" + text + "\x1b[0m";
        break;
    case Dim:
        return "\x1b[2m" + text + "\x1b[0m";
        break;
    case Italic:
        return "\x1b[3m" + text + "\x1b[0m";
        break;
    case Underlined:
        return "\x1b[4m" + text + "\x1b[0m";
        break;
    case Blink:
        return "\x1b[5m" + text + "\x1b[0m";
        break;
    case Inverse:
        return "\x1b[7m" + text + "\x1b[0m";
        break;
    case Hidden:
        return "\x1b[8m" + text + "\x1b[0m";
        break;
    case Strike:
        return "\x1b[9m" + text + "\x1b[0m";
        break;
    case DoubleUnderlined:
        return "\x1b[21m" + text + "\x1b[0m";
        break;
    case Overlined:
        return "\x1b[53m" + text + "\x1b[0m";
        break;
    default:
        break;
    }
}

#pragma endregion style