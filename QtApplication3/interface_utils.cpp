#include <windows.h>
#include <wlanapi.h>
#include <iostream>
#include <QString>

#pragma comment(lib, "Wlanapi.lib")

static const DWORD WLAN_CLIENT_VERSION = 2;

static bool fails(DWORD result) {
    return result != ERROR_SUCCESS;
}

QString* printInterfaces() {
    DWORD version = NULL;
    HANDLE client = NULL;

    if (fails(WlanOpenHandle(WLAN_CLIENT_VERSION, NULL, &version, &client))) {
        return new QString("Could not find interface");
    }

    PWLAN_INTERFACE_INFO_LIST interfaces;
    if (fails(WlanEnumInterfaces(client, NULL, &interfaces))) {
        return new QString("Could not find interface");
    }

    for (int i = 0; i < interfaces->dwNumberOfItems; i++) {
        PWLAN_INTERFACE_INFO interfaceInfo = (PWLAN_INTERFACE_INFO)&interfaces->InterfaceInfo[i];
        return new QString(QString::fromWCharArray(interfaceInfo->strInterfaceDescription, WLAN_MAX_NAME_LENGTH));
        //wprintf(L"Interface Description: %ws\n", interfaceInfo->);
        //wprintf(L"\n");
    }
    return new QString("Could not find interface");
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

