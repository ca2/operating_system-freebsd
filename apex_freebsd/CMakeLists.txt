cmake_minimum_required(VERSION 3.17)
project(apex_freebsd CXX)


list(APPEND library_source
   _.cpp
   _.h
   _factory.cpp
   crypto.cpp
   crypto.h
   dir_context.cpp
   dir_context.h
   dir_system.cpp
   dir_system.h
   file_context.cpp
   file_context.h
   file_system.cpp
   file_system.h
   framework.cpp
   framework.h
   interprocess_communication.cpp
   interprocess_communication.h
   ip_enum.cpp
   ip_enum.h
   launcher.cpp
   launcher.h
   node.cpp
   node.h
   os_context.cpp
   os_context.h
   service_handler.cpp
   service_handler.h
   )


if(DEFINED USE_KQUEUE_FILE_WATCHER_DIRECTLY)
   list(APPEND library_source
   kqueue/file_watcher.cpp
   kqueue/file_watcher.h
      )
endif()


list(APPEND library_references acme acme_posix acme_freebsd apex apex_posix)

add_library(apex_freebsd SHARED ${library_source} kqueue/file_watcher.cpp kqueue/file_watcher.h)

target_precompile_headers(apex_freebsd PRIVATE framework.h)

set_target_properties(apex_freebsd PROPERTIES LINKER_LANGUAGE CXX)


if (MSVC)
    target_compile_options(apex_freebsd PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(apex_freebsd PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(apex_freebsd PRIVATE "/IMPLIB:${LIBRARY_OUTPUT_PATH}/apex_freebsd.lib")
    target_link_options(apex_freebsd PRIVATE "/DEF:${CMAKE_CURRENT_SOURCE_DIR}/apex_freebsd.def")
    target_link_libraries(apex_freebsd PRIVATE acme apex aqua aura Gdiplus)
elseif(FREEBSD)
    #pkg_check_modules(PKGCONFIG glib-2.0 gtk+-3.0 gdk-3.0 appindicator-0.1)
    pkg_check_modules(PKGCONFIG glib-2.0 freetype2 gtk+-3.0 gdk-3.0)
       target_compile_options(apex_freebsd PRIVATE ${PKGCONFIG_CFLAGS})
   target_link_options(apex_freebsd PRIVATE ${PKGCONFIG_LDFLAGS})
   target_link_options(apex_freebsd PRIVATE ${PKGCONFIG_LDFLAGS})
    #target_compile_options(apex_freebsd PRIVATE -std=c++14)
    #target_link_options(apex_freebsd PRIVATE ${GTK_LDFLAGS})
    target_link_options(apex_freebsd PRIVATE -Wl,-rpath=\$ORIGIN)
    target_link_libraries(apex_freebsd PRIVATE z dl pthread ncurses X11 Xrender Xinerama Xft ${PKGCONFIG_LIBRARIES})
    target_link_libraries(apex_freebsd PRIVATE ${library_references})
    target_link_options(apex_freebsd PRIVATE -Wl,-z,defs)
    message("PKGCONFIG_LIBRARIES is " ${PKGCONFIG_LIBRARIES})
endif()


target_include_directories(apex_freebsd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(apex_freebsd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(apex_freebsd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_definitions(apex_freebsd PRIVATE _APEX_FREEBSD_LIBRARY)



