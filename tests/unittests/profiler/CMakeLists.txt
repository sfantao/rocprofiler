# Setup unit testing env

find_library(PCIACCESS_LIBRARIES pciaccess REQUIRED)

enable_testing()
find_package(GTest REQUIRED)

# Getting Source files for ROCProfiler, Hardware, HSA, Memory, Session, Counters, Utils
set(CORE_MEMORY_DIR ${PROJECT_SOURCE_DIR}/src/core/memory)
file(GLOB CORE_MEMORY_SRC_FILES ${CORE_MEMORY_DIR}/*.cpp)

set(CORE_SESSION_DIR ${PROJECT_SOURCE_DIR}/src/core/session)
file(GLOB CORE_SESSION_SRC_FILES ${CORE_SESSION_DIR}/session.cpp)
file(GLOB CORE_FILTER_SRC_FILES ${CORE_SESSION_DIR}/filter.cpp)
file(GLOB CORE_DEVICE_PROFILING_SRC_FILES ${CORE_SESSION_DIR}/device_profiling.cpp)

set(CORE_HW_DIR ${PROJECT_SOURCE_DIR}/src/core/hardware)
file(GLOB CORE_HW_SRC_FILES ${CORE_HW_DIR}/hsa_info.cpp)

set(CORE_HW_DIR ${PROJECT_SOURCE_DIR}/src/core/hardware)
file(GLOB CORE_HW_SRC_FILES ${CORE_HW_DIR}/hsa_info.cpp)

set(CORE_UTILS_DIR ${PROJECT_SOURCE_DIR}/src/utils)
file(GLOB CORE_UTILS_SRC_FILES ${CORE_UTILS_DIR}/*.cpp)

set(CORE_HSA_PACKETS_DIR ${PROJECT_SOURCE_DIR}/src/core/hsa/packets)
file(GLOB CORE_HSA_PACKETS_SRC_FILES ${CORE_HSA_PACKETS_DIR}/packets_generator.cpp)

file(GLOB CORE_COUNTERS_SRC_FILES ${PROJECT_BINARY_DIR}/src/api/*_counter.cpp)

file(GLOB ROCPROFILER_SRC_PROFILER_FILES ${PROJECT_SOURCE_DIR}/src/core/session/profiler/profiler.cpp)
file(GLOB ROCPROFILER_TRACER_SRC_FILES ${PROJECT_SOURCE_DIR}/src/core/session/tracer/*.cpp)
file(GLOB ROCPROFILER_ROCTRACER_SRC_FILES ${PROJECT_SOURCE_DIR}/src/core/session/tracer/src/*.cpp)
file(GLOB ROCPROFILER_ATT_SRC_FILES ${PROJECT_SOURCE_DIR}/src/core/session/att/att.cpp)
file(GLOB ROCPROFILER_SRC_CLASS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/rocmtool.cpp)
file(GLOB ROCPROFILER_SPM_SRC_FILES ${PROJECT_SOURCE_DIR}/src/core/session/spm/spm.cpp)
file(GLOB ROCPROFILER_SRC_API_FILES ${PROJECT_SOURCE_DIR}/src/api/*.cpp)

set(ROCPROFILER_SRC_FILES ${ROCPROFILER_SRC_API_FILES} ${ROCPROFILER_SRC_CLASS_FILES} ${ROCPROFILER_SRC_PROFILER_FILES} ${ROCPROFILER_ATT_SRC_FILES})

set(CORE_HSA_DIR ${PROJECT_SOURCE_DIR}/src/core/hsa)
file(GLOB CORE_HSA_SRC_FILES ${CORE_HSA_DIR}/*.cpp)

set(CORE_HSA_QUEUES_DIR ${PROJECT_SOURCE_DIR}/src/core/hsa/queues)
file(GLOB CORE_HSA_QUEUES_SRC_FILES ${CORE_HSA_QUEUES_DIR}/*.cpp)

set(CORE_PC_SAMPLING_DIR ${PROJECT_SOURCE_DIR}/src/pcsampler)
file(GLOB CORE_PC_SAMPLING_FILES ${CORE_PC_SAMPLING_DIR}/core/*.cpp ${CORE_PC_SAMPLING_DIR}/gfxip/*.cpp ${CORE_PC_SAMPLING_DIR}/session/*.cpp)

# Compiling gtests
file(GLOB ROCPROFILER_TOOL_SRC_FILES ${PROJECT_SOURCE_DIR}/src/rocmtools/tools/tool.cpp)

file(GLOB CORE_COUNTERS_PARENT_SRC_FILES ${PROJECT_SOURCE_DIR}/src/core/counters/*.cpp)
file(GLOB CORE_COUNTERS_METRICS_SRC_FILES ${PROJECT_SOURCE_DIR}/src/core/counters/metrics/*.cpp)

add_executable(runProfilerUnitTests ${CMAKE_CURRENT_SOURCE_DIR}/tools/tool_gtest.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/api/rocmtool_gtest.cpp
  ${CORE_MEMORY_SRC_FILES}
  ${CORE_SESSION_SRC_FILES}
  ${CORE_FILTER_SRC_FILES}
  ${CORE_DEVICE_PROFILING_SRC_FILES}
  ${CORE_HW_SRC_FILES}
  ${CORE_UTILS_SRC_FILES}
  ${ROCPROFILER_SPM_SRC_FILES}
  ${ROCPROFILER_SRC_FILES}
  ${CORE_HSA_SRC_FILES}
  ${CORE_HSA_PACKETS_SRC_FILES}
  ${CORE_COUNTERS_SRC_FILES}
  ${CORE_HSA_QUEUES_SRC_FILES}
  ${ROCPROFILER_TRACER_SRC_FILES}
  ${ROCPROFILER_ROCTRACER_SRC_FILES}
  ${CORE_COUNTERS_METRICS_SRC_FILES}
  ${CORE_COUNTERS_PARENT_SRC_FILES}
  ${CORE_PC_SAMPLING_FILES})

target_include_directories(runProfilerUnitTests PRIVATE ${PROJECT_SOURCE_DIR}
  ${PROJECT_SOURCE_DIR}/src
  ${PROJECT_SOURCE_DIR}/inc
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${PROJECT_BINARY_DIR}
  ${PROJECT_BINARY_DIR}/rocprofiler)

target_compile_definitions(runProfilerUnitTests
  PUBLIC AMD_INTERNAL_BUILD
  PRIVATE PROF_API_IMPL HIP_PROF_HIP_API_STRING=1 __HIP_PLATFORM_AMD__=1)

target_link_libraries(runProfilerUnitTests PRIVATE rocprofiler_tool ${AQLPROFILE_LIB}
  hsa-runtime64::hsa-runtime64
  GTest::gtest GTest::gtest_main stdc++fs
  ${PCIACCESS_LIBRARIES})

add_dependencies(tests runProfilerUnitTests)
install(TARGETS runProfilerUnitTests RUNTIME DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/tests COMPONENT tests)
add_test(AllTests runProfilerUnitTests)
