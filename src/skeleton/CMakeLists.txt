#===========================================================
# Module: Skeleton
#===========================================================
# Define directories
set( SKELETON_DIR    ${SRC}/skeleton         )
set( SKELETON_INC    ${SKELETON_DIR}/include )
set( SKELETON_SRC    ${SKELETON_DIR}/src     )

# Define source files
set( SKELETON_FILES
  ${SKELETON_SRC}/foo.cpp
  )

#===========================================================
# Library: Skeleton
#===========================================================
# Define library name
set( SKELETON_LIB skeleton )

# add sources to library
add_library( ${SKELETON_LIB} STATIC ${SKELETON_FILES} )

# set includes
target_include_directories( ${SKELETON_LIB}
  PUBLIC $<BUILD_INTERFACE:${SKELETON_INC}>
  PRIVATE ${SKELETON_SRC}
# PUBLIC ${P4EST_INCLUDE_DIR} # Example to include libs
# PUBLIC ${MPI_INCLUDE_DIR}   # from paths
)

# set libraries
target_link_libraries( ${SKELETON_LIB}
  PUBLIC aux
  INTERFACE m
  # PUBLIC ${P4EST_LIBRARY}     # Example to include libs
# PUBLIC ${P4EST_SC_LIBRARY}    # from paths
# PUBLIC ${MPI_LIBRARY}         #
)

install( TARGETS skeleton DESTINATION ${LIB} )


#===========================================================
# Main: Skeleton
#===========================================================
set( MAINEXE_SKELETON Skeleton )

add_executable( ${MAINEXE_SKELETON}
  ${SKELETON_SRC}/main.cpp
)

target_include_directories( ${MAINEXE_SKELETON} PUBLIC
  $<BUILD_INTERFACE:${INC_SKELETON}>
)

target_link_libraries( ${MAINEXE_SKELETON}
  PUBLIC skeleton
  PUBLIC aux
  INTERFACE m
)

# Install executables
install( TARGETS ${MAINEXE_SKELETON} RUNTIME DESTINATION ${BIN} )

#===========================================================
# Tests: Skeleton
#===========================================================
set( TESTEXE_SKELETON tests )
set( TESTDIR_SKELETON ${SKELETON_DIR}/tests )

add_executable( ${TESTEXE_SKELETON}
  ${TESTDIR_SKELETON}/skeleton_tests.cpp
)

target_include_directories( ${TESTEXE_SKELETON}
  PUBLIC $<BUILD_INTERFACE:${INC_SKELETON}>
# PUBLIC ${P4EST_INCLUDE_DIR}   # Example to include libs
# PUBLIC ${MPI_INCLUDE_DIR}     # from paths
)

target_link_libraries( ${TESTEXE_SKELETON}
  PUBLIC skeleton
  PUBLIC aux
  INTERFACE m
  # PUBLIC ${P4EST_LIBRARY}       # Example to include libs
# PUBLIC ${P4EST_SC_LIBRARY}      # from paths
# PUBLIC ${MPI_LIBRARY}
)

# Install executables
install( TARGETS ${TESTEXE_SKELETON} RUNTIME DESTINATION ${BIN} )

