// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <iomanip>


/*The additional include directry were included via Visual studio project properties. this allows direct inclusion of files from other project(folders) as follows:*/
#include "Room.h"									//IF PROJECT IS MISSING CLASSES USE #include "../Problem1/Room.h"
#include "Customer.h"								//IF PROJECT IS MISSING CLASSES USE #include "../Problem2/Customer.h"
#include "Date.h"									//../Problem2/Date.h
#include "Reservations.h"