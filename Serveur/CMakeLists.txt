cmake_minimum_required(VERSION 3.23)
project(BIM_Serveur)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_RELEASE_LIBS ON)

if(MSVC)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
    set(Boost_USE_STATIC_RUNTIME ON)
elseif(MSVC)
endif (MSVC)

find_package(Boost REQUIRED COMPONENTS json serialization)
find_package(unofficial-sqlite3 REQUIRED)

add_executable(BIM_Serveur main.cpp ../classes/socket/tsQueue.h ../classes/socket/Message.h ../classes/socket/Connection.h ../classes/socket/Client.h ../classes/socket/Server.h ../classes/database/DB.h)

set_property(TARGET BIM_Serveur PROPERTY CXX_STANDARD 17)

target_link_libraries(BIM_Serveur PRIVATE ${Boost_LIBRARIES} unofficial::sqlite3::sqlite3)
target_include_directories(BIM_Serveur PRIVATE ${Boost_INCLUDE_DIRS})



