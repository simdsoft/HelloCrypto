@echo off
"%XS_INSTDIR%\x-studio" -c -enc -cfg=.\encrypt-cfg.xml -i=.\dev-assets -o=.\assets

echo "Exiting ..."
ping /n 2 127.0.0.1 >nul
