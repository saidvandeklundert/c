# Stuff on C

Used `docker pull gcc` to work through all the sample code on a Windows machine.

```
gcc -o main *.c
```


Find out where include files are:
```
`gcc -print-prog-name=cpp` -v
```

Where is the compiler:
```
which gcc
```
Edit the vscode settings in `c_cpp_properties.json`. Example:
```
{
    "env": {
      "myDefaultIncludePath": ["${workspaceFolder}", "${workspaceFolder}/include"],
      "myCompilerPath": "/usr/local/bin/gcc"
    },
    "configurations": [
      {
        "name": "devcontainer",
        "intelliSenseMode": "clang-x64",
        "includePath": [
            "${workspaceFolder}/**",
            "/home/klundert/c/hnpc/udp",
            "/usr/include"
        ],        
        "compilerPath": "/usr/bin/clang",
        "cStandard": "c13"
      }
    ],
    "version": 4
}

```

Find stuff:
```
egrep -r "struct addrinfo" /usr/include
```

https://www.cbyexample.com/

https://beej.us/guide/bgnet/html/

man -k socket 
