#pragma once


// TODO: Get MAC address based from GUID

// TODO: Change MAC address based on (GUID, new MAC)

// TODO: Enable monitor mode
// TODO: Disable monitor mode
// - https://docs.microsoft.com/en-us/windows/win32/api/wlanapi/nf-wlanapi-wlansetinterface

// TODO: get list of wlan interfaces + information
// - https://docs.microsoft.com/en-us/windows/win32/api/wlanapi/nf-wlanapi-wlanenuminterfaces
// - https://docs.microsoft.com/en-us/windows/win32/api/wlanapi/nf-wlanapi-wlangetinterfacecapability
// - https://docs.microsoft.com/en-us/windows/win32/api/wlanapi/ns-wlanapi-wlan_association_attributes
// - https://docs.microsoft.com/en-us/windows/win32/api/wlanapi/nf-wlanapi-wlanqueryinterface
QString* printInterfaces();