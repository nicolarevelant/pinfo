install_man('pinfo.1')

doc_data = configuration_data()
doc_data.set('EDITION', meson.project_version())
doc_data.set('UPDATED', '2024-05-17')
doc_data.set('VERSION', meson.project_version())
doc_data.set('UPDATED-MONTH', 'May')

configure_file(
    input: 'version.texi.in',
    output: 'version.texi',
    configuration: doc_data,
)

pinfo_texi = configure_file(
    input: 'pinfo.texi',
    output: 'pinfo.texi',
    copy: true
)

custom_target('INFO',
    input: pinfo_texi,
    output: 'pinfo.info',
    command: ['makeinfo', '@INPUT@', '-o@OUTPUT@'],
    install: true,
    install_dir: 'share/info',
)
