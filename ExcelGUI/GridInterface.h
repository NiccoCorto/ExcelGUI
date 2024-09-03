#ifndef GRIDINTERFACE_H
#define GRIDINTERFACE_H

#include <wx/wx.h>
#include <vector>
#include "Cell.h"
#include "Function.h"

class GridInterface {
public:
    GridInterface(wxPanel* panel);

    void OnCellValueChanged(wxCommandEvent& event);

private:
    wxTextCtrl* cellInputs[4][4];
    wxTextCtrl* sumText;
    wxTextCtrl* meanText;
    wxTextCtrl* minText;
    wxTextCtrl* maxText;

    Cell* cells[4][4];
    Function* sumFunction;
    Function* meanFunction;
    Function* minFunction;
    Function* maxFunction;

    void InitializeGrid(wxPanel* panel);
    void UpdateFunctionResults();
};

#endif // GRIDINTERFACE_H