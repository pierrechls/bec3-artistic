[![Version](https://img.shields.io/badge/version-1.0-green.svg)](https://img.shields.io/badge/version-1.1-green.svg) [![Build status](https://img.shields.io/badge/build-passing-green.svg)](https://img.shields.io/badge/build-passing-green.svg) [![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20OS%20X%20%7C%20Windows-lightgrey.svg)](https://img.shields.io/badge/platform-Linux%20%7C%20OS%20X%20%7C%20Windows-lightgrey.svg)

# BeC3 artistic installation

Artistic installation realised in OpenGL, SDL, FMOD and BeC3-lib. Project realised in IMAC Engineering School, using the [BeC3 library](https://github.com/PierreChls/Bec3-lib), a C++ library created by [Pierre Charles](https://github.com/PierreChls), [Jérome Hernandez](https://github.com/Chouche) and [Corentin Limoge](https://github.com/climoge)

## How to use it

####Run WebLite API

Linux and Mac OSX :

	./weblite-api
	
Windows : 

	./weblite-api.bat

#### Open a new terminal window and clone the project

	git clone https://github.com/PierreChls/BeC3-artistic.git
	
####Create a JSON configuration file

```
{
  "user": {
    "login"    : "YOUR_LOGIN",
    "password" : "YOUR_PASSWORD" 
  },
  "objects" : [
    {
      "id"   : "Texture",
      "type" : "light"
    },
    {
      "id"   : "Cercles",
      "type" : "light"
    },
    {
      "id"   : "Musique",
      "type" : "light"
    },
    {
      "id"   : "Etoiles",
      "type" : "light"
    },
    {
      "id"   : "Satelite",
      "type" : "light"
    }
  ]
}
```

- Copy/paste this text on your json file
- Name this file : **Bec3.json**
- Put it in the **project/assets/conf/** folder
- Complete with your login and password BeC3 account
	
#### Build

	cd Bec3Artistic/build
	cmake ../project
	make

#### Run project 
	
	./template/artistic

##Prior installation

###For Mac users, install brew, a really cool package manager

    $ ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"

###You need CMake

Linux :

    $ sudo apt-get install cmake

Mac OSX :

    $ brew install cmake
    

###You need some libs

####GLEW

Linux :

    $ sudo apt-get install glew

Mac OSX :

    $ brew install glew

####SDL2

Linux :

    $ sudo apt-get install libsdl2-dev

Mac OSX :

    $ brew install sdl2

####FMOD

Download [FMOD Ex API](http://www.fmod.org/browse-fmod-ex-api/)

####CURL

Download [CURL](http://curl.haxx.se/download.html)


###You need install Web-Lite API (created by Bec3)

- Download [Web-Lite](https://drive.google.com/file/d/0ByN00DGNcsTBSUZDbWktbXh2RHM/view?usp=sharing)
- Install [JAVA ORACLE JDK 8](http://www.oracle.com/technetwork/java/javase/downloads/jdk8-downloads-2133151.html)
- Install [SBT](http://www.scala-sbt.org/download.html)
- Follow the instructions in the README file

