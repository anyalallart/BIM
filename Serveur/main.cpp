//
// Created by Administrateur on 21/11/2022.
//

#include "../classes/socket/Server.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
    Server server(8000);
    server.start();

    auto res = std::async(std::launch::async, [&] {
        while(1)
        {
            std::this_thread::sleep_for(std::chrono::seconds(60));
            std::cout << "Sent update request" << std::endl;
            Message msg;
            msg.header.type = messageTypes::ServerAskUpdate;
            server.sendToAll(msg);
        }
    });

    while(1)
    {
        server.update(-1, false);
    }

    return 0;
}
