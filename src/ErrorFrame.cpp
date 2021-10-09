// This File is the definition of P A I N

#include "ErrorFrame.h"

enum{EFbtn = 30001};

wxBEGIN_EVENT_TABLE(ErrorFrame, wxFrame)
    EVT_BUTTON(EFbtn, ErrorFrame::OnButtonClick)
wxEND_EVENT_TABLE()

ErrorFrame::ErrorFrame(int x, int y):
    wxFrame(nullptr, wxID_ANY, "DENIAL", wxPoint(x, y), wxSize(400, 200))
{ 
    m_stext  = new wxStaticText(this, wxID_ANY, "YOU ARE IN DENIAL!!!", wxPoint(100, 50), wxSize(200,30), wxALIGN_CENTRE_HORIZONTAL);

    m_button = new wxButton(this, EFbtn, "NO", wxPoint(110, 100), wxSize(150, 50));
}

ErrorFrame::~ErrorFrame() {
    ErrorFrame *ef = new ErrorFrame(100, 100);
    ef->Show();
}

void ErrorFrame::OnButtonClick(wxCommandEvent& evt)
{
    ErrorFrame *ef = new ErrorFrame(100, 100);
    ef->Show();
    evt.Skip();
}
