/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtSvg module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain
** additional rights. These rights are described in the Nokia Qt LGPL
** Exception version 1.0, included in the file LGPL_EXCEPTION.txt in this
** package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at http://www.qtsoftware.com/contact.
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QSVGFONT_P_H
#define QSVGFONT_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include "qpainterpath.h"

#ifndef QT_NO_SVG

#include "qhash.h"
#include "qstring.h"
#include "qsvgstyle_p.h"

QT_BEGIN_NAMESPACE

class QSvgGlyph
{
public:
    QSvgGlyph(QChar unicode, const QPainterPath &path, qreal horizAdvX);
    QSvgGlyph() : m_unicode(0), m_horizAdvX(0) {}

    QChar m_unicode;
    QPainterPath m_path;
    qreal m_horizAdvX;
};


class QSvgFont : public QSvgRefCounted
{
public:
    QSvgFont(qreal horizAdvX);

    void setFamilyName(const QString &name);
    QString familyName() const;

    void setUnitsPerEm(qreal upem);

    void addGlyph(QChar unicode, const QPainterPath &path, qreal horizAdvX = -1);

    void draw(QPainter *p, const QPointF &point, const QString &str, qreal pixelSize, Qt::Alignment alignment) const;
public:
    QString m_familyName;
    qreal m_unitsPerEm;
    qreal m_ascent;
    qreal m_descent;
    qreal m_horizAdvX;
    QHash<QChar, QSvgGlyph> m_glyphs;
};

QT_END_NAMESPACE

#endif // QT_NO_SVG
#endif // QSVGFONT_P_H
