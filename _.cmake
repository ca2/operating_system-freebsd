

message(STATUS "CMAKE_SYSTEM_NAME is ${CMAKE_SYSTEM_NAME}")

#FIND_PACKAGE(PkgConfig)

#include(FindPkgConfig)

#IF(PKG_CONFIG_FOUND)
    # use pkg_check_modules()
#ENDIF(PKG_CONFIG_FOUND)
set(USE_PKGCONFIG TRUE)
set(NO_PRECOMPILED_HEADER TRUE)

set(LAUNCH_STORE_SYSTEM "freebsd")
set(TOOL_RELEASE_NAME "freebsd")
set(MAIN_STORE_SLASHED_OPERATING_SYSTEM "freebsd")



execute_process(COMMAND uname -m OUTPUT_VARIABLE __SYSTEM_ARCHITECTURE)
string(STRIP ${__SYSTEM_ARCHITECTURE} __SYSTEM_ARCHITECTURE)

execute_process(COMMAND uname -r OUTPUT_VARIABLE __SYSTEM_RELEASE)
set(OPERATING_SYSTEM_RELEASE ${__SYSTEM_RELEASE})


message(STATUS "__SYSTEM_ARCHITECTURE is ${__SYSTEM_ARCHITECTURE}")


#set(GLOBAL_EXTRA_COMPILER_FLAGS -fnon-call-exceptions -nostdinc -nostdinc++ -I/usr/include/c++/v1 -I/usr/include -I/usr/local/include)
#set(GLOBAL_EXTRA_LINKER_FLAGS -nodefaultlibs -lc++ -lcxxrt -lthr -lm -lc -lgcc_s)
#set(GLOBAL_EXTRA_LINKER_FLAGS -L/usr/lib)

if ("${CMAKE_BUILD_TYPE}" STREQUAL "")

    set(CMAKE_BUILD_TYPE Debug)

endif()


set(CURL_NANO_HTTP TRUE)
set(CONFIGURATION_NAME ${CMAKE_BUILD_TYPE})
set(__BSD__ TRUE)


if (${CMAKE_SYSTEM_NAME} STREQUAL "FreeBSD")

    set(OPERATING_SYSTEM_NAME "freebsd")
    set(OPERATING_SYSTEM "freebsd")
    set(PLATFORM_NAME "freebsd")
    set(HAS_SYSTEM_UNAC FALSE)
    set(default_acme acme_freebsd)
    set(default_apex apex_freebsd)
    set(OPERATING_SYSTEM_TOOL_FOLDER "tool-freebsd")


elseif (${CMAKE_SYSTEM_NAME} STREQUAL "OpenBSD")

    set(OPERATING_SYSTEM_NAME "openbsd")
    set(OPERATING_SYSTEM "openbsd")
    set(PLATFORM_NAME "openbsd")


elseif (${CMAKE_SYSTEM_NAME} STREQUAL "NetBSD")

    set(OPERATING_SYSTEM_NAME "netbsd")
    set(OPERATING_SYSTEM "netbsd")
    set(PLATFORM_NAME "netbsd")


else()

    error("This file is designed to be used only for FreeBSD systems...")

endif ()


if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")

    SET(CMAKE_CXX_FLAGS "-fPIC -fexceptions -fnon-call-exceptions -frtti")

endif ()


#set(DONT_USE_PKG_CONFIG NOT PKG_CONFIG_FOUND)
set(DONT_USE_PKG_CONFIG FALSE)


if ($ENV{XDG_CURRENT_DESKTOP} STREQUAL "KDE")
    set(KDE_DESKTOP TRUE)
    message(STATUS "System is KDE")
    set(DESKTOP_ENVIRONMENT_NAME "kde")
    include("operating_system/operating_system-posix/_kde_desktop.cmake")
elseif ($ENV{XDG_CURRENT_DESKTOP} STREQUAL "GNOME")
    set(GNOME_DESKTOP TRUE)
    set(GTK_BASED_DESKTOP TRUE)
    message(STATUS "System is GNOME")
    set(DESKTOP_ENVIRONMENT_NAME "gnome")
elseif ($ENV{XDG_CURRENT_DESKTOP} STREQUAL "LXDE")
    set(LXDE_DESKTOP TRUE)
    set(GTK_BASED_DESKTOP TRUE)
    message(STATUS "System is LXDE")
    set(DESKTOP_ENVIRONMENT_NAME "lxde")
endif ()

message(STATUS "DESKTOP_ENVIRONMENT_NAME is ${DESKTOP_ENVIRONMENT_NAME}")

set(UNDERSCORE_OPERATING_SYSTEM $ENV{__SYSTEM_UNDERSCORE_OPERATING_SYSTEM})
set(SLASHED_OPERATING_SYSTEM $ENV{__SYSTEM_SLASHED_OPERATING_SYSTEM})
#set(OPERATING_SYSTEM $ENV{__OPERATING_SYSTEM})
#set(OPERATING_SYSTEM_RELEASE $ENV{__OPERATING_SYSTEM_RELEASE})


#    execute_process(COMMAND gnome-shell --version OUTPUT_VARIABLE GNOME_SHELL_VERSION_RAW OUTPUT_STRIP_TRAILING_WHITESPACE)
#    message(STATUS "GNOME_SHELL_VERSION_RAW is ${GNOME_SHELL_VERSION_RAW}")
#    string(TOLOWER ${GNOME_SHELL_VERSION_RAW} GNOME_RELEASE)
#    #message(STATUS "GNOME_RELEASE now is ${GNOME_RELEASE}")
#    string(REPLACE "gnome" "" GNOME_RELEASE ${GNOME_RELEASE})
#    string(REPLACE "shell" "" GNOME_RELEASE ${GNOME_RELEASE})
#    string(STRIP ${GNOME_RELEASE} GNOME_RELEASE)
#    message(STATUS "GNOME_RELEASE is ${GNOME_RELEASE}")
#    string(FIND ${GNOME_RELEASE} "." GNOME_RELEASE_FIRST_DOT)
#    string(SUBSTRING ${GNOME_RELEASE} 0 ${GNOME_RELEASE_FIRST_DOT} GNOME_RELEASE_MAJOR)
#    message(STATUS "GNOME_RELEASE_MAJOR is ${GNOME_RELEASE_MAJOR}")
#    if(${GNOME_RELEASE_MAJOR} GREATER_EQUAL 40)
#        #set(HAS_GTK4 TRUE)
#        #message(STATUS "HAS_GTK4 is ${HAS_GTK4}")
#        #add_compile_definitions(HAS_GTK4)
#        set(GNOME_RELEASE_MAJOR "3")
#    endif()
#    if(${GNOME_RELEASE_MAJOR} GREATER_EQUAL 3)
#        set(HAS_GTK3 TRUE)
#        message(STATUS "HAS_GTK3 is ${HAS_GTK3}")
#        add_compile_definitions(HAS_GTK3)
#    endif()
#endif()

string(TOLOWER ${CMAKE_BUILD_TYPE} tolower_cmake_build_type)


message(STATUS "tolower_cmake_build_type = ${tolower_cmake_build_type}")


if (${tolower_cmake_build_type} STREQUAL "debug")

    message(STATUS "Debug Build!!")

    add_compile_definitions(DEBUG)

    add_compile_options(-g -O0)

    message(STATUS "DEBUG compile definition set!!")

elseif (${tolower_cmake_build_type} STREQUAL "relwithdebinfo")

    message(STATUS "RelWithDebInfo Build!!")

    add_compile_definitions(DEBUG)

    message(STATUS "DEBUG compile definition set!!")

elseif (${tolower_cmake_build_type} STREQUAL "release")

    message(STATUS "Release Build!!")

    add_compile_definitions(NDEBUG)

    message(STATUS "NDEBUG compile definition set!!")

elseif (${tolower_cmake_build_type} STREQUAL "minsizerel")

    message(STATUS "MinSizeRel Build!!")

    add_compile_definitions(NDEBUG)

    message(STATUS "NDEBUG compile definition set!!")

else ()

    message(STATUS "\"${CMAKE_BUILD_TYPE}\" Build!!")

    add_compile_definitions(DEBUG)

    message(STATUS "DEBUG compile definition set!!")

endif ()



set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH $ORIGIN)
set(OPERATING_SYSTEM_POSIX TRUE)
set(FILE_SYSTEM_INOTIFY TRUE)
set(POSIX_SPAWN TRUE)
set(POSIX_LIST_SERIAL_PORTS TRUE)
set(WITH_X11 FALSE) # FALSE, it means X11 is not explicitly handled (maybe only indirectly by some toolkit api/implementation)
set(HAS_X11 FALSE) # FALSE, it means X11 is not explicitly handled (maybe only indirectly by some toolkit api/implementation)
set(WITH_XCB FALSE) # FALSE, it means XCB is not explicitly handled (maybe only indirectly by some toolkit api/implementation)
set(WITH_XI TRUE)
set(USE_OPENSSL TRUE)
set(PTHREAD TRUE)
set(BSD TRUE)
add_compile_definitions(__BSD__)



if (${OPERATING_SYSTEM} STREQUAL "freebsd")

    set(FREEBSD TRUE)
    set(NETBSD FALSE)
    set(OPENBSD FALSE)

    add_compile_definitions(FREEBSD)

    message(STATUS "FREEBSD has been set TRUE")

    #set(APPINDICATOR_PKG_MODULE "ayatana-appindicator3-0.1")
    #set(APPINDICATOR_PKG_MODULE "ayatana-indicator3-0.4")
    set(APPINDICATOR_PKG_MODULE "appindicator3-0.1")

    set(MPG123_PKG_MODULE "libmpg123")

elseif (${OPERATING_SYSTEM} STREQUAL "netbsd")

    set(NETBSD TRUE)
    set(FREEBSD FALSE)
    set(OPENBSD FALSE)

    add_compile_definitions(NETBSD)

    message(STATUS "NETBSD has been set TRUE")

    set(APPINDICATOR_PKG_MODULE "ayatana-appindicator3-0.1")

    set(MPG123_PKG_MODULE "libmpg123")

elseif ("${OPERATING_SYSTEM}" STREQUAL "openbsd")

    set(OPENBSD TRUE)
    set(FREEBSD FALSE)
    set(NETBSD FALSE)

    set(DONT_USE_PKG_CONFIG FALSE)

    add_compile_definitions(OPENBSD)

    message(STATUS "RASPBERRYPIOS defined!!")

else ()

    set(APPINDICATOR_PKG_MODULE "appindicator3-0.1")

    set(MPG123_PKG_MODULE "mpg123")

endif ()

message(STATUS "OPERATING_SYSTEM_RELEASE is ${OPERATING_SYSTEM_RELEASE}")

set(MIDI FALSE)
set(ALSA_MIDI FALSE)
set(INTERPROCESS_COMMUNICATION_SYSTEM_5 TRUE)

#add_compile_definitions(WITH_X11)
#add_compile_definitions(WITH_SN)
add_compile_definitions(WITH_XI)
link_libraries(pthread)
include(FindPkgConfig)

if (EXISTS $ENV{HOME}/__config/xfce.txt)

    set(LINUX_XFCE TRUE)
    message(STATUS "Adding Xfce/X11 dependency.")

endif ()

if (${KDE_DESKTOP})

    set(WITH_XCB TRUE)
    add_compile_definitions(WITH_XCB=1)

    set(QT_MIN_VERSION "5.3.0")
    set(KF5_MIN_VERSION "5.2.0")

    # apt install extra-cmake-modules
    # dnf install extra-cmake-modules
    find_package(ECM 1.0.0 REQUIRED NO_MODULE)
    set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

    # apt install libkf5notifications-dev
    # dnf install kf5-knotifications-devel

    #include(KDEInstallDirs)
    #include(KDECMakeSettings)
    #include(KDECompilerSettings NO_POLICY_SCOPE)
    #    find_package(KF5 ${KF5_MIN_VERSION} REQUIRED COMPONENTS
    # CoreAddons      # KAboutData
    #          I18n            # KLocalizedString
    #         WidgetsAddons   # KMessageBox
    #      Notifications
    #     )
    #include(FeatureSummary)

    # Find Qt modules
    #find_package(Qt5 ${QT_MIN_VERSION} CONFIG REQUIRED COMPONENTS
    #  Core    # QCommandLineParser, QStringLiteral
    #  Widgets # QApplication
    #  )
    find_package(KF5 ${KF5_MIN_VERSION} REQUIRED COMPONENTS
            # CoreAddons      # KAboutData
            #          I18n            # KLocalizedString
            #         WidgetsAddons   # KMessageBox
            CoreAddons
            Notifications
            ConfigWidgets
            KIO
            IconThemes
            )

    find_package(LibKWorkspace CONFIG REQUIRED)

    find_package(Qt5 ${QT_MIN_VERSION} REQUIRED COMPONENTS
            Core
            DBus
            UiTools
            X11Extras
            )

    # Find KDE modules

    #feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)
    #        find_package(KDE5 REQUIRED)
    message(STATUS "Adding KDE/xcb dependency.")
    #        file (STRINGS $ENV{HOME}/__config/knotifications/cflags.txt knotifications_cflags)
    #        file (STRINGS $ENV{HOME}/__config/knotifications/libs.txt knotifications_libs)
    #        if(knotifications_cflags STREQUAL "")
    #            set(knotifications_cflags -I/usr/include/KF5/KNotifications)
    #        endif()
    #        if(knotifications_libs STREQUAL "")
    #            set(knotifications_cflags -I/usr/include/KF5/KNotifications)
    #        endif()
endif ()

if(${GTK_BASED_DESKTOP})
include(${WORKSPACE_FOLDER}/operating_system/operating_system-posix/_gtk_desktop.cmake)
endif()

set(default_draw2d "draw2d_cairo")
set(default_imaging "imaging_freeimage")
set(default_write_text "write_text_pango")
set(default_audio "audio_alsa")
set(default_music_midi "music_midi_alsa")
set(default_node "node_freebsd")
set(default_audio_mixer "audio_mixer_alsa")
set(default_gpu "gpu_opengl")
set(default_input "input_xinput")
set(default_networking "networking_bsd")
set(default_nano_graphics "nano_graphics_cairo")
#add_compile_definitions(default_draw2d=draw2d_cairo)
#add_compile_definitions(default_imaging=imaging_freeimage)
#add_compile_definitions(default_write_text=write_text_pango)
#add_compile_definitions(default_audio=audio_alsa)
#add_compile_definitions(default_music_midi=music_midi_alsa)
#add_compile_definitions(default_node=node_linux)


if (LXDE_DESKTOP)

    list(APPEND app_common_dependencies
            desktop_environment_gnome)

#    list(APPEND static_app_common_dependencies
#            static_desktop_environment_gnome
#            static_node_gnome
#            static_node_gtk
#            static_windowing_x11)

    set(default_windowing "windowing_x11")

    add_compile_definitions(DESKTOP_ENVIRONMENT_GNOME)

    add_compile_definitions(default_windowing=windowing_x11)

endif ()


if (XFCE_DESKTOP)

    list(APPEND app_common_dependencies
            desktop_environment_xfce)

    list(APPEND static_app_common_dependencies
            static_desktop_environment_xfce)

    set(default_windowing "windowing_x11")

    add_compile_definitions(DESKTOP_ENVIRONMENT_XFCE)

    add_compile_definitions(default_windowing=windowing_x11)

endif ()


list(APPEND acme_libraries
    acme
    acme_posix
    acme_darwin
    acme_freebsd)


list(APPEND apex_libraries
    ${acme_libraries}
    apex
    apex_posix
    apex_darwin
    apex_freebsd
    )

list(APPEND aura_libraries
    ${apex_libraries}
    aura
    aura_posix
    aura_darwin
    aura_freebsd
    node_freebsd
    )

set(default_nano_graphics nano_graphics_cairo)


if (${GTK_BASED_DESKTOP})

    message(STATUS "Adding GNOME/X11 dependency.")

    list(APPEND static_app_common_dependencies
            static_operating_ambient_gtk4
            static_node_gnome
            static_node_gtk
            static_node_linux)

    set(default_common_windowing acme_windowing_g)

    if(${HAS_GTK4})
    
        set(default_acme_windowing acme_windowing_gtk4)

        set(default_innate_ui innate_ui_gtk4)

        set(default_windowing_common windowing_posix)

        set(default_windowing windowing_gtk4)

        set(default_operating_ambient operating_ambient_gtk4)

        set(default_node node_gtk4)

    endif()

    add_compile_definitions(DESKTOP_ENVIRONMENT_GNOME)

elseif(${KDE_DESKTOP})

    if(${HAS_KDE5})

        set(default_acme_windowing acme_windowing_kde5)

        set(default_innate_ui innate_ui_kde5)

        set(default_windowing_common windowing_posix)

        set(default_windowing windowing_kde5)

        set(default_operating_ambient operating_ambient_kde5)

        set(default_node node_kde5)

    endif()

endif ()


list(APPEND acme_windowing_libraries
    ${default_nano_graphics}
    ${default_acme_windowing}
    )
    

list(APPEND innate_ui_libraries
    ${acme_windowing_libraries}
    ${default_innate_ui}
    )


list(APPEND operating_ambient_libraries
    ${innate_ui_libraries}
    ${default_common_windowing}
    ${default_windowing_common}
    ${default_windowing}
    ${default_node}
    ${default_operating_ambient}
    )


list(APPEND app_common_dependencies
    ${aura_libraries}
    ${operating_ambient_libraries}
    )


#if (KDE_DESKTOP)
#
#    list(APPEND app_common_dependencies
#            desktop_environment_kde)
#
##    list(APPEND static_app_common_dependencies
##            static_desktop_environment_kde
##            static_node_kde
##            static_windowing_xcb
##            KF5::Notifications
##            KF5::ConfigWidgets
##            KF5::IconThemes
##            KF5::KIOCore
##            KF5::KIOFileWidgets
##            KF5::KIOWidgets
##            KF5::KIONTLM
##            PW::KWorkspace
##            )
#
#    set(default_windowing "windowing_xcb")
#
#    add_compile_definitions(DESKTOP_ENVIRONMENT_KDE)
#
#    add_compile_definitions(default_windowing=windowing_xcb)
#
#endif ()


#set(static_acme_extra_pkgconfig cairo xcb x11 xkbcommon xcb-render xcb-aux x11-xcb)
#set(static_aura_posix_pkgconfig libstartupxx-notification-1.0)
#
#set(static_acme_pkgconfig freetype2 libidn ${static_acme_extra_pkgconfig} ncurses dbus-glib-1)
#set(static_apex_pkgconfig libcrypto libssl libarchive)
#set(static_database_cairo_pkgconfig freetype2 pango cairo pangocairo)
#set(static_database_sqlite3_pkgconfig sqlite3)
#set(static_mpg123_pkgconfig ${MPG123_PKG_MODULE})
#set(static_desktop_environment_gnome_pkgconfig glib-2.0 gtk+-3.0 gdk-3.0 ${APPINDICATOR_PKG_MODULE})
#set(static_desktop_environment_kde_pkgconfig Qt5X11Extras Qt5Core Qt5UiTools)

#if (KDE_DESKTOP)
#    set(static_desktop_environment_pkgconfig ${static_desktop_environment_kde_pkgconfig})
#elseif (GNOME_DESKTOP)
#    set(static_desktop_environment_pkgconfig ${static_desktop_environment_gnome_pkgconfig})
#else ()
#    set(static_desktop_environment_pkgconfig ${static_desktop_environment_gnome_pkgconfig})
#endif()
#


set(LIBCXX_TARGETING_MSVC OFF)


add_compile_definitions(UNICODE)
add_compile_definitions(_UNICODE)



#set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/time-${OPERATING_SYSTEM_NAME}/x64/basis)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/output)
#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/time-${OPERATING_SYSTEM_NAME}/x64/basis)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/output)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)

link_directories(/usr/lib)
link_directories(/usr/local/lib)
link_directories(${LIBRARY_OUTPUT_PATH})
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/operating_system/storage-${OPERATING_SYSTEM_NAME}/library/x64/basis)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/operating_system/storage-${OPERATING_SYSTEM_NAME}/third/library/x64/basis)


include_directories(${WORKSPACE_FOLDER})
include_directories($ENV{HOME}/__config)
include_directories(${WORKSPACE_FOLDER}/source)
include_directories(${WORKSPACE_FOLDER}/source/app)
include_directories(${WORKSPACE_FOLDER}/source/app/include)
include_directories(${WORKSPACE_FOLDER}/source/include)
include_directories(${WORKSPACE_FOLDER}/port/_)
include_directories(${WORKSPACE_FOLDER}/port/include)
include_directories(${WORKSPACE_FOLDER}/operating_system)
if (OPERATING_SYSTEM_POSIX)
    include_directories(${WORKSPACE_FOLDER}/operating_system/operating_system-posix)
    include_directories(${WORKSPACE_FOLDER}/operating_system/operating_system-posix/include)
endif ()
include_directories(${WORKSPACE_FOLDER}/operating_system/operating_system-${OPERATING_SYSTEM_NAME})
include_directories(${WORKSPACE_FOLDER}/operating_system/operating_system-${OPERATING_SYSTEM_NAME}/include)
include_directories(${WORKSPACE_FOLDER}/operating_system/operating_system-${OPERATING_SYSTEM_NAME}/configuration)
include_directories(${WORKSPACE_FOLDER}/operating_system/operating_system-${OPERATING_SYSTEM_NAME}/include/configuration_selection/${CONFIGURATION_NAME})
include_directories(${WORKSPACE_FOLDER}/operating_system/operating_system-${OPERATING_SYSTEM_NAME}/operating_system/${SLASHED_OPERATING_SYSTEM})


set(INCLUDE_DRAW2D_CAIRO TRUE)
set(INCLUDE_IMAGING_FREEIMAGE TRUE)


set(STORE_FOLDER $ENV{HOME}/store/${SLASHED_OPERATING_SYSTEM})




