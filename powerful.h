#pragma once
#include <bits/stdc++.h>
using namespace std;
#pragma region type - def

typedef enum
{
    Fraction,
    Percentage,
    None,
} progressbarPromptStyle;
typedef enum
{
    Legacy,
    Modern,
    Line,
} progressbarStyle;
typedef enum
{
    Info,
    Success,
    Warning,
    Error,
} msgType;
typedef enum
{
    Classic,
    Block,
    Iconed,
    NoColor,
} msgStyle;
#pragma endregion type - def
#pragma region function - def

#pragma endregion function - def

void setTitle(string title)
{
    system(("title " + title).c_str());
}
#pragma region cursor
void cursorGoto(int x, int y)
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
#pragma endregion cursor
#pragma region controls
string progressBar(int progress, int maxProgress = 100, int width = 50, string foreGround = "#FFFFFF", string backGround = "#000000", char symbol = '=', char leftBorder = '[', char rightBorder = ']', progressbarPromptStyle promptStyle = Percentage)
{
    string bar = string(&leftBorder, 1);
    int progressWidth = (progress * width) / maxProgress;
    for (int i = 0; i < width; i++)
    {
        if (i < progressWidth)
        {
            bar += setColor(string(&symbol, 1), foreGround, backGround);
        }
        else
        {
            bar += setColor(" ", foreGround, backGround);
        }
    }
    bar += string(&rightBorder, 1);
    switch (promptStyle)
    {
    case Fraction:
        bar += " " + to_string(progress) + "/" + to_string(maxProgress);
        break;
    case Percentage:
        bar += " " + to_string(float(progress / maxProgress)) + "%";
        break;
    case None:
        break;
    default:
        break;
    }
    return bar;
}
string progressBar(int progress, int maxProgress = 100, int width = 50, color foreGround = White, color backGround = Black, char symbol = '=', char leftBorder = '[', char rightBorder = ']', progressbarPromptStyle promptStyle = Percentage)
{
    string bar = string(&leftBorder, 1);
    int progressWidth = (progress * width) / maxProgress;
    for (int i = 0; i < width; i++)
    {
        if (i < progressWidth)
        {
            bar += setColor(string(&symbol, 1), foreGround, backGround);
        }
        else
        {
            bar += setColor(" ", foreGround, backGround);
        }
    }
    bar += string(&rightBorder, 1);
    switch (promptStyle)
    {
    case Fraction:
        bar += " " + to_string(progress) + "/" + to_string(maxProgress);
        break;
    case Percentage:
        bar += " " + to_string(float(progress / maxProgress)) + "%";
        break;
    case None:
        break;
    default:
        break;
    }
    return bar;
}
string progressBar(int progress, int maxProgress = 100, int width = 50, color foreGround = White, color backGround = Black, char symbol = '=', char leftBorder = '[', char rightBorder = ']', color promptForeGround = Black, color promptBackGround = White, char promptLeftBorder = '(', char promptRightBorder = ')', progressbarPromptStyle promptStyle = Percentage)
{
    string bar = string(&leftBorder, 1);
    int progressWidth = (progress * width) / maxProgress;
    for (int i = 0; i < width; i++)
    {
        if (i < progressWidth)
        {
            bar += " " + setColor(string(&symbol, 1), foreGround, backGround);
        }
        else
        {
            bar += " " + setColor(" ", foreGround, backGround);
        }
    }
    bar += string(&rightBorder, 1);
    switch (promptStyle)
    {
    case Fraction:
        bar += " " + setColor(string(&promptLeftBorder, 1) + to_string(progress) + "/" + to_string(maxProgress) + string(&promptRightBorder, 1), promptForeGround, promptBackGround);
        break;
    case Percentage:
        bar += " " + setColor(string(&promptLeftBorder, 1) + to_string(float(progress / maxProgress)) + "%" + string(&promptRightBorder, 1), promptForeGround, promptBackGround);
        break;
    case None:
        break;

    default:
        break;
    }
    return bar;
}
string progressBar(int progress, int maxProgress = 100, int width = 50, string foreGround = "#FFFFFF", string backGround = "#000000", char symbol = '=', char leftBorder = '[', char rightBorder = ']', string promptForeGround = "#000000", string promptBackGround = "#FFFFFF", char promptLeftBorder = '(', char promptRightBorder = ')', progressbarPromptStyle promptStyle = Percentage)
{
    string bar = string(&leftBorder, 1);
    int progressWidth = (progress * width) / maxProgress;
    for (int i = 0; i < width; i++)
    {
        if (i < progressWidth)
        {
            bar += setColor(string(&symbol, 1), foreGround, backGround);
        }
        else
        {
            bar += setColor(" ", foreGround, backGround);
        }
    }
    bar += string(&rightBorder, 1);
    switch (promptStyle)
    {
    case Fraction:
        bar += " " + setColor(string(&promptLeftBorder, 1) + to_string(progress) + "/" + to_string(maxProgress) + string(&promptRightBorder, 1), promptForeGround, promptBackGround);
        break;
    case Percentage:
        bar += " " + setColor(string(&promptLeftBorder, 1) + to_string(float(progress / maxProgress)) + "%" + string(&promptRightBorder, 1), promptForeGround, promptBackGround);
        break;
    case None:
        break;
    default:
        break;
    }
    return bar;
}
string progressBar(int progress, int maxProgress = 100, int width = 50, color foreGround = White, color backGround = Black, progressbarPromptStyle promptStyle = Percentage)
{
    string bar = "";
    int progressWidth = (progress * width) / maxProgress;
    for (int i = 0; i < width; i++)
    {
        if (i < progressWidth)
        {
            bar += setBackGround(" ", foreGround);
        }
        else
        {
            bar += setBackGround(" ", backGround);
        }
    }
    switch (promptStyle)
    {
    case progressbarPromptStyle::Fraction:
        bar += " " + to_string(progress) + "/" + to_string(maxProgress);
        break;
    case progressbarPromptStyle::Percentage:
        bar += " " + to_string(float(progress / maxProgress)) + "%";
        break;
    case progressbarPromptStyle::None:
        break;
    default:
        break;
    }
    return bar;
}
string progressBar(int progress, int maxProgress = 100, int width = 50, string foreGround = "#FFFFFF", string backGround = "#000000", progressbarPromptStyle promptStyle = Percentage)
{
    string bar = "";
    int progressWidth = (progress * width) / maxProgress;
    for (int i = 0; i < width; i++)
    {
        if (i < progressWidth)
        {
            bar += setBackGround(" ", foreGround);
        }
        else
        {
            bar += setBackGround(" ", backGround);
        }
    }
    switch (promptStyle)
    {
    case Fraction:
        bar += " " + to_string(progress) + "/" + to_string(maxProgress);
        break;
    case Percentage:
        bar += " " + to_string(float(progress / maxProgress)) + "%";
        break;
    case None:
        break;
    default:
        break;
    }
    return bar;
}
string progressBar(int progress, int maxProgress = 100, int width = 50, color foreGround = White, color backGround = Black, color promptForeGround = Black, color promptBackGround = White, progressbarPromptStyle promptStyle = Percentage)
{
    string bar = "";
    int progressWidth = (progress * width) / maxProgress;
    for (int i = 0; i < width; i++)
    {
        if (i < progressWidth)
        {
            bar += setBackGround(" ", foreGround);
        }
        else
        {
            bar += setBackGround(" ", backGround);
        }
    }
    switch (promptStyle)
    {
    case Fraction:
        bar += " " + setColor(to_string(progress) + "/" + to_string(maxProgress), promptForeGround, promptBackGround);
        break;
    case Percentage:
        bar += " " + setColor(to_string(float(progress / maxProgress)) + "%", promptForeGround, promptBackGround);
        break;
    case None:
        break;
    default:
        break;
    }
    return bar;
}
string progressBar(int progress, int maxProgress = 100, int width = 50, progressbarStyle style = progressbarStyle::Modern, progressbarPromptStyle promptStyle = Percentage)
{
    string bar = "";
    switch (style)
    {
    case progressbarStyle::Modern or progressbarStyle::Line:
        break;
    case progressbarStyle::Legacy:
        bar += "[";
        break;
    default:
        break;
        int progressWidth = (progress * width) / maxProgress;
        for (int i = 0; i < width; i++)
        {
            if (i < progressWidth)
            {
                switch (style)
                {
                case progressbarStyle::Modern:
                    bar += setStyle(" ", Inverse);
                    break;
                case progressbarStyle::Legacy:
                    bar += "=";
                    break;
                case progressbarStyle::Line:
                    bar += "-";
                    break;
                default:
                    break;
                }
            }
            else
            {
                bar += " ";
            }
        }
        switch (style)
        {
        case Modern:
            break;
        case Legacy:
            bar += "]";
            break;

            switch (promptStyle)
            {
            case progressbarPromptStyle::Fraction:
                bar += " " + to_string(progress) + "/" + to_string(maxProgress);
                break;
            case progressbarPromptStyle::Percentage:
                bar += " " + to_string(float(progress / maxProgress)) + "%";
                break;
            case progressbarPromptStyle::None:
                break;
            default:
                break;
            }
            return bar;
        }
    }
}
string message(string msg, msgType type, msgStyle style)
{
    switch (type)
    {
    case Info:
        switch (style)
        {
        case Classic:
            return setForeGround("[INFO] ", Blue) + msg;
            break;
        case Block:
            return setBackGround("[INFO] ", Blue) + setForeGround(msg, BrightBlue);
            break;
        case Iconed:
            return setBackGround("\u24d8 [INFO] ", Blue) + setForeGround(msg, BrightBlue);
            break;
        case NoColor:
            return "[INFO] " + msg;
            break;
        default:
            break;
        }
        break;
    case Warning:
        switch (style)
        {
        case Legacy:
            return setForeGround("[WARNING] ", Yellow) + msg;
            break;
        case Modern:
            return setBackGround("[WARNING] ", Yellow) + setForeGround(msg, BrightYellow);
            break;
        case Iconed:
            return setBackGround("\u26a0 [WARNING] ", Yellow) + setForeGround(msg, BrightYellow);
            break;
        case NoColor:
            return "[WARNING] " + msg;
            break;
        default:
            break;
        }
        break;
    case Error:
        switch (style)
        {
        case Legacy:
            return setForeGround("[ERROR] ", Red) + msg;
            break;
        case Modern:
            return setBackGround("[ERROR] ", Red) + setForeGround(msg, BrightRed);
            break;
        case Iconed:
            return setBackGround("\u2297 [ERROR] ", Red) + setForeGround(msg, BrightRed);
            break;
        case NoColor:
            return "[ERROR] " + msg;
            break;
        default:
            break;
        }
        break;
    case Success:
        switch (style)
        {
        case Legacy:
            return setForeGround("[SUCCESS] ", Green) + msg;
            break;
        case Modern:
            return setBackGround("[SUCCESS] ", Green) + setForeGround(msg, BrightGreen);
            break;
        case Iconed:
            return setBackGround("\u2713 [SUCCESS] ", Green) + setForeGround(msg, BrightGreen);
            break;
        case NoColor:
            return "[SUCCESS] " + msg;
            break;
        }
        break;
    default:
        break;
    }
}
void showSpinner(string prompt = "Loading...", int delay = 100)
{
    char spinner[] = {'|', '/', '-', '\\'};
    int i = 0;
    while (true)
    {
        cout << "\r" << prompt << " " << spinner[i];
        i++;
        if (i == 3)
        {
            i = 0;
        }
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
}
#pragma endregion controls