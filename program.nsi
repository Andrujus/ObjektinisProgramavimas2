; NSIS Installer Script for Studentu_Proga
Outfile "Program_Installer.exe"
InstallDir "$PROGRAMFILES\Studentu_Proga"
RequestExecutionLevel admin
SetCompressor /SOLID lzma

Section "Install"
  SetOutPath $INSTDIR
  File "bin\ro5_test.exe"

  CreateShortcut "$DESKTOP\Program.lnk" "$INSTDIR\ro5_test.exe"

  ; Sukuriam Start Menu nuorodą
  CreateDirectory "$SMPROGRAMS\Studentu_Proga"
  CreateShortcut "$SMPROGRAMS\Studentu_Proga\Studentu_Proga.lnk" "$INSTDIR\ro5_test.exe"
  CreateShortcut "$SMPROGRAMS\Studentu_Proga\Uninstall.lnk" "$INSTDIR\uninstall.exe"
SectionEnd

Section "Uninstall"
  Delete "$INSTDIR\ro5_test.exe"
  Delete "$DESKTOP\Program.lnk"
  Delete "$SMPROGRAMS\Program\Studentu_Proga.lnk"
  Delete "$SMPROGRAMS\Program\Uninstall.lnk"
  RMDir "$SMPROGRAMS\Program"
  RMDir "$INSTDIR"
SectionEnd
