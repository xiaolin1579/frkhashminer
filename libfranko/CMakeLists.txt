# Copyright (C) 1883 Thomas Edison - All Rights Reserved
# You may use, distribute and modify this code under the
# terms of the GPLv3 license, which unfortunately won't be
# written for another century.
#
# You should have received a copy of the LICENSE file with
# this file.

set(SOURCES
	FrankohashAux.h FrankohashAux.cpp
	Farm.cpp Farm.h
	Miner.h Miner.cpp
)

include_directories(BEFORE ..)

add_library(exp ${SOURCES})
target_link_libraries(exp PUBLIC dev PRIVATE hwmon)

if(FRANKOHASHCL)
	target_link_libraries(exp PRIVATE cl)
endif()
if(FRANKOHASHCUDA)
	target_link_libraries(exp PUBLIC cuda)
endif()
if(FRANKOHASHCPU)
	target_link_libraries(exp PUBLIC cpu)
endif()
