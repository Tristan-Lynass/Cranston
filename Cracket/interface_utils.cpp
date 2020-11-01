#include <windows.h>
#include <wlanapi.h>

#pragma comment(lib, "Wlanapi.lib")

static const DWORD WLAN_CLIENT_VERSION = 2;

static bool fails(DWORD result) {
    return result != ERROR_SUCCESS;
}



//void PrintWlanInterface(PWLAN_INTERFACE_INFO interfaceInfo) {
//    wprintf(L"Interface Description: %ws\n", interfaceInfo->strInterfaceDescription);
//    wprintf(L"Interface Description: %ws\n", interfaceInfo->InterfaceGuid);
//    wprintf(L"\n");
//}
//
//void PrintAllWlanInterfaces() {
//    DWORD version = NULL;
//    HANDLE client = NULL;
//
//    if (fails(WlanOpenHandle(WLAN_CLIENT_VERSION, NULL, &version, &client))) {
//        return;
//    }
//
//    PWLAN_INTERFACE_INFO_LIST interfaces;
//    if (fails(WlanEnumInterfaces(client, NULL, &interfaces))) {
//        return;
//    }
//
//    for (int i = 0; i < interfaces->dwNumberOfItems; i++) {
//        PWLAN_INTERFACE_INFO interfaceInfo = (PWLAN_INTERFACE_INFO)&interfaces->InterfaceInfo[i];
//        PrintWlanInterface(interfaceInfo);
//    }
//
//}

