//
// Created by Administrateur on 21/11/2022.
//
#include <iostream>

#include <mysql/jdbc.h>
#include "../classes/socket/Client.h"
#include "../classes/socket/Message.h"
#include <windows.h>

using namespace std;

int main()
{
    Client client;

    client.connect("127.0.0.1", 8000);

    while (1)
    {
        if (client.isConnected() && !client.receive().empty())
        {
            Message msg;
            msg.header.type = messageTypes::ClientAskConnection;
            std::string payload = "1";
            msg << payload;
            client.send(msg);
            cout << "Message Received !" << endl;
        }
    }
    return 0;
}