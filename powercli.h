#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

char* colored(char* text,int fr,int fg,int fb,int br,int bg,int bb)
{
    if (fr>=0&&fr<=255&&fg>=0&&fg<=255&&fb>=0&&fb<=255&&br>=0&&br<=255&&bg>=0&&bg<=255&&bb>=0&&bb<=255)//Value-check
    {
        return "\x1b[38;2;"+(fr)+";"+to_string(fg)+";"+to_string(fb)+"m\x1b[38;2;"+to_string(br)+";"+to_string(bg)+";"+to_string(bb)+"m"+text+"\x1b[0m";
    }
    else{return "\x1b[31mE\x1b[0m:Invalid Arguments";}
}
char* colored(char* text,int r,int g,int b,bool isForeGround)
{
    if (r>=0&&r<=255&&g>=0&&g<=255&&b>=0&&b<=255)//Value-check
    {
        if(isForeGround)
        {
        
        }
        else
        {

        }
        
        
    }
    else{return "\x1b[31mE\x1b[0m:Invalid Arguments";}
}
