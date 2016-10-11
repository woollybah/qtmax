/*
  Copyright (c) 2009-2013 Bruce A Henderson
 
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
  
  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.
  
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/ 

#ifndef MAX_QT_GRAPHICSBLUREFFECT
#define MAX_QT_GRAPHICSBLUREFFECT

#include "../core.mod/glue.h"
#include <QtCore>
#include <QGraphicsBlurEffect>

class MaxQGraphicsBlurEffect;

extern "C" {

#include <blitz.h>

	void _qt_qgraphicsblureffect_QGraphicsBlurEffect__OnBlurHintsChanged(BBObject * handle, int hints);
	void _qt_qgraphicsblureffect_QGraphicsBlurEffect__OnBlurRadiusChanged(BBObject * handle, double radius);
	void _qt_qgraphicsblureffect_QGraphicsBlurEffect__OnEnabledChanged(BBObject * handle, int value);
	void _qt_qgraphicsblureffect_QGraphicsBlurEffect__draw(BBObject * handle, QPainter * painter);
	MaxQRectF * _qt_qgraphicsblureffect_QGraphicsBlurEffect__boundingRect(BBObject * handle);

	QGraphicsBlurEffect * bmx_qt_qgraphicsblureffect_create(BBObject * handle, QObject * parent);
	int bmx_qt_qgraphicsblureffect_blurhints(QGraphicsBlurEffect * effect);
	double bmx_qt_qgraphicsblureffect_blurradius(QGraphicsBlurEffect * effect);
	void bmx_qt_qgraphicsblureffect_setblurhints(QGraphicsBlurEffect * effect, int hints);
	void bmx_qt_qgraphicsblureffect_setblurradius(QGraphicsBlurEffect * effect, double radius);
	void bmx_qt_qgraphicsblureffect_default_draw(MaxQGraphicsBlurEffect * effect, QPainter * painter);
	MaxQRectF * bmx_qt_qgraphicsblureffect_default_boundingrect(MaxQGraphicsBlurEffect * effect);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQGraphicsBlurEffect : public QGraphicsBlurEffect
{
	Q_OBJECT

public:
	MaxQGraphicsBlurEffect(BBObject * handle, QObject * parent);
	~MaxQGraphicsBlurEffect();

	void defaultDraw(QPainter *painter);
	QRectF defaultBoundingRect() const;
	QRectF boundingRect() const;

protected:
	virtual void draw(QPainter *painter);

private:
	BBObject * maxHandle;

private slots:
	void onBlurHintsChanged(BlurHints hints);
	void onBlurRadiusChanged(qreal radius);
	void onEnabledChanged(bool enabled);

};

#endif
