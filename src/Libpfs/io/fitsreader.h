/*
 * This file is a part of Luminance HDR package.
 * ----------------------------------------------------------------------
 * Copyright (C) 2013 Franco Comida
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 * ----------------------------------------------------------------------
 */

//! \brief FITS file format reader
//! \author Franco Comida <fcomida@users.sourceforge.net>

#ifndef PFS_IO_FITSREADER_H
#define PFS_IO_FITSREADER_H

#include <boost/scoped_ptr.hpp>

#include <string>
#include <Libpfs/params.h>
#include <Libpfs/io/framereader.h>
#include <Libpfs/io/ioexception.h>
#include <Libpfs/utils/resourcehandlerstdio.h>

// include windows.h to avoid TBYTE define clashes with fitsio.h
#ifdef Q_OS_WIN
#define _WINSOCKAPI_    // stops windows.h including winsock.h
#include <windows.h>
#endif

#include <CCfits/CCfits>

namespace pfs {
class Frame;

namespace io {

class FitsReader : public FrameReader
{
public:
    FitsReader(const std::string& filename);

    bool isOpen() const
    { return m_file.get(); }

    void open();
    void close();
    void read(Frame &frame, const Params &);

private:
    boost::scoped_ptr<CCfits::FITS> m_file;
};

}   // io
}   // pfs

#endif
