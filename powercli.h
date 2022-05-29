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
    BrightWhite,
} color;
typedef enum
{
    Bold,
    Weak,
    Italic,
    Underlined,
    Blink,
    Inverse,
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
    Legacy,
    Modern,
    Iconed,
    NoColor,
} msgStyle;
#pragma region style
string setColor(string text, int foreGroundR, int foreGroundG, int foreGroundB, int backGroundR, int backGroundG, int backGroundB)
{
    if (foreGroundR >= 0 && foreGroundR <= 255 && foreGroundG >= 0 && foreGroundG <= 255 && foreGroundB >= 0 && foreGroundB <= 255 && backGroundR >= 0 && backGroundR <= 255 && backGroundG >= 0 && backGroundG <= 255 && backGroundB >= 0 && backGroundB <= 255) // Value-check
    {
        return "\x1b[38;2;" + to_string(foreGroundR) + ";" + to_string(foreGroundG) + ";" + to_string(foreGroundB) + ";38;2;" + to_string(backGroundR) + ";" + to_string(backGroundG) + ";" + to_string(backGroundB) + "m" + text + "\x1b[0m";
    }
    else
    {
        throw invalid_argument(message("Invalid color value", Error));
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
        throw invalid_argument(message("Invalid color value", Error));
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
        throw invalid_argument(message("Invalid color value", Error));
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
            throw invalid_argument(message("Invalid color value", Error));
        }
    }
    else
        throw invalid_argument(message("Invalid color value", Error));
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
            throw invalid_argument(message("Invalid color value", Error));
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
            throw invalid_argument(message("Invalid color value", Error));
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
        throw invalid_argument(message("Invalid color value", Error));
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
        throw invalid_argument(message("Invalid color value", Error));
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
        throw invalid_argument(message("Invalid color value", Error));
    }
}
string setStyle(string text, textStyle style)
{
    switch (style)
    {
    case Bold:
        return "\x1b[1m" + text + "\x1b[0m";
        break;
    case Weak:
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
string progressBar(int progress, int maxProgress = 100, int width = 50, string foreGround, string backGround, char symbol = '=', char leftBorder = '[', char rightBorder = ']', progressbarPromptStyle promptStyle = Percentage)
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
string progressBar(int progress, int maxProgress = 100, int width = 50, color foreGround, color backGround, char symbol = '=', char leftBorder = '[', char rightBorder = ']', progressbarPromptStyle promptStyle = Percentage)
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
string progressBar(int progress, int maxProgress = 100, int width = 50, color foreGround, color backGround, char symbol = '=', char leftBorder = '[', char rightBorder = ']', color promptForeGround, color promptBackGround, char promptLeftBorder = '(', char promptRightBorder = ')', progressbarPromptStyle promptStyle = Percentage)
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
string progressBar(int progress, int maxProgress = 100, int width = 50, string foreGround, string backGround, char symbol = '=', char leftBorder = '[', char rightBorder = ']', string promptForeGround, string promptBackGround, char promptLeftBorder = '(', char promptRightBorder = ')', progressbarPromptStyle promptStyle = Percentage)
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
string progressBar(int progress, int maxProgress = 100, int width = 50, color foreGround, color backGround, progressbarPromptStyle promptStyle = Percentage)
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
string progressBar(int progress, int maxProgress = 100, int width = 50, string foreGround, string backGround, progressbarPromptStyle promptStyle = Percentage)
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
        return;
        break;
    }
    return bar;
}
string progressBar(int progress, int maxProgress = 100, int width = 50, color foreGround, color backGround, color promptForeGround, color promptBackGround, progressbarPromptStyle promptStyle = Percentage)
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
string message(string msg, msgType type, msgStyle style = Modern)
{
    switch (type)
    {
    case Info:
        switch (style)
        {
        case Legacy:
            return setForeGround("[INFO] ", Blue) + msg;
            break;
        case Modern:
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
        return;
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