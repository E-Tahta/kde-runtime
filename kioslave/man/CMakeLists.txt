add_subdirectory( tests )

########### next target ###############

set(kio_man_PART_SRCS man2html.cpp kio_man.cpp request_hash.cpp )


kde4_add_plugin(kio_man ${kio_man_PART_SRCS})


target_link_libraries(kio_man  ${KDE4_KIO_LIBS}  )

install(TARGETS kio_man  DESTINATION ${PLUGIN_INSTALL_DIR} )


########### next target ###############

set(kmanpart_PART_SRCS kmanpart.cpp )


kde4_add_plugin(kmanpart WITH_PREFIX ${kmanpart_PART_SRCS})


target_link_libraries(kmanpart  ${KDE4_KHTML_LIBS} )

install(TARGETS kmanpart  DESTINATION ${PLUGIN_INSTALL_DIR} )


########### install files ###############

install( FILES man.protocol kmanpart.desktop  DESTINATION  ${SERVICES_INSTALL_DIR} )

