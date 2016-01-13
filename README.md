# iSeason

Project realised in IMAC Engineering School, in November and December 2015

**Collaborators :**

- [Pierre CHARLES](https://github.com/PierreChls)
- [Charlie DARRAUD](https://github.com/charliesrc)
- [Romain FRANÇOIS](https://github.com/Arctic76)

**Supported OS (require OpenGL 3+)**

- Linux Ubuntu
- Mac OSX


## How to use it

#### Download the models
	
[Download Files](https://drive.google.com/folderview?id=0B9RhOR0UbDtoR2VzZ19QMUY4WUU&usp=sharing)

put them in iSeason/project/assets/models/

#### Clone the project

	git clone git@github.com:PierreChls/iSeason.git
	
#### Build

	cd iSeason/build
	cmake ../project
	make
	
#### Run

	./template/game

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

####SDL2 MIXER

Linux :

    $ sudo apt-get install libsdl2-mixer-dev

Mac OSX :

    $ brew install sdl2_mixer
