#!/bin/bash
gcc -W -fcommon utilities.c linkedList.c cqueue.c userAdmin.c friendAdmin.c sendMsg.c groupAdmin.c server.c -pthread -L/usr/include/postgresql/libpq -lpq -o server
./server