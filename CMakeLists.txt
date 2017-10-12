## require for CMake
cmake_minimum_required(VERSION 3.3)

## build system set up
set (CMAKE_SYSTEM_NAME      Generic)
set (CMAKE_SYSTEM_PROCESSOR arm)
set (CMAKE_CROSSCOMPILING   TRUE)

## project
project(aiko)

## languagse
enable_language(C ASM)

## cross compiler prefix
if (not (defined "ARM_PREFIX"))
  set (ARM_PREFIX "arm-unknown-eabi-")
endif (not (defined "ARM_PREFIX"))

## set up compiler
set (CMAKE_C_COMPILER   "${ARM_PREFIX}gcc")
set (CMAKE_CXX_COMPILER "${ARM_PREFIX}g++")
set (CMAKE_C_FLAGS      "$ENV{CCFLAGS} -mcpu=cortex-m3 -mthumb")
set (CMAKE_ASM_COMPILER "${ARM_PREFIX}gcc")

## for platform
if (CMAKE_HOST_SYSTEM_NAME MATCHES "Windows")
  if (NOT (DEFINED "EXE_IGNORE"))
    set (EXE_POSTFIX ".exe") 
  endif (NOT (DEFINED "EXE_IGNORE"))
endif (CMAKE_HOST_SYSTEM_NAME MATCHES "Windows")
