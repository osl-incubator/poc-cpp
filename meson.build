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
  PROJECT_PATH + '/src/test_unique_ptr.cpp',
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
