#if defined(__GNUC__)
#ident "MRC HGU $Id$"
#else
#if defined(__SUNPRO_C) || defined(__SUNPRO_CC)
#pragma ident "MRC HGU $Id$"
#else
static char _ClipPlaneButton_h[] = "MRC HGU $Id$";
#endif
#endif
/*!
* \file         ClipPlaneButton.h
* \author       Zsolt Husz
* \date         July 2009
* \version      $Id$
* \par
* Address:
*               MRC Human Genetics Unit,
*               Western General Hospital,
*               Edinburgh, EH4 2XU, UK.
* \par
* Copyright (C) 2008 Medical research Council, UK.
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
* \brief        Button for clip plane switch
* \ingroup      UI
*
*/

#ifndef CLIPPLANEBUTTON_H
#define CLIPPLANEBUTTON_H

#include <QPushButton>

class ClipPlaneButton : public QPushButton
{
    Q_OBJECT
public:
  typedef enum {ClipOn,ClipOff, ClipOnly} statetype;  /*!< states of the button */

 /*!
  * \ingroup      UI
  * \brief        Constructor
  * \param        parent parent widget
  * \par      Source:
  *               ClipPlaneButton.cpp
  */
  ClipPlaneButton(QWidget *parent);

 /*!
  * \ingroup      UI
  * \brief        Returns the state of the button
  * \param        button state
  * \par      Source:
  *               ClipPlaneButton.cpp
  */
  statetype state() {return m_state;}

protected slots:
 /*!
  * \ingroup      UI
  * \brief        Processes button click
  * \par      Source:
  *               ClipPlaneButton.cpp
  */
  virtual void buttonClicked(bool);

signals:
 /*!
  * \ingroup      UI
  * \brief        Signals button state change
  * \param        state new state
  * \par      Source:
  *               ClipPlaneButton.cpp
  */
  void stateChanged(ClipPlaneButton::statetype state);

protected:
    QIcon m_iconOff;               /*!< icon to remove the plane */
    QIcon m_iconOn;                /*!< icon to use the plane and manipulator */
    QIcon m_iconVisible;           /*!< icon to use the plane but without manipulator */
    statetype m_state;             /*!< current stat of the button */
};

#endif // CLIPPLANEBUTTON_H
