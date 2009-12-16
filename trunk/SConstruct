from easy_environment import easy_environment

env = Environment()

easy_environment( env,
                  pkg_config       = [],
                  extra_programs   = [],
                  extra_pathes     = [],
                  extra_libs       = [ "boost_program_options" ],
                  extra_libspathes = [] )

env.Append( RPATH = env.Literal( '\\$$ORIGIN'))

library_target = env.SharedLibrary( "stargazer", ["StarGazer.cpp", "serial_port.cpp"] )
env.Program( "learn_stargazer_map", ["learn_stargazer_map.cpp", library_target] )

