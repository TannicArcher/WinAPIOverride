/*
Copyright (C) 2004 Jacquelin POTIER <jacquelin.potier@free.fr>
Dynamic aspect ratio code Copyright (C) 2004 Jacquelin POTIER <jacquelin.potier@free.fr>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; version 2 of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

//-----------------------------------------------------------------------------
// Object: manages query monitoring ownership
//-----------------------------------------------------------------------------
#pragma once

#include <windows.h>
#pragma warning (push)
#pragma warning(disable : 4005)// for '_stprintf' : macro redefinition in tchar.h
#include <TCHAR.h>
#pragma warning (pop)
#include "resource.h"
#include "DynamicLoadedFuncs.h"
#include "dialoginterfacemanager.h"

class CQueryFakingOwnerShip
{
private:
    TCHAR* pszPrefix;
    BOOL* pQuestionAsked;
    BOOL* pTakeSameAction;
    BOOL* pUpdateFakeApi;

    HWND hWndDialog;
    INT_PTR Dlg_Res;
    BOOL bDialogCreationError;

    void Init(HWND hWnd);
    void Close();
    static CQueryFakingOwnerShip* GetAssociatedObject(HWND hWndDialog);
    static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    static DWORD WINAPI ModelessDialogThread(PVOID lParam);
public:
    CQueryFakingOwnerShip(TCHAR* pszPrefix,BOOL* pTakeSameAction,BOOL* pUpdateFakeApi,BOOL* pQuestionAsked);
    ~CQueryFakingOwnerShip(void);

    INT_PTR ShowDialog();
};
