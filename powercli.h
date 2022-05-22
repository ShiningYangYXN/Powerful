#pragma once

#include <bits/stdc++.h>

using namespace std;

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
    BrightWight
} color;
typedef enum
{
    Bold,
    Weak,
    Italic,
    Underlined,
    Twinkle,
    Opposite,
    Hidden,
    Deleted,
    DoubleUnderline,
    OverLined
} style;

string setColor(string text, int foreColorR, int foreColorG, int foreColorB, int backColorR, int backColorG, int backColorB)
{
    if (foreColorR >= 0 && foreColorR <= 255 && foreColorG >= 0 && foreColorG <= 255 && foreColorB >= 0 && foreColorB <= 255 && backColorR >= 0 && backColorR <= 255 && backColorG >= 0 && backColorG <= 255 && backColorB >= 0 && backColorB <= 255) // Value-check
    {
        return "\x1b[38;2;" + to_string(foreColorR) + ";" + to_string(foreColorG) + ";" + to_string(foreColorB) + "m\x1b[38;2;" + to_string(backColorR) + ";" + to_string(backColorG) + ";" + to_string(backColorB) + "m" + text + "\x1b[0m";
    }
    else
    {
        return "\x1b[41mE\x1b[0m:\x1b[31mInvalid Arguments\x1b[0m";
    }
}
string setForeGround(string text, int r, int g, int b)
{
    if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255) // Value-check
    {
        return "\x1b[38;2;" + to_string(r) + ";" + to_string(g) + ";" + to_string(b) + "m" + text + "\x1b[0m";
    }
    else
    {
        return "\x1b[41mE\x1b[0m:\x1b[31mInvalid Arguments\x1b[0m";
    }
}
string setBackGround(string text, int r, int g, int b)
{
    if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255) // Value-check
    {
        return "\x1b[48;2;" + to_string(r) + ";" + to_string(g) + ";" + to_string(b) + "m" + text + "\x1b[0m";
    }
    else
    {
        return "\x1b[41mE\x1b[0m:\x1b[31mInvalid Arguments\x1b[0m";
    }
}
string setColor(string text, string foreColor, string backColor)
{
    if (foreColor.length() == backColor.length() == 7 && foreColor[0] == backColor[0] == '#') // Value check
    {
        try
        {
            setColor(text, stoi(string(&foreColor[1]) + string(&foreColor[2]), 0, 16), stoi(string(&foreColor[3]) + string(&foreColor[4]), 0, 16), stoi(string(&foreColor[5]) + string(&foreColor[6]), 0, 16), stoi(string(&backColor[1]) + string(&backColor[2]), 0, 16), stoi(string(&backColor[3]) + string(&backColor[4]), 0, 16), stoi(string(&backColor[5]) + string(&backColor[6]), 0, 16));
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            return "\x1b[41mE\x1b[0m:\x1b[31mInvalid Arguments\x1b[0m";
        }
    }
    else
        return "\x1b[41mE\x1b[0m:\x1b[31mInvalid Arguments\x1b[0m";
}
string setForeGround(string text, string foreColor)
{
    if (foreColor.length() == 7 && foreColor[0] == '#') // Value check
    {
        try
        {
            setForeGround(text, stoi(string(&foreColor[1]) + string(&foreColor[2]), 0, 16), stoi(string(&foreColor[3]) + string(&foreColor[4]), 0, 16), stoi(string(&foreColor[5]) + string(&foreColor[6]), 0, 16));
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            return "\x1b[41mE\x1b[0m:\x1b[31mInvalid Arguments\x1b[0m";
        }
    }
    else
    {
        return "\x1b[41mE\x1b[0m:\x1b[31mInvalid Arguments\x1b[0m";
    }
}
string setBackGround(string text, string backColor)
{
    if (backColor.length() == 7 && backColor[0] == '#') // Value check
    {
        try
        {
            setBackGround(text, stoi(string(&backColor[1]) + string(&backColor[2]), 0, 16), stoi(string(&backColor[3]) + string(&backColor[4]), 0, 16), stoi(string(&backColor[5]) + string(&backColor[6]), 0, 16));
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            return "\x1b[41mE\x1b[0m:\x1b[31mInvalid Arguments\x1b[0m";
        }
    }
    else
    {
        return "\x1b[41mE\x1b[0m:\x1b[31mInvalid Arguments\x1b[0m";
    }
}
string setColor(string text, color foreColor, color backColor)
{
    if (foreColor <= 7)
    {
        if (backColor <= 7)
        {
            return "\x1b[3" + to_string(foreColor) + "m\x1b[4" + to_string(backColor) + "m" + text + "\x1b[0m";
        }
        else
        {
            return "\x1b[3" + to_string(foreColor) + "m\x1b[10" + to_string(backColor - 8) + "m" + text + "\x1b[0m";
        }
    }
    else
    {
        if (backColor <= 7)
        {
            return "\x1b[9" + to_string(foreColor) + "m\x1b[4" + to_string(backColor) + "m" + text + "\x1b[0m";
        }
        else
        {
            return "\x1b[9" + to_string(foreColor) + "m\x1b[10" + to_string(backColor - 8) + "m" + text + "\x1b[0m";
        }
    }
}
string setForeGround(string text, color foreColor)
{
    if (foreColor <= 7)
    {
        return "\x1b[3" + to_string(foreColor) + "m" + text + "\x1b[0m";
    }
    else
    {
        return "\x1b[9" + to_string(foreColor) + "m" + text + "\x1b[0m";
    }
}
string setBackGround(string text, color backColor)
{
    if (backColor <= 7)
    {
        return "\x1b[4" + to_string(backColor) + "m" + text + "\x1b[0m";
    }
    else
    {
        return "\x1b[10" + to_string(backColor) + "m" + text + "\x1b[0m";
    }
}
string setStyle(string text, style textStyle)
{
    switch (textStyle)
    {
    case 0:
        return "\x1b[1m" + text + "\x1b[0m";
        break;
    case 1:
        return "\x1b[2m" + text + "\x1b[0m";
        break;
    default:
        break;
    }
}
void setTitle(string title)
{
    system(("title " + title).c_str());
}
void setCursor(int x, int y)
{
    puts(("\x1b[" + to_string(x) + ";" + to_string(y) + "H").c_str());
}
void cursorUp(int n)
{
    puts(("\x1b[" + to_string(n) + "A").c_str());
}
void cursorDown(int n)
{
    puts(("\x1b[" + to_string(n) + "B").c_str());
}
void cursorLeft(int n)
{
    puts(("\x1b[" + to_string(n) + "C").c_str());
}
void cursorRight(int n)
{
    puts(("\x1b[" + to_string(n) + "D").c_str());
}
void cursorNextLine(int n)
{
    puts(("\x1b[" + to_string(n) + "E").c_str());
}
void cursorPrevLine(int n)
{
    puts(("\x1b[" + to_string(n) + "F").c_str());
}
void cursorGotoColumn(int n)
{
    puts(("\x1b[" + to_string(n) + "G").c_str());
}
void scrollUp(int n)
{
    puts(("\x1b[" + to_string(n) + "S").c_str());
}
void scrollDown(int n)
{
    puts(("\x1b[" + to_string(n) + "T").c_str());
}
void eraseLine()
{
    puts("\x1b[2K");
}
void clearScreen()
{
    puts("\x1b[2D");
}
void saveCursor()
{
    puts("\x1b[s");
}
void restoreCursor()
{
    puts("\x1b[u");
}