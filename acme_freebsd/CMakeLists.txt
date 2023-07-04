cmake_minimum_required(VERSION 3.17)
project(acme_freebsd CXX)


list(APPEND library_source
   _.cpp
   _.h
   _factory.cpp
   acme_directory.cpp
   acme_directory.h
   acme_file.cpp
   acme_file.h
   acme_path.cpp
   acme_path.h
   file.cpp
   file.h
   framework.cpp
   framework.h
   node.cpp
   node.h
   )



add_library(${PROJECT_NAME} SHARED ${library_source} calculate_edesktop.cpp)
add_library(static_${PROJECT_NAME} STATIC ${library_source} calculate_edesktop.cpp)


list(APPEND library_references acme acme_posix acme_darwin)


if (NOT ${NO_PRECOMPILED_HEADER})

    target_precompile_headers(${PROJECT_NAME} PRIVATE framework.h)
    target_precompile_headers(static_${PROJECT_NAME} PRIVATE framework.h)

endif ()



list(APPEND static_library_references ${library_references})

list(TRANSFORM static_library_references PREPEND static_)




set_target_properties(acme_freebsd PROPERTIES LINKER_LANGUAGE CXX)


if (MSVC)
    target_compile_options(acme_freebsd PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(acme_freebsd PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(acme_freebsd PRIVATE "/IMPLIB:${LIBRARY_OUTPUT_PATH}/acme_freebsd.lib")
    target_link_options(acme_freebsd PRIVATE "/DEF:${CMAKE_CURRENT_SOURCE_DIR}/acme_freebsd.def")
    target_link_libraries(acme_freebsd PRIVATE acme apex aqua aura Gdiplus)
elseif(${FREEBSD})


    target_compile_options(${PROJECT_NAME} PRIVATE -fpermissive)
    target_compile_options(static_${PROJECT_NAME} PRIVATE -fpermissive)
    target_compile_definitions(static_${PROJECT_NAME} PRIVATE CUBE)


    target_compile_options(${PROJECT_NAME} PRIVATE ${PKGCONFIG_CFLAGS})
    target_compile_options(static_${PROJECT_NAME} PRIVATE ${PKGCONFIG_CFLAGS})
    target_compile_options(${PROJECT_NAME} PRIVATE ${PKGCONFIG_CFLAGS})
    target_compile_options(static_${PROJECT_NAME} PRIVATE ${PKGCONFIG_CFLAGS})
    target_link_options(acme_posix PRIVATE ${PKGCONFIG_LDFLAGS})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${library_references} ${PKGCONFIG_LIBRARIES})
    target_link_libraries(static_${PROJECT_NAME} PRIVATE ${static_library_references} ${PKGCONFIG_LIBRARIES})
    target_link_options(${PROJECT_NAME} PRIVATE -Wl,-z,defs)
    if(${LINUX})
    target_link_options(static_${PROJECT_NAME} PRIVATE --whole-archive)
    endif()


endif ()


list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../../operating_system-darwin)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../../operating_system-posix)


target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})
target_include_directories(static_${PROJECT_NAME} PRIVATE ${library_include_directories})




target_compile_definitions(acme_freebsd PRIVATE _acme_freebsd_LIBRARY)
target_compile_definitions(acme_freebsd PRIVATE UNICODE)
target_compile_definitions(acme_freebsd PRIVATE _UNICODE)



