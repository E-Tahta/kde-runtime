project(corebindings)

set(corebindings_SRCS
    declarativeitemcontainer.cpp
    corebindingsplugin.cpp
    dataengineconsumer.cpp
    theme.cpp
    datamodel.cpp
    datasource.cpp
    runnermodel.cpp
    svgitem.cpp
    framesvgitem.cpp
    dialog.cpp
    tooltip.cpp
    dataenginebindings.cpp
    iconitem.cpp
    )

INCLUDE_DIRECTORIES(
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_BINARY_DIR}
        ${KDE4_INCLUDES}
        ${KDECLARATIVE_INCLUDE_DIR}
)

qt4_automoc(${corebindings_SRCS})



add_library(corebindingsplugin SHARED ${corebindings_SRCS})
target_link_libraries(corebindingsplugin ${KDE4_PLASMA_LIBS} ${QT_QTSCRIPT_LIBRARY} ${QT_QTDECLARATIVE_LIBRARY} ${KDECLARATIVE_LIBRARIES})

install(TARGETS corebindingsplugin DESTINATION ${IMPORTS_INSTALL_DIR}/org/kde/plasma/core)
install(FILES qmldir DESTINATION ${IMPORTS_INSTALL_DIR}/org/kde/plasma/core)

add_subdirectory(tests)
