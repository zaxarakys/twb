project('twb', 'c')
gtk_dep = dependency('gtk4')
webkit_dep = dependency('webkitgtk-6.0')
curl_dep = dependency('libcurl')

deps = [
  gtk_dep,
  webkit_dep,
  curl_dep,
]

sources = [
  'src/main.c',
  'src/searchbar.c',
  'src/webview.c'
]

inc = include_directories('./src')

executable('twb', sources, dependencies : deps, include_directories: inc)
