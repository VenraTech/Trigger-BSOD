// WindowsBSOD.cpp: Defines the entry point for the console application.
//

#include <Windows.h>
#pragma comment(lib, "ntdll.lib") // You MUST link this.

extern "C" NTSTATUS WINAPI RtlAdjustPrivilege(DWORD dwPrivilege, BYTE bEnable, BYTE bClient, BYTE *lpbWasEnabled);
extern "C" NTSTATUS WINAPI NtRaiseHardError(NTSTATUS ntErrorCode, DWORD dwParamNum, DWORD dwOemStrParamMask, DWORD **ppdwParam, DWORD dwRspOption, DWORD *lpdwRsp);

int main() {
   BYTE unused;
   DWORD lpdwRsp;
   DWORD SHUTDOWN_PRIVILEGE = 19, OPTION_SHUTDOWN = 6;
   RtlAdjustPrivilege(SHUTDOWN_PRIVILEGE, TRUE, FALSE, &unused);
   NtRaiseHardError(/* Any error code from 0xc0000000 to 0xc0000fff */, 0, 0, NULL, OPTION_SHUTDOWN, &lpdwRsp);
}
