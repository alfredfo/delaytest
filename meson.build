project(
    'delaytest',
    'c',
    meson_version: '>=1.3.0',
    default_options: ['c_std=c17'],
)

delaytest_src = []
delaytest_includes = []

subdir('src')

delaytest = executable(
    'delaytest',
    delaytest_src,
    include_directories: delaytest_includes,
)

prog_objcopy = find_program('objcopy')

input_bfdname = meson.get_external_property('input_bfdname')

custom_target(
    'delaytest_srecord',
    build_by_default: true,
    output: 'delaytest.s19',
    input: delaytest,
    command: [
        prog_objcopy,
        '-I' + input_bfdname,
        '@INPUT@',
        '-Osrec', '@OUTPUT@',
    ],
)
