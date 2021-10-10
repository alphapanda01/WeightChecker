#include <wx/wx.h>
#include <wx/progdlg.h> // Progress dialog
#include <string>

// Sleep
#include <chrono>
#include <thread> 

#include "InputWeight.h"
#include "ErrorFrame.h"
#include "HelperFuncs.h"


enum{IWstext = 1001, IWitext = 1002, IWlist = 1003, IWbtn = 1004};

wxBEGIN_EVENT_TABLE(InputWeight, wxFrame)
    EVT_BUTTON(IWbtn, InputWeight::OnButtonClick)
wxEND_EVENT_TABLE()


InputWeight::InputWeight():
    wxFrame(nullptr, wxID_ANY, "Weight Calculator", wxPoint(300, 300), wxSize(600, 200))
{

    wxArrayString choices;
    choices.Add("KGs");
    choices.Add("LBs");
    //choices.Add("Girls per Tentacles"); // TODO Implement somthing for this


    m_title  = new wxStaticText(this, IWstext, "Weight Calculator");
    m_stext  = new wxStaticText(this, IWstext, "Enter your Weight: ", wxPoint(100, 50), wxSize(150,30), wxALIGN_CENTRE_HORIZONTAL);
    m_itext  = new wxTextCtrl(this, IWitext, "", wxPoint(260,45), wxSize(100, 30));

    m_list   = new wxComboBox(this, IWlist, "Symbol", wxPoint(400, 45), wxSize(100, 30), choices, wxCB_DROPDOWN);

    m_button = new wxButton(this, IWbtn, "Calculate", wxPoint(200, 100), wxSize(150, 50));

    // Menu bar copied from wxWidgets hello world demo
    wxMenu *menuFile = new wxMenu;
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar( menuBar );

    Bind(wxEVT_MENU, &InputWeight::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &InputWeight::OnExit, this, wxID_EXIT);

}

InputWeight::~InputWeight()
{
    // PAIN: You just can't quit
    InputWeight *iw = new InputWeight();
    iw->SetBackgroundColour(*wxBLACK);
    iw->SetForegroundColour(*wxWHITE);
    iw->Show(true); 
}

void InputWeight::OnButtonClick(wxCommandEvent& evt)
{
    bool invalid = false;
    int weight = -1;

    int metric = m_list->GetSelection();
    if(m_list->GetSelection() == wxNOT_FOUND) {
        wxMessageBox("Please Select a valid Metric","INVALID", wxICON_INFORMATION);
        return; 
    }

    try {
        weight = std::stoi(std::string(m_itext->GetValue()));
    }
    catch (std::invalid_argument& ia) {
        invalid = true;
    }
    catch(...) {
        invalid = true;
    }

    if(invalid || weight <= 0) {
        wxMessageBox("Please Enter a Vaild Number","INVALID", wxICON_INFORMATION);
        return;
    }

    if(metric == 1) {
        weight /= 2.205; // LBs to KGs
    } 

    wxMessageDialog* msg = new wxMessageDialog(this, "Message", "Caption", wxYES_NO | wxCANCEL | wxICON_INFORMATION | wxSTAY_ON_TOP| wxCENTRE);
    msg->SetMessage("Weight Checker");
    std::string emsg = std::string("Your Weight is: ") + std::to_string(weight) + std::string(" KGs");
    msg->SetExtendedMessage(emsg);

    int id = msg->ShowModal();

    if(id == wxID_YES) {
        wxMessageBox("Did you like this application? Give Feedback", "Feedback", wxYES | wxNO | wxCENTER);
        // TODO: Change link
        wxLaunchDefaultBrowser("https://shattereddisk.github.io/rickroll/rickroll.mp4");
        Close(true);
    }
    else if (id == wxID_NO) {

        InputWeight::Virus(); 

    }
    else {
        int count = 0;
        std::string m = "YOU NEVER HAD AN OPTION";
        while(wxMessageBox(m, "FAT!!", wxYES_NO | wxCANCEL, this, wxDefaultCoord, wxDefaultCoord)) {
            // TODO: add some more cool stuff here
            count++;
            if(count > 5) {
                m = std::string("YOU NEVER HAD AN CHOICE: ") + std::to_string(count);
            }
        }
    }

    evt.Skip();
}

void InputWeight::Virus() {
    
    wxGenericProgressDialog gpd("DOWNLOADING", "Downloading Virus...", 100, this, wxPD_SMOOTH);

    int done = 0;
    for(int i = 0; i < 100; i++) {
        gpd.Update(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(5));  
    }
   
   for(int i = 0; i < 1; i++) {
        ErrorFrame *ef = new ErrorFrame(getRandCoord());
        ef->Show();
   }

}


void InputWeight::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("A Simple Weight checker made using wxWidgets",
                 "About Weight Checker", wxOK | wxICON_INFORMATION);
 
}

void InputWeight::OnExit(wxCommandEvent& event) 
{
    wxMessageBox("Did you think you can close this?",
                 "HAHAHA", wxOK | wxICON_INFORMATION);
    

}
