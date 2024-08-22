# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/jovel/esp/v5.0.7/esp-idf/components/bootloader/subproject"
  "C:/Projetos/esp/fade/build/bootloader"
  "C:/Projetos/esp/fade/build/bootloader-prefix"
  "C:/Projetos/esp/fade/build/bootloader-prefix/tmp"
  "C:/Projetos/esp/fade/build/bootloader-prefix/src/bootloader-stamp"
  "C:/Projetos/esp/fade/build/bootloader-prefix/src"
  "C:/Projetos/esp/fade/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Projetos/esp/fade/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Projetos/esp/fade/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
