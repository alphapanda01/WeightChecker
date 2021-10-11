// The main
#include <wx/wx.h>
#include "main.h"
#include "InputWeight.h"

// Main
wxIMPLEMENT_APP(Main);

bool Main::OnInit()
{
    InputWeight *iw = new InputWeight();
    iw->Show(true);
    
    return true;
}