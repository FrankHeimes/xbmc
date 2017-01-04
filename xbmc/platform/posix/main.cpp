/*
 *      Copyright (C) 2005-2013 Team XBMC
 *      http://xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include "system.h"
#include "AppParamParser.h"
#include "settings/AdvancedSettings.h"
#include "FileItem.h"
#include "PlayListPlayer.h"
#include "utils/log.h"
#include "platform/xbmc.h"
#ifdef TARGET_POSIX
#include <sys/resource.h>
#include <signal.h>
#endif
#if defined(TARGET_DARWIN_OSX)
  #include "Util.h"
  // SDL redefines main as SDL_main 
  #ifdef HAS_SDL
    #include <SDL/SDL.h>
  #endif
#include <locale.h>
#endif
#ifdef HAS_LIRC
#include "input/linux/LIRC.h"
#endif
#include "platform/XbmcContext.h"

#pragma comment(lib, "compileinfo")
#pragma comment(lib, "effects11")
#pragma comment(lib, "libkodi")
#pragma comment(lib, "python_binding")
#pragma comment(lib, "unrarxlib")
#pragma comment(lib, "upnp")

#pragma comment(lib, "avcodec")
#pragma comment(lib, "avfilter")
#pragma comment(lib, "avformat")
#pragma comment(lib, "avutil")
#pragma comment(lib, "postproc")
#pragma comment(lib, "swresample")
#pragma comment(lib, "swscale")

#pragma comment(lib, "cpluff")
#pragma comment(lib, "CrossGuidd")
#pragma comment(lib, "dnssd")
#pragma comment(lib, "EasyHook32")
#pragma comment(lib, "EasyHook64")
#pragma comment(lib, "expatd")
#pragma comment(lib, "freetyped")
#pragma comment(lib, "giflibd")
#pragma comment(lib, "jpeg-staticd")
#pragma comment(lib, "libass")
#pragma comment(lib, "libbluray")
#pragma comment(lib, "libcdio")
#pragma comment(lib, "libcurl")
#pragma comment(lib, "libeay32")
#pragma comment(lib, "libfribidi")
#pragma comment(lib, "libiconvd")
#pragma comment(lib, "libmicrohttpd")
#pragma comment(lib, "libmysql")
#pragma comment(lib, "libplist")
#pragma comment(lib, "libpng16_staticd")
#pragma comment(lib, "libxml2")
#pragma comment(lib, "libxslt")
#pragma comment(lib, "lzo2-no_idb")
#pragma comment(lib, "lzo2d")
#pragma comment(lib, "pcre")
#pragma comment(lib, "pcrecppd")
#pragma comment(lib, "pcred")
#pragma comment(lib, "pcreposixd")
#pragma comment(lib, "python27")
#pragma comment(lib, "shairplay")
#pragma comment(lib, "sqlite3")
#pragma comment(lib, "ssh")
#pragma comment(lib, "ssleay32")
#pragma comment(lib, "tagd")
#pragma comment(lib, "tag_c")
#pragma comment(lib, "tinyxmlSTLd")
#pragma comment(lib, "turbojpeg-staticd")
#pragma comment(lib, "yajl")
#pragma comment(lib, "zlib")
#pragma comment(lib, "zlibstaticd")

#ifdef __cplusplus
extern "C"
#endif
int main(int argc, char* argv[])
{
  // set up some xbmc specific relationships
  XBMC::Context context;

  bool renderGUI = true;
  //this can't be set from CAdvancedSettings::Initialize() because it will overwrite
  //the loglevel set with the --debug flag
#ifdef _DEBUG
  g_advancedSettings.m_logLevel     = LOG_LEVEL_DEBUG;
  g_advancedSettings.m_logLevelHint = LOG_LEVEL_DEBUG;
#else
  g_advancedSettings.m_logLevel     = LOG_LEVEL_NORMAL;
  g_advancedSettings.m_logLevelHint = LOG_LEVEL_NORMAL;
#endif
  CLog::SetLogLevel(g_advancedSettings.m_logLevel);

#ifdef TARGET_POSIX
#if defined(DEBUG)
  struct rlimit rlim;
  rlim.rlim_cur = rlim.rlim_max = RLIM_INFINITY;
  if (setrlimit(RLIMIT_CORE, &rlim) == -1)
    CLog::Log(LOGDEBUG, "Failed to set core size limit (%s)", strerror(errno));
#endif
#endif
  setlocale(LC_NUMERIC, "C");
  g_advancedSettings.Initialize();

  CAppParamParser appParamParser;
  appParamParser.Parse(const_cast<const char**>(argv), argc);
  
  return XBMC_Run(renderGUI, appParamParser.m_playlist);
}
