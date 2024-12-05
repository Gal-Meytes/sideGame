//
// Created by Surfer Boy on 30/11/2024.
//

#ifndef PROJECT_LIBRARYDEPENDENCIES_H
#define PROJECT_LIBRARYDEPENDENCIES_H
#include <vector>
#include <string>
#include <iostream>
#include <fcntl.h>           /* Definition of AT_* constants */
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// should we assume 64 bit or 32 bit?
// the code of FileStorageDevice depends on it
// important: -D_FILE_OFFSET_BITS=64
// or just use define
// we want to support all file sizes
#endif //PROJECT_LIBRARYDEPENDENCIES_H
