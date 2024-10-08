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




add_library(${PROJECT_NAME} SHARED ${library_source})
add_library(static_${PROJECT_NAME} STATIC ${library_source})

list(APPEND library_references
   acme
   apex
   aqua
   aura
   acme_posix
   acme_darwin
   acme_freebsd
   apex_posix
   apex_darwin
   apex_freebsd
   aura_posix
   aura_darwin
   )




if (NOT ${NO_PRECOMPILED_HEADER})

    target_precompile_headers(${PROJECT_NAME} PRIVATE framework.h)
    target_precompile_headers(static_${PROJECT_NAME} PRIVATE framework.h)

endif ()




list(APPEND static_library_references ${library_references})

list(TRANSFORM static_library_references PREPEND static_)



set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)


if (MSVC)
    target_compile_options(aura_freebsd PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(aura_freebsd PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(aura_freebsd PRIVATE "/IMPLIB:${LIBRARY_OUTPUT_PATH}/aura_freebsd.lib")
    target_link_options(aura_freebsd PRIVATE "/DEF:${CMAKE_CURRENT_SOURCE_DIR}/aura_freebsd.def")
    target_link_libraries(aura_freebsd PRIVATE acme apex aqua aura Gdiplus)
elseif(${FREEBSD})
    #pkg_check_modules(PKGCONFIG glib-2.0 gtk+-3.0 gdk-3.0 appindicator-0.1)
    #pkg_check_modules(PKGCONFIG glib-2.0 freetype2 gtk+-3.0 gdk-3.0)
       target_compile_options(aura_freebsd PRIVATE ${${PROJECT_NAME}_PKGCONFIG_CFLAGS})
   target_link_options(aura_freebsd PRIVATE ${${PROJECT_NAME}_PKGCONFIG_LDFLAGS})
    target_compile_options(${PROJECT_NAME} PRIVATE -fpermissive)
    target_compile_options(static_${PROJECT_NAME} PRIVATE -fpermissive)
    target_compile_definitions(static_${PROJECT_NAME} PRIVATE CUBE)


    target_compile_options(${PROJECT_NAME} PRIVATE ${${PROJECT_NAME}_PKGCONFIG_CFLAGS})
    target_compile_options(static_${PROJECT_NAME} PRIVATE ${${PROJECT_NAME}_PKGCONFIG_CFLAGS})
    target_compile_options(${PROJECT_NAME} PRIVATE ${${PROJECT_NAME}_PKGCONFIG_CFLAGS})
    target_compile_options(static_${PROJECT_NAME} PRIVATE ${${PROJECT_NAME}_PKGCONFIG_CFLAGS})
    target_link_options(acme_posix PRIVATE ${${PROJECT_NAME}_PKGCONFIG_LDFLAGS})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${library_references} ${${PROJECT_NAME}_PKGCONFIG_LIBRARIES})
    target_link_libraries(static_${PROJECT_NAME} PRIVATE ${static_library_references} ${${PROJECT_NAME}_PKGCONFIG_LIBRARIES})
    target_link_options(${PROJECT_NAME} PRIVATE -Wl,-z,defs)
    # target_link_options(static_${PROJECT_NAME} PRIVATE --whole-archive)



endif ()


list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)


target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})
target_include_directories(static_${PROJECT_NAME} PRIVATE ${library_include_directories})




list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../../operating_system-darwin)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../../operating_system-posix)


target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})
target_include_directories(static_${PROJECT_NAME} PRIVATE ${library_include_directories})


target_compile_definitions(aura_freebsd PRIVATE _aura_freebsd_project)
target_compile_definitions(aura_freebsd PRIVATE UNICODE)
target_compile_definitions(aura_freebsd PRIVATE _UNICODE)
