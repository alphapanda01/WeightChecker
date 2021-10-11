// The main
#include <wx/wx.h>
#include "main.h"
#include "InputWeight.h"

// Main
wxIMPLEMENT_APP(Main);

bool Main::OnInit()
{
    InputWeight *iw = new InputWeight();
    //iw->SetBackgroundColour(*wxBLACK);
    //iw->SetForegroundColour(*wxWHITE);
    iw->Show(true);
    
    return true;
}