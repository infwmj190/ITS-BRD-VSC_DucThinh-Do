# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/TI_Labor/gitProjekte/ITSBoard_2_Semester/Programs/Aufgabe1_neu/tmp/Aufgabe1_neu.Debug+ITSboard"
  "C:/TI_Labor/gitProjekte/ITSBoard_2_Semester/Programs/Aufgabe1_neu/tmp/1"
  "C:/TI_Labor/gitProjekte/ITSBoard_2_Semester/Programs/Aufgabe1_neu/tmp/Aufgabe1_neu.Debug+ITSboard"
  "C:/TI_Labor/gitProjekte/ITSBoard_2_Semester/Programs/Aufgabe1_neu/tmp/Aufgabe1_neu.Debug+ITSboard/tmp"
  "C:/TI_Labor/gitProjekte/ITSBoard_2_Semester/Programs/Aufgabe1_neu/tmp/Aufgabe1_neu.Debug+ITSboard/src/Aufgabe1_neu.Debug+ITSboard-stamp"
  "C:/TI_Labor/gitProjekte/ITSBoard_2_Semester/Programs/Aufgabe1_neu/tmp/Aufgabe1_neu.Debug+ITSboard/src"
  "C:/TI_Labor/gitProjekte/ITSBoard_2_Semester/Programs/Aufgabe1_neu/tmp/Aufgabe1_neu.Debug+ITSboard/src/Aufgabe1_neu.Debug+ITSboard-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/TI_Labor/gitProjekte/ITSBoard_2_Semester/Programs/Aufgabe1_neu/tmp/Aufgabe1_neu.Debug+ITSboard/src/Aufgabe1_neu.Debug+ITSboard-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/TI_Labor/gitProjekte/ITSBoard_2_Semester/Programs/Aufgabe1_neu/tmp/Aufgabe1_neu.Debug+ITSboard/src/Aufgabe1_neu.Debug+ITSboard-stamp${cfgdir}") # cfgdir has leading slash
endif()
