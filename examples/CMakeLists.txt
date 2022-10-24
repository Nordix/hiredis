INCLUDE(FindPkgConfig)
# Check for GLib

PKG_CHECK_MODULES(GLIB2 glib-2.0)
if (GLIB2_FOUND)
    INCLUDE_DIRECTORIES(${GLIB2_INCLUDE_DIRS})
    LINK_DIRECTORIES(${GLIB2_LIBRARY_DIRS})
    ADD_EXECUTABLE(example-glib example-glib.c)
    TARGET_LINK_LIBRARIES(example-glib hiredis ${GLIB2_LIBRARIES})
ENDIF(GLIB2_FOUND)

FIND_PATH(LIBEV ev.h
    HINTS /usr/local /usr/opt/local
    ENV LIBEV_INCLUDE_DIR)

if (LIBEV)
    # Just compile and link with libev
    ADD_EXECUTABLE(example-libev example-libev.c)
    TARGET_LINK_LIBRARIES(example-libev hiredis ev)
ENDIF()

FIND_PATH(LIBEVENT event.h)
if (LIBEVENT)
    ADD_EXECUTABLE(example-libevent example-libevent.c)
    TARGET_LINK_LIBRARIES(example-libevent hiredis event)
ENDIF()

find_package(libhv CONFIG REQUIRED)
# FIND_PATH(LIBHV hv/hv.h)
# IF (LIBHV)
MESSAGE("Detected libhv: ${libhv}")
    ADD_EXECUTABLE(example-libhv example-libhv.cc)
    TARGET_LINK_LIBRARIES(example-libhv hiredis hv)
    target_compile_options(example-libhv PRIVATE /Wall /we2664)
    # target_compile_options(example-libhv PRIVATE /W4) # /WX
# ENDIF()

FIND_PATH(LIBUV uv.h)
IF (LIBUV)
    ADD_EXECUTABLE(example-libuv example-libuv.c)
    TARGET_LINK_LIBRARIES(example-libuv hiredis uv)
ENDIF()

IF (APPLE)
    FIND_LIBRARY(CF CoreFoundation)
    ADD_EXECUTABLE(example-macosx example-macosx.c)
    TARGET_LINK_LIBRARIES(example-macosx hiredis ${CF})
ENDIF()

IF (ENABLE_SSL)
    ADD_EXECUTABLE(example-ssl example-ssl.c)
    TARGET_LINK_LIBRARIES(example-ssl hiredis hiredis_ssl)
ENDIF()

ADD_EXECUTABLE(example example.c)
TARGET_LINK_LIBRARIES(example hiredis)

ADD_EXECUTABLE(example-push example-push.c)
TARGET_LINK_LIBRARIES(example-push hiredis)
