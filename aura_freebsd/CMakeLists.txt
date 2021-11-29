cmake_minimum_required(VERSION 3.17)
project(aura_freebsd CXX)


list(APPEND library_source
   _.cpp
   _.h
   _const.h
   _factory.cpp
   appindicator.cpp
   appindicator.h
   interaction_impl.cpp
   interaction_impl.h
   node.cpp
   node.h
   #../platform/x_window.cpp
   )




add_library(aura_freebsd SHARED ${library_source})

list(APPEND library_references
   acme
   apex
   aqua
   aura
   acme_posix
   acme_freebsd
   apex_posix
   apex_freebsd
   aura_posix
   )


target_precompile_headers(aura_freebsd PRIVATE framework.h)

set_target_properties(aura_freebsd PROPERTIES LINKER_LANGUAGE CXX)

if (MSVC)
    target_compile_options(aura_freebsd PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(aura_freebsd PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(aura_freebsd PRIVATE "/IMPLIB:${LIBRARY_OUTPUT_PATH}/aura_freebsd.lib")
    target_link_options(aura_freebsd PRIVATE "/DEF:${CMAKE_CURRENT_SOURCE_DIR}/aura_freebsd.def")
    target_link_libraries(aura_freebsd PRIVATE acme apex aqua aura Gdiplus)
elseif(FREEBSD)
    #pkg_check_modules(PKGCONFIG glib-2.0 gtk+-3.0 gdk-3.0 appindicator-0.1)
    pkg_check_modules(PKGCONFIG glib-2.0 freetype2 gtk+-3.0 gdk-3.0)
       target_compile_options(aura_freebsd PRIVATE ${PKGCONFIG_CFLAGS})
   target_link_options(aura_freebsd PRIVATE ${PKGCONFIG_LDFLAGS})
    #target_compile_options(aura_freebsd PRIVATE -std=c++14)
    #target_link_options(aura_freebsd PRIVATE ${GTK_LDFLAGS})
    target_link_options(aura_freebsd PRIVATE -Wl,-rpath=\$ORIGIN)
    target_link_libraries(aura_freebsd PRIVATE z dl pthread ncurses ${PKGCONFIG_LIBRARIES} ${library_references})
    target_link_options(aura_freebsd PRIVATE -Wl,-z,defs)
    message("PKGCONFIG_LIBRARIES is " ${PKGCONFIG_LIBRARIES})
endif()

target_link_directories(aura_freebsd PRIVATE ${LIBRARY_OUTPUT_PATH})
target_link_directories(aura_freebsd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/storage-${PLATFORM_NAME}/library/x64/basis)
target_link_directories(aura_freebsd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/storage-${PLATFORM_NAME}/third/library/x64/basis)


target_include_directories(aura_freebsd PRIVATE $ENV{HOME}/__config)
target_include_directories(aura_freebsd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(aura_freebsd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(aura_freebsd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source)
target_include_directories(aura_freebsd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/app)
target_include_directories(aura_freebsd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/app/_include)
target_include_directories(aura_freebsd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/include)
target_include_directories(aura_freebsd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/platform-${PLATFORM_NAME})
target_include_directories(aura_freebsd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/platform-${PLATFORM_NAME}/_include)
target_include_directories(aura_freebsd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/include)
target_include_directories(aura_freebsd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/third/include)
target_include_directories(aura_freebsd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/third/include/include)
target_include_directories(aura_freebsd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_definitions(aura_freebsd PRIVATE _DRAW2D_GDIPLUS_LIBRARY)
target_compile_definitions(aura_freebsd PRIVATE UNICODE)
target_compile_definitions(aura_freebsd PRIVATE _UNICODE)
