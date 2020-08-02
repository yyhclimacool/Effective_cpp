add_executable(item42 item42.cc)
add_executable(item43 item43.cc)
install(TARGETS item42 item43
  RUNTIME DESTINATION bin/Chapter07)
