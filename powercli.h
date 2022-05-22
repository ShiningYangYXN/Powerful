#pragma once
#include <bits/stdc++.h>

using namespace std;


string setColor(string text,int fr,int fg,int fb,int br,int bg,int bb)
{
    if (fr>=0&&fr<=255&&fg>=0&&fg<=255&&fb>=0&&fb<=255&&br>=0&&br<=255&&bg>=0&&bg<=255&&bb>=0&&bb<=255)//Value-check
    {
        return "\x1b[38;2;"+to_string(fr)+";"+to_string(fg)+";"+to_string(fb)+"m\x1b[38;2;"+to_string(br)+";"+to_string(bg)+";"+to_string(bb)+"m"+text+"\x1b[0m";
    }
    else return "\x1b[41mE\x1b[0m:\x1b[31mInvalid Arguments\x1b[0m";
}
string setForeGround(string text,int r,int g,int b)
{
    if (r>=0&&r<=255&&g>=0&&g<=255&&b>=0&&b<=255)//Value-check
    {
        return "\x1b[38;2;"+to_string(r)+";"+to_string(g)+";"+to_string(b)+"m"+text+"\x1b[0m";
    }
    else return "\x1b[41mE\x1b[0m:\x1b[31mInvalid Arguments\x1b[0m";
}
string setBackGround(string text,int r,int g,int b)
{
    if (r>=0&&r<=255&&g>=0&&g<=255&&b>=0&&b<=255)//Value-check
    {
        return "\x1b[48;2;"+to_string(r)+";"+to_string(g)+";"+to_string(b)+"m"+text+"\x1b[0m";
    }
    else return "\x1b[41mE\x1b[0m:\x1b[31mInvalid Arguments\x1b[0m";
}
string setColor(string text,string foreColor,string backColor)
{
    if(foreColor.length()==backColor.length()==7&&foreColor[0]==backColor[0]=='#')//Value check
    {
        try
        {
            setColor(text,stoi(string(&foreColor[1])+string(&foreColor[2]),0,16),stoi(string(&foreColor[3])+string(&foreColor[4]),0,16),stoi(string(&foreColor[5])+string(&foreColor[6]),0,16),stoi(string(&backColor[1])+string(&backColor[2]),0,16),stoi(string(&backColor[3])+string(&backColor[4]),0,16),stoi(string(&backColor[5])+string(&backColor[6]),0,16));
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return "\x1b[41mE\x1b[0m:\x1b[31mInvalid Arguments\x1b[0m";
        }
        
    }
    else return "\x1b[41mE\x1b[0m:\x1b[31mInvalid Arguments\x1b[0m";
}
string setForeGround(string text,string foreColor)
{
    if(foreColor.length()==7&&foreColor[0]=='#')//Value check
    {
        try
        {
            setForeGround(text,stoi(string(&foreColor[1])+string(&foreColor[2]),0,16),stoi(string(&foreColor[3])+string(&foreColor[4]),0,16),stoi(string(&foreColor[5])+string(&foreColor[6]),0,16));
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return "\x1b[41mE\x1b[0m:\x1b[31mInvalid Arguments\x1b[0m";
        }
        
    }
    else return "\x1b[41mE\x1b[0m:\x1b[31mInvalid Arguments\x1b[0m";
}
string setBackGround(string text,string backColor)
{
    if(backColor.length()==7&&backColor[0]=='#')//Value check
    {
        try
        {
            setBackGround(text,stoi(string(&backColor[1])+string(&backColor[2]),0,16),stoi(string(&backColor[3])+string(&backColor[4]),0,16),stoi(string(&backColor[5])+string(&backColor[6]),0,16));
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return "\x1b[41mE\x1b[0m:\x1b[31mInvalid Arguments\x1b[0m";
        }
        
    }
    else return "\x1b[41mE\x1b[0m:\x1b[31mInvalid Arguments\x1b[0m";
}
