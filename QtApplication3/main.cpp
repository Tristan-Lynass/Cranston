
#include <windows.h>
#include <wlanapi.h>
#include <iostream>

#include "security.h" 
#include "application.h"

#pragma comment(lib, "Wlanapi.lib")
 
//static void windows() {
//	DWORD version = NULL;
//	HANDLE client = NULL;
//	WlanOpenHandle(2, NULL, &version, &client);
//}
//
//
//
//int main(int argc, char** argv) {
//	return start(argc, argv);
//}





int main(int argc, char** argv) {
    // TODO: Add CLI option '-gui' to run with GUI
    //if (IsRunAsElevatedUser()) {
        start(argc, argv);
    //} else {
        //std::cerr << "Please run as admin." << std::endl;
        //return 1;
    //}
}
