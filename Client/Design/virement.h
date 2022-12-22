#include "wx/wx.h"

//------------------------------------------------------------------------------
class TVir : public wxDialog
{
public:
    TVir(const wxString& title);
    void OkButton(wxCommandEvent& evt);
private:
    wxTextCtrl *Iban, *Nom;
};

enum{
    FIRST_ID = 3
};



