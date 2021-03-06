/*
 * This file is part of the Shiboken Python Binding Generator project.
 *
 * Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
 *
 * Contact: PySide team <contact@pyside.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef PEN_H
#define PEN_H

#include "libsamplemacros.h"
#include "samplenamespace.h"

class LIBSAMPLE_API Color
{
public:
    Color() : m_null(true) {}
    Color(SampleNamespace::InValue arg) : m_null(false) {}
    Color(unsigned int arg) : m_null(false) {}

    bool isNull() const { return m_null; }
private:
    bool m_null;
};

class LIBSAMPLE_API Pen
{
public:
    enum { EmptyCtor, EnumCtor, ColorCtor, CopyCtor };

    Pen() : m_ctor(EmptyCtor) {}
    Pen(SampleNamespace::Option option) : m_ctor(EnumCtor) {}
    Pen(const Color& color) : m_ctor(ColorCtor) {}
    Pen(const Pen& pen) : m_ctor(CopyCtor) {}

    int ctorType() { return m_ctor; }
private:
    int m_ctor;
};

#endif
