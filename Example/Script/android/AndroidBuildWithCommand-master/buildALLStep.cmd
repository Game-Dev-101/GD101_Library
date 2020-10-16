:: Define Platform Version
set ANDROID_API_VERSION=android-22
set ANDROID_BUILDTOOL_VERSION=26.0.2
set PROJECT_NAME=AndroidBuildWithCommand-master
set ANDROID_PROJECT=C:\GD101_LIB\Example\Script\android

set NAME=2_Basic_Primitive_Shape

cd %ANDROID_PROJECT%\%PROJECT_NAME%
call 0_Preparing.cmd

:: Kita lewati step 1 2 3 karena belum butuh Java ya

cd %ANDROID_PROJECT%\%PROJECT_NAME%
call 4_CreateAPK.cmd

cd %ANDROID_PROJECT%\%PROJECT_NAME%
call 4_1_AddLib.cmd

cd %ANDROID_PROJECT%\%PROJECT_NAME%
call 5_SignAPK.cmd

cd %ANDROID_PROJECT%\%PROJECT_NAME%
call 6_ZipAlignAPK.cmd

cd %ANDROID_PROJECT%\%PROJECT_NAME%
echo BUILD SUCCESSFUL
pause
