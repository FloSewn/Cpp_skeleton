#===========================================================
# Module: Auxilliaries
#===========================================================
# Define directories
set( AUX_DIR    ${SRC}/aux         )
set( AUX_INC    ${AUX_DIR}/include )
set( AUX_SRC    ${AUX_DIR}/src     )

# Define source files
set( AUX_MAIN
  ${AUX_SRC}/catch.cpp
  )

#===========================================================
# Library: Auxilliaries
#===========================================================
# define library name
set( AUX_LIB aux )

# add sources to library
#add_library( ${AUX_LIB} INTERFACE  ) # if header only
add_library( ${AUX_LIB} STATIC ${AUX_MAIN} )

# set includes for header only
#target_include_directories( ${AUX_LIB}
#  INTERFACE $<BUILD_INTERFACE:${AUX_INC}>
#  )

# Libraries for olc_pixel_game_engine
#target_link_libraries(${AUX_LIB} -lX11)
#target_link_libraries(${AUX_LIB} -lGL)
#target_link_libraries(${AUX_LIB} -lpthread)
#target_link_libraries(${AUX_LIB} -lpng)
#target_link_libraries(${AUX_LIB} -lstdc++fs)
target_link_libraries(${AUX_LIB}
  INTERFACE X11
  INTERFACE GL
  INTERFACE pthread
  INTERFACE png
  INTERFACE stdc++fs
)

target_include_directories( ${AUX_LIB}
  PUBLIC $<BUILD_INTERFACE:${AUX_INC}>
  PRIVATE ${AUX_SRC}
)

install( TARGETS aux DESTINATION ${LIB} )
