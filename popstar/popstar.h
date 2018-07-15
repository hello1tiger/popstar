// popstar.h : main header file for the POPSTAR application
//

#if !defined(AFX_POPSTAR_H__D7BF3CDC_8A8B_46C4_AD18_75D3671B100D__INCLUDED_)
#define AFX_POPSTAR_H__D7BF3CDC_8A8B_46C4_AD18_75D3671B100D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPopstarApp:
// See popstar.cpp for the implementation of this class
//

class CPopstarApp : public CWinApp
{
public:
	CPopstarApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPopstarApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPopstarApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POPSTAR_H__D7BF3CDC_8A8B_46C4_AD18_75D3671B100D__INCLUDED_)
