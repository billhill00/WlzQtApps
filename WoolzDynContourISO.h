#if defined(__GNUC__)
#ident "MRC HGU $Id$"
#else
#if defined(__SUNPRO_C) || defined(__SUNPRO_CC)
#pragma ident "MRC HGU $Id$"
#else
static char _WoolzDynContourISO_h[] = "MRC HGU $Id$";
#endif
#endif
/*!
* \file         WoolzDynContourISO.h
* \author       Zsolt Husz
* \date         June 2009
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
* \brief        Dynamicaly generated contour and ISO Woolz objects
* \ingroup      Control
*
*/
#ifndef WOOLZDYNCONTOURISO_H
#define WOOLZDYNCONTOURISO_H

#include <WoolzDynObject.h>

class ObjectListModel;

#include <Wlz.h>

/*!
 * \brief	Class storing and managing the contour woolz object
 * \ingroup      Control
 */
class WoolzDynContourISO : public WoolzDynObject
{
  Q_OBJECT
public:
 /*!
  * \ingroup      Control
  * \brief        Constructor
  * \return       void
  * \par      Source:
  *                WoolzDynContourISO.cpp
  */
  WoolzDynContourISO(ObjectListModel * objectListModel);

 /*!
  * \ingroup      Control
  * \brief        Destructor
  * \return       void
  * \par      Source:
  *                WoolzDynContourISO.cpp
  */
  virtual ~WoolzDynContourISO();

 /*!
  * \ingroup      Control
  * \brief        Returns notes of the object.
  * \return       Return the "generated" string
  * \par      Source:
  *                WoolzDynContourISO.cpp
  */
  virtual QString notes ( )   {
    return "contour";
  }

 /*!
  * \ingroup      Control
  * \brief        Sets mesh generation distances
  * \param        meshMinDist minimum mesh distance
  * \param        meshMaxDist minimum mesh distance
  * \return       void
  * \par      Source:
  *                WoolzDynContourISO.cpp
  */
  void setValue( unsigned char value) {
    if (m_value != value) {
       m_value = value;
       emit updated(false);
       emit objectPropertyChanged();
   }
  }

 /*!
  * \ingroup      Control
  * \brief        Returns if ISO value
  * \return       true
  * \par      Source:
  *                WoolzDynContourISO.cpp
  */
  unsigned char value() { return  m_value;}

 /*!
  * \ingroup      Control
  * \brief        Sets sub sampling value
  * \param        subsample subsampling value
  * \return       void
  * \par      Source:
  *                WoolzDynContourISO.cpp
  */
  void setSubsample( unsigned char subsample) {
    if (m_subsample != subsample) {
       m_subsample = subsample;
       emit updated(false);
       emit objectPropertyChanged();
   }
  }

 /*!
  * \ingroup      Control
  * \brief        Returns subsample value
  * \return       true
  * \par      Source:
  *                WoolzDynContourISO.cpp
  */
  unsigned char subsample() { return  m_subsample;}

 /*!
  * \ingroup      Control
  * \brief        Sets mesh generation distances
  * \param        boundary true if contour is boundary based
  * \return       void
  * \par      Source:
  *                WoolzDynContourISO.cpp
  */
  void setBoundary( bool boundary) {
    if (m_boundary != boundary) {
       m_boundary = boundary;
       emit updated(false);
       emit objectPropertyChanged();
   }
  }

 /*!
  * \ingroup      Control
  * \brief        Returns if the object is generated by boundary.
  * \return       true
  * \par      Source:
  *                WoolzDynContourISO.cpp
  */
  bool boundary() {return m_boundary;}

 /*!
  * \ingroup      Control
  * \brief        Sets the filtering
  * \param        filter true if filtering is requested
  * \return       void
  * \par      Source:
  *                WoolzDynContourISO.cpp
  */
  void setFilter( bool filter) {
    if (m_filter != filter) {
       m_filter = filter;
       emit updated(false);
       emit objectPropertyChanged();
   }
  }

 /*!
  * \ingroup      Control
  * \brief        Returns if filter is used
  * \return       true
  * \par      Source:
  *                WoolzDynContourISO.cpp
  */
  bool filter() {return m_filter;}

 /*!
  * \ingroup      Control
  * \brief        Sets sell selection
  * \param        selection sells selected (15 shells bit encoded. least semnificative bit is 1st shell, most semnificative bit rest of the shells)
  * \return       void
  * \par      Source:
  *                WoolzDynContourISO.cpp
  */
  void setSelection( int selection) {
    if (m_selection != selection) {
       emit updated(false);
       m_selection = selection;
    }
  }

 /*!
  * \ingroup      Control
  * \brief        Returns the shell selection
  * \return       true
  * \par      Source:
  *                WoolzDynContourISO.cpp
  */
  int selection() { return m_selection;}

 /*!
  * \ingroup      Control
  * \brief        Returns the shell selection
  * \return       number of shells
  * \par      Source:
  *                WoolzDynContourISO.cpp
  */
  int shellno() { return m_shellNo;}

 /*!
  * \ingroup      Control
  * \brief        Recomputes the object by only applying a new shell selection
  * \return       void
  * \par      Source:
  *                WoolzDynContourISO.cpp
  */
  void recomputeShells();

  /*!
  * \ingroup      Control
  * \brief        Saves object details in xml format.
  * \param        xmlWriter output xml stream
  * \return       true if succeded, false if not
  * \par      Source:
  *                WoolzDynContourISO.cpp
  */
  virtual bool saveAsXml(QXmlStreamWriter *xmlWriter);

  /*!
  * \ingroup      Control
  * \brief        Sets up connections to target
  * \param        target connection target
  * \return       void
  * \par      Source:
  *                WoolzDynContourISO.cpp
  */
  virtual void setupConnections(QObject *target);

 /*!
  * \ingroup      Control
  * \brief        Checks without reading the whole file if the object is a Contour
  * \return       true if is a 2D or 3D contour
  * \par      Source:
  *                WoolzFileObject.cpp
  */
  virtual bool isContourPreRead () { return (m_obj== NULL && m_srcObjID!=-1) || isContour();}

 /*!
  * \ingroup      Control
  * \brief        Checks if object parameters changes requiring update
  * \return       true if object needs update
  * \par      Source:
  *                WoolzDynContourISO.cpp
  */
  virtual bool needsUpdate();


protected:
 /*!
  * \ingroup      Control
  * \brief        Replaces a previous mesh with a newly generated mesh.
  * \return       void
  * \par      Source:
  *                WoolzDynContourISO.cpp
  */
  void doUpdate ();

 /*!
  * \ingroup      Control
  * \brief        Saves object details in xml format.
  * \param        xmlWriter output xml stream
  * \return       true if succeded, false if not
  * \par      Source:
  *                WoolzDynContourISO.cpp
  */
  virtual bool saveAsXmlProperties(QXmlStreamWriter *xmlWriter) ;

 /*!
  * \ingroup      Control
  * \brief        Reads current token if known
  * \param        element current element of the DOM tree
  * \return       true if succeded, false if not
  * \par      Source:
  *                WoolzDynContourISO.cpp
  */
  virtual bool parseDOMLine(const QDomElement &element);

private:
 /*!
  * \ingroup      Control
  * \brief        Does the work for shell selection
  * \return       void
  * \par      Source:
  *                WoolzDynContourISO.cpp
  */
  void recomputeShells_intern();

 /*!
  * \ingroup      Control
  * \brief        Computes the contour object
  * \return       void
  * \par      Source:
  *                WoolzDynContourISO.cpp
  */
  void recomputeFullContour();

 /*!
  * \ingroup      Control
  * \brief        Save parameters used for dynamic object
  * \return       void
  * \par      Source:
  *               WoolzDynContourISO.cpp
  */
  virtual void saveUsedParameters();

protected:
  unsigned char m_value;                          /*!< ISO value*/
  bool m_filter;                                  /*!< true if filtering is enabled */
  bool m_boundary;                                /*!< true is boundary based contour is generated, false for ISO contours */
  unsigned char m_subsample;                      /*!< subsampling factor*/
  int m_selection;                                /*!< selected shells*/
  int m_shellNo;                                  /*!< number of shells of the current countour*/
  WlzObject *m_fullContourObject;                 /*!< the full contour object (no shells removed)*/
  const int max_no_checkboxes ;                   /*!< maximum number of checkboxes. should not be altered*/

  unsigned char m_valueUsed;                      /*!< ISO value used in dynamic object*/
  bool m_filterUsed;                              /*!< true if filtering is enabled used in dynamic object*/
  bool m_boundaryUsed;                            /*!< true is boundary based contour is generated, false for ISO contours used in dynamic object*/
  unsigned char m_subsampleUsed;                  /*!< subsampling factor used in dynamic object*/
  int m_selectionUsed;                            /*!< selected shells used in dynamic object*/
 
public:
  static const char * xmlTag;                     /*!< xml section tag string */
};

#endif //WOOLZDYNCONTOURISO_H
