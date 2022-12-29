//
// Created by Administrateur on 29/12/2022.
//

#include "banque.h"

BEGIN_EVENT_TABLE(TMyFrame_agc, wxFrame)
                EVT_BUTTON(BUTTON_RECH,  TMyFrame_agc::Recherche)
END_EVENT_TABLE()

IMPLEMENT_APP(TMyAgc)

//------------------------------------------------------------------------------

bool TMyAgc::OnInit() {

    TMyFrame_agc *frame = new TMyFrame_agc("Informations Clients",
                                   wxPoint(150, 150), wxSize(480, 360));
    frame->Show(true);
    return (true);
}

//------------------------------------------------------------------------------

TMyFrame_agc::TMyFrame_agc(const wxString& title, const wxPoint& pos, const wxSize& size,
                   long style) : wxFrame(nullptr, -1, title, pos, size, style)
{
    Centre();
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));
    auto *txt = new wxStaticText(this, -1, _T("Bienvenu sur BIM pour les agences"), wxPoint(180,20));

    // wxStaticText pour la recherche
    auto *labelrech = new wxStaticText(this, -1, _T("Recherche client :"), wxPoint(160,70));

    // wxTextCtrl pour la recherche
    txt_rech = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(160,90), wxSize(250, wxDefaultSize.GetHeight()));

    // wxStaticText pour la recherche
    auto *labelrech_c = new wxStaticText(this, -1, _T("Recherche compte:"), wxPoint(160,120));

    // wxTextCtrl pour la recherche
    txt_rech_c = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(160,150), wxSize(250, wxDefaultSize.GetHeight()));


    rech = new wxButton(this,-1,"Recherche", wxPoint(70,60),
                       wxDefaultSize);
}


void TMyFrame_agc::Recherche(wxCommandEvent &event) {
    bool bOK = true;
    if (txt_rech->IsEmpty() && txt_rech_c->IsEmpty()) bOK = false;
    if (bOK){
        if (!txt_rech->IsEmpty()){
            // requete info client
        }

        if(!txt_rech_c->IsEmpty()){
            //requete info compte
        }

        // affichez info
        wxMessageBox(_T("oui"),wxT("BIM"));
    }
    else
        wxMessageBox(_T("Veuillez remplir une zone de recherche"),wxT("BIM"), wxICON_ERROR);
}
