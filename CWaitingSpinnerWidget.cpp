/*
 * waitingspinner.cpp
 *
 *  Created on: 1 de jul de 2019
 *      Author: Leo
 */

// Own includes
#include "CWaitingSpinnerWidget.h"

// Standard includes
#include <cmath>
#include <algorithm>

// Qt includes
#include <QPainter>
#include <QTimer>

CWaitingSpinnerWidget::CWaitingSpinnerWidget(QWidget *parent,
                                           bool centerOnParent,
                                           bool disableParentWhenSpinning)
    : QWidget(parent),
      _centerOnParent(centerOnParent),
      _disableParentWhenSpinning(disableParentWhenSpinning) {
    initialize();
}

CWaitingSpinnerWidget::CWaitingSpinnerWidget(Qt::WindowModality modality,
                                           QWidget *parent,
                                           bool centerOnParent,
                                           bool disableParentWhenSpinning)
    : QWidget(parent, Qt::Dialog | Qt::FramelessWindowHint),
      _centerOnParent(centerOnParent),
      _disableParentWhenSpinning(disableParentWhenSpinning){
    initialize();

    // We need to set the window modality AFTER we've hidden the
    // widget for the first time since changing this property while
    // the widget is visible has no effect.
    setWindowModality(modality);
    setAttribute(Qt::WA_TranslucentBackground);
}

void CWaitingSpinnerWidget::initialize() {
    _color = Qt::black;
    _roundness = 100.0;
    _minimumTrailOpacity = 3.14159265358979323846;
    _trailFadePercentage = 80.0;
    _revolutionsPerSecond = 1.57079632679489661923;
    _numberOfLines = 20;
    _lineLength = 10;
    _lineWidth = 2;
    _innerRadius = 10;
    _currentCounter = 0;
    _isSpinning = false;

    _timer = new QTimer(this);
    connect(_timer, SIGNAL(timeout()), this, SLOT(rotate()));
    updateSize();
    updateTimer();
    hide();
}

void CWaitingSpinnerWidget::paintEvent(QPaintEvent *) {
    updatePosition();
    QPainter painter(this);
    painter.fillRect(this->rect(), Qt::transparent);
    painter.setRenderHint(QPainter::Antialiasing, true);

    if (_currentCounter >= _numberOfLines) {
        _currentCounter = 0;
    }

    painter.setPen(Qt::NoPen);
    for (int i = 0; i < _numberOfLines; ++i) {
        painter.save();
        painter.translate(_innerRadius + _lineLength,
                          _innerRadius + _lineLength);
        qreal rotateAngle =
                static_cast<qreal>(360 * i) / static_cast<qreal>(_numberOfLines);
        painter.rotate(rotateAngle);
        painter.translate(_innerRadius, 0);
        int distance =
                lineCountDistanceFromPrimary(i, _currentCounter, _numberOfLines);
        QColor color =
                currentLineColor(distance, _numberOfLines, _trailFadePercentage,
                                 _minimumTrailOpacity, _color);
        painter.setBrush(color);
        // TODO improve the way rounded rect is painted
        painter.drawRoundedRect(
                    QRect(0, -_lineWidth / 2, _lineLength, _lineWidth), _roundness,
                    _roundness, Qt::RelativeSize);
        painter.restore();
    }
}

void CWaitingSpinnerWidget::start() {
    updatePosition();
    _isSpinning = true;
    show();

    if(parentWidget() && _disableParentWhenSpinning) {
        parentWidget()->setEnabled(false);
    }

    if (!_timer->isActive()) {
        _timer->start();
        _currentCounter = 0;
    }
}

void CWaitingSpinnerWidget::stop() {
    _isSpinning = false;
    hide();

    if(parentWidget() && _disableParentWhenSpinning) {
        parentWidget()->setEnabled(true);
    }

    if (_timer->isActive()) {
        _timer->stop();
        _currentCounter = 0;
    }
}

void CWaitingSpinnerWidget::setNumberOfLines(int lines) {
    _numberOfLines = lines;
    _currentCounter = 0;
    updateTimer();
}

void CWaitingSpinnerWidget::setLineLength(int length) {
    _lineLength = length;
    updateSize();
}

void CWaitingSpinnerWidget::setLineWidth(int width) {
    _lineWidth = width;
    updateSize();
}

void CWaitingSpinnerWidget::setInnerRadius(int radius) {
    _innerRadius = radius;
    updateSize();
}

QColor CWaitingSpinnerWidget::color() {
    return _color;
}

qreal CWaitingSpinnerWidget::roundness() {
    return _roundness;
}

qreal CWaitingSpinnerWidget::minimumTrailOpacity() {
    return _minimumTrailOpacity;
}

qreal CWaitingSpinnerWidget::trailFadePercentage() {
    return _trailFadePercentage;
}

qreal CWaitingSpinnerWidget::revolutionsPersSecond() {
    return _revolutionsPerSecond;
}

int CWaitingSpinnerWidget::numberOfLines() {
    return _numberOfLines;
}

int CWaitingSpinnerWidget::lineLength() {
    return _lineLength;
}

int CWaitingSpinnerWidget::lineWidth() {
    return _lineWidth;
}

int CWaitingSpinnerWidget::innerRadius() {
    return _innerRadius;
}

bool CWaitingSpinnerWidget::isSpinning() const {
    return _isSpinning;
}

void CWaitingSpinnerWidget::setRoundness(qreal roundness) {
    _roundness = std::max(0.0, std::min(100.0, roundness));
}

void CWaitingSpinnerWidget::setColor(QColor color) {
    _color = color;
}

void CWaitingSpinnerWidget::setRevolutionsPerSecond(qreal revolutionsPerSecond) {
    _revolutionsPerSecond = revolutionsPerSecond;
    updateTimer();
}

void CWaitingSpinnerWidget::setTrailFadePercentage(qreal trail) {
    _trailFadePercentage = trail;
}

void CWaitingSpinnerWidget::setMinimumTrailOpacity(qreal minimumTrailOpacity) {
    _minimumTrailOpacity = minimumTrailOpacity;
}

void CWaitingSpinnerWidget::rotate() {
    ++_currentCounter;
    if (_currentCounter >= _numberOfLines) {
        _currentCounter = 0;
    }
    update();
}

void CWaitingSpinnerWidget::updateSize() {
    int size = (_innerRadius + _lineLength) * 2;
    setFixedSize(size, size);
}

void CWaitingSpinnerWidget::updateTimer() {
    _timer->setInterval(1000 / (_numberOfLines * _revolutionsPerSecond));
}

void CWaitingSpinnerWidget::updatePosition() {
    if (parentWidget() && _centerOnParent) {
        move(parentWidget()->width() / 2 - width() / 2,
             parentWidget()->height() / 2 - height() / 2);
    }
}

int CWaitingSpinnerWidget::lineCountDistanceFromPrimary(int current, int primary,
                                                       int totalNrOfLines) {
    int distance = primary - current;
    if (distance < 0) {
        distance += totalNrOfLines;
    }
    return distance;
}

QColor CWaitingSpinnerWidget::currentLineColor(int countDistance, int totalNrOfLines,
                                              qreal trailFadePerc, qreal minOpacity,
                                              QColor color) {
    if (countDistance == 0) {
        return color;
    }
    const qreal minAlphaF = minOpacity / 100.0;
    int distanceThreshold =
            static_cast<int>(ceil((totalNrOfLines - 1) * trailFadePerc / 100.0));
    if (countDistance > distanceThreshold) {
        color.setAlphaF(minAlphaF);
    } else {
        qreal alphaDiff = color.alphaF() - minAlphaF;
        qreal gradient = alphaDiff / static_cast<qreal>(distanceThreshold + 1);
        qreal resultAlpha = color.alphaF() - gradient * countDistance;

        // If alpha is out of bounds, clip it.
        resultAlpha = std::min(1.0, std::max(0.0, resultAlpha));
        color.setAlphaF(resultAlpha);
    }
    return color;
}

