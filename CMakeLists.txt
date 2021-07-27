cmake_minimum_required(VERSION 3.20)

project(algorithms)

# ====================================================================================
#                               base targets - modules
# ====================================================================================

#
# make module target with a given name using "${PROJECT_NAME}-" prefix;
# you must explicitly specify the target sources
#
macro(make_module MODULE)
  add_library(${PROJECT_NAME}-${MODULE} MODULE)
  target_compile_features(${PROJECT_NAME}-${MODULE} PRIVATE cxx_std_17)

  target_include_directories(${PROJECT_NAME}-${MODULE} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
  )

endmacro()

# ====================================================================================

make_module(patterns)

target_sources(${PROJECT_NAME}-patterns PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/creational/abstract-factory.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/creational/builder.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/creational/factory-method.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/creational/prototype.cpp

  ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/structural/adapter.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/structural/bridge.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/structural/composite.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/structural/decorator.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/structural/facade.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/structural/flyweight.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/structural/proxy.cpp

  ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/behavioral/command.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/behavioral/cor.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/behavioral/mediator.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/behavioral/memento.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/behavioral/observer.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/behavioral/state.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/behavioral/strategy.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/behavioral/template-method.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/behavioral/visitor.cpp

)

# ====================================================================================

make_module(misc)

target_sources(${PROJECT_NAME}-misc PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src/misc/numeral-system-converter.cpp
)


# ====================================================================================
#                                     tests target
# ====================================================================================

add_subdirectory(extern/Catch2)

#
# make tests for a given module target and add target to run they;
# you must explicitly specify the target sources;
# created target will be named using "run-MODULE-tests" pattern
#
macro(make_tests_for MODULE RUN_RULE)
  add_executable(${MODULE}-tests EXCLUDE_FROM_ALL)
  target_compile_features(${MODULE}-tests PRIVATE cxx_std_17)

  add_dependencies(${MODULE}-tests ${MODULE})

  target_sources(${MODULE}-tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/tests.cpp
  )
  target_include_directories(${MODULE}-tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
  )
  target_link_libraries(${MODULE}-tests PRIVATE
    Catch2::Catch2

    $<TARGET_OBJECTS:${MODULE}>
  )

  add_custom_target(run-${MODULE}-tests COMMAND $<TARGET_FILE:${MODULE}-tests> ${RUN_RULE})
  add_dependencies(run-${MODULE}-tests ${MODULE}-tests)

endmacro()

# ====================================================================================

make_tests_for(${PROJECT_NAME}-patterns patterns::*)

target_sources(${PROJECT_NAME}-patterns-tests PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/patterns/tests-creational.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/patterns/tests-structural.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/patterns/tests-behavioral.cpp
)

# ====================================================================================

make_tests_for(${PROJECT_NAME}-misc misc::*)

target_sources(${PROJECT_NAME}-misc-tests PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/misc/tests-misc.cpp
)
