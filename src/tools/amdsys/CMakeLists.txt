# ############################################################################################################################################
# ROCMTOOL AMDSYS Frontend
# ############################################################################################################################################
set(CMAKE_BINARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

# Getting Source files for RDC, Utils, Counters
file(GLOB ROCPROFILER_AMDSYS_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# Compiling/Installing ROCProfiler API
add_executable(rocprofiler_amdsys_fe ${ROCPROFILER_AMDSYS_SRC_FILES})

set_target_properties(rocprofiler_amdsys_fe PROPERTIES
  OUTPUT_NAME "rocsys")

target_include_directories(rocprofiler_amdsys_fe
  PRIVATE
  ${PROJECT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}
  ${PROJECT_SOURCE_DIR}/inc)

target_link_libraries(rocprofiler_amdsys_fe dl rt stdc++fs)

install(TARGETS rocprofiler_amdsys_fe RUNTIME
  PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
  DESTINATION ${CMAKE_INSTALL_BINDIR}
  COMPONENT runtime)

# ############################################################################################################################################