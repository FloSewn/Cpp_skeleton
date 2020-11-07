#===========================================================
# Define Build Type                                        
#===========================================================

# default build type
if( NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES )

  # set the default build type
  message( STATUS "Setting build type to 'Debug' as none was specified." )
  set( CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE )

  # set the possible values of build type
  set_property( CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" )

endif()


#===========================================================
# Compiler FLags                                           
#===========================================================
set(
  CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17"
  CACHE STRING "Flags used by the compiler during all build types." FORCE
)

# set compiler definition
if(     CMAKE_CXX_COMPILER_ID STREQUAL "GNU"   )
  string( APPEND MY_CMAKE_CXX_FLAGS   "-DGNU"   )
elseif( CMAKE_CXX_COMPILER_ID STREQUAL "Intel" )
  string( APPEND MY_CMAKE_CXX_FLAGS   "-DINTEL" )
endif()


#===========================================================
# Compiler Flags (Debug Mode)   
#===========================================================
# set debug compiler flags
if( CMAKE_BUILD_TYPE STREQUAL "Debug" )

  # produce debugging information
  string( APPEND MY_CMAKE_CXX_FLAGS " -g" )

  # disable optimization
  string( APPEND MY_CMAKE_CXX_FLAGS " -O0" )

  # disable optimization
  string( APPEND MY_CMAKE_CXX_FLAGS " -pg" )

  # overwrite compiler flags
  set(
    CMAKE_CXX_FLAGS_DEBUG ${MY_CMAKE_CXX_FLAGS}
    CACHE STRING "Flags used by the compiler during debug builds." FORCE
  )

endif()

#===========================================================
# Compiler Flags (Release Mode) 
#===========================================================

# set release compiler flags
if( CMAKE_BUILD_TYPE STREQUAL "Release" )

  # enable optimization
  string( APPEND MY_CMAKE_CXX_FLAGS " -O3" )

  # overwrite compiler flags
  set(
    CMAKE_CXX_FLAGS_RELEASE ${MY_CMAKE_CXX_FLAGS}
    CACHE STRING "Flags used by the compiler during debug builds." FORCE
  )

endif()

