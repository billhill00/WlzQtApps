#if defined(__GNUC__)
#ident "MRC HGU $Id$"
#else
#if defined(__SUNPRO_C) || defined(__SUNPRO_CC)
#pragma ident "MRC HGU $Id$"
#else
static char _CrossHairDragger_h[] = "MRC HGU $Id$";
#endif
#endif
/*!
* \file         CrossHairDragger.h
* \author       Zsolt Husz
* \date         February 2009
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
* \brief        2D dragger
* \ingroup      Controls
*
*/

#ifndef  CROSSHAIRDRAGGER_H
#define  CROSSHAIRDRAGGER_H

#include "LandmarkDragger.h"

// Inventor includes
#include <Inventor/fields/SoSFVec3f.h>
#include <Inventor/sensors/SoFieldSensor.h>

class SbPlaneProjector;

/*!
 * \brief	2D dragger nodekit
 * \ingroup      Controls
 */
class CrossHairDragger : public LandmarkDragger
{
   SO_KIT_HEADER(CrossHairDragger);

   // Catalog entries for new parts added by this class...
   SO_KIT_CATALOG_ENTRY_HEADER(translator);

   SO_KIT_CATALOG_ENTRY_HEADER(materialSwitch);
   SO_KIT_CATALOG_ENTRY_HEADER(validitySwitch);

   SO_KIT_CATALOG_ENTRY_HEADER(materialPlaced);
   SO_KIT_CATALOG_ENTRY_HEADER(materialActive);
   SO_KIT_CATALOG_ENTRY_HEADER(materialNormal);
   SO_KIT_CATALOG_ENTRY_HEADER(materialInvalid);

   SO_KIT_CATALOG_ENTRY_HEADER(scale);


  public:
 /*!
  * \ingroup      Controls
  * \brief        Constructor
  * \return       void
  * \par      Source:
  *                CrossHairDragger.cpp
  */
   CrossHairDragger();

   SoSFVec3f translation; /*!< Field that will always contain the dragger's position */

 /*!
  * \ingroup      Controls
  * \brief        Initializes the type ID for this dragger node. 
  *
  *               This should be called once after SoInteraction::init().
  * \return       void
  * \par      Source:
  *                CrossHairDragger.cpp
  */
  static void initClass();

 /*!
  * \ingroup      Controls
  * \brief        Sets the size/scaling of the dragger
  * \param        scale the new scaling factor
  * \return       void
  * \par      Source:
  *                CrossHairDragger.cpp
  */
  virtual void setScale(float scale = 1.0);

protected:

   SbPlaneProjector *planeProj; /*!< Planar projector */

 /*!
  * \ingroup      Controls
  * \brief        Dragging callback.
  *
  * Static callback function invoked by SoDragger when the 
  * when mouse button goes down over this dragger
  * \return       void
  * \par      Source:
  *                CrossHairDragger.cpp
  */
   static void startCB(void *, SoDragger *);

 /*!
  * \ingroup      Controls
  * \brief        Dragger moving callback.
  *
  * Static callback function invoked by SoDragger when the 
  * when the mouse drags
  * \return       void
  * \par      Source:
  *                CrossHairDragger.cpp
  */
   static void motionCB(void *, SoDragger *);

 /*!
  * \ingroup      Controls
  * \brief        Dragging mouse button released callback.
  *
  * Static callback function invoked by SoDragger when the 
  * when the mouse button is released
  * \return       void
  * \par      Source:
  *                CrossHairDragger.cpp
  */
   static void finishCB(void *, SoDragger *);

 /*!
  * \ingroup      Controls
  * \brief        Strart drag processing.
  *
  * Invoked by the static callback startCB()
  * functions, do the work of moving the dragger.
  * \return       void
  * \par      Source:
  *                CrossHairDragger.cpp
  */
   void dragStart();

 /*!
  * \ingroup      Controls
  * \brief        Drag processing.
  *
  * Invoked by the static callback startCB()
  * functions, do the work of moving the dragger.
  * \return       void
  * \par      Source:
  *                CrossHairDragger.cpp
  */
   void drag();

 /*!
  * \ingroup      Controls
  * \brief        Drag finished.
  *
  * Invoked by the static callback motionCB()
  * functions, do the work of moving the dragger.
  * \return       void
  * \par      Source:
  *                CrossHairDragger.cpp
  */
   void dragFinish();

   SoFieldSensor *fieldSensor; /*!< watches for changes to the translation field */

 /*!
  * \ingroup      Controls
  * \brief        Field sensor callback.
  *
  * Called when sensor signals change of the field value.
  * \return       void
  * \par      Source:
  *                CrossHairDragger.cpp
  */
   static void fieldSensorCB(void *, SoSensor *);

 /*!
  * \ingroup      Controls
  * \brief        Update translation field
  *
  * This callback updates the translation field when 
  * the dragger is moved.
  * \return       void
  * \par      Source:
  *                CrossHairDragger.cpp
  */
   static void valueChangedCB(void *, SoDragger *);

 /*!
  * \ingroup      Controls
  * \brief        Update translation field
  * \param        onOff connection state
  * \param        doItAlways foreces reconnect, even if state change is not required
  *
  * This will detach/attach the fieldSensor.
  * It is called at the end of the constructor (to attach).
  * and at the start/end of SoBaseKit::readInstance()
  * and on the new copy at the start/end of SoBaseKit::copy()
  * Returns the state of the node when this was called.
  * This callback updates the translation field when 
  * the dragger is moved.
  * \return       state of the node 
  * \par      Source:
  *                CrossHairDragger.cpp
  */
  virtual SbBool setUpConnections( SbBool onOff,
                                SbBool doItAlways = FALSE);

private:

  static const char geomBuffer[]; /*!< inventor model of the dragger */

 /*!
  * \ingroup      Controls
  * \brief        Destructor
  * \return       void
  * \par      Source:
  *                CrossHairDragger.cpp
  */
   ~CrossHairDragger();
};

#endif  /* CROSSHAIRDRAGGER_H */
