# General

This library will provide some basic JNA functionality to interact with ROOT objects via jvm. JNA will have an overhead with respect to JNI, but, to me, is much simpler to use with respect to JNI. This library has the aim to import the functionality of loading histograms into hps-java and retrieve information for calibration purposes so will be developed with that concept in mind. 

# Getting started

Compile the c++ library

```
cmake -B build -S .
cmake --build build
```

The library librootjna.so (.dylib) should now be inside the build folder.
In the java directory there are some files of example on how to interact with the wrapper that are used inside hps-java. 
In order to load the library, one has to specify the location of the library via -Djna.library.path="/path/to/rootjna/build/"

