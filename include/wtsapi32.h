/*
 * Copyright 2005 Ulrich Czekalla (For CodeWeavers)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __WINE_WTSAPI32_H
#define __WINE_WTSAPI32_H

#ifdef __cplusplus
extern "C" {
#endif


typedef enum tagWTS_INFO_CLASS
{
    WTSInitialProgram,
    WTSApplicationName,
    WTSWorkingDirectory,
    WTSOEMId,
    WTSSessionId,
    WTSUserName,
    WTSWinStationName,
    WTSDomainName,
    WTSConnectState,
    WTSClientBuildNumber,
    WTSClientName,
    WTSClientDirectory,
    WTSClientProductId,
    WTSClientHardwareId,
    WTSClientAddress,
    WTSClientDisplay,
    WTSClientProtocolType,
} WTS_INFO_CLASS;

typedef enum _WTS_CONNECTSTATE_CLASS
{
    WTSActive,
    WTSConnected,
    WTSConnectQuery,
    WTSShadow,
    WTSDisconnected,
    WTSIdle,
    WTSListen,
    WTSReset,
    WTSDown,
    WTSInit
} WTS_CONNECTSTATE_CLASS;

typedef struct _WTS_PROCESS_INFOA
{
    DWORD SessionId;
    DWORD ProcessId;
    LPSTR pProcessName;
    PSID pUserSid;
} WTS_PROCESS_INFOA, *PWTS_PROCESS_INFOA;

typedef struct _WTS_PROCESS_INFOW
{
    DWORD SessionId;
    DWORD ProcessId;
    LPWSTR pProcessName;
    PSID pUserSid;
} WTS_PROCESS_INFOW, *PWTS_PROCESS_INFOW;

typedef struct _WTS_SESSION_INFOA
{
    DWORD SessionId;
    LPSTR pWinStationName;
    WTS_CONNECTSTATE_CLASS State;
} WTS_SESSION_INFOA, *PWTS_SESSION_INFOA;

typedef struct _WTS_SESSION_INFOW
{
    DWORD SessionId;
    LPWSTR pWinStationName;
    WTS_CONNECTSTATE_CLASS State;
} WTS_SESSION_INFOW, *PWTS_SESSION_INFOW;

BOOL WINAPI WTSQuerySessionInformationW(
    HANDLE hServer,
    DWORD SessionId,
    WTS_INFO_CLASS WTSInfoClass,
    LPWSTR * Buffer,
    DWORD * BytesReturned
    );

BOOL WINAPI WTSQuerySessionInformationA(
    HANDLE hServer,
    DWORD SessionId,
    WTS_INFO_CLASS WTSInfoClass,
    LPSTR * Buffer,
    DWORD * BytesReturned
    );
#define WTSQuerySessionInformation WINELIB_NAME_AW(WTSQuerySessionInformation)

BOOL WINAPI WTSWaitSystemEvent(HANDLE hServer, DWORD Mask, DWORD* Flags);

#ifdef __cplusplus
}
#endif

#endif
