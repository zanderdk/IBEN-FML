#IBEN-FML
A fork of [IBEN 1.1](https://sourceforge.net/projects/iben/) originally created by Gerd Behrmann, with patches allowing compilation on modern Linux distributions, as well as other small improvements such as the ability to choose another postscript viewer then Ghostview as the standard version of IBEN 1.1 used.

## Dependencies
The following dependencies should be installed before compiling IBEN-FML.

+ [BuDDy](https://sourceforge.net/projects/buddy/)
+ A postscript compatible viewer, GV, GSview, etc.
+ graphviz 

## Installation
1. Install BuDDy, graphviz, and a postscript viewer, GSview is used as the default.

2. If another viewer then GSview is installed, then change the macro PSV in iben.h.
```
#define PSV "gsview" => #define PSV "your viewer"
```

3. Use the standard ./configure and make combination to compile the program.

## Patches
This is a list of all the changes made to the program, none of patches changes parts of the program doing actual computations.

+ Added the C 'string.h' header for the 'strlen' method as it is not always included in the C++ header.
+ Added macro for the path to the postscript viewer in 'iben.h', and inserted it instead of 'Ghostview'.
+ Changed the mentions of 'Ghostview' in the man page to postscript viewer.

Note: if you only want the patches and not the source code is a patch file provided in the patch folder.

##License
The program is licensed under version 2 of the GPL as IBEN originally was, and a copy of the license is bundled with the program. 
