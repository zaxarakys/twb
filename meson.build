project('twb', 'c')
gtk_dep = dependency('gtk4')
webkit_dep = dependency('webkitgtk-6.0')

deps = [
  gtk_dep,
  webkit_dep,
]

sources = [
  'src/main.c',
]

inc = include_directories('./src')

executable('twb', sources, dependencies : deps, include_directories: inc)
