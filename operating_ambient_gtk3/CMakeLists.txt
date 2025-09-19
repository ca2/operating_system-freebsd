cmake_minimum_required(VERSION 3.17)
project(operating_ambient_gtk3 CXX)

message(STATUS "Project: ${PROJECT_NAME}")

list(APPEND library_source
   _.cpp
   _.h
        _operating_ambient_xfce.h
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
        #xfce_direct.cpp
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
   acme_freebsd
   acme_windowing_gtk3
   apex
   apex_posix
   apex_freebsd
   aqua
   aura
   aura_posix
   aura_freebsd
   windowing_gtk3
   node_gtk
   node_xfce
   )



add_library(${PROJECT_NAME} SHARED ${library_source})

target_precompile_headers(${PROJECT_NAME} PRIVATE framework.h)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)


if (MSVC)
   target_compile_options(${PROJECT_NAME} PRIVATE "/MD$<$<CONFIG:Debug>:d>")
   target_link_options(${PROJECT_NAME} PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
   target_link_options(${PROJECT_NAME} PRIVATE "/SUBSYSTEM:WINDOWS")
   target_link_libraries(${PROJECT_NAME} PRIVATE ${library_references})
elseif(FREEBSD OR FREEBSD)
   pkg_check_modules(PKGCONFIG glib-2.0 gtk+-3.0 gdk-3.0 appindicator3-0.1)
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


target_compile_definitions(${PROJECT_NAME} PRIVATE _${PROJECT_NAME}_LIBRARY)



