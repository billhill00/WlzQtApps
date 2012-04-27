#if defined(__GNUC__)
#ident "MRC HGU $Id$"
#else
#if defined(__SUNPRO_C) || defined(__SUNPRO_CC)
#pragma ident "MRC HGU $Id$"
#else
static char _WarperConfig_h[] = "MRC HGU $Id$";
#endif
#endif
/*!
* \file         WarperConfig.h
* \author       Zsolt Husz
* \date         October 2008
* \version      $Id$
* \par
* Address:
*               MRC Human Genetics Unit,
*               Western General Hospital,
*               Edinburgh, EH4 2XU, UK.
* \par
* Copyright (C) 2009 Medical research Council, UK.
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
* \brief        Class to store global data.
* \ingroup      UI
*
*/

#ifndef WARPERCONFIG_H
#define WARPERCONFIG_H

#include <QObject>

class ObjectListModel ;
/*! 
* \brief	Combo box control for selecting a colour.
* \ingroup      Control
*/
class WarperConfig : public QObject
{
  Q_OBJECT
public:
/**
  * \ingroup      Control
  * \brief        Constructor
  * \return       void
  * \par      Source:
  *                WarperConfig.h
  */
  WarperConfig();

/**
  * \ingroup      Control
  * \brief        Returns the global auto update state
  * \return       update sate
  * \par      Source:
  *                WarperConfig.h
  */
  bool globalAutoUpdate() {return m_globalAutoUpdate;}

/**
  * \ingroup      Control
  * \brief        Sets the global auto update state.
  * \return       void
  * \par      Source:
  *                WarperConfig.h
  */
  void setGlobalAutoUpdate(bool newGlobalAutoUpdate);

/**
  * \ingroup      Control
  * \brief        Returns the global warp update state.
  * \return       void
  * \par      Source:
  *                WarperConfig.h
  */
  bool globalWarpUpdate() {return m_globalWarpUpdate;}

/**
  * \ingroup      Control
  * \brief        Sets the global warp update state.
  * \return       update sate
  * \par      Source:
  *                WarperConfig.h
  */
  void setGlobalWarpUpdate(bool newWarpAutoUpdate);

/**
  * \ingroup      Control
  * \brief        Returns the project directory
  * \return       void
  * \par      Source:
  *                WarperConfig.h
  */
  QString projectDir() {return m_strProjectDir;}

/**
  * \ingroup      Control
  * \brief        Sets the project base
  * \param        dir directory to set
  * \return       void
  * \par      Source:
  *                WarperConfig.h
  */
  void setProjectDir(QString dir);

/**
  * \ingroup      Control
  * \brief        Sets the project base from the filename
  * \param        filename file to get the directory from
  * \return       void
  * \par      Source:
  *                WarperConfig.h
  */
  void setProjectDirFromFile(QString filename);

signals:
/**
  * \ingroup      Control
  * \brief        Signals need to update all dynamic objects
  * \return       void
  * \par      Source:
  *                WarperConfig.h
  */
  void updateAll();

/**
  * \ingroup      Control
  * \brief        Signals need to update all warped objects
  * \return       void
  * \par      Source:
  *                WarperConfig.h
  */
  void updateAllWarped();
private:
   bool m_globalAutoUpdate;                 /*!< if enables/disables warping updates*/
   bool m_globalWarpUpdate;                 /*!< if enables/disables updates for all dynamic objects*/
   QString m_strProjectDir;                 /*!< directory of the project*/
};

extern WarperConfig config;

#endif //WARPERCONFIG
