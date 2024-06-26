cmake_minimum_required(VERSION 3.18)
project(tophat)


if(MSVC)
    set(umka_dir ${CMAKE_CURRENT_SOURCE_DIR}/lib/umka/umka_windows_msvc)
    set(umka_lib_path  ${umka_dir}/libumka_static.lib)

    execute_process(COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/cmd/win-buildmodules.bat WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} RESULT_VARIABLE ret)
    if (NOT ret EQUAL "0")
        message(FATAL_ERROR "Failed to generate staembed.c")
    endif()

    file( GLOB th_sources
        "src/*.c"
    )

    add_executable(tophat ${th_sources})

    # NOTE(skejeton): _USE_MATH_DEFINES flag for M_PI and so on.
    # NOTE(skejeton): UMKA_STATIC flag for we are linking umka statically not as a DLL.
    target_compile_definitions(tophat PUBLIC UMKA_STATIC _USE_MATH_DEFINES _CONSOLE)
    # target_compile_options(tophat PRIVATE /fsanitize=address)

    target_include_directories(tophat PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/miniaudio
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/stb
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/umprof
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/umka/src
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/sokol
    )

    file(READ ${CMAKE_CURRENT_SOURCE_DIR}/version ver)
    execute_process(COMMAND git rev-parse --short HEAD OUTPUT_VARIABLE gitver)
    string(STRIP "${ver}" ver)
    string(STRIP "${gitver}" gitver)
    target_compile_definitions(tophat PUBLIC -DTH_VERSION=\"${ver}\" -DTH_GITVER=\"${gitver}\")

    target_link_libraries(tophat xinput gdi32 opengl32 user32 ${umka_lib_path})
else()
    message("TODO(skejeton): This script only works with MSVC. If you are on Linux or WSL/MSYS2 run `make` instead.")
endif()
