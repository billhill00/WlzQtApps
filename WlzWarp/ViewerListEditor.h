#if defined(__GNUC__)
#ident "MRC HGU $Id$"
#else
#if defined(__SUNPRO_C) || defined(__SUNPRO_CC)
#pragma ident "MRC HGU $Id$"
#else
static char _ViewerListEditor_h[] = "MRC HGU $Id$";
#endif
#endif
/*!
* \file         ViewerListEditor.h
* \author       Zsolt Husz
* \date         October 2008
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
* \brief        Provides a combo box for viewer selection
* \ingroup      UI
*
*/

#ifndef VIEWERLISTEDITOR_H
#define VIEWERLISTEDITOR_H

#include <QComboBox>
#include <QItemEditorCreatorBase>
#include <QVariant>

class QMdiArea;
class ObjectViewer;

QT_BEGIN_NAMESPACE
class QWidget;
QT_END_NAMESPACE

/*!
* \brief	Combo box widget for viewer selection
* \ingroup      UI
*/
class ViewerListEditor : public QComboBox
{
    Q_OBJECT
    Q_PROPERTY(QVariant viewer READ viewer WRITE setViewer USER true)

public:
 /*!
  * \ingroup      UI
  * \brief        Constructor
  * \param        mdiArea area containing the viewers
  * \param        widget parent widget
  * \return       void
  * \par      Source:
  *                ViewerListEditor.cpp
  */
   ViewerListEditor (QMdiArea * mdiArea , QWidget *widget = 0);

public:
 /*!
  * \ingroup      UI
  * \brief        Return the selected viewer
  * \return       selected viewer
  * \par      Source:
  *                ViewerListEditor.cpp
  */
  QVariant viewer() const;

 /*!
  * \ingroup      UI
  * \brief        Sets the selection
  * \param        viewer container for ObjectViewer* pointer
  * \return       void
  * \par      Source:
  *                ViewerListEditor.cpp
  */
  void setViewer(QVariant viewer);

private:
 /*!
  * \ingroup      UI
  * \brief        Populates combo content
  * \return       void
  * \par      Source:
  *                ViewerListEditor.cpp
  */
  void populateList();
  QMdiArea * m_mdiArea;         /*!< MDI area that provides the list of viewers*/
};

/*!
 * \brief	Item editor for viewer selection used in delegates
 *
 * \ingroup      UI
 */
class ViewerListEditorBase : public QItemEditorCreatorBase
{
public:
 /*!
  * \ingroup      UI
  * \brief        Constructor
  * \param        mdiArea area containing the viewers
  * \param        widget parent widget
  * \return       void
  * \par      Source:
  *                ViewerListEditor.cpp
  */
  ViewerListEditorBase(QMdiArea * mdiArea): m_mdiArea(mdiArea) {}
 /*!
  * \ingroup      UI
  * \brief        Creates a viewer combo box as the editor
  * \param        parent parent widget
  * \return       created widget
  * \par      Source:
  *                ViewerListEditor.cpp
  */
  virtual QWidget * createWidget ( QWidget * parent = 0) const {
      return new ViewerListEditor (m_mdiArea, parent);
  }

 /*!
  * \ingroup      UI
  * \brief        Return the property name
  *
  *               Property is returned by ViewerListEditor.
  *               Empty implementation should be never called.
  * \param        parent parent widget
  * \return       empty array
  * \par      Source:
  *                ViewerListEditor.cpp
  */
  virtual QByteArray valuePropertyName () const {return QByteArray ();}
private:
  QMdiArea * m_mdiArea;     /*!< MDI area that provides the list of viewers*/

};
#endif


