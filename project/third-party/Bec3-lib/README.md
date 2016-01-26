# Bec3 - Library

Project realised in IMAC Engineering School

**Supported OS :**

- Linux Ubuntu
- Mac OSX

## How to use it

1) Download zip file or clone the git repository

    git clone https://github.com/PierreChls/Bec3-lib.git
    
2) Move it to your third-party directory

3) In your third-party's CMakeLists.txt, add Bec3-lib subdirectory's
    
    add_subdirectory(Bec3-lib)
    
4) In your project's CMakeLists.txt, include Bec3-lib directory's and set Bec3-lib

    include_directories(third-party/Bec3-lib/include/)
    set(Bec3-lib)
    
##Prior installation

###You need CMake

Linux :

    $ sudo apt-get install cmake

Mac OSX :

    $ brew install cmake
    

###You need CURL

Download [CURL](http://curl.haxx.se/download.html)

