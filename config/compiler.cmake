##
## maintainer Johann Lee <me@qinka.pro>
## Copyright (C) 2017 Johann Lee <me@qinka.pro>
## GPLv3
##
## compiler configure
##


## cross compiler prefix
set (AIKO_ARM_PREFIX "arm-unknown-eabi-" CACHE STRING "The cross compiler prefix")


## compiler macro
## debug
option(AIKO_CONFIG_DEBUG "Turn on debug" ON)
if (${AIKO_CONFIG_DEBUG})
  set(INNER_AIKO_CONFIG_BUG " -g ")
else (${AIKO_CONFIG_DEBUG})
  set(INNER_AIKO_CONFIG_BUG " ")
endif (${AIKO_CONFIG_DEBUG})
## device type
set (AIKO_CONFIG_DEV "STM32F10X_HD" CACHE string "the kind of device")
## config compiling
## set up compiler
set (CMAKE_C_COMPILER   "${AIKO_ARM_PREFIX}gcc")
set (CMAKE_CXX_COMPILER "${AIKO_ARM_PREFIX}g++")
set (CMAKE_C_FLAGS      "$ENV{CCFLAGS} ${INNER_AIKO_CONFIG_DEBUG}  -mcpu=cortex-m3 -mthumb -nostdlib")
set (CMAKE_ASM_COMPILER "${AIKO_ARM_PREFIX}gcc")
set(CMAKE_EXE_LINKER_FLAGS " -T ${PROJECT_SOURCE_DIR}/link/aiko.ld")
add_definitions(" -D ${AIKO_CONFIG_DEV} -D USE_STDPERIPH_DRIVER ")