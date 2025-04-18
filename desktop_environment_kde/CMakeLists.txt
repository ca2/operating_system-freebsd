cmake_minimum_required(VERSION 3.17)
project(desktop_environment_kde CXX)


list(APPEND library_source
   _.cpp
   _.h
        _desktop_environment_kde.h
   #appindicator.cpp
   #appindicator.h
   #application.cpp
   #application.h
   #clipboard_data.h
   #copydesk.cpp
   #copydesk.h
   #enum_display_monitors.cpp
   _factory.cpp

   #framework.cpp
   #framework.h
   #gdk.cpp
   #gdk.h
   #gnome_direct.cpp
   #gtk_clipboard.cpp
   node.cpp
   node.h
   #node_impl.cpp
   #node_impl.h
   #q_node_impl.cpp
   #q_node_impl.h
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
   windowing_xcb
   )

if(${HAS_KDE6})
   list(APPEND library_references
      node_kde6)
elseif(${HAS_KDE5})
   list(APPEND library_references
      node_kde5)
endif()


#set_source_files_properties(q_node_impl.cpp PROPERTIES SKIP_PRECOMPILE_HEADERS ON)

add_library(${PROJECT_NAME} SHARED ${library_source} )

target_precompile_headers(${PROJECT_NAME} PRIVATE framework.h)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)


if (MSVC)
   target_compile_options(${PROJECT_NAME} PRIVATE "/MD$<$<CONFIG:Debug>:d>")
   target_link_options(${PROJECT_NAME} PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
   target_link_options(${PROJECT_NAME} PRIVATE "/SUBSYSTEM:WINDOWS")
   target_link_libraries(${PROJECT_NAME} PRIVATE ${library_references})
elseif(FREEBSD OR FREEBSD)
   pkg_check_modules(PKGCONFIG Qt5X11Extras Qt5Core Qt5UiTools)
   target_compile_options(${PROJECT_NAME} PRIVATE -fpermissive)
      target_compile_options(${PROJECT_NAME} PRIVATE ${PKGCONFIG_CFLAGS})
   target_link_options(${PROJECT_NAME} PRIVATE ${PKGCONFIG_LDFLAGS})
   if(KDE_DESKTOP)
      target_include_directories(${PROJECT_NAME} PRIVATE KF5::Notifications)
   endif()
   target_link_libraries(${PROJECT_NAME} PRIVATE ${library_references} ${PKGCONFIG_LIBRARIES})
   if(KDE_DESKTOP)
      target_link_libraries(${PROJECT_NAME} PRIVATE KF5::Notifications)
   endif()
   target_link_options(${PROJECT_NAME} PRIVATE -Wl,-z,defs)
endif ()

list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../../operating_system-darwin)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../../operating_system-posix)


target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})
#target_include_directories(static_${PROJECT_NAME} PRIVATE ${library_include_directories})

target_compile_definitions(${PROJECT_NAME} PRIVATE _MUSIC_MIDI_ALSA_LIBRARY)



