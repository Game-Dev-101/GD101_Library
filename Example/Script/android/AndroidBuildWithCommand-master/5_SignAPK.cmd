
::
::
::

cd %JAVA_HOME%\bin

jarsigner -verbose -keystore %ANDROID_PROJECT%\%PROJECT_NAME%\gen\AndroidTest.keystore -storepass 123456 -keypass 123456 -signedjar %ANDROID_PROJECT%\%PROJECT_NAME%\bin\%NAME%.signed.apk %ANDROID_PROJECT%\%PROJECT_NAME%\bin\%NAME%.unsigned.apk AndroidTestKey
