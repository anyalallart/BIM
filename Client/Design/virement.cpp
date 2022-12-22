#include "virement.h"


TVir::TVir(const wxString& title) : wxDialog(NULL, -1, title, wxDefaultPosition, wxDefaultSize)
{
 wxPanel *panel = new wxPanel(this, -1);

    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

    wxStaticBox *st = new wxStaticBox(panel, -1, wxT("Vos comptes"),
                                      wxPoint(70, 15), wxSize(240, 150));
    for (int i = 0; i < 3; i++){
        auto* button = new wxRadioButton(panel,FIRST_ID+i,wxT("nom compte"));
        button->SetPosition(wxPoint(80,50+i*25));
    }
    /*
    wxRadioButton *rb = new wxRadioButton(panel, -1,
                                          wxT("compte 1"), wxPoint(80, 50), wxDefaultSize, wxRB_GROUP);
    wxRadioButton *rb1 = new wxRadioButton(panel, -1,
                                           wxT("compte 2"), wxPoint(80, 75));
    wxRadioButton *rb2 = new wxRadioButton(panel, -1,
                                           wxT("compte 3"), wxPoint(80, 100));
    */

    wxRadioButton *rb3 = new wxRadioButton(panel, -1,
                                           wxT("Autres"), wxPoint(80, 125));

    wxTextCtrl *tc = new wxTextCtrl(panel, -1, wxT(""),
                                    wxPoint(165, 125));

    wxStaticBox *sv = new wxStaticBox(panel, -1, wxT("Choix du compte a crediter"),
                                      wxPoint(70, 200), wxSize(240, 150));

    auto *txt1 = new wxStaticText(this, -1, _T("Nom :"), wxPoint(85,240));

    Nom = new wxTextCtrl(panel, -1, wxT(""),
                                    wxPoint(135, 240));

    auto *txt2 = new wxStaticText(this, -1, _T("Iban :"), wxPoint(85,290));

    Iban = new wxTextCtrl(panel, -1, wxT(""),
                                    wxPoint(135, 290));

    wxButton *okButton = new wxButton(this, -1, wxT("Ok"),
                                      wxDefaultPosition, wxSize(70, 30));

    hbox->Add(okButton, 1);

    vbox->Add(panel, 1);
    vbox->Add(hbox, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);

    SetSizer(vbox);

    okButton->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TVir::OkButton, this);

    Centre();
    ShowModal();

    Destroy();
}

void TVir::OkButton(wxCommandEvent &evt) {
    bool bOK = true;
    if (Iban->IsEmpty()) bOK = false;
    if (Nom->IsEmpty()) bOK = false;
    if (bOK){

    }
    else{
        wxMessageBox( wxT("Veuillez remplir les informations"), wxT("BIM"), wxICON_ERROR);
    }
}
