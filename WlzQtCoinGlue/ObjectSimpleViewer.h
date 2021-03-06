#if defined(__GNUC__)
#ident "University of Edinburgh $Id$"
#else
static char _ObjectSimpleViewer_h[] = "University of Edinburgh $Id$";
#endif
/*!
* \file         ObjectSimpleViewer.h
* \author	Zsolt Husz
* \date		October 2008
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
* \brief	A basic Woolz object viewer.
* \ingroup	UI
*/

#ifndef OBJECTSIMPLEVIEWER_H
#define OBJECTSIMPLEVIEWER_H

#include <QWidget>
#include "ClipPlaneButtonBiDirection.h"
#include <Inventor/SbLinear.h>

//project objects
class WoolzObject;
class Viewer2D3D;
class ObjectView;
class WarperController;

//Inventor objects
class SoEventCallback;
class SoSeparator;
class SoCamera;
class SoSensor;
class SoNodeSensor;
class SoSFPlane;
class SoClipPlaneManip;
class SoClipPlane;
class SoSwitch;

//Qt objects
class QCloseEvent;
class QDomElement;
class QSlider;

#include <QtXml/QXmlStreamWriter>

/*!
* \ingroup	UI
* \brief	Woolz object viewer class.
*
*		For earch object viewed manages an view that cares of the
*		actual visualisation of the object by generating an Inventor
*		SoSeparator node
*
*		Uses a scene graph:
*		\verbatim
 		  - root
 		      - event callback (mouse events)
 		      - views_root
 			 - view 0
 			 .....
 			 - view n
 		\endverbatim
*/
class ObjectSimpleViewer: public QWidget
{
  Q_OBJECT

  public:
   /*!
    * \ingroup	UI
    * \brief	Constructor
    * \param	is3D			if viewer is for 3D objects
    * \param	isBlending		if mixing control to be generated
    */
    ObjectSimpleViewer(bool is3D, bool isBlending = false);

   /*!
    * \ingroup	UI
    * \brief	Configures the view
    */
    virtual void init();
   /*!
    * \ingroup	UI
    * \brief	Destructor
    */
    virtual ~ObjectSimpleViewer();

   /*!
    * \ingroup	UI
    * \brief	Sets viewer title.
    * \param	title viewer title
    */
    void setWindowTitle(QString title);

   /*!
    * \return	view list
    * \ingroup	UI
    * \brief	Returns view list
    */
    virtual QList <ObjectView*> getViews() {return views;}

   /*!
    * \ingroup	UI
    * \brief	Activates window
    *
    *		Rises window of the viewer and brings it in focus
    */
    void activate();

   /*!
    * \ingroup	UI
    * \brief	Callback function to notify in the camera was replaced.
    * \param	cam 			new camera
    */
    virtual void replacedCamera  (SoCamera * /* cam */) {};

    /*!
    * \return	true if succeded, false if not
    * \ingroup	Control
    * \brief	Saves model in xml format.
    * \param	xmlWriter 		output xml stream
    */
    virtual bool saveAsXml(QXmlStreamWriter *xmlWriter);

   /*!
    * \return	true if succeded, false if not
    * \ingroup	Control
    * \brief	Reads viewer from DOM tree
    * \param	element 		current element of the DOM tree
    */
    virtual bool parseDOM(const QDomElement& element);

   /*!
    * \return	true if succeded, false if not
    * \ingroup	Control
    * \brief	Reads window geometry from DOM node
    * \param	element 		current element of the DOM tree
    */
    bool parseGeometry(const QDomElement &element);

   /*!
    * \return	true if succeded, false if not
    * \ingroup	Control
    * \brief	Reads clip plane information
    * \param	element 		current element of the DOM tree
    */
    bool parseClipPlane(const QDomElement &element);

   /*!
    * \ingroup	Control
    * \brief	Reads a SbVec3f
    * \param	element current element of the DOM tree
    * \return	read vector value
    */
    SbVec3f parseSbVec3f(const QDomElement &element) const;

   /*!
    * \ingroup	Control
    * \brief	Reads views from DOM node
    * \param	element current element of the DOM tree
    * \return	true if succeded, false if not
    */
    bool parseViews(const QDomElement &element);

   /*!
    * \ingroup	Control
    * \brief	Reads current token if known
    * \param	element current element of the DOM tree
    * \return	true if succeded, false if not
    */
    virtual bool parseDOMLine(const QDomElement &/*element*/);

  public slots:
   /*!
    * \ingroup	UI
    * \brief	Adds new object to the viewer.
    *
    *		Adds a new object to the viewer. The object is made visible
    *		in the viewer only if the the viewer is the default viewer
    *		of the object (i.e. this == viewer) 
    *
    * \param	object			object to be added
    * \param	doViewAll 		if true and no view all was done in
    * 					the viewer then it also viewer will
    * 					be adjusted to include all objects
    * \param	previousView 		if not NULL, copies transparency and
    * 					visibility values to the new view
    */
    virtual void addObject(WoolzObject * object, bool doViewAll = true,
                           ObjectView *previousView = NULL);

   /*!
    * \ingroup	UI
    * \brief	Removes all views of an object.
    *
    *
    * \param	object object to be removed
    */
    void removedObject (WoolzObject * object);

    /*!
     * \ingroup UI
     * \brief   Sets alpha
     *
     */
    void alphaChanged(bool alpha);

   /*!
    * \ingroup	UI
    * \brief	Forwards object property change signals.
    */
    void viewPropertyChanged();

   /*!
    * \ingroup	UI
    * \brief	Sets viewer in editing mode.
    */
    void setEditingMode();

   /*!
    * \ingroup	UI
    * \brief	Sets viewer in viwing mode.
    */
    void setViewingMode();

   /*!
    * \ingroup	UI
    * \brief	Switches the viewer editing/viewing modes.
    */
    void switchModes();

   /*!
    * \ingroup	UI
    * \brief	Processes transparency slider change if slider is present
    * \param	transparency 		new transparency
    */
    virtual void transparencyChanged(int /* transparency */) {}

   /*!
    * \ingroup	UI
    * \brief	Processes view type changes. Called by a view when the
    * 		view canot handle its object
    */
    virtual void regerateView();

   /*!
    * \ingroup	UI
    * \brief	Slot processing status update
    * \param	message 		new message
    * \param	timeout 		timeout of the new message
    */
    virtual void stateChanged(ClipPlaneButton::statetype state);

   /*!
    * \ingroup	UI
    * \brief	Sets the background colour of the viewer
    */
    virtual void setBackgroundColour();

   /*!
    * \return	activation action
    * \ingroup	UI
    * \brief	Returns action for activating viewer
    */
    QAction * activateAction() const {return m_activateAction;}

   /*!
    * \ingroup	UI
    * \brief	Processes the blink button state change
    * \param	on			set on if true
    */
    virtual void setFlashSourceTarget(bool on);

   /*!
    * \return	clip plane used in the viewer
    * \ingroup	UI
    * \brief	Return the clip plane of the viewer
    */
    SoClipPlaneManip * clipPlaneManip() {return m_clipPlaneManip;}

  protected:
   /*!
    * \ingroup	UI
    * \brief	Handler for viewer closing.
    *
    *		Frees all viewes and additional allocated memory.
    */
    void closeEvent(QCloseEvent * /* event */);

   /*!
    * \return	100 is transparent, 0 if not
    * \ingroup	UI
    * \brief	Returns the default object transparency.
    * \param	object 			the new object
    */
    virtual int initialTransparency(WoolzObject * /*object*/) { return  0;}

   /*!
    * \ingroup	UI
    * \brief	Static event handler for camera mouse events.
    *
    *		Callback for mouse events .
    */
    virtual void notifyMouseEvent(SoEventCallback * event);

   /*!
    * \return	new view created
    * \ingroup	Views
    * \brief	Method generating the subclass coresponding to a Woolz object
    * \param	parent 			parent viewer
    * \param	object 			Woolz object to be visualised
    */
    ObjectView * Factory(QObject * parent, WoolzObject *object);

   /*!
    * \return	true if viewer accepts object, false otherwise
    * \ingroup	UI
    * \brief	Checks if viewer accepts object.
    */
    virtual bool accepting(WoolzObject * object) {return(object != NULL);}

   /*!
    * \return	colour
    * \ingroup	UI
    * \brief	Returns the background colour of the viewer
    *
    *		Reimplemented form ObjectViewer
    */
    virtual QColor getBackgroundColour();

  private:
   /*!
    * \ingroup	UI
    * \brief	Static event handler for camera mouse events.
    *
    *		Calls notifyCameraChanged().
    */
    static void mouseEventCB(void *data, SoEventCallback * event);

  signals:
   /*!
    * \ingroup	UI
    * \brief	Signals peparation of removing the viewer.
    */
    void removedViewerStart();

   /*!
    * \ingroup	UI
    * \brief	Signals finished viewer removal.
    *
    *		Called from destructor.
    */
    void removedViewerFinished();

   /*!
    * \ingroup	UI
    * \brief	Signals changed viewer
    */
    void changedViewer();

   /*!
    * \ingroup	UI
    * \brief	Notifies changed viewer
    * \param	viewer 			the change viewer
    */
    void changedObjectView(ObjectView * viewer);

   /*!
    * \ingroup	UI
    * \brief	Notifies added view
    * \param	view 			added view
    */
    void addedView(ObjectView * view);

   /*!
    * \ingroup	UI
    * \brief	Notifies a view removal start
    * \param	view 			removed view
    */
    void removedViewStart(ObjectView * view);

   /*!
    * \ingroup	UI
    * \brief	Notifies a view removal finish
    * \param	view 			removed view
    */
    void removedViewFinish(ObjectView * view);

   /*!
    * \ingroup	UI
    * \brief	Notifies changed camera
    */
    void cameraChanged();

   /*!
    * \ingroup	  UI
    * \brief	  Notifies cretion of clip plane
    */
    void addedClipPlane(SoClipPlane * plane);

  protected:

    // protected attributes
    Viewer2D3D * m_viewer;	    	/*!< Inventor viewer that performs
    					     the viewing */
    SoSeparator *root;		    	/*!< secene grapg root */
    SoSeparator *views_root_s;	    	/*!< views root source views */
    SoSeparator *views_root_t;	    	/*!< views root target views */
    SoSwitch *blinker_root;	    	/*!< blinker root allowing switching
    					     blink on / off */
    QList <ObjectView *> views;	    	/*!< list of views */

    QAction * m_activateAction ;	/*!< action with the name of the
    					     window */
    SoClipPlaneManip *m_clipPlaneManip;	/*!< clip plane manipulator*/
    SoClipPlane *m_clipPlane;		/*!< clip plane */
    ClipPlaneButtonBiDirection *m_clipManipulatorButtonBi; /*!< clip
                                             manipulator button */
    QPushButton * m_obliqueSliceButton;	/*!< oblique slice button */
    QPushButton * m_clipLandmarkButton;	/*!< landmark clipping button */	 //TODO: move from child class
    QPushButton * m_blinkButton;	/*!< blinking button */	//TODO: move from child class
    QSlider *m_mixSlider;		/*!< mixing slider */
    bool m_viewAll;			/*!< if true, after an object is
    					     inserted viewAll() is called to
					     change to view all object in the
					     viewer */
};
#endif // OBJECTSIMPLEVIEWER_H
