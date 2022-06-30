#pragma once
#include <bits/stdc++.h>

using namespace std;
#pragma region typedef

typedef enum
{
    Fraction,
    Percentage,
    None,
} progressbarPromptStyle;
typedef enum
{
    Legacy,
    Block,
    Line,
} progressbarStyle;
typedef enum
{
    Debug,
    Info,
    Success,
    Warning,
    Error,
    Fatal,
} logLevel;
typedef enum
{
    Classic,
    Modern,
    Iconed,
    NoColor,
} logStyle;
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
typedef unsigned int HEX;
typedef byte colorRGB[3];
byte loglevel = 0b111111;
#pragma endregion typedef
#pragma region functiondef

#pragma endregion functiondef
#pragma region style
colorRGB *hexToRGB(HEX color)
{
    colorRGB rgb;
    rgb[0] = (color >> 16) & 0xFF;
    rgb[1] = (color >> 8) & 0xFF;
    rgb[2] = color & 0xFF;
    cout << &rgb;
}
string setColor(string text, colorRGB foreGround, colorRGB backGround)
{
    cout << "\x1b[38;2;" + to_string(foreGround[0]) + ";" + to_string(foreGround[1]) + ";" + to_string(foreGround[2]) + ";38;2;" + to_string(backGround[0]) + ";" + to_string(backGround[1]) + ";" + to_string(backGround[2]) + "m" + text + "\x1b[0m";
}
string setForeGround(string text, colorRGB foreGround)
{
    cout << "\x1b[38;2;" + to_string(foreGround[0]) + ";" + to_string(foreGround[1]) + ";" + to_string(foreGround[2]) + "m" + text + "\x1b[0m";
}
string setBackGround(string text, colorRGB backGround)
{
    cout << "\x1b[48;2;" + to_string(backGround[0]) + ";" + to_string(backGround[1]) + ";" + to_string(backGround[2]) + "m" + text + "\x1b[0m";
}
string setColor(string text, HEX ForeGround, HEX BackGround)
{
    cout << setColor(text, *hexToRGB(ForeGround), *hexToRGB(BackGround));
}
string setForeGround(string text, HEX ForeGround)
{
    cout << setForeGround(text, *hexToRGB(ForeGround));
}
string setBackGround(string text, HEX BackGround)
{
    cout << setBackGround(text, *hexToRGB(BackGround));
}
string setColor(string text, color foreGround, color backGround)
{
    if (foreGround <= 7)
    {
        if (backGround <= 7)
        {
            cout << "\x1b[3" + to_string(foreGround) + ";4" + to_string(backGround) + "m" + text + "\x1b[0m";
        }
        else
        {
            cout << "\x1b[3" + to_string(foreGround) + ";10" + to_string(backGround - 8) + "m" + text + "\x1b[0m";
        }
    }
    else
    {
        if (backGround <= 7)
        {
            cout << "\x1b[9" + to_string(foreGround) + ";4" + to_string(backGround) + "m" + text + "\x1b[0m";
        }
        else
        {
            cout << "\x1b[9" + to_string(foreGround) + ";10" + to_string(backGround - 8) + "m" + text + "\x1b[0m";
        }
    }
}
string setForeGround(string text, color foreGround)
{
    if (foreGround <= 7)
    {
        cout << "\x1b[3" + to_string(foreGround) + "m" + text + "\x1b[0m";
    }
    else
    {
        cout << "\x1b[9" + to_string(foreGround) + "m" + text + "\x1b[0m";
    }
}
string setBackGround(string text, color backGround)
{
    if (backGround <= 7)
    {
        cout << "\x1b[4" + to_string(backGround) + "m" + text + "\x1b[0m";
    }
    else
    {
        cout << "\x1b[10" + to_string(backGround) + "m" + text + "\x1b[0m";
    }
}
string setColor(string text, byte foreGround, byte backGround)
{
    cout << "\x1b[38;5;" + to_string(foreGround) + ";48;5;" + to_string(backGround) + "m" + text + "\x1b[0m";
}
string setForeGround(string text, byte foreGround)
{
    cout << "\x1b[38;5;" + to_string(foreGround) + "m" + text + "\x1b[0m";
}
string setBackGround(string text, byte backGround)
{
    cout << "\x1b[48;5;" + to_string(backGround) + "m" + text + "\x1b[0m";
}
string setStyle(string text, textStyle style)
{
    switch (style)
    {
    case Bold:
        cout << "\x1b[1m" + text + "\x1b[0m";
        break;
    case Dim:
        cout << "\x1b[2m" + text + "\x1b[0m";
        break;
    case Italic:
        cout << "\x1b[3m" + text + "\x1b[0m";
        break;
    case Underlined:
        cout << "\x1b[4m" + text + "\x1b[0m";
        break;
    case Blink:
        cout << "\x1b[5m" + text + "\x1b[0m";
        break;
    case Inverse:
        cout << "\x1b[7m" + text + "\x1b[0m";
        break;
    case Hidden:
        cout << "\x1b[8m" + text + "\x1b[0m";
        break;
    case Strike:
        cout << "\x1b[9m" + text + "\x1b[0m";
        break;
    case DoubleUnderlined:
        cout << "\x1b[21m" + text + "\x1b[0m";
        break;
    case Overlined:
        cout << "\x1b[53m" + text + "\x1b[0m";
        break;
    default:
        break;
    }
}

#pragma endregion style
#pragma region cursor
void cursorGoto(int x, int y)
{
    cout << "\x1b[" + to_string(x) + ";" + to_string(y) + "H" << flush;
}
void cursorUp(int n)
{
    cout << "\x1b[" + to_string(n) + "A" << flush;
}
void cursorDown(int n)
{
    cout << "\x1b[" + to_string(n) + "B" << flush;
}
void cursorLeft(int n)
{
    cout << "\x1b[" + to_string(n) + "C" << flush;
}
void cursorRight(int n)
{
    cout << "\x1b[" + to_string(n) + "D" << flush;
}
void cursorNextLine(int n)
{
    cout << "\x1b[" + to_string(n) + "E" << flush;
}
void cursorPrevLine(int n)
{
    cout << "\x1b[" + to_string(n) + "F" << flush;
}
void cursorGotoColumn(int n)
{
    cout << "\x1b[" + to_string(n) + "G" << flush;
}
void scrollUp(int n)
{
    cout << "\x1b[" + to_string(n) + "S" << flush;
}
void scrollDown(int n)
{
    cout << "\x1b[" + to_string(n) + "T" << flush;
}
void eraseLine()
{
    cout << "\x1b[2K" << flush;
}
void clearScreen()
{
    cout << "\x1b[2D" << flush;
}
void saveCursor()
{
    cout << "\x1b[s" << flush;
}
void restoreCursor()
{
    cout << "\x1b[u" << flush;
}
#pragma endregion cursor
#pragma region controls
bool stringContains(string text, string search)
{
    cout << text.find(search) != string::npos;
}
void setLogLevel(string level)
{
    loglevel = 0b000000;
    if (stringContains(level, "D")) // debug
    {
        loglevel |= 0b000001;
    }
    if (stringContains(level, "I")) // info
    {
        loglevel |= 0b000010;
    }
    if (stringContains(level, "S")) // success
    {
        loglevel |= 0b000100;
    }
    if (stringContains(level, "W")) // warning
    {
        loglevel |= 0b001000;
    }
    if (stringContains(level, "E")) // error
    {
        loglevel |= 0b010000;
    }
    if (stringContains(level, "F")) // fatal
    {
        loglevel |= 0b100000;
    }
    else
    {
        loglevel = 0b111111;
        printLog("Log level not set, using all levels", Debug);
    }
}
void printLog(string msg, logLevel level, logStyle style = Modern)
{
    switch (level)
    {
    case Debug:
        if (loglevel & 0b000001)
        {
            switch (style)
            {
            case Classic:
                cout << setStyle("[DEBUG] ", Bold) << msg << endl;
                break;
            case Modern:
                cout << setStyle("[DEBUG] ", Inverse) << setStyle(msg, Bold) << endl;
                break;
            case Iconed:
                cout << setStyle("\u1f41e [DEBUG] ", Inverse) << setStyle(msg, Bold) << endl;
                break;
            case NoColor:
                cout << "[DEBUG] " << msg << endl;
                break;
            default:
                break;
            }
        }
        break;
    case Info:
        if (loglevel & 0b000010)
        {
            switch (style)
            {
            case Classic:
                cout << setForeGround("[INFO] ", Blue) << msg << endl;
                break;
            case Modern:
                cout << setBackGround("[INFO] ", Blue) << setForeGround(msg, BrightBlue) << endl;
                break;
            case Iconed:
                cout << setBackGround("\u24d8 [INFO] ", Blue) << setForeGround(msg, BrightBlue) << endl;
                break;
            case NoColor:
                cout << "[INFO] " << msg << endl;
                break;
            default:
                break;
            }
        }

        break;
    case Warning:
        switch (style)
        {
        case Legacy:
            cout << setForeGround("[WARNING] ", Yellow) << msg << endl;
            break;
        case Modern:
            cout << setBackGround("[WARNING] ", Yellow) << setForeGround(msg, BrightYellow) << endl;
            break;
        case Iconed:
            cout << setBackGround("\u26a0 [WARNING] ", Yellow) << setForeGround(msg, BrightYellow) << endl;
            break;
        case NoColor:
            cout << "[WARNING] " << msg << endl;
            break;
        default:
            break;
        }
        break;
    case Error:
        switch (style)
        {
        case Legacy:
            cout << setForeGround("[ERROR] ", Red) << msg << endl;
            break;
        case Modern:
            cout << setBackGround("[ERROR] ", Red) << setForeGround(msg, BrightRed) << endl;
            break;
        case Iconed:
            cout << setBackGround("\u2297 [ERROR] ", Red) << setForeGround(msg, BrightRed) << endl;
            break;
        case NoColor:
            cout << "[ERROR] " << msg << endl;
            break;
        default:
            break;
        }
        break;
    case Success:
        switch (style)
        {
        case Legacy:
            cout << setForeGround("[SUCCESS] ", Green) << msg << endl;
            break;
        case Modern:
            cout << setBackGround("[SUCCESS] ", Green) << setForeGround(msg, BrightGreen) << endl;
            break;
        case Iconed:
            cout << setBackGround("\u2713 [SUCCESS] ", Green) << setForeGround(msg, BrightGreen) << endl;
            break;
        case NoColor:
            cout << "[SUCCESS] " << msg << endl;
            break;
        }
        break;
    default:
        break;
    }
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
    cout << bar;
}
string progressBar(int progress, int maxProgress, int width, HEX foreGround, HEX backGround, char symbol, char leftBorder, char rightBorder, HEX promptForeGround, HEX promptBackGround, char promptLeftBorder, char promptRightBorder, progressbarPromptStyle promptStyle)
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
    cout << bar;
}
string progressBar(int progress, int maxProgress, int width, byte foreGround, byte backGround, char symbol, char leftBorder, char rightBorder, byte promptForeGround, byte promptBackGround, char promptLeftBorder, char promptRightBorder, progressbarPromptStyle promptStyle)
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
    cout << bar;
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