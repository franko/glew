  return GLEW_OK;
}

#endif /* _WIN32 */

/* ------------------------------------------------------------------------ */

const GLubyte* glewGetErrorString (GLenum error)
{
  static const GLubyte* _glewErrorString[] =
  {
    "no error",
    "missing GL version",
    "GL 1.1 and up are not supported",
    "GLX 1.2 and up are not supported",
    "unknown error"
  };
  if (error > 4) error = 4;
  return _glewErrorString[error];
}

const GLubyte* glewGetString (GLenum name)
{
  static const GLubyte* _glewString[] =
  {
    NULL,
    "GLEW_VERSION_STRING"
  };
  if (name > 1) name = 0;
  return _glewString[name];
}

/* ------------------------------------------------------------------------ */

GLboolean glewExperimental = GL_FALSE;

GLenum glewInit ()
{
  GLenum r;
  if ( (r = _glewInit()) ) return r;
#ifdef _WIN32
  return _wglewInit();
#else /* _UNIX */
  return _glxewInit();
#endif /* _WIN32 */
}
