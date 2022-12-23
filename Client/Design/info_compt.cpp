#include "include.h"


TInf::TInf(const wxString& title) : wxDialog(NULL, -1, title, wxDefaultPosition, wxSize(480, 460))
{
    wxPanel *panel = new wxPanel(this, -1);

    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

    wxStaticBox *st = new wxStaticBox(panel, -1, wxT("Vos informations"),
                                      wxPoint(105, 15), wxSize(260, 150));

    auto *labelCompte = new wxStaticText(this, -1, _T("Compte numero 69"), wxPoint(140,50));

    auto *labelType = new wxStaticText(this, -1, _T("Votre type de compte :"), wxPoint(140,80));
    // Requete pour le prenom
    auto *labelTypeR = new wxStaticText(this, -1, _T("ouii"), wxPoint(280,80));

    wxStaticBox *sv = new wxStaticBox(panel, -1, wxT("Votre moula"),
                                      wxPoint(105, 200), wxSize(260, 150));

    auto *txt1 = new wxStaticText(this, -1, _T("1234567"), wxPoint(210,240));

    //si interet
    auto *interet = new wxStaticText(this, -1, _T("Vos interets : beaucoup"), wxPoint(170,280));

    wxButton *retourButton = new wxButton(this, -1, wxT("Retour"),
                                      wxDefaultPosition, wxSize(120, 30));

    hbox->Add(retourButton, 1);

    vbox->Add(panel, 1);
    vbox->Add(hbox, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);

    SetSizer(vbox);

    retourButton->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TInf::Button, this);

    Centre();
    ShowModal();
    Destroy();
}

void TInf::Button(wxCommandEvent &evt) {
    Close();
    TAcc *accueil = new TAcc("Vos comptes",
                             wxPoint(150, 150), wxSize(480, 360));
    accueil->Show(true);
}

