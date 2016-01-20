# Bec3 - Artistic Installation

Project realised in IMAC Engineering School

**Supported OS :**

- Linux Ubuntu
- Mac OSX


## How to use it

####Run WebLite API

Linux and Mac OSX :

	./weblite-api
	
Windows : 

	./weblite-api.bat

#### Open a new terminal window and clone the project

	git clone https://github.com/PierreChls/Bec3Artistic.git
	
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

