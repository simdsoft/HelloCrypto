@echo off
"%XS_INSTDIR%\x-studio" -c -enc -cfg=.\encrypt-cfg.xml -i=.\assets-dev -o=.\assets -cp=.ttf;.mp3;.ogg;.mp4

echo "Exiting ..."
ping /n 2 127.0.0.1 >nul
