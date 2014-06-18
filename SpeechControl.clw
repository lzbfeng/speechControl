; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAddConfig
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "SpeechControl.h"

ClassCount=4
Class1=CSpeechControlApp
Class2=CSpeechControlDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SPEECHCONTROL_DIALOG
Class4=CAddConfig
Resource4=IDD_ADDCONFIG

[CLS:CSpeechControlApp]
Type=0
HeaderFile=SpeechControl.h
ImplementationFile=SpeechControl.cpp
Filter=N

[CLS:CSpeechControlDlg]
Type=0
HeaderFile=SpeechControlDlg.h
ImplementationFile=SpeechControlDlg.cpp
Filter=D
BaseClass=CBkDialogST
VirtualFilter=dWC
LastObject=CSpeechControlDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=SpeechControlDlg.h
ImplementationFile=SpeechControlDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SPEECHCONTROL_DIALOG]
Type=1
Class=CSpeechControlDlg
ControlCount=2
Control1=IDC_SPEAK,button,1342242816
Control2=IDC_ADDCONFIG,button,1342242816

[DLG:IDD_ADDCONFIG]
Type=1
Class=CAddConfig
ControlCount=11
Control1=IDCANCEL,button,1342242816
Control2=IDC_GOODS,edit,1350631552
Control3=IDC_ORDER,edit,1350631552
Control4=IDC_STATIC_GOODS,static,1342308352
Control5=IDC_STATIC_ORDER,static,1342308352
Control6=IDC_STATIC,button,1342177287
Control7=IDC_ADD,button,1342242816
Control8=IDC_DELETE,button,1342242816
Control9=IDC_STATIC,button,1342177287
Control10=IDC_DELGOODS,edit,1350631552
Control11=IDC_STATIC_DELETEORDER,static,1342308352

[CLS:CAddConfig]
Type=0
HeaderFile=AddConfig.h
ImplementationFile=AddConfig.cpp
BaseClass=CBkDialogST
Filter=D
VirtualFilter=dWC
LastObject=CAddConfig

