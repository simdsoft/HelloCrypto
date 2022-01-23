@echo off
rem !!!Don't move this file
rem usage: run.bat <BUILD_CFG>
rem    BUILD_CFG could be Debug,Release,MinSizeRel,RelWithDebInfo
pushd %~dp0
echo The current directory is: %cd%

set APP_NAME=HelloLua
set BUILD_DIR=D:/dev/projects/HelloLua/build_x86
set BUILD_CFG=%1

rem Determine which build config to run
if not defined BUILD_CFG (
  if exist run.bat.txt set /p BUILD_CFG=< run.bat.txt
)
if not defined BUILD_CFG set /p BUILD_CFG=Please input Build config(Debug,Release,MinSizeRel,RelWithDebInfo):
if not defined BUILD_CFG set BUILD_CFG=Debug

rem Save run config to run.bat.txt
echo %BUILD_CFG%>run.bat.txt

pushd assets
start %BUILD_DIR%/bin/%APP_NAME%/%BUILD_CFG%/%APP_NAME%.exe
popd
