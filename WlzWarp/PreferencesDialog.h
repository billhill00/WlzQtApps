#if defined(__GNUC__)
#ident "University of Edinburgh $Id$"
#else
static char _PreferencesDialog_h[] = "University of Edinburgh $Id$";
#endif
/*!
* \file         PreferencesDialog.h
* \author       Zsolt Husz
* \date         September 2009
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
* \brief	Dialog to set UI preferences
* \ingroup	UI
*/

#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H

#include <QDialog>
#include <ui_PreferencesDialog.h>

class QMdiArea;
class ObjectListModel;
class WoolzObject;
class LandmarkModel;
class QObject;

/*!
 * \brief	Dialog for UI properties
 * \ingroup	UI
 */
class PreferencesDialog : public QDialog, public Ui::PreferencesDialog
{
  Q_OBJECT
  public:
    /*!
     * \ingroup	UI
     * \brief	Constructor
     * \param	parent			parent widget
     * \param   objectListModel
     */
    PreferencesDialog(QWidget *parent);

    /*!
     * \ingroup	UI
     * \brief	Return the current snap to fit distance
     * \return	snap to fit distance
     */
    double snapToFitDist() {return(m_snapToFitDist);}

  private slots:
    /*!
     * \ingroup	UI
     * \brief	Processes dialog close with accept
     */
    virtual void accept();

    /*!
     * \ingroup	UI
     * \brief	Processes dialog close with cancel
     */
    virtual void reject();

    /*!
     * \ingroup	UI
     * \brief	Processes apply button press
     */
    virtual void apply();

  private slots:
    /*!
     * \ingroup	UI
     * \brief	Processes basis function change
     */
    void basisFnChanged();

  signals:
    /*!
     * \ingroup	UI
     * \brief	Signals configuration change that has be processed by those
     * 		functionalities using this configuration
     */
    void configurationChanged();
  protected:
    QColor m_origSourceViewerColour;	/*!< source viewer background colour */
    QColor m_origTargetViewerColour;    /*!< target viewer background colour */
    QColor m_origResultViewerColour;    /*!< result viewer background colour */
    float  m_orig2DMarkerSize;          /*!< 2D marker size */
    float  m_orig3DMarkerSize;          /*!< 3D marker size */
    float  m_origSnapToFitDist;         /*!< Snap to fit distance */
    bool   m_origIsIMQ;                 /*!< if is IMQ warping */
    float  m_origDeltaIMQ;              /*!< delta value for IMQ */
    float  m_origDeltaMQ;               /*!< delta value for MQ */
    bool   m_useIMQ;                    /*!< current warping type */
    float  m_deltaIMQ;                  /*!< current delta value for IMQ */
    float  m_deltaMQ;                   /*!< current delta value for MQ */
    float  m_snapToFitDist;             /*!< current snap to fit distance */

};

#endif  //PREFERENCESDIALOG_H
