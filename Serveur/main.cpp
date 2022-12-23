//
// Created by Administrateur on 21/11/2022.
//

#include "../classes/socket/Server.h"
#include <iostream>

using namespace std;

int main()
{
    Server server(8000);
    server.start();

    while(1)
    {
        server.update(-1, true);
        std::cout << "oui222" << std::endl;
    }

    return 0;
}
