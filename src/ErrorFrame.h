#pragma once

#include <wx/wx.h>

class ErrorFrame: public wxFrame
{
public:
    ErrorFrame(int x, int y);
    ~ErrorFrame();

public:
    wxStaticText* m_stext  = nullptr;
    wxButton*     m_button = nullptr;

    void OnButtonClick(wxCommandEvent& evt);

    wxDECLARE_EVENT_TABLE();
};