/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
class usrAiNode;
class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();
    inline usrAiNode *getNode() { return usrAiNodeRoot; }

    int xRotation() const { return xRot; }
    int yRotation() const { return yRot; }
    int zRotation() const { return zRot; }

public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);
    void setXTransition(double xposition, const char * currentNodeName);
    void setYTransition(double yposition, const char * currentNodeName);
    void setZTransition(double zposition, const char * currentNodeName);

    void setNode() {
        updateGL();
    }


signals:
    void xRotationChanged(double angle);
    void yRotationChanged(double angle);
    void zRotationChanged(double angle);
    void xTransitionChanged(double angle);
    void yTransitionChanged(double angle);
    void zTransitionChanged(double angle);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseDoubleClickEvent(QMouseEvent *);
    void keyPressEvent( QKeyEvent *);

private slots:
    void advanceGears();

private:
    GLuint makeLoadObj();
    GLuint makeGear(const GLfloat *reflectance, GLdouble innerRadius,
                    GLdouble outerRadius, GLdouble thickness,
                    GLdouble toothSize, GLint toothCount);
    void drawGear(GLuint gear, GLdouble dx, GLdouble dy, GLdouble dz,
                  GLdouble angle);
    void normalizeAngle(int *angle);
    float getNearLen();
    void creatBasicNodeTree();
    unsigned int drawGrid(float size, float step);
    void setViewportSub(int x, int y, int width, int height, float nearPlane, float farPlane);
    void setFrustum(float fovY, float aspectRatio, float front, float back,float floatArry[]);
    void setFrustum(float l, float r, float b, float t, float n, float f, float floatArry[]);
    void setModelMat(const char *objname, GLfloat Tx, GLfloat Ty, GLfloat Tz, GLfloat Rx, GLfloat Ry, GLfloat Rz);
    void loadGLTextures(const char *fileName);//载入纹理

    //显示列表
    GLuint gear1;
    GLuint gear2;
    GLuint gear3;
    GLuint axis;


    int xRot;
    int yRot;
    int zRot;
    int gear1Rot;
    float wordx;
    float wordy;
    int wordz;
    float viewNearLen;
    int viewNearLenSteps;
    bool fullscreen; //全屏幕标志
    QPoint lastPos;
    usrAiNode* usrAiNodeRoot;
    GLuint texture[1];
    //float axes[][6];

};

#endif
