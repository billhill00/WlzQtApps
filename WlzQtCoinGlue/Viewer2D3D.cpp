#if defined(__GNUC__)
#ident "University of Edinburgh $Id$"
#else
static char _Viewer2D3D_cpp[] = "University of Edinburgh $Id$";
#endif
/*!
* \file         Viewer2D3D.cpp
* \author       Zsolt Husz
* \date         October 2008
* \version      $Id$
* \par
* Address:
*               MRC Human Genetics Unit,
*               MRC Institute of Genetics and Molecular Medicine,
*               University of Edinburgh,
*               Western General Hospital,
*               Edinburgh, EH4 2XU, UK.
* \par
* Copyright (C), [2014],
* The University Court of the University of Edinburgh,
* Old College, Edinburgh, UK.
* 
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be
* useful but WITHOUT ANY WARRANTY; without even the implied
* warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
* PURPOSE.  See the GNU General Public License for more
* details.
*
* You should have received a copy of the GNU General Public
* License along with this program; if not, write to the Free
* Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
* Boston, MA  02110-1301, USA.
* \brief        Interface for wrapping both View2D and View3D classes
* \ingroup      UI
*/

#include "Viewer2D3D.h"

void Viewer2D3D::
changeCameraValues(
  SoCamera * camera)
{
  //forward call to superclass
  SoQtFullViewer::changeCameraValues(camera);
}
