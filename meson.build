project('poccpp', 'cpp', 'c',
  license : 'BSD-3-Clause',
  version : '1.0.0',  # semantic-release
  default_options : [
    'warning_level=3',
    'cpp_std=c++20',
  ]
)

PROJECT_PATH = meson.source_root()

cxx = meson.get_compiler('cpp')

deps = []

inc = include_directories('./src')

project_src_files = files(
  PROJECT_PATH + '/src/expr.cpp',
  PROJECT_PATH + '/src/expr-visitor.cpp',
  PROJECT_PATH + '/src/test_casting.cpp',
  PROJECT_PATH + '/src/test_macros.cpp',
  PROJECT_PATH + '/src/test_template.cpp',
  PROJECT_PATH + '/src/test_types.cpp',
  PROJECT_PATH + '/src/test_unique_ptr.cpp',
  PROJECT_PATH + '/src/test_visitor.cpp',
  PROJECT_PATH + '/src/utils.cpp',
)

if get_option('dev').enabled()
  deps += []
  # subdir('tests')
endif

poccpp_exe = executable(
  'poccpp',
  project_src_files + files(PROJECT_PATH + '/src/main.cpp'),
  dependencies : deps,
  include_directories : inc,
  install : true)
