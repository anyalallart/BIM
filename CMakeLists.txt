cmake_minimum_required(VERSION 3.22)
project(BIM)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_RELEASE_LIBS ON)

if(MSVC)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
    set(Boost_USE_STATIC_RUNTIME ON)
    set(Boost_DIR "C:/Users/Administrateur/CLionProjects/BIM/lib/Boost/lib/cmake/Boost-1.80.0")

    set(wxWidgets_ROOT_DIR  "C:/Users/Administrateur/CLionProjects/BIM/lib/wxWidgets")
    set(CMAKE_PREFIX_PATH  C:/Users/Administrateur/CLionProjects/BIM/lib/wxWidgets)
    add_compile_options($<$<CONFIG:Release>:/MT> # Runtime library: Multi-threaded
            $<$<CONFIG:Debug>:/MTd> # Runtime library: Multi-threaded Debug
            )
elseif(MSVC)
    set(Boost_DIR lib/Boost/lib/cmake/Boost-1.80.0)
endif (MSVC)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

find_package(Boost 1.80.0 COMPONENTS json serialization REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(BIM main.cpp classes/Compte.cpp classes/Compte.h classes/Client.cpp classes/Client.h)

if(MSVC)
    set_target_properties(BIM PROPERTIES LINK_FLAGS /SUBSYSTEM:WINDOWS)
endif (MSVC)

target_link_libraries (BIM LINK_PUBLIC ${Boost_LIBRARIES} ${wxWidgets_LIBRARIES})



