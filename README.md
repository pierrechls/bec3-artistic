# Bec3 - Artistic Installation

Project realised in IMAC Engineering School

**Supported OS (require OpenGL 3+)**

- Linux Ubuntu
- Mac OSX


## How to use it

#### Clone the project

	git clone git@github.com:PierreChls/iSeason.git
	
#### Build

	cd Bec3Artistic/build
	cmake ../project
	make
	
#### Run

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

- [Download FMOD Ex API](http://www.fmod.org/browse-fmod-ex-api/)
