

add_library( sortfilterproxymodelplugin SHARED

    ${ALL_SRCS} # all .cpp files in parent folders

    ${CMAKE_CURRENT_LIST_DIR}/sortfilterproxymodelplugin.h
    ${CMAKE_CURRENT_LIST_DIR}/sortfilterproxymodelplugin.cpp

    ${CMAKE_CURRENT_LIST_DIR}/qmldir

)
#target_compile_definitions(qaterialplugin PUBLIC -DQATERIAL_SHARED)
#target_include_directories(qaterialplugin PUBLIC ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_LIST_DIR}/../..)
#target_compile_features(
#    qaterialplugin
#    PRIVATE
#        cxx_auto_type
#        cxx_generic_lambdas
#)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    target_compile_options(
        ${PROJECT_NAME}
        PRIVATE
            -Wall
            -Wextra
            -Wpedantic
    )
endif()
target_compile_definitions(sortfilterproxymodelplugin PUBLIC -DSFPM_STATIC)#SFPM_SHARED
target_include_directories(sortfilterproxymodelplugin PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/../..
    $<TARGET_PROPERTY:Qt5::Core,INTERFACE_INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:Qt5::Qml,INTERFACE_INCLUDE_DIRECTORIES>
    )
target_link_libraries( sortfilterproxymodelplugin PUBLIC
  Qt::Core
  Qt::Qml

)

set(QT_BIN ${CMAKE_PREFIX_PATH}/bin CACHE STRING "Qt installation bin path")
set(QT_QML ${CMAKE_PREFIX_PATH}/qml CACHE STRING "Qml plugin installation path")
add_custom_command(
    TARGET sortfilterproxymodelplugin
    POST_BUILD

    COMMAND
        cd $<TARGET_FILE_DIR:sortfilterproxymodelplugin>/.. &&
        ${QT_BIN}/qmlplugindump.exe -nonrelocatable SortFilterProxyModel 1.0 . > SortFilterProxyModel/plugin.qmltypes

)
add_custom_command(
    TARGET sortfilterproxymodelplugin
    POST_BUILD

    COMMAND
        cd ${QT_QML} &&
        if not exist SortFilterProxyModel mkdir SortFilterProxyModel

)
install(
    TARGETS
        sortfilterproxymodelplugin
    DESTINATION
        ${QT_QML}/SortFilterProxyModel
)
install(
    FILES
        ${CMAKE_CURRENT_LIST_DIR}/qmldir
        $<TARGET_FILE_DIR:sortfilterproxymodelplugin>/plugin.qmltypes
    DESTINATION
        ${QT_QML}/SortFilterProxyModel
)
