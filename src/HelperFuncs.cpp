#include "HelperFuncs.h"

#include <ctime>   // time
#include <cstdlib> // srand, rand
#include <wx/wx.h> // Display size
#include <wx/display.h> // wxDisplay

wxPoint getRandCoord()
{
    srand(time(NULL));

    int w = wxDisplay().GetGeometry().GetWidth() ;
    int h = wxDisplay().GetGeometry().GetHeight();

    wxPoint p(rand()%h, rand()%w);

    return p;
}