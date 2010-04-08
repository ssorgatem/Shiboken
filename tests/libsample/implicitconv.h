/*
 * This file is part of the Shiboken Python Binding Generator project.
 *
 * Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
 *
 * Contact: PySide team <contact@pyside.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * version 2.1 as published by the Free Software Foundation. Please
 * review the following information to ensure the GNU Lesser General
 * Public License version 2.1 requirements will be met:
 * http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
 *
 * As a special exception to the GNU Lesser General Public License
 * version 2.1, the object code form of a "work that uses the Library"
 * may incorporate material from a header file that is part of the
 * Library.  You may distribute such object code under terms of your
 * choice, provided that the incorporated material (i) does not exceed
 * more than 5% of the total size of the Library; and (ii) is limited to
 * numerical parameters, data structure layouts, accessors, macros,
 * inline functions and templates.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 */

#ifndef IMPLICITCONV_H
#define IMPLICITCONV_H

#include "libsamplemacros.h"

class ObjectType;

class LIBSAMPLE_API ImplicitConv
{
public:
    enum CtorEnum {
        CtorNone,
        CtorOne,
        CtorTwo,
        CtorThree,
        CtorObjectTypeReference
    };

    enum ICOverloadedFuncEnum {
        OverFunc_Ii,
        OverFunc_Ib,
        OverFunc_i,
        OverFunc_C
    };

    ImplicitConv() : m_ctorEnum(CtorNone), m_objId(-1), m_value(-1.0) {}
    ImplicitConv(int objId) : m_ctorEnum(CtorOne), m_objId(objId), m_value(-1.0) {}
    ImplicitConv(CtorEnum ctorEnum) : m_ctorEnum(ctorEnum), m_objId(-1), m_value(-1.0) {}
    ImplicitConv(ObjectType&) : m_ctorEnum(CtorObjectTypeReference), m_objId(-1), m_value(-1.0) {}
    ImplicitConv(double value, bool=true) : m_ctorEnum(CtorNone), m_value(value) {}
    ~ImplicitConv() {}

    CtorEnum ctorEnum() { return m_ctorEnum; }
    int objId() { return m_objId; }
    double value() { return m_value; }

    static ImplicitConv implicitConvCommon(ImplicitConv implicit);

    static ImplicitConv implicitConvDefault(ImplicitConv implicit = CtorTwo);

    static ICOverloadedFuncEnum implicitConvOverloading(ImplicitConv implicit, int dummyArg);
    static ICOverloadedFuncEnum implicitConvOverloading(ImplicitConv implicit, bool dummyArg);
    static ICOverloadedFuncEnum implicitConvOverloading(int dummyArg);
    static ICOverloadedFuncEnum implicitConvOverloading(CtorEnum dummyArg);

private:
    CtorEnum m_ctorEnum;
    int m_objId;
    double m_value;
};

#endif // IMPLICITCONV_H
