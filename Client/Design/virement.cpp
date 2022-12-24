#include "include.h"


TVir::TVir(const wxString& title) : wxDialog(NULL, -1, title, wxDefaultPosition, wxSize(480, 460))
{
 wxPanel *panel = new wxPanel(this, -1);

    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

    wxStaticBox *st = new wxStaticBox(panel, -1, wxT("Vos comptes"),
                                      wxPoint(105, 15), wxSize(260, 150));

    std::string request ="SELECT * FROM compte WHERE client='"+ std::to_string(wxGetApp().user.id)+"'";
    std::vector<std::map<std::string, std::string>> result = wxGetApp().database.select(request);

    std::string request2 ="SELECT * FROM type_compte";
    std::vector<std::map<std::string, std::string>> type = wxGetApp().database.select(request2);

    for (int i = 0; i < result.size(); i++){
        auto* button = new wxRadioButton(panel,FIRST_ID+i,_T("Compte numero " + result[i]["id"] + ", " + type[stoi(result[i]["type"]) - 1]["nom"]));
        button->SetPosition(wxPoint(120,50+i*25));
    }

    wxStaticBox *sv = new wxStaticBox(panel, -1, wxT("Choix du compte a crediter"),
                                      wxPoint(105, 200), wxSize(260, 150));

    auto *txt1 = new wxStaticText(this, -1, _T("Iban :"), wxPoint(120,240));

    Nom = new wxTextCtrl(panel, -1, wxT(""),
                                    wxPoint(175, 240));

    auto *txt2 = new wxStaticText(this, -1, _T("Libelle :"), wxPoint(120,280));

    Iban = new wxTextCtrl(panel, -1, wxT(""),
                                    wxPoint(175, 280));

    auto *txt3 = new wxStaticText(this, -1, _T("Somme :"), wxPoint(120,320));

    Somme = new wxTextCtrl(panel, -1, wxT(""),
                          wxPoint(175, 320));

    wxButton *okButton = new wxButton(this, -1, wxT("Ok"),
                                      wxDefaultPosition, wxSize(100, 30));

    wxButton *retourButton = new wxButton(this, -1, wxT("Retour"),
                                          wxDefaultPosition, wxSize(160, 30));

    hbox->Add(okButton, 1);
    hbox->Add(retourButton, 1);

    vbox->Add(panel, 1);
    vbox->Add(hbox, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);

    SetSizer(vbox);

    okButton->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TVir::OkButton, this);
    retourButton->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TVir::Button, this);

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

void TVir::Button(wxCommandEvent &evt) {
    Close();
    TAcc *accueil = new TAcc("Vos comptes",
                             wxPoint(150, 150), wxSize(480, 360));
    accueil->Show(true);
}
