#ifndef PongConsoleClient_H
#define PongConsoleClient_H

#include <string>

namespace pong {

class ConsoleClient {

public:
    ConsoleClient(std::string serverIPv4Str, int serverPort);

    ~ConsoleClient();
};


}

#endif