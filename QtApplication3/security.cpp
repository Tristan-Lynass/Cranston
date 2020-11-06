#include <Windows.h>

/*
    Copied from: https://docs.microsoft.com/en-us/windows/win32/api/securitybaseapi/nf-securitybaseapi-checktokenmembership
*/
bool IsRunAsElevatedUser() {
    BOOL isElevated;
    SID_IDENTIFIER_AUTHORITY authority = SECURITY_NT_AUTHORITY;
    PSID administrators = NULL;
    isElevated = AllocateAndInitializeSid(&authority,
                                          2,
                                          SECURITY_BUILTIN_DOMAIN_RID,
                                          DOMAIN_ALIAS_RID_ADMINS,
                                          0, 0, 0, 0, 0, 0,
                                          &administrators);
    if (isElevated) {
        if (!CheckTokenMembership(NULL, administrators, &isElevated)) {
            isElevated = FALSE;
        }
        FreeSid(administrators);
    }

    return(isElevated);
}
