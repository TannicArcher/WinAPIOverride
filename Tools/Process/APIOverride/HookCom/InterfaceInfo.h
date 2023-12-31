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
// Object: manages COM interface info from IDispatch parsing
//-----------------------------------------------------------------------------
#pragma once

#include "COM_include.h"
#include "MethodInfo.h"
#include "PropertyInfo.h"

class CInterfaceInfo
{
protected:
    void FreeMemory();
    void FreePropertiesMemory();
    void FreeMethodsMemory();

    void CommonConstructor();
public:
    CInterfaceInfo();
    CInterfaceInfo(IID* pIid,PBYTE* pVTBLAddress);
    ~CInterfaceInfo();

    HRESULT Parse(IUnknown* pObject,IDispatch* pDispatch,ITypeInfo* pTypeInfo,BOOL bParseMethods,BOOL bParseProperties);

    CMethodInfo* GetMethodInfoFromVTBLAddress(PBYTE VTBLAddress);

    CLinkListSimple* pMethodInfoList;// linked list of CMethodInfo*
    CLinkListSimple* pPropertyInfoList;// linked list of CPropertyInfo*

    PBYTE VTBLAddress;
    IID Iid;
    BSTR Name;
};
