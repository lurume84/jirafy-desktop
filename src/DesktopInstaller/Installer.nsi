;NSIS Modern User Interface
;Basic Example Script
;Written by Joost Verburg

;--------------------------------
;Include Jirafy Desktop

!include "MUI2.nsh"
!include "WinVer.nsh"

!define MUI_ICON "..\..\src\DesktopUI\img\logo2.ico"
!define MUI_HEADERIMAGE
!define MUI_HEADERIMAGE_BITMAP "..\..\src\DesktopUI\img\logo.bmp"
!define MUI_HEADERIMAGE_RIGHT
!define PRODUCT_NAME "Jirafy Desktop"
!define VERSION "0.1.2.0"
!define PRODUCT_PUBLISHER "Luis Ruiz"
!define PRODUCT_WEB_SITE "https://github.com/lurume84/jirafy-desktop"

VIProductVersion "${VERSION}"
VIAddVersionKey "ProductName" "Jirafy Desktop"
VIAddVersionKey "FileVersion" "${VERSION}"
VIAddVersionKey "LegalCopyright" "Copyright (c) 2019 Luis Ruiz"
VIAddVersionKey "FileDescription" "Jirafy Desktop"
;--------------------------------
;General

  ;Name and file
  Name "Jirafy Desktop"
  OutFile "../../bin/Release/DesktopInstaller/JirafySetup.exe"

  ;Default installation folder
  InstallDir "$LOCALAPPDATA\Jirafy Desktop"
  
  ;Get installation folder from registry if available
  InstallDirRegKey HKCU "Software\Jirafy Desktop" ""

  ;Request application privileges for Windows Vista
  RequestExecutionLevel user

;--------------------------------
;Interface Settings

  !define MUI_ABORTWARNING

;--------------------------------
;Pages

  !insertmacro MUI_PAGE_LICENSE "..\..\LICENSE"
  !insertmacro MUI_PAGE_COMPONENTS
  !insertmacro MUI_PAGE_DIRECTORY
  !insertmacro MUI_PAGE_INSTFILES

  !insertmacro MUI_UNPAGE_CONFIRM
  !insertmacro MUI_UNPAGE_INSTFILES
  
;--------------------------------
;Languages
 
  !insertmacro MUI_LANGUAGE "English"

;--------------------------------
;Installer Sections

Section "Desktop" SecDummy

  SetOutPath "$INSTDIR"
  File /x "*.pdb" /x "*.ipdb" /x "*.iobj" /x "*.lib" "..\..\bin\Release\DesktopApp\*.*"
  
  ; File /oname=JirafyW7.exe "..\..\bin\Release\DesktopAppW7\Jirafy.exe"
  
  SetOutPath "$INSTDIR\Html"
  File /r "..\..\bin\Release\DesktopApp\Html\loading"

  SetOutPath "$INSTDIR\locales"
  File /r "..\..\bin\Release\DesktopApp\locales\*.*"

  SetOutPath "$INSTDIR\swiftshader"
  File /r "..\..\bin\Release\DesktopApp\swiftshader\*.dll"

  ; Create application shortcut (first in installation dir to have the correct "start in" target)
  SetOutPath "$INSTDIR"
  
  ; ${If} ${IsWin7}
  ;   CreateShortCut "$INSTDIR\${PRODUCT_NAME}.lnk" "$INSTDIR\JirafyW7.exe"
  ; ${Else} 
    CreateShortCut "$INSTDIR\${PRODUCT_NAME}.lnk" "$INSTDIR\Jirafy.exe"
  ; ${EndIf} 
  
  ; Start menu entries
  SetOutPath "$SMPROGRAMS\${PRODUCT_NAME}\"
  CopyFiles "$INSTDIR\${PRODUCT_NAME}.lnk" "$SMPROGRAMS\${PRODUCT_NAME}\"
  CopyFiles "$INSTDIR\${PRODUCT_NAME}.lnk" "$desktop"
  Delete "$INSTDIR\${PRODUCT_NAME}.lnk"

  ;Store installation folder
  WriteRegStr HKCU "Software\Jirafy Desktop" "" $INSTDIR
  
  ;Create uninstaller
  WriteUninstaller "$INSTDIR\Uninstall.exe"

SectionEnd

;--------------------------------
;Descriptions

  ;Language strings
  LangString DESC_SecDummy ${LANG_ENGLISH} "Desktop section."

  ;Assign language strings to sections
  !insertmacro MUI_FUNCTION_DESCRIPTION_BEGIN
    !insertmacro MUI_DESCRIPTION_TEXT ${SecDummy} $(DESC_SecDummy)
  !insertmacro MUI_FUNCTION_DESCRIPTION_END

;--------------------------------
;Uninstaller Section

Section "Uninstall"

  ;ADD YOUR OWN FILES HERE...

  Delete "$INSTDIR\Uninstall.exe"

  RMDir /r "$INSTDIR"

  DeleteRegKey /ifempty HKCU "Software\Jirafy Desktop"

SectionEnd