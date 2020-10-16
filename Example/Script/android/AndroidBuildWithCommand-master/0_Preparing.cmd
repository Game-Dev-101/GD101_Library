
:: JAVA_HOME must be set on Environment Variable and added to path
:: ANDROID_HOME must be set too...

:: Create KeyStore for release version
:: keytool from JDK
set JAVA_HOME = C:\Program Files\Java\jdk1.8.0_111
set ANDROID_HOME = C:\Program Files\Android\android-sdk

cd %JAVA_HOME%\bin
:: Create keystore and save in \gen direktory
keytool -genkeypair -validity 10000 -dname "CN=Jenggot Malam,OU=Software Development,O=Jenggot Malam,L=Malang,S=East Java,C=id" -keystore %ANDROID_PROJECT%\%PROJECT_NAME%\gen\AndroidTest.keystore -storepass 123456 -keypass 123456 -alias AndroidTestKey -keyalg RSA -v