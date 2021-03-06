#if defined(__GNUC__)
#ident "University of Edinburgh $Id$"
#else
static char _LandmarkDragger_h[] = "University of Edinburgh $Id$";
#endif
/*!
* \file         LandmarkDragger.h
* \author       Zsolt Husz
* \date         February 2009
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
* \brief	Dragger superclass
* \ingroup	Controls
*/

#ifndef  LANDMARKDRAGGER_H
#define  LANDMARKDRAGGER_H

#include <Inventor/draggers/SoDragger.h>

/*!
 * \brief	Dragger superclass
 * \ingroup	Controls
 */
class LandmarkDragger : public SoDragger
{
  SO_KIT_HEADER(LandmarkDragger);
  public:

  typedef enum {created=0, off=1, on=2,
                invalid=2} dragger_mode; /*!< Visualisation mode of dragger */

  /*!
   * \ingroup	Controls
   * \brief	Sets the visualisation mode of the dragger.
   * \param	mode			dragger visualisation mode
   */
  virtual void setType(dragger_mode mode);

  /*!
   * \ingroup	Controls
   * \brief	Sets the validity of the dragger
   * \param	valid			true if dragger is valid
   */
  virtual void setValid(bool valid);

  /*!
   * \ingroup	Controls
   * \brief	Sets the size/scaling of the dragger
   * \param	scale			the new scaling factor
   */
  virtual void setScale(float scale = 1.0);
};

#endif  /* LANDMARKDRAGGER_H */
