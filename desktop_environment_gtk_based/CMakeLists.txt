cmake_minimum_required(VERSION 3.17)
project(desktop_environment_gtk_based CXX)


message(STATUS "Project: ${PROJECT_NAME}")


list(APPEND library_source
   _.cpp
   _.h
   #        _${PROJECT_NAME}.h
   #appindicator.cpp
   #appindicator.h
   #application.cpp
   #application.h
   #clipboard_data.h
   #copydesk.cpp
   #copydesk.h
   #display.cpp
   #display.h
   #enum_display_monitors.cpp
   _factory.cpp
   framework.cpp
   framework.h
   #gdk.cpp
   #gdk.h
   #gnome_direct.cpp
   #gtk_clipboard.cpp
   #monitor.cpp
   #monitor.h
   node.cpp
   node.h
   #notify_icon.cpp
   #windowing.cpp
   #windowing.h
   )


list(APPEND library_references
   acme
   acme_posix
   acme_darwin
   acme_freebsd
   apex
   apex_posix
   apex_darwin
   apex_freebsd
   aqua
   aura
   aura_posix
   aura_darwin
   aura_freebsd
   #windowing_x11
        #node_gdk
   node_freebsd
   node_gtk_based
   )

if(${HAS_GTK4})
   list(APPEND library_references node_gtk4)
elseif(${HAS_GTK3})
   list(APPEND library_references node_gtk3)
endif()

add_library(${PROJECT_NAME} SHARED ${library_source})

target_precompile_headers(${PROJECT_NAME} PRIVATE framework.h)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)


if (MSVC)
   target_compile_options(${PROJECT_NAME} PRIVATE "/MD$<$<CONFIG:Debug>:d>")
   target_link_options(${PROJECT_NAME} PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
   target_link_options(${PROJECT_NAME} PRIVATE "/SUBSYSTEM:WINDOWS")
   target_link_libraries(${PROJECT_NAME} PRIVATE ${library_references})
elseif (${FREEBSD})

   if(${HAS_GTK4})
      pkg_check_modules(PKGCONFIG gtk4 ${APPINDICATOR_PKG_MODULE})
   elseif(${HAS_GTK3})
      pkg_check_modules(PKGCONFIG glib-2.0 gtk+-3.0 gdk-3.0 ${APPINDICATOR_PKG_MODULE})
   endif()
   target_compile_options(${PROJECT_NAME} PRIVATE -fpermissive)
   target_compile_options(${PROJECT_NAME} PRIVATE ${PKGCONFIG_CFLAGS})
   target_link_options(${PROJECT_NAME} PRIVATE ${PKGCONFIG_LDFLAGS})
   target_link_libraries(${PROJECT_NAME} PRIVATE ${library_references} ${PKGCONFIG_LIBRARIES})
   target_link_options(${PROJECT_NAME} PRIVATE -Wl,-z,defs)
endif ()

list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../../operating_system-darwin)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../../operating_system-posix)


target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})
#target_include_directories(static_${PROJECT_NAME} PRIVATE ${library_include_directories})

target_compile_definitions(${PROJECT_NAME} PRIVATE _${PROJECT_NAME}_project)
target_compile_definitions(${PROJECT_NAME} PRIVATE UNICODE)
target_compile_definitions(${PROJECT_NAME} PRIVATE _UNICODE)



