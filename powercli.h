#pragma once
#include <bits/stdc++.h>
using namespace std;
#pragma region type - def
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
    BrightWight,
} color;
typedef enum
{
    Bold,
    Weak,
    Italic,
    Underlined,
    Blink,
    Inverted,
    Hidden,
    Strike,
    DoubleUnderlined,
    Overlined,
} textStyle;
typedef enum
{
    Fraction,
    Percentage,
    None,
} progressbarPromptStyle;
typedef enum
{
    Info,
    Success,
    Warning,
    Error,
} msgType;
#pragma endregion type - def
#pragma region style
string setColor(string text, int foreGroundR, int foreGroundG, int foreGroundB, int backGroundR, int backGroundG, int backGroundB)
{
    if (foreGroundR >= 0 && foreGroundR <= 255 && foreGroundG >= 0 && foreGroundG <= 255 && foreGroundB >= 0 && foreGroundB <= 255 && backGroundR >= 0 && backGroundR <= 255 && backGroundG >= 0 && backGroundG <= 255 && backGroundB >= 0 && backGroundB <= 255) // Value-check
    {
        return "\x1b[38;2;" + to_string(foreGroundR) + ";" + to_string(foreGroundG) + ";" + to_string(foreGroundB) + ";38;2;" + to_string(backGroundR) + ";" + to_string(backGroundG) + ";" + to_string(backGroundB) + "m" + text + "\x1b[0m";
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
string setColor(string text, string foreGround, string backGround)
{
    if (foreGround.length() == backGround.length() == 7 && foreGround[0] == backGround[0] == '#') // Value check
    {
        try
        {
            setColor(text, stoi(string(&foreGround[1]) + string(&foreGround[2]), 0, 16), stoi(string(&foreGround[3]) + string(&foreGround[4]), 0, 16), stoi(string(&foreGround[5]) + string(&foreGround[6]), 0, 16), stoi(string(&backGround[1]) + string(&backGround[2]), 0, 16), stoi(string(&backGround[3]) + string(&backGround[4]), 0, 16), stoi(string(&backGround[5]) + string(&backGround[6]), 0, 16));
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
string setForeGround(string text, string foreGround)
{
    if (foreGround.length() == 7 && foreGround[0] == '#') // Value check
    {
        try
        {
            setForeGround(text, stoi(string(&foreGround[1]) + string(&foreGround[2]), 0, 16), stoi(string(&foreGround[3]) + string(&foreGround[4]), 0, 16), stoi(string(&foreGround[5]) + string(&foreGround[6]), 0, 16));
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
string setBackGround(string text, string backGround)
{
    if (backGround.length() == 7 && backGround[0] == '#') // Value check
    {
        try
        {
            setBackGround(text, stoi(string(&backGround[1]) + string(&backGround[2]), 0, 16), stoi(string(&backGround[3]) + string(&backGround[4]), 0, 16), stoi(string(&backGround[5]) + string(&backGround[6]), 0, 16));
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
string setColor(string text, color foreGround, color backGround)
{
    if (foreGround <= 7)
    {
        if (backGround <= 7)
        {
            return "\x1b[3" + to_string(foreGround) + ";4" + to_string(backGround) + "m" + text + "\x1b[0m";
        }
        else
        {
            return "\x1b[3" + to_string(foreGround) + ";10" + to_string(backGround - 8) + "m" + text + "\x1b[0m";
        }
    }
    else
    {
        if (backGround <= 7)
        {
            return "\x1b[9" + to_string(foreGround) + ";4" + to_string(backGround) + "m" + text + "\x1b[0m";
        }
        else
        {
            return "\x1b[9" + to_string(foreGround) + ";10" + to_string(backGround - 8) + "m" + text + "\x1b[0m";
        }
    }
}
string setForeGround(string text, color foreGround)
{
    if (foreGround <= 7)
    {
        return "\x1b[3" + to_string(foreGround) + "m" + text + "\x1b[0m";
    }
    else
    {
        return "\x1b[9" + to_string(foreGround) + "m" + text + "\x1b[0m";
    }
}
string setBackGround(string text, color backGround)
{
    if (backGround <= 7)
    {
        return "\x1b[4" + to_string(backGround) + "m" + text + "\x1b[0m";
    }
    else
    {
        return "\x1b[10" + to_string(backGround) + "m" + text + "\x1b[0m";
    }
}
string setColor(string text, int foreGround, int backGround)
{
    if (foreGround >= 0 && foreGround < 256 && backGround >= 0 && backGround < 256)
    {
        return "\x1b[38;5;" + to_string(foreGround) + ";48;5;" + to_string(backGround) + "m" + text + "\x1b[0m";
    }
    else
    {
        return "\x1b[41mE\x1b[0m:\x1b[31mInvalid Arguments\x1b[0m";
    }
}
string setForeGround(string text, int foreGround)
{
    if (foreGround >= 0 && foreGround < 256)
    {
        return "\x1b[38;5;" + to_string(foreGround) + "m" + text + "\x1b[0m";
    }
    else
    {
        return "\x1b[41mE\x1b[0m:\x1b[31mInvalid Arguments\x1b[0m";
    }
}
string setBackGround(string text, int backGround)
{
    if (backGround >= 0 && backGround < 256)
    {
        return "\x1b[48;5;" + to_string(backGround) + "m" + text + "\x1b[0m";
    }
    else
    {
        return "\x1b[41mE\x1b[0m:\x1b[31mInvalid Arguments\x1b[0m";
    }
}
string setStyle(string text, textStyle style)
{
    switch (style)
    {
    case textStyle::Bold:
        return "\x1b[1m" + text + "\x1b[0m";
        break;
    case textStyle::Weak:
        return "\x1b[2m" + text + "\x1b[0m";
        break;
    case textStyle::Italic:
        return "\x1b[3m" + text + "\x1b[0m";
        break;
    case textStyle::Underlined:
        return "\x1b[4m" + text + "\x1b[0m";
        break;
    case textStyle::Blink:
        return "\x1b[5m" + text + "\x1b[0m";
        break;
    case textStyle::Inverted:
        return "\x1b[7m" + text + "\x1b[0m";
        break;
    case textStyle::Hidden:
        return "\x1b[8m" + text + "\x1b[0m";
        break;
    case textStyle::Strike:
        return "\x1b[9m" + text + "\x1b[0m";
        break;
    case textStyle::DoubleUnderlined:
        return "\x1b[21m" + text + "\x1b[0m";
        break;
    case textStyle::Overlined:
        return "\x1b[53m" + text + "\x1b[0m";
        break;
    default:
        break;
    }
}

#pragma endregion style
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
string progressBar(int progress, int maxProgress, int width, string foreGround, string backGround, char symbol, char leftBorder, char rightBorder, progressbarPromptStyle promptStyle)
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
string progressBar(int progress, int maxProgress, int width, color foreGround, color backGround, char symbol, char leftBorder, char rightBorder, progressbarPromptStyle promptStyle)
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
string progressBar(int progress, int maxProgress, int width, color foreGround, color backGround, char symbol, char leftBorder, char rightBorder, color promptForeGround, color promptBackGround, char promptLeftBorder, char promptRightBorder, progressbarPromptStyle promptStyle)
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
    case progressbarPromptStyle::Fraction:
        bar += " " + setColor(string(&promptLeftBorder, 1) + to_string(progress) + "/" + to_string(maxProgress) + string(&promptRightBorder, 1), promptForeGround, promptBackGround);
        break;
    case progressbarPromptStyle::Percentage:
        bar += " " + setColor(string(&promptLeftBorder, 1) + to_string(float(progress / maxProgress)) + "%" + string(&promptRightBorder, 1), promptForeGround, promptBackGround);
        break;
    case progressbarPromptStyle::None:
        break;

    default:
        break;
    }
    return bar;
}
string progressBar(int progress, int maxProgress, int width, string foreGround, string backGround, char symbol, char leftBorder, char rightBorder, string promptForeGround, string promptBackGround, char promptLeftBorder, char promptRightBorder, progressbarPromptStyle promptStyle)
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
    case progressbarPromptStyle::Fraction:
        bar += " " + setColor(string(&promptLeftBorder, 1) + to_string(progress) + "/" + to_string(maxProgress) + string(&promptRightBorder, 1), promptForeGround, promptBackGround);
        break;
    case progressbarPromptStyle::Percentage:
        bar += " " + setColor(string(&promptLeftBorder, 1) + to_string(float(progress / maxProgress)) + "%" + string(&promptRightBorder, 1), promptForeGround, promptBackGround);
        break;
    case progressbarPromptStyle::None:
        break;
    default:
        break;
    }
    return bar;
}
string progressBar(int progress, int maxProgress, int width, color foreGround, color backGround, progressbarPromptStyle promptStyle)
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
string progressBar(int progress, int maxProgress, int width, string foreGround, string backGround, progressbarPromptStyle promptStyle)
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
string progressBar(int progress, int maxProgress, int width, color foreGround, color backGround, color promptForeGround, color promptBackGround, progressbarPromptStyle promptStyle)
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
        bar += " " + setColor(to_string(progress) + "/" + to_string(maxProgress), promptForeGround, promptBackGround);
        break;
    case progressbarPromptStyle::Percentage:
        bar += " " + setColor(to_string(float(progress / maxProgress)) + "%", promptForeGround, promptBackGround);
        break;
    case progressbarPromptStyle::None:
        break;
    default:
        break;
    }
    return bar;
}
string message(string message, msgType type)
{
    string msg = "";
    switch (type)
    {
    case msgType::Info:
        msg += setBackGround("[INFO]", color::White) + setForeGround(message, color::White);
        break;
    case msgType::Warning:
        msg += setBackGround("[WARNING]", color::Yellow) setForeGround(message, color::Yellow);
        break;
    case msgType::Error:
        msg += setBackGround("[ERROR]", color::Red);
        break;
    case msgType::Success:
        msg += setBackGround("[SUCCESS]", color::Green);
        break;
    default:
        break;
    }
    return msg;
}
void showSpinner()
{
    static string symbols[] = {"|", "/", "-", "\\"};
    for (int i = 0; i < 4; i++)
    {
        this_thread::sleep_for(chrono::milliseconds(250));
        cout << symbols[i] << "Loading.../r" << flush;
    }
}
#pragma endregion controls