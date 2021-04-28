cmake_minimum_required(VERSION 3.1)

project(SortFilterProxyModel VERSION 1.0
        DESCRIPTION          "SortFilterProxyModel as plugin extension"
        LANGUAGES            CXX)

set(CMAKE_CXX_STANDARD 11)

find_package(Qt5 REQUIRED COMPONENTS
    Core
    Qml
    )

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON) # This is to find generated *.moc and *.h files in build dir

set(ALL_SRCS
    ${CMAKE_CURRENT_LIST_DIR}/qqmlsortfilterproxymodel.cpp
    ${CMAKE_CURRENT_LIST_DIR}/filters/filter.cpp
    ${CMAKE_CURRENT_LIST_DIR}/filters/filtercontainer.cpp
    ${CMAKE_CURRENT_LIST_DIR}/filters/rolefilter.cpp
    ${CMAKE_CURRENT_LIST_DIR}/filters/valuefilter.cpp
    ${CMAKE_CURRENT_LIST_DIR}/filters/indexfilter.cpp
    ${CMAKE_CURRENT_LIST_DIR}/filters/regexpfilter.cpp
    ${CMAKE_CURRENT_LIST_DIR}/filters/rangefilter.cpp
    ${CMAKE_CURRENT_LIST_DIR}/filters/expressionfilter.cpp
    ${CMAKE_CURRENT_LIST_DIR}/filters/filtercontainerfilter.cpp
    ${CMAKE_CURRENT_LIST_DIR}/filters/anyoffilter.cpp
    ${CMAKE_CURRENT_LIST_DIR}/filters/alloffilter.cpp
    ${CMAKE_CURRENT_LIST_DIR}/filters/filtersqmltypes.cpp
    ${CMAKE_CURRENT_LIST_DIR}/sorters/sorter.cpp
    ${CMAKE_CURRENT_LIST_DIR}/sorters/sortercontainer.cpp
    ${CMAKE_CURRENT_LIST_DIR}/sorters/rolesorter.cpp
    ${CMAKE_CURRENT_LIST_DIR}/sorters/stringsorter.cpp
    ${CMAKE_CURRENT_LIST_DIR}/sorters/expressionsorter.cpp
    ${CMAKE_CURRENT_LIST_DIR}/sorters/sortersqmltypes.cpp
    ${CMAKE_CURRENT_LIST_DIR}/proxyroles/proxyrole.cpp
    ${CMAKE_CURRENT_LIST_DIR}/proxyroles/proxyrolecontainer.cpp
    ${CMAKE_CURRENT_LIST_DIR}/proxyroles/joinrole.cpp
    ${CMAKE_CURRENT_LIST_DIR}/proxyroles/switchrole.cpp
    ${CMAKE_CURRENT_LIST_DIR}/proxyroles/expressionrole.cpp
    ${CMAKE_CURRENT_LIST_DIR}/proxyroles/proxyrolesqmltypes.cpp
    ${CMAKE_CURRENT_LIST_DIR}/proxyroles/singlerole.cpp
    ${CMAKE_CURRENT_LIST_DIR}/proxyroles/regexprole.cpp
    ${CMAKE_CURRENT_LIST_DIR}/sorters/filtersorter.cpp
    ${CMAKE_CURRENT_LIST_DIR}/proxyroles/filterrole.cpp
    )
#add_library(SortFilterProxyModel SHARED
#    ${ALL_SRCS}
#)
#target_compile_definitions(SortFilterProxyModel PUBLIC -DSFPM_STATIC)#SFPM_SHARED
#target_include_directories(SortFilterProxyModel PUBLIC
#    ${CMAKE_CURRENT_LIST_DIR}
#    $<TARGET_PROPERTY:Qt5::Core,INTERFACE_INCLUDE_DIRECTORIES>
#    $<TARGET_PROPERTY:Qt5::Qml,INTERFACE_INCLUDE_DIRECTORIES>
#    )
#target_link_libraries( SortFilterProxyModel PUBLIC
#  Qt::Core
#  Qt::Qml
#)

add_subdirectory(plugins/SortFilterProxyModel)
