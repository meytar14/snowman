#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <array>
#include <exception>

#include "snowman.hpp"
using namespace std;
namespace ariel{
    const string hat[4]={" _===_\n","  ___\n .....\n","   _\n  /_\\\n", "  ___\n (_*_)\n"};
    const string nose[4]={",",".","_", "  "};
    const string leftEye[4] ={"(.","(o","(O","(-"};
    const string rightEye[4] ={".)","o)","O)","-)"};
    const string leftArm[4] ={"<","\\","/"," "};
    const string rightArm[4] ={">\n","/\n","\\n","\n"};
    const string torso[4]={"( : )","(] [)","(> <)","(   )"};
    const string base[4]={" ( : )"," (\" \")"," (___)"," (   )"};


    string snowman(int x)
    {
        int temp=x;
        
        //check if the input is valid
        for(int i=0;i<8;i++)
        {
            if(temp%10>4||temp%10<1)
            {
                throw exception();
            }
            temp=temp/10;
        }
        if(temp!=0)
        {
            throw exception();
        }


        
        bool isRightArmUp=false;
        bool isLeftArmUp=false;
        if((x/100)%10==2)
        {
            isRightArmUp=true;
        }
         if((x/1000)%10==2)
        {
            isLeftArmUp=true;
        }
        //build the snowman
        string s="";
        s=s+hat[(x/10000000)-1];
        if(isLeftArmUp)
        {
            s=s+leftArm[1];
        }
        else{
            s=s+" ";
        }
        s=s+leftEye[((x/100000)%10)-1];
        s=s+nose[((x/1000000)%10)-1];
        s=s+rightEye[((x/10000)%10)-1];
        if(isRightArmUp)
        {
            s=s+rightArm[1];
        }
        else{
            s=s+"\n";
        }
        if(!isLeftArmUp)
        {
            s=s+leftArm[((x/1000)%10)-1];
        }
        else{// add " "before the torso
            s=s+" ";
        }
        s=s+torso[((x/10)%10)-1];
        if(!isRightArmUp)
        {
            s=s+rightArm[((x/100)%10)-1];
        }
        else
        {
            s=s+"\n";
        }
        s=s+base[(x%10)-1];
        return s;
    }
}

