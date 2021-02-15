# Blackjack

## Install G++ Compiler
The g++ compiler is a free, open source compiler available on almost any operating system. g++ is part of the [GNU Compiler Collection](https://en.wikipedia.org/wiki/GNU_Compiler_Collection).

### Windows
If you are running under the windows OS then I recommend you download: [MinGW-w64](http://mingw-w64.org/)

### macOS
Just go to a terminal and type `g++` and it should offer to install

### Ubuntu
```bash
sudo apt install g++
```

## Install Game
* Open Terminal and change the current working directory to the location where you want the cloned directory to be made.
* Download the repository using the [instruction](https://help.github.com/en/github/creating-cloning-and-archiving-repositories/cloning-a-repository).
* In the command line go to the directory with the files downloaded:
```bash
cd cpp-games/07-blackjack
g++ -o game -I ./lib *.cpp lib/*.cpp
./game
```

## References

* [Blackjack Rules from Wikipedia](https://en.wikipedia.org/wiki/Blackjack#Rules)
