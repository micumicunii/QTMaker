# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\CardiNest_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\CardiNest_autogen.dir\\ParseCache.txt"
  "CardiNest_autogen"
  )
endif()
