# エラーの原因
cmake_minimum_required(VERSION 3.11)

# プロジェクト名
project(KongkongLibrary)

# C++20を指定
if(NOT DEFINED CMAKE_CXX_STANDARD OR CMAKE_CXX_STANDARD STREQUAL "")
    set(CMAKE_CXX_STANDARD 20)
endif()

# C++20以上が必要
if(CMAKE_CXX_STANDARD LESS 20)
  message(FATAL_ERROR "このプロジェクトでは C++20 以上が必要です（指定された言語バージョン: C++${CMAKE_CXX_STANDARD}）")
endif()

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ターゲット名は klib
add_library(klib STATIC
    ${CMAKE_SOURCE_DIR}/../../../src/cpp/All.cpp
)

# 追加のincludeパス
target_include_directories(KongkongLibrary PRIVATE
    ${CMAKE_SOURCE_DIR}/../../../src/include
)

# プラットフォーム固有の機能を使用しない
target_compile_definitions(KongkongLibrary PRIVATE
    KONGKONG_OBJECTIVE_C_DISABLED = 1
    KONGKONG_NO_PLATFORM_SPECIFICS = 1
)