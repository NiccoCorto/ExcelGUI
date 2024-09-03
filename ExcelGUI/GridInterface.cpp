#include "GridInterface.h"

GridInterface::GridInterface(wxPanel* panel) {
    InitializeGrid(panel);
}

void GridInterface::InitializeGrid(wxPanel* panel) {
    // Create a wxGridSizer with 4 rows and 4 columns
    wxGridSizer* gridSizer = new wxGridSizer(5, 4, 10, 10);

    // Create cells and link them to wxTextCtrl
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cells[i][j] = new Cell();
            cellInputs[i][j] = new wxTextCtrl(panel, wxID_ANY);
            gridSizer->Add(cellInputs[i][j], 1, wxEXPAND | wxALL);  // Add each control to the grid sizer
            cellInputs[i][j]->Bind(wxEVT_TEXT, &GridInterface::OnCellValueChanged, this);  // Bind event
        }
    }

    // Create function objects for all cells
    std::vector<Cell*> allCells;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            allCells.push_back(cells[i][j]);
        }
    }

    // Initialize function objects with all cells
    sumFunction = new Function(Function::SUM, allCells);
    meanFunction = new Function(Function::MEAN, allCells);
    minFunction = new Function(Function::MIN, allCells);
    maxFunction = new Function(Function::MAX, allCells);

    // Create readonly text controls to display the results
    sumText = new wxTextCtrl(panel, wxID_ANY, std::to_string(sumFunction->getValue()), wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
    meanText = new wxTextCtrl(panel, wxID_ANY, std::to_string(meanFunction->getValue()), wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
    minText = new wxTextCtrl(panel, wxID_ANY, std::to_string(minFunction->getValue()), wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
    maxText = new wxTextCtrl(panel, wxID_ANY, std::to_string(maxFunction->getValue()), wxDefaultPosition, wxDefaultSize, wxTE_READONLY);

    // Ensure these are added AFTER all cell inputs
    gridSizer->Add(sumText, 1, wxEXPAND | wxALL);
    gridSizer->Add(meanText, 1, wxEXPAND | wxALL);
    gridSizer->Add(minText, 1, wxEXPAND | wxALL);
    gridSizer->Add(maxText, 1, wxEXPAND | wxALL);

    // Set the sizer for the panel
    panel->SetSizer(gridSizer);
}

void GridInterface::OnCellValueChanged(wxCommandEvent& event) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            wxString valueStr = cellInputs[i][j]->GetValue();
            long value;
            if (valueStr.ToLong(&value)) {
                cells[i][j]->setValue(static_cast<int>(value));
            }
            else {
                cells[i][j]->setValue(0);
            }
        }
    }

    UpdateFunctionResults();
}

void GridInterface::UpdateFunctionResults() {
    sumText->SetValue(std::to_string(sumFunction->getValue()));
    meanText->SetValue(std::to_string(meanFunction->getValue()));
    minText->SetValue(std::to_string(minFunction->getValue()));
    maxText->SetValue(std::to_string(maxFunction->getValue()));
}