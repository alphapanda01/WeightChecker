#pragma once

#include <wx/wx.h>

class InputWeight: public wxFrame
{
public:
    InputWeight();
    ~InputWeight();

public:
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

public:
    wxStaticText* m_title  = nullptr;
    wxStaticText* m_stext  = nullptr;
    wxTextCtrl*   m_itext  = nullptr;
    wxComboBox*   m_list   = nullptr;
    wxButton*     m_button = nullptr;

    void OnButtonClick(wxCommandEvent& evt);
    void Virus();

    wxDECLARE_EVENT_TABLE();
};