//
// Created by Administrateur on 21/11/2022.
//

#include "../classes/socket/Server.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    clock_t t;
    Server server(8000);
    server.start();

    while(1)
    {
        t = clock();
        if (t/CLOCKS_PER_SEC % 60 == 0)
        {
            Message msg;
            msg.header.type = messageTypes::ServerAskUpdate;
            server.sendToAll(msg);
        }
        server.update(-1, false);
    }

    return 0;
}
