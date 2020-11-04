
#include <windows.h>
#include <wlanapi.h>

#include "application.h"

#pragma comment(lib, "Wlanapi.lib")
 
static void windows() {
	DWORD version = NULL;
	HANDLE client = NULL;
	WlanOpenHandle(2, NULL, &version, &client);
}



int main(int argc, char** argv) {
	return start(argc, argv);
}