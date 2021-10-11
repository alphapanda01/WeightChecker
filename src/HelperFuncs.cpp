#include "HelperFuncs.h"

#include <ctime>   // time
#include <cstdlib> // srand, rand
#include <wx/wx.h> // Display size
#include <wx/display.h> // wxDisplay

wxPoint getRandCoord()
{
    int offset = 500;

    srand(time(NULL));

    int w = wxDisplay().GetGeometry().GetWidth() ;
    int h = wxDisplay().GetGeometry().GetHeight();

    int x = (rand()+300)%h;
    int y = (rand())%w;

    x = (x > h-offset) ? x-offset : ((x < offset) ? x+offset : x);

    wxPoint p(x, y);

    return p;
}