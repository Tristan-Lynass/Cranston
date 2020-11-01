#include <iostream>

#include "security.h"
#include "interface_utils.h"

int main() {

    // TODO: Add CLI option '-gui' to run with GUI
    if (IsRunAsElevatedUser()) {
       // PrintAllWlanInterfaces();
    } else {
        std::cerr << "Please run as admin." << std::endl;
        return 1;
    }
}
