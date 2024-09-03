#include <wx/wx.h>
#include "GridInterface.h"

class SpreadsheetApp : public wxApp {
public:
    virtual bool OnInit();
};

class SpreadsheetFrame : public wxFrame {
public:
    SpreadsheetFrame(const wxString& title);

private:
    GridInterface* gridInterface;
};

wxIMPLEMENT_APP(SpreadsheetApp);

bool SpreadsheetApp::OnInit() {
    SpreadsheetFrame* frame = new SpreadsheetFrame("Spreadsheet");
    frame->Show(true);
    return true;
}

SpreadsheetFrame::SpreadsheetFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 400)) {
    wxPanel* panel = new wxPanel(this, wxID_ANY);
    gridInterface = new GridInterface(panel);
}