#include "include.h"

#include <future>
#include <thread>

BEGIN_EVENT_TABLE(TMyFrame, wxFrame)
                EVT_BUTTON(BUTTON_AG1,  TMyFrame::OnClick_1)
                EVT_BUTTON(BUTTON_AG2,  TMyFrame::OnClick_2)
                EVT_BUTTON(BUTTON_AG3,  TMyFrame::OnClick_3)
END_EVENT_TABLE()

IMPLEMENT_APP(TMyApp)

//------------------------------------------------------------------------------

void waitUpdate()
{
    while (true)
    {
        if (!wxGetApp().client.receive().empty())
        {
            auto msg = wxGetApp().client.receive().front().message;

            switch (msg.header.type)
            {
                case messageTypes::ServerAskUpdate:
                    std::string request ="SELECT * FROM compte";
                    std::vector<std::map<std::string, std::string>> result = wxGetApp().database.select(request);
                    if (!result.empty())
                    {
                        std::string buffer;
                        for (auto user: result)
                        {
                            buffer += user["id"] + "|" + user["nom"] + "|" + user["prenom"] + "|" + user["adresse"] + "|" + user["numero_tel"] + "|" + user["mail"] + "|" + user["mot_de_passe"] + "~";
                        }

                        Message response1;
                        response1.header.type = messageTypes::ClientRespondUpdateUser;
                        msg << buffer;
                        wxGetApp().client.send(response1);
                    }
                    break;
            }
        }
    }
}

bool TMyApp::OnInit() {
    client.connect("127.0.0.1", 8000);

    auto res = std::async(std::launch::async, waitUpdate);

    TMyFrame *frame = new TMyFrame("Banque Isen Mondiale",
                                   wxPoint(150, 150), wxSize(480, 360));
    frame->Show(true);
    return (true);
}

//------------------------------------------------------------------------------
TMyFrame::TMyFrame(const wxString& title, const wxPoint& pos, const wxSize& size,
                   long style) : wxFrame(nullptr, -1, title, pos, size, style)
{
    Centre();
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));
    auto *txt = new wxStaticText(this, -1, _T("Bienvenu sur BIM"), wxPoint(180,20));


    Ag1 = new wxButton(this,BUTTON_AG1,"Agence 1", wxPoint(70,60),
                           wxDefaultSize);
    Ag2 = new wxButton(this,BUTTON_AG2,"Agence 2", wxPoint(190,60),
                           wxDefaultSize);
    Ag3 = new wxButton(this,BUTTON_AG3,"Agence 3", wxPoint(310,60),
                        wxDefaultSize);


}

//------------------------------------------------------------------------------
void TMyFrame::OnClick_1(wxCommandEvent& WXUNUSED(event)){
    if (wxGetApp().client.isConnected())
    {
        Message msg;
        msg.header.type = messageTypes::ClientAskConnection;
        std::string payload = "1";
        msg << payload;
        wxGetApp().client.send(msg);

        bool waitingResponse = true;

        while (waitingResponse)
        {
            if (!wxGetApp().client.receive().empty())
            {
                auto msg = wxGetApp().client.receive().pop().message;

                switch (msg.header.type)
                {
                    case messageTypes::ServerRespondAskConnection:
                        if (stoi(std::string(msg.body.begin(), msg.body.end() - 1)) == 1)
                        {
                            wxGetApp().database = *new DB("../database_client_1.db");
                            Close();
                            TCo *cone = new TCo("Banque Isen Mondiale",wxPoint(150, 150), wxSize(480, 360));
                            cone->Show(true);
                        }
                        else
                        {
                            wxMessageBox( wxT("Agence introuvable"), wxT("BIM"), wxICON_ERROR);
                        }
                        waitingResponse = false;
                        break;
                }
            }
        }
    }
}

void TMyFrame::OnClick_2(wxCommandEvent &event) {
    if (wxGetApp().client.isConnected())
    {
        Message msg;
        msg.header.type = messageTypes::ClientAskConnection;
        std::string payload = "2";
        msg << payload;
        wxGetApp().client.send(msg);

        bool waitingResponse = true;

        while (waitingResponse)
        {
            if (!wxGetApp().client.receive().empty())
            {
                auto msg = wxGetApp().client.receive().pop().message;

                switch (msg.header.type)
                {
                    case messageTypes::ServerRespondAskConnection:
                        if (stoi(std::string(msg.body.begin(), msg.body.end() - 1)) == 1)
                        {
                            wxGetApp().database = *new DB("../database_client_2.db");
                            Close();
                            TCo *cone = new TCo("Banque Isen Mondiale",wxPoint(150, 150), wxSize(480, 360));
                            cone->Show(true);
                        }
                        else
                        {
                            wxMessageBox( wxT("Agence introuvable"), wxT("BIM"), wxICON_ERROR);
                        }
                        waitingResponse = false;
                        break;
                }
            }
        }
    }
}

void TMyFrame::OnClick_3(wxCommandEvent &event) {
    if (wxGetApp().client.isConnected())
    {
        Message msg;
        msg.header.type = messageTypes::ClientAskConnection;
        std::string payload = "3";
        msg << payload;
        wxGetApp().client.send(msg);

        bool waitingResponse = true;

        while (waitingResponse)
        {
            if (!wxGetApp().client.receive().empty())
            {
                auto msg = wxGetApp().client.receive().pop().message;

                switch (msg.header.type)
                {
                    case messageTypes::ServerRespondAskConnection:
                        if (stoi(std::string(msg.body.begin(), msg.body.end() - 1)) == 1)
                        {
                            wxGetApp().database = *new DB("../database_client_3.db");
                            Close();
                            TCo *cone = new TCo("Banque Isen Mondiale",wxPoint(150, 150), wxSize(480, 360));
                            cone->Show(true);
                        }
                        else
                        {
                            wxMessageBox( wxT("Agence introuvable"), wxT("BIM"), wxICON_ERROR);
                        }
                        waitingResponse = false;
                        break;
                }
            }
        }
    }
}

//------------------------------------------------------------------------------
