/**************************************************************************
*   Author <mike@pikeaero.com> Mike Sharkey                               *
*   Copyright (C) 2010 by Pike Aerospace Research Corporation             *
*                                                                         *
*   This program is free software: you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation, either version 3 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
*   This program is distributed in the hope that it will be useful,       *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
*   GNU General Public License for more details.                          *
*                                                                         *
*   You should have received a copy of the GNU General Public License     *
*   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
**************************************************************************/
#include "cdevicelock.h"
#include <fcntl.h>
#include <QFile>
//getpid
#include <sys/types.h>
#include <unistd.h>
#define inherited QObject

/** ***************************************************************************
* @brief Constructor
******************************************************************************/
CDeviceLock::CDeviceLock(const QString& name)
: inherited()
, mName(name)
{
}

/** ***************************************************************************
* @brief Destructor
******************************************************************************/
CDeviceLock::~CDeviceLock()
{
    unlock();
}

/** ***************************************************************************
* @brief Device lock name.
******************************************************************************/
#ifndef Q_OS_WIN32
QString CDeviceLock::lockName()
{
    QString deviceLockName = QString("/var/lock/LCK..") + mName.right( mName.length() - (mName.lastIndexOf('/')>=0?(mName.lastIndexOf('/')+1):0) );
    return deviceLockName;
}
#endif

/** ***************************************************************************
* @brief Test the device lock.
* @return true if device is locked.
******************************************************************************/
bool CDeviceLock::tryLock()
{
#ifdef Q_OS_WIN32
    // ???
    return false;
#else
    QFile fLock( lockName() );
    if ( fLock.exists() )
    {
        return true;
    }
    return false;
#endif
}

/** ***************************************************************************
* @brief Lock the device.
* @return true if the device is locked.
******************************************************************************/
bool CDeviceLock::lock()
{
#ifdef Q_OS_WIN32
    // ???
    return true;
#else
    QFile fLock( lockName() );
    if ( fLock.open(QIODevice::ReadWrite|QIODevice::Truncate) )
    {
        //fLock.write(QString(QString::number(getpid())+"\n").toAscii().data());
        fLock.write(QString(QString::number(getpid())+"\n").toLatin1().data());
        fLock.close();
        return true;
    }
    return false;
#endif
}

/** ***************************************************************************
* @brief Unlock the device.
******************************************************************************/
void CDeviceLock::unlock()
{
#ifdef Q_OS_WIN32
    // ???
#else
    QFile fLock( lockName() );
    if ( fLock.exists() )
    {
        fLock.remove();
    }
#endif
}

