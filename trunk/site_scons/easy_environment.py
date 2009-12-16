def InstallUsingLink(target, source, env):
  """Install function for environment which uses link in preference to copy.

  Args:
    target: Destintion filename
    source: Source filename
    env: Environment

  Returns:
    Return code from SCons Node link function.
  """

  # Use link function for Install() and InstallAs(), since it's much much
  # faster than copying.  This is ok for the way we build clients, where we're
  # installing to a build output directory and not to a permanent location such
  # as /usr/bin.
  # Need to force the target and source to be lists of nodes
  return SCons.Node.FS.LinkFunc([env.Entry(target)], [env.Entry(source)], env)


def easy_environment( env, pkg_config=[], extra_programs=[], extra_pathes=[], extra_libs=[], extra_libspathes=[] ):
    for p in pkg_config:
        env.ParseConfig( "pkg-config " + p + " --cflags --libs" )
        
    for p in extra_programs:
        print p
        env.ParseConfig( p + " --cflags" )
        env.ParseConfig( p + " --libs" )


    env.Append( CPPPATH = extra_pathes )
    env.Append( LIBS = extra_libs )
    env.Append( LIBPATH = extra_libspathes )
        
        
    return env
