#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "sdl_utils::sdl_utils" for configuration "Debug"
set_property(TARGET sdl_utils::sdl_utils APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(sdl_utils::sdl_utils PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libsdl_utils.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS sdl_utils::sdl_utils )
list(APPEND _IMPORT_CHECK_FILES_FOR_sdl_utils::sdl_utils "${_IMPORT_PREFIX}/lib/libsdl_utils.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
