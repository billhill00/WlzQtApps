#if defined(__GNUC__)
#ident "University of Edinburgh $Id$"
#else
static char _main_cpp[] = "University of Edinburgh $Id$";
#endif
/*!
* \file         main.cpp
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
* \brief        Main project file
* \ingroup      UI
*/


// Qt includes
#include <QApplication>

// Inventor (SoQt) includes
#include <Inventor/Qt/SoQt.h>

#include "MainWindow.h"

int 		main(int argc, char *argv[])
{
  QCoreApplication::setOrganizationName("HGU-MRC");
  QCoreApplication::setOrganizationDomain("hgu.mrc.ac.uk");
  QCoreApplication::setApplicationName("Warping Interface");

  QApplication app(argc, argv);
  {
    MainWindow mainWindow;

    SoQt::show(&mainWindow);
    SoQt::mainLoop();
  }

  // this clears up the memmory, usefull for valgrind, but generates
  // "context-bound resources not free'd" warning message
  // Must be called after MainWindow is distroyed, since MainWindow
  // has SoQt/Coin objects
  // 
  // SoQt::done();

  return(0);
}
