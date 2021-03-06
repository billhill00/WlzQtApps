#if defined(__GNUC__)
#ident "University of Edinburgh $Id$"
#else
static char _MeshDialog_h[] = "University of Edinburgh $Id$";
#endif
/*!
* \file         MeshDialog.h
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
* \brief	Mesh object generation dialog
* \ingroup	UI
*/

#ifndef MESHDDIALOG_H
#define MESHDDIALOG_H

#include <QDialog>
#include <ui_MeshDialog.h>

class QMdiArea;
class QObject;

class ObjectListModel;
class WoolzObject;

/*!
 * \brief	Controler class for setting mesh properties
 * \ingroup	UI
 */
class MeshDialog : public QDialog, public Ui::MeshDialog
{
  Q_OBJECT
  public:
    /*!
     * \ingroup	UI
     * \brief	Constructor
     * \param	parent			parent widget
     * \param   objectListModel
     * \param   useSource
     * \param   is3D
     */
    MeshDialog(QWidget *parent, ObjectListModel *objectListModel,
	bool useSource, bool is3D);

    /*!
     * \ingroup	UI
     * \brief	Returns the selected WoolzObject
     * \return	pointer to the selected WoolzObject
     */
    WoolzObject* getSelected();

  private slots:
    /*!
     * \ingroup	UI
     * \brief	Processes dialog close with accept
     */
    virtual void accept();

  protected:
    QList <WoolzObject*> m_objects;  /*!< list of objects */
};

#endif
