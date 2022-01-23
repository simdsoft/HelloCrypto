
## Folder description

- dev-assets: The plain resources for dev, debugging
- assets: The encrypted resources for tests/release/publish

## Build and run

- Clone adxe(another cocos2d-x fork) and run setup.py in root of engine

git clone https://github.com/adxeproject/adxe

# Ensure install visual studio 2019/2022
- Use cmake to build
cmake -B build_x86 -A Win32 -DBUILD_EXTENSION_FAIRYGUI=OFF -DBUILD_EXTENSION_GUI=OFF
cmake --build build_x86 --target HelloLua

- Open build_x86/HelloLua.sln, and press F5 to run, by default the vs debugging working directory is the encrypted folder `assets`,
 everything should be fine if the decrypt work well. 

## Use a new key & ivec to encrypt resources

- Method A:
  - Delete file encrypt-cfg.xml and run do-encrypt.bat
  
- Method B:
  - run command: "%XS_INSTDIR%\x-studio" -c -enc -nk -cfg=.\encrypt-cfg.xml -i=.\dev-assets -o=.\assets
  
- After reencrypt with new key, you needs change it at AppDelegate.cpp

## For more usage of x-studio encrypt system, run follow command:

"%XS_INSTDIR%\x-studio" -c --help
