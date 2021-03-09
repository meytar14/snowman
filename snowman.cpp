#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <array>
#include <exception>

#include "snowman.hpp"
using namespace std;
namespace ariel{
    const string hat[]={"_===_\n","___ \n.....\n"," _\n/_\n", " ___\n (_*_)\n"};
    const string nose[]={",",".","_", "  "};
    const string leftEye[] ={".","o","O","-"};
    const string rightEye[] ={".","o","O","-"};
    const string leftArm[] ={"<","\\","/"," "};
    const string rightArm[] ={">","/","\\"," "};
    


    string snowman(int x)
    {
        int tmp=x;
        
        for(int i=0;i<8;i++)
        {
            if(tmp%10>4||tmp%10<1)
            {
                throw exception();
            }
            tmp=tmp/10;
        }
        if(tmp!=0)
        {
            throw exception();
        }
        string s;
        return s;
    }
}

