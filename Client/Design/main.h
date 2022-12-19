#include "wx/wx.h"
#include <iostream>
#include "connexion.h"
#include "../../classes/database/DB.h"
#include "../../classes/socket/Client.h"
#include "../../classes/socket/Message.h"

//------------------------------------------------------------------------------
class TMyApp : public wxApp
{
public:
    Client client;
    virtual bool OnInit();
};

//------------------------------------------------------------------------------
class TMyFrame : public wxFrame
{
public:
    TMyFrame(const wxString& title, const wxPoint& pos, const wxSize& size,
             long style = wxDEFAULT_FRAME_STYLE);
    void OnClick_1(wxCommandEvent& event);
    void OnClick_2(wxCommandEvent& event);
    void OnClick_3(wxCommandEvent& event);

private:
    wxButton *Ag1;
    wxButton *Ag2;
    wxButton *Ag3;

DECLARE_EVENT_TABLE()
};

enum
{
    BUTTON_AG1 = 1,
    BUTTON_AG2 = 2,
    BUTTON_AG3 = 3,
};
