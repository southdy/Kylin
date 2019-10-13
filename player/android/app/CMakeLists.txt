cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wno-argument-outside-range -Wno-invalid-offsetof")

set(PROJ_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../../code")

add_definitions(-DGL_GLEXT_PROTOTYPES)
add_definitions(-DFT2_BUILD_LIBRARY)
add_definitions(-DURHO3D_LUA)
add_definitions(-DURHO3D_IK)
add_definitions(-DURHO3D_NETWORK)
add_definitions(-DURHO3D_PHYSICS)
add_definitions(-DURHO3D_NAVIGATION)
add_definitions(-DURHO3D_URHO2D)
add_definitions(-DURHO3D_FILEWATCHER)
add_definitions(-DURHO3D_PROFILING)
add_definitions(-DURHO3D_LOGGING)
add_definitions(-DURHO3D_THREADING)

add_definitions (-DRAKNET_ENABLE_STATIC -D_RAKNET_SUPPORT_NatTypeDetectionServer=0 -D_RAKNET_SUPPORT_UDPForwarder=0 -D_RAKNET_SUPPORT_TwoWayAuthentication=0)
add_definitions (-D_RAKNET_SUPPORT_CloudClient=0 -D_RAKNET_SUPPORT_CloudServer=0 -D_RAKNET_SUPPORT_ConnectionGraph2=0 -D_RAKNET_SUPPORT_NatPunchthroughServer=0)
add_definitions (-D_RAKNET_SUPPORT_RelayPlugin=0 -D_RAKNET_SUPPORT_LibVoice=0 -D_RAKNET_SUPPORT_DynDNS=0 -D_RAKNET_SUPPORT_HTTPConnection2=0 -D_RAKNET_SUPPORT_HTTPConnection=0)
add_definitions (-D_RAKNET_SUPPORT_EmailSender=0 -D_RAKNET_SUPPORT_UDPProxyClient=0 -D_RAKNET_SUPPORT_UDPProxyCoordinator=0 -D_RAKNET_SUPPORT_TeamManager=0 -D_RAKNET_SUPPORT_TeamBalancer=0)
add_definitions (-D_RAKNET_SUPPORT_NatTypeDetectionClient=0 -D_RAKNET_SUPPORT_FullyConnectedMesh2=0 -D_RAKNET_SUPPORT_ConnectionGraph2=0 -D_RAKNET_SUPPORT_FullyConnectedMesh=0 -D_RAKNET_SUPPORT_TelnetTransport=0)
add_definitions (-D_RAKNET_SUPPORT_PacketLogger=0 -D_RAKNET_SUPPORT_DirectoryDeltaTransfer=0 -D_RAKNET_SUPPORT_FileOperations=0 -D_RAKNET_SUPPORT_UDPProxyServer=0)
add_definitions (-D_RAKNET_SUPPORT_ConsoleServer=0 -D_RAKNET_SUPPORT_RakNetTransport=0 -D_RAKNET_SUPPORT_TCPInterface=0 -D_RAKNET_SUPPORT_LogCommandParser=0 -D_RAKNET_SUPPORT_RakNetCommandParser=0)
add_definitions (-D_RAKNET_SUPPORT_Rackspace=0 -D_RAKNET_SUPPORT_PacketizedTCP=0 -D_RAKNET_SUPPORT_RPC4Plugin=0 -D_RAKNET_SUPPORT_Router2=0 -D_RAKNET_SUPPORT_ReplicaManager3=0)
add_definitions (-D_RAKNET_SUPPORT_ReadyEvent=0 -D_RAKNET_SUPPORT_MessageFilter=0 -D_RAKNET_SUPPORT_FileListTransfer=0)

message(STATUS "Current build type: ${CMAKE_BUILD_TYPE}")

file(GLOB_RECURSE SOURCE_FILES_GAME
  ${PROJ_DIR}/game/*.cpp
  ${PROJ_DIR}/thirdparty/Urho3D/*.cpp
  ${PROJ_DIR}/thirdparty/lua/*.c
  ${PROJ_DIR}/thirdparty/toluapp/*.c
  ${PROJ_DIR}/thirdparty/ik/*.c
  ${PROJ_DIR}/thirdparty/LZ4/*.c
  ${PROJ_DIR}/thirdparty/Recast/*.cpp
  ${PROJ_DIR}/thirdparty/Detour/*.cpp
  ${PROJ_DIR}/thirdparty/DetourCrowd/*.cpp
  ${PROJ_DIR}/thirdparty/DetourTileCache/*.cpp
  ${PROJ_DIR}/thirdparty/Civetweb/*.c
  ${PROJ_DIR}/thirdparty/Bullet/*.cpp
  ${PROJ_DIR}/thirdparty/slikenet/*.cpp
  ${PROJ_DIR}/thirdparty/PugiXml/*.cpp
  ${PROJ_DIR}/thirdparty/StanHull/*.cpp
  ${PROJ_DIR}/thirdparty/Box2D/*.cpp
  ${PROJ_DIR}/thirdparty/FreeType/src/autofit/autofit.c
  ${PROJ_DIR}/thirdparty/FreeType/src/base/ftbase.c
  ${PROJ_DIR}/thirdparty/FreeType/src/base/ftbbox.c
  ${PROJ_DIR}/thirdparty/FreeType/src/base/ftbitmap.c
  ${PROJ_DIR}/thirdparty/FreeType/src/base/ftfntfmt.c
  ${PROJ_DIR}/thirdparty/FreeType/src/base/ftfstype.c
  ${PROJ_DIR}/thirdparty/FreeType/src/base/ftgasp.c
  ${PROJ_DIR}/thirdparty/FreeType/src/base/ftglyph.c
  ${PROJ_DIR}/thirdparty/FreeType/src/base/ftgxval.c
  ${PROJ_DIR}/thirdparty/FreeType/src/base/ftinit.c
  ${PROJ_DIR}/thirdparty/FreeType/src/base/ftlcdfil.c
  ${PROJ_DIR}/thirdparty/FreeType/src/base/ftmm.c
  ${PROJ_DIR}/thirdparty/FreeType/src/base/ftotval.c
  ${PROJ_DIR}/thirdparty/FreeType/src/base/ftpatent.c
  ${PROJ_DIR}/thirdparty/FreeType/src/base/ftpfr.c
  ${PROJ_DIR}/thirdparty/FreeType/src/base/ftstroke.c
  ${PROJ_DIR}/thirdparty/FreeType/src/base/ftsynth.c
  ${PROJ_DIR}/thirdparty/FreeType/src/base/ftsystem.c
  ${PROJ_DIR}/thirdparty/FreeType/src/base/fttype1.c
  ${PROJ_DIR}/thirdparty/FreeType/src/base/ftwinfnt.c
  ${PROJ_DIR}/thirdparty/FreeType/src/bdf/bdf.c
  ${PROJ_DIR}/thirdparty/FreeType/src/bzip2/ftbzip2.c
  ${PROJ_DIR}/thirdparty/FreeType/src/cache/ftcache.c
  ${PROJ_DIR}/thirdparty/FreeType/src/cff/cff.c
  ${PROJ_DIR}/thirdparty/FreeType/src/cid/type1cid.c
  ${PROJ_DIR}/thirdparty/FreeType/src/gxvalid/gxvalid.c
  ${PROJ_DIR}/thirdparty/FreeType/src/gzip/ftgzip.c
  ${PROJ_DIR}/thirdparty/FreeType/src/lzw/ftlzw.c
  ${PROJ_DIR}/thirdparty/FreeType/src/otvalid/otvalid.c
  ${PROJ_DIR}/thirdparty/FreeType/src/pcf/pcf.c
  ${PROJ_DIR}/thirdparty/FreeType/src/pfr/pfr.c
  ${PROJ_DIR}/thirdparty/FreeType/src/psaux/psaux.c
  ${PROJ_DIR}/thirdparty/FreeType/src/pshinter/pshinter.c
  ${PROJ_DIR}/thirdparty/FreeType/src/psnames/psmodule.c
  ${PROJ_DIR}/thirdparty/FreeType/src/raster/raster.c
  ${PROJ_DIR}/thirdparty/FreeType/src/sfnt/sfnt.c
  ${PROJ_DIR}/thirdparty/FreeType/src/smooth/smooth.c
  ${PROJ_DIR}/thirdparty/FreeType/src/truetype/truetype.c
  ${PROJ_DIR}/thirdparty/FreeType/src/type1/type1.c
  ${PROJ_DIR}/thirdparty/FreeType/src/type42/type42.c
  ${PROJ_DIR}/thirdparty/FreeType/src/winfonts/winfnt.c
)

file(GLOB SOURCE_FILES_SDL2
  ${PROJ_DIR}/thirdparty/SDL/src/*.c
  ${PROJ_DIR}/thirdparty/SDL/src/audio/*.c
  ${PROJ_DIR}/thirdparty/SDL/src/audio/android/*.c
  ${PROJ_DIR}/thirdparty/SDL/src/audio/dummy/*.c
  ${PROJ_DIR}/thirdparty/SDL/src/atomic/*.c
  ${PROJ_DIR}/thirdparty/SDL/src/core/android/*.c
  ${PROJ_DIR}/thirdparty/SDL/src/cpuinfo/*.c
  ${PROJ_DIR}/thirdparty/SDL/src/dynapi/*.c
  ${PROJ_DIR}/thirdparty/SDL/src/events/*.c
  ${PROJ_DIR}/thirdparty/SDL/src/file/*.c
  ${PROJ_DIR}/thirdparty/SDL/src/haptic/*.c
  ${PROJ_DIR}/thirdparty/SDL/src/haptic/android/*.c
  ${PROJ_DIR}/thirdparty/SDL/src/joystick/*.c
  ${PROJ_DIR}/thirdparty/SDL/src/joystick/android/*.c
  ${PROJ_DIR}/thirdparty/SDL/src/joystick/steam/SDL_steamcontroller.c
  ${PROJ_DIR}/thirdparty/SDL/src/loadso/dlopen/*.c
  ${PROJ_DIR}/thirdparty/SDL/src/power/*.c
  ${PROJ_DIR}/thirdparty/SDL/src/power/android/*.c
  ${PROJ_DIR}/thirdparty/SDL/src/filesystem/android/*.c
  ${PROJ_DIR}/thirdparty/SDL/src/render/*.c
  ${PROJ_DIR}/thirdparty/SDL/src/render/*/*.c
  ${PROJ_DIR}/thirdparty/SDL/src/stdlib/*.c
  ${PROJ_DIR}/thirdparty/SDL/src/thread/*.c
  ${PROJ_DIR}/thirdparty/SDL/src/thread/pthread/*.c
  ${PROJ_DIR}/thirdparty/SDL/src/timer/*.c
  ${PROJ_DIR}/thirdparty/SDL/src/timer/unix/*.c
  ${PROJ_DIR}/thirdparty/SDL/src/video/*.c
  ${PROJ_DIR}/thirdparty/SDL/src/video/android/*.c
)

add_library(
    SDL2 SHARED
    ${SOURCE_FILES_SDL2}
)

add_library(
    main SHARED
    ${SOURCE_FILES_GAME}
)

target_include_directories(
    SDL2 PRIVATE
    .
    ${PROJ_DIR}/thirdparty/SDL/include
    ${PROJ_DIR}/thirdparty/SDL/src
)

target_include_directories(
    main PRIVATE
    .
    ${PROJ_DIR}/game
    ${PROJ_DIR}/thirdparty
    ${PROJ_DIR}/thirdparty/SDL/include
    ${PROJ_DIR}/thirdparty/Urho3D
    ${PROJ_DIR}/thirdparty/lua
    ${PROJ_DIR}/thirdparty/ik/include
    ${PROJ_DIR}/thirdparty/Recast
    ${PROJ_DIR}/thirdparty/Detour
    ${PROJ_DIR}/thirdparty/FreeType/include
    ${PROJ_DIR}/thirdparty/Bullet
    ${PROJ_DIR}/thirdparty/slikenet
    ${PROJ_DIR}/thirdparty/slikenet/include
)

target_link_libraries(
    SDL2
    android
    EGL
    GLESv1_CM
    GLESv2
    OpenSLES
    log
)

target_link_libraries(
    main
    SDL2
)
