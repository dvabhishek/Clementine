/* This file is part of Clementine.
   Copyright 2012, David Sansome <me@davidsansome.com>

   Clementine is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Clementine is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Clementine.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "filesystemwatcherinterface.h"

#include "qtfslistener.h"

#ifdef Q_OS_DARWIN
#include "macfslistener.h"
#endif

FileSystemWatcherInterface::FileSystemWatcherInterface(QObject* parent)
    : QObject(parent) {}

FileSystemWatcherInterface* FileSystemWatcherInterface::Create(
    QObject* parent) {
  FileSystemWatcherInterface* ret;
#ifdef Q_OS_DARWIN
  ret = new MacFSListener(parent);
#else
  ret = new QtFSListener(parent);
#endif

  ret->Init();
  return ret;
}
