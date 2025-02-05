cmake_minimum_required(VERSION 3.14)
project(server)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch asio
include(FetchContent)
FetchContent_Declare(
    asio
    GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git
    GIT_TAG asio-1-28-0  # Change version as needed
)
FetchContent_MakeAvailable(asio)

# Create server executable
add_executable(server server.cpp)
target_link_libraries(server asio)

# Create client executable
add_executable(client client.cpp)
target_link_libraries(client asio)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 11)

include(FindLib/FindAsioLib.cmake)
include(FindLib/FindJsonLib.cmake)

if(CMAKE_COMPILER_IS_GNUCXX)
    add_compile_options(-Wall -Wextra)
endif(CMAKE_COMPILER_IS_GNUCXX)

if (WIN32)
    add_compile_options(/W4)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "./")
    #set_target_properties (rtype.exe PROPERTIES PREFIX "./build/")
endif(WIN32)

#[[set(SCENE_MANAGER_SRC
        src/SceneManager/SceneManager.cpp
        )

set(PROJECT_MANAGER_SRC # ECS
        src/ProjectManager/EcsSparseArray.cpp
        src/ProjectManager/EcsRegistry.cpp
        )]]

set(USER_SRC
        User/UserManager.cpp
)

set(SERVER_SRC_GAME
        src/Game/Game.cpp
)

set(SERVER_SRC
        App/main.cpp
        src/receive.cpp
        src/send.cpp
        ${SERVER_SRC_GAME}
)

include_directories(
        # Module
        Module/
        Module/ProjectManager/

        # User
        ./
        User/

        src/

        # Universal Protocol
        Protocol/
        App/
)

add_executable(${PROJECT_NAME}
        ${SERVER_SRC}
        ${USER_SRC}
)


target_link_libraries(${PROJECT_NAME}
        asio
        nlohmann_json::nlohmann_json
)

if(WIN32)
    target_link_libraries(${PROJECT_NAME} Rpcrt4)
endif(WIN32)

if(UNIX)
    target_link_libraries(${PROJECT_NAME} uuid)
endif(UNIX)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
include(CPack)