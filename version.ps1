$x='0'
$y='1'
$z='6'

((Get-Content -path .\src\DesktopApp\resources\win\resources.rc -Raw) -replace '0.0.0.0', ($x + '.' + $y + '.' + $z + '.0')) | Set-Content -Path .\src\DesktopApp\resources\win\resources.rc
((Get-Content -path .\src\DesktopApp\resources\win\resources.rc -Raw) -replace '0,0,0,0', ($x + ',' + $y + ',' + $z + ',0')) | Set-Content -Path .\src\DesktopApp\resources\win\resources.rc
((Get-Content -path .\src\DesktopInstaller\Installer.nsi -Raw) -replace '0.0.0.0', ($x + '.' + $y + '.' + $z + '.0')) | Set-Content -Path .\src\DesktopInstaller\Installer.nsi