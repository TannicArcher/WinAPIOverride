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
// Object: manages lite xml fields
//-----------------------------------------------------------------------------

#pragma once

#include <windows.h>
#pragma warning (push)
#pragma warning(disable : 4005)// for '_stprintf' : macro redefinition in tchar.h
#include <TCHAR.h>
#pragma warning (pop)

namespace EmulatedRegistry
{

class CXmlLite
{
public:
    static BOOL ReadXMLValue(TCHAR* FullString,TCHAR* Markup,SIZE_T* pValue,TCHAR** pPointerAfterEndingMarkup);
    static BOOL ReadXMLValue(TCHAR* FullString,TCHAR* Markup,BYTE** pBuffer,SIZE_T* pBufferLengthInByte,TCHAR** pPointerAfterEndingMarkup);
    static BOOL ReadXMLValue(TCHAR* FullString,TCHAR* Markup,TCHAR** pszValue,BOOL bUnicodeFile,TCHAR** pPointerAfterEndingMarkup);
    static BOOL ReadXMLMarkupContent(TCHAR* FullString,TCHAR* Markup,TCHAR** ppszContent,SIZE_T* pContentLength,TCHAR** pPointerAfterEndingMarkup);
    static void WriteXMLValue(HANDLE hFile,TCHAR* Markup,SIZE_T Value);
    static void WriteXMLValue(HANDLE hFile,TCHAR* Markup,PBYTE Buffer,SIZE_T BufferLengthInByte);
    static void WriteXMLValue(HANDLE hFile,TCHAR* Markup,TCHAR* Value);
};
}