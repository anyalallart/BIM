//
// Created by Administrateur on 21/11/2022.
//

#include "socket/Server.h"
#include <iostream>

using namespace std;

int main()
{
    Server testServer(8000);
    testServer.start();

    while(1)
    {
        testServer.update(-1, true);
        std::cout << "OUIIIIII123456789101112131415161718" << std::endl;
    }

    return 0;
}
