cmake_minimum_required(VERSION 3.17)
project(acme_freebsd CXX)


list(APPEND library_source
   _.cpp
   _.h
   _factory.cpp
   acme_dir.cpp
   acme_dir.h
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



add_library(acme_freebsd SHARED ${library_source} calculate_edesktop.cpp)


list(APPEND library_references acme acme_posix)


target_precompile_headers(acme_freebsd PRIVATE framework.h)


set_target_properties(acme_freebsd PROPERTIES LINKER_LANGUAGE CXX)


if (MSVC)
    target_compile_options(acme_freebsd PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(acme_freebsd PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(acme_freebsd PRIVATE "/IMPLIB:${LIBRARY_OUTPUT_PATH}/acme_freebsd.lib")
    target_link_options(acme_freebsd PRIVATE "/DEF:${CMAKE_CURRENT_SOURCE_DIR}/acme_freebsd.def")
    target_link_libraries(acme_freebsd PRIVATE acme apex aqua aura Gdiplus)
elseif(FREEBSD)
    #pkg_check_modules(PKGCONFIG glib-2.0 gtk+-3.0 gdk-3.0 appindicator-0.1)
    #pkg_check_modules(PKGCONFIG glib-2.0 freetype2 gtk+-3.0 gdk-3.0)
    #   target_compile_options(acme_freebsd PRIVATE ${PKGCONFIG_CFLAGS})
   target_link_options(acme_freebsd PRIVATE ${PKGCONFIG_LDFLAGS})
    #target_compile_options(acme_freebsd PRIVATE -std=c++14)
    #target_link_options(acme_freebsd PRIVATE ${GTK_LDFLAGS})
    target_link_options(acme_freebsd PRIVATE -Wl,-rpath=\$ORIGIN)
    target_link_libraries(acme_freebsd PRIVATE ${PKGCONFIG_LIBRARIES} ${library_references})
    target_link_options(acme_freebsd PRIVATE -Wl,-z,defs)
    message("PKGCONFIG_LIBRARIES is " ${PKGCONFIG_LIBRARIES})
endif()


target_link_directories(acme_freebsd PRIVATE ${LIBRARY_OUTPUT_PATH})
target_link_directories(acme_freebsd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/storage-${PLATFORM_NAME}/library/x64/basis)
target_link_directories(acme_freebsd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/storage-${PLATFORM_NAME}/third/library/x64/basis)


target_include_directories(acme_freebsd PRIVATE $ENV{HOME}/__config)
target_include_directories(acme_freebsd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(acme_freebsd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(acme_freebsd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_definitions(acme_freebsd PRIVATE _acme_freebsd_LIBRARY)
target_compile_definitions(acme_freebsd PRIVATE UNICODE)
target_compile_definitions(acme_freebsd PRIVATE _UNICODE)



