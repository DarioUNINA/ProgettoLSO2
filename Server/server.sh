#!/bin/bash
gcc -W -fcommon  Controller/UtenteController.c Controller/BevandaController.c Controller/OrdinazioneController.c Controller/OrdineController.c Repository/DataBase.c Utilities/cqueue.c Utilities/Utilities.c server.c -pthread -L/usr/include/postgresql/libpq -lpq -o server
./server