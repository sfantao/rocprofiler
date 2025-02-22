file(GLOB ROCPROFILER_UTIL_SRC_FILES ${PROJECT_SOURCE_DIR}/src/utils/helper.cpp)

add_library(perfetto_plugin
        ${LIBRARY_TYPE} ${ROCPROFILER_UTIL_SRC_FILES}
        perfetto.cpp perfetto_sdk/sdk/perfetto.cc)

set_target_properties(perfetto_plugin PROPERTIES
        CXX_VISIBILITY_PRESET hidden
        LINK_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/../exportmap
        LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

target_compile_definitions(perfetto_plugin
        PRIVATE HIP_PROF_HIP_API_STRING=1
        __HIP_PLATFORM_HCC__=1)

target_include_directories(perfetto_plugin
        PRIVATE ${PROJECT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/plugin/perfetto/perfetto_sdk/sdk)

target_link_options(perfetto_plugin
        PRIVATE -Wl,--version-script=${CMAKE_CURRENT_SOURCE_DIR}/../exportmap -Wl,--no-undefined)

target_link_libraries(perfetto_plugin PRIVATE rocprofiler-v2 Threads::Threads stdc++fs amd_comgr)

install(TARGETS perfetto_plugin LIBRARY
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/${PROJECT_NAME}
        COMPONENT plugins)