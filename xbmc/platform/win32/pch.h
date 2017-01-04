/*
 *      Copyright (C) 2009-2013 Team XBMC
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
#pragma once
#define _CRT_RAND_S
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#if !(defined(_WINSOCKAPI_) || defined(_WINSOCK_H))
#include <winsock2.h>
#endif
#include <windows.h>
#include <mmsystem.h>
#include <TCHAR.H>
#include <locale>
#include <comdef.h>
#define DIRECTINPUT_VERSION 0x0800
#include "DInput.h"
#include "DSound.h"
#ifdef HAS_DX
#include "d3d9.h"
#include "d3d11_1.h"
#include "dxgi.h"
#include "d3dcompiler.h"
#include "directxmath.h"
#include "directxcolors.h" 
#else
#include <d3d9types.h>
#endif
#include <memory>
#pragma comment(lib, "advapi32")
#pragma comment(lib, "DInput8")
#pragma comment(lib, "DSound")
#pragma comment(lib, "DelayImp")
#pragma comment(lib, "Iphlpapi")
#pragma comment(lib, "Gdi32")
#pragma comment(lib, "Mpr")
#pragma comment(lib, "PowrProf")
#pragma comment(lib, "WS2_32")
#pragma comment(lib, "d3d11")
#pragma comment(lib, "dwmapi")
#pragma comment(lib, "dxguid")
#pragma comment(lib, "setupapi")
#pragma comment(lib, "shell32")
#pragma comment(lib, "winmm")
#pragma comment(lib, "yajl")

 // anything below here should be headers that very rarely (hopefully never)
// change yet are included almost everywhere.
/* empty */
