conf_data = configuration_data()
conf_data.set_quoted('PACKAGE', meson.project_name())
conf_data.set_quoted('CONFIGDIR', '/etc/pinforc')
conf_data.set_quoted('LOCALEDIR', '/usr/share/locale')
conf_data.set_quoted('PACKAGE_VERSION', meson.project_version())

conf_data.set10('ENABLE_NLS', true)
conf_data.set10('HAVE_CURSES_H', true)
conf_data.set10('HAVE_DECL_USE_DEFAULT_COLORS', true)
conf_data.set10('HAVE_DECL_BKGDSET', true)
conf_data.set10('HAVE_GETOPT_LONG', true)
conf_data.set10('HAVE_CURSES_COLOR', true)
conf_data.set10('HAS_READLINE', true)
conf_data.set10('USE_WCHAR', true)

config_h = configure_file(
	output: 'config.h',
	configuration: conf_data)

target_include = include_directories('.')
curses_dep = dependency('curses')
readline_dep = dependency('readline')

executable(meson.project_name(),
	config_h,
    'pinfo.c',
	'colors.c',
	'datatypes.c',
	'filehandling_functions.c',
	'mainfunction.c',
	'manual.c',
	'menu_and_note_utils.c',
	'parse_config.c',
	'regexp_search.c',
	'signal_handler.c',
	'utils.c',
	'video.c',
	'colors.h',
	'common_includes.h',
	'datatypes.h',
	'filehandling_functions.h',
	'keyboard.h',
	'mainfunction.h',
	'manual.h',
	'menu_and_note_utils.h',
	'parse_config.h',
	'regexp_search.h',
	'signal_handler.h',
	'utils.h',
	'video.h',
	'initializelinks.c',
	'initializelinks.h',
	'printinfo.c',
	'printinfo.h',
	'localestuff.h',
	include_directories: target_include,
	dependencies: [curses_dep, readline_dep],
	install: true)

install_data('pinforc',
	install_dir: '/etc')
