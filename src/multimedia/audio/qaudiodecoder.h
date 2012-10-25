/****************************************************************************
**
** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QAUDIODECODER_H
#define QAUDIODECODER_H

#include "qmediaobject.h"
#include "qmediaenumdebug.h"

#include "qaudiobuffer.h"

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

class QAudioDecoderPrivate;
class Q_MULTIMEDIA_EXPORT QAudioDecoder : public QMediaObject
{
    Q_OBJECT
    Q_PROPERTY(QString sourceFilename READ sourceFilename WRITE setSourceFilename NOTIFY sourceChanged)
    Q_PROPERTY(State state READ state NOTIFY stateChanged)
    Q_PROPERTY(QString error READ errorString)
    Q_PROPERTY(bool bufferAvailable READ bufferAvailable NOTIFY bufferAvailableChanged)

    Q_ENUMS(State)
    Q_ENUMS(Error)

public:
    enum State
    {
        StoppedState,
        DecodingState
    };

    enum Error
    {
        NoError,
        ResourceError,
        FormatError,
        AccessDeniedError,
        ServiceMissingError
    };

    QAudioDecoder(QObject *parent = 0);
    ~QAudioDecoder();

    static QtMultimedia::SupportEstimate hasSupport(const QString &mimeType, const QStringList& codecs = QStringList());

    State state() const;

    QString sourceFilename() const;
    void setSourceFilename(const QString &fileName);

    QIODevice* sourceDevice() const;
    void setSourceDevice(QIODevice *device);

    QAudioFormat audioFormat() const;
    void setAudioFormat(const QAudioFormat &format);

    Error error() const;
    QString errorString() const;

    QAudioBuffer read() const;
    bool bufferAvailable() const;

    qint64 position() const;
    qint64 duration() const;

public Q_SLOTS:
    void start();
    void stop();

Q_SIGNALS:
    void bufferAvailableChanged(bool);
    void bufferReady();
    void finished();

    void stateChanged(QAudioDecoder::State newState);
    void formatChanged(const QAudioFormat &format);

    void error(QAudioDecoder::Error error);

    void sourceChanged();

    void positionChanged(qint64 position);
    void durationChanged(qint64 duration);

public:
    virtual bool bind(QObject *);
    virtual void unbind(QObject *);

private:
    Q_DISABLE_COPY(QAudioDecoder)
    Q_DECLARE_PRIVATE(QAudioDecoder)
    Q_PRIVATE_SLOT(d_func(), void _q_stateChanged(QAudioDecoder::State))
    Q_PRIVATE_SLOT(d_func(), void _q_error(int, const QString &))
};

QT_END_NAMESPACE

Q_DECLARE_METATYPE(QAudioDecoder::State)
Q_DECLARE_METATYPE(QAudioDecoder::Error)

Q_MEDIA_ENUM_DEBUG(QAudioDecoder, State)
Q_MEDIA_ENUM_DEBUG(QAudioDecoder, Error)

QT_END_HEADER

#endif  // QAUDIODECODER_H
