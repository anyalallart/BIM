#include "test.h"
#include "virement.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{

    TVir *custom = new TVir(wxT("test"));
    custom->Show(true);

    return true;
}