cmake_minimum_required(VERSION 3.16)
project(operating_ambient_kde6 CXX)


list(APPEND library_source
   _.cpp
   _.h
   _factory.cpp
   #_library.h
   framework.cpp
   framework.h
   node.cpp
   node.h
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
   node_freebsd
   )


if(${HAS_KDE6})
   list(APPEND library_references
           node_q
           node_kde6)
elseif(${HAS_KDE5})
   list(APPEND library_references
           node_q
           node_kde5)
endif()




list(APPEND this_system_libraries
        KF6::ConfigWidgets
        KF6::IconThemes
        KF6::KIOCore
        KF6::KIOGui
        KF6::KIOWidgets
        KF6::Notifications
        PW::KWorkspace
        Qt6::Core
        Qt6::Widgets
        #Qt6::X11Extras
        Qt6::GuiPrivate
)

if (${FREEBSD} OR ${DEBIAN})
    list(APPEND this_system_libraries
            KF6Package
    )
else ()
    list(APPEND this_system_libraries
            KF6::Plasma
            KF6::PlasmaQuick
    )
endif ()


list(APPEND static_library_references ${library_references})
list(TRANSFORM static_library_references PREPEND static_)


add_library(${PROJECT_NAME} SHARED ${library_source})
add_library(static_${PROJECT_NAME} STATIC ${library_source})



target_precompile_headers(${PROJECT_NAME} PRIVATE framework.h)
target_precompile_headers(static_${PROJECT_NAME} PRIVATE framework.h)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)


if (MSVC)
   target_compile_options(${PROJECT_NAME} PRIVATE "/MD$<$<CONFIG:Debug>:d>")
   target_link_options(${PROJECT_NAME} PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
   target_link_options(${PROJECT_NAME} PRIVATE "/SUBSYSTEM:WINDOWS")
   target_link_libraries(${PROJECT_NAME} PRIVATE ${library_references})
elseif (${LINUX} OR ${__BSD__})


   #if(${HAS_KDE6})
     # #pkg_check_modules(${PROJECT_NAME}_PKGCONFIG glib-2.0 gtk4)
    #  pkg_check_modules(${PROJECT_NAME}_PKGCONFIG gtk4)
   #elseif(${HAS_KDE5})
    #  pkg_check_modules(${PROJECT_NAME}_PKGCONFIG glib-2.0 gtk+-3.0 gdk-3.0)
   #endif()


   target_compile_options(${PROJECT_NAME} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fpermissive  ${EXTRA_CXX_TARGET_COMPILER_OPTIONS}>)
   target_compile_options(static_${PROJECT_NAME} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fpermissive  ${EXTRA_CXX_TARGET_COMPILER_OPTIONS}>)
   target_compile_definitions(static_${PROJECT_NAME} PRIVATE CUBE)


   target_compile_options(${PROJECT_NAME} PRIVATE ${${PROJECT_NAME}_PKGCONFIG_CFLAGS})
   target_compile_options(static_${PROJECT_NAME} PRIVATE ${${PROJECT_NAME}_PKGCONFIG_CFLAGS})

   target_link_libraries(${PROJECT_NAME} PRIVATE ${library_references} ${this_system_libraries} ${${PROJECT_NAME}_PKGCONFIG_LIBRARIES})
   target_link_libraries(static_${PROJECT_NAME} PRIVATE ${static_library_references} ${this_system_libraries} ${${PROJECT_NAME}_PKGCONFIG_LIBRARIES})

   target_link_options(${PROJECT_NAME} PRIVATE -Wl,-z,defs)
   target_link_options(static_${PROJECT_NAME} PRIVATE --whole-archive)

endif ()


add_dependencies(${PROJECT_NAME} ${default_nano_graphics})


list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../../operating_system-darwin)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../../operating_system-posix)


target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})
target_include_directories(static_${PROJECT_NAME} PRIVATE ${library_include_directories})



target_compile_definitions(${PROJECT_NAME} PRIVATE _${PROJECT_NAME}_project)
target_compile_definitions(${PROJECT_NAME} PRIVATE UNICODE)
target_compile_definitions(${PROJECT_NAME} PRIVATE _UNICODE)



