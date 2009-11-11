#if defined(__GNUC__)
#ident "MRC HGU $Id$"
#else
#if defined(__SUNPRO_C) || defined(__SUNPRO_CC)
#pragma ident "MRC HGU $Id$"
#else
static char _ProjectPropertiesDialog_cpp[] = "MRC HGU $Id$";
#endif
#endif
/*!
* \file         ProjectPropertiesDialog.cpp
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
* \brief        Mesh object generation dialog
* \ingroup      UI
*
*/

//project includes:
#include "ProjectPropertiesDialog.h"
#include "ObjectListModel.h"
#include "ProjectProperties.h"

ProjectPropertiesDialog::ProjectPropertiesDialog(ProjectProperties *projectProperties, QWidget *parent): QDialog(parent), m_projectProperties(projectProperties) {
 setupUi( this );
 lineEditProjectName->setText(m_projectProperties->m_projectName);
}


void ProjectPropertiesDialog::accept() {
  m_projectProperties->m_projectName = lineEditProjectName->text();
  m_projectProperties->m_isNameSet = true;
  QDialog::accept();
}
