; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPopstarDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "popstar.h"

ClassCount=3
Class1=CPopstarApp
Class2=CPopstarDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_POPSTAR_DIALOG

[CLS:CPopstarApp]
Type=0
HeaderFile=popstar.h
ImplementationFile=popstar.cpp
Filter=N

[CLS:CPopstarDlg]
Type=0
HeaderFile=popstarDlg.h
ImplementationFile=popstarDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CPopstarDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=popstarDlg.h
ImplementationFile=popstarDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_POPSTAR_DIALOG]
Type=1
Class=CPopstarDlg
ControlCount=7
Control1=IDC_newgame,button,1342242816
Control2=IDC_exit,button,1342242816
Control3=IDC_level,edit,1342242949
Control4=IDC_goal,edit,1342242949
Control5=IDC_score,edit,1342242949
Control6=IDC_show,static,1342177280
Control7=IDC_Solve,button,1342242816

