/* This file is part of the KDE Project
   Copyright (c) 2008-2010 Sebastian Trueg <trueg@kde.org>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License version 2 as published by the Free Software Foundation.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#include "fileexcludefilters.h"

namespace {
    const char* s_defaultFileExcludeFilters[] = {
        // tmp files
        "*~",
        "*.part",

        // temporary build files
        "*.o",
        "*.la",
        "*.lo",
        "*.loT",
        "*.moc",
        "moc_*.cpp",
        "cmake_install.cmake",
        "CMakeCache.txt",
        "CTestTestfile.cmake",
        "libtool",
        "config.status",
        "confdefs.h",
        "autom4te",
        "conftest",
        "confstat",
        "Makefile.am",

        // misc
        "*.csproj",
        "*.m4",
        "*.rej",
        "*.gmo",
        "*.pc",
        "*.omf",
        "*.aux",
        "*.tmp",
        "*.po",
        "*.vm*",
        "*.nvram",
        "*.rcore",
        "lzo",
        "litmain.sh",
        "*.orig",
        ".histfile.*",
        ".xsession-errors*",

        // Compiled files
        "*.class", // Java
        "*.pyc",   // Python
        "*.elc",   // Emacs Lisp

        // end of list
        0
    };

    const int s_defaultFileExcludeFiltersVersion = 2;

    const char* s_defaultFolderExcludeFilters[] = {
        "po",

        // VCS
        "CVS",
        ".svn",
        ".git",
        "_darcs",
        ".bzr",
        ".hg",

        // development
        "CMakeFiles",
        "CMakeTmp",
        "CMakeTmpQmake",

        //misc
        "core-dumps",
        "lost+found",

        // end of list
        0
    };

    const int s_defaultFolderExcludeFiltersVersion = 1;

    const char* s_documentMimeTypes[] = {
        "application/pdf",
        "application/vnd.oasis.opendocument.text",
        "application/vnd.oasis.opendocument.spreadsheet",
        "application/vnd.oasis.opendocument.presentation",
        "application/vnd.oasis.opendocument.graphics",
        "application/vnd.ms-excel",
        "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet",
        "application/vnd.ms-powerpoint",
        "application/vnd.openxmlformats-officedocument.presentationml.presentation",
        "application/msword",
        "application/vnd.openxmlformats-officedocument.wordprocessingml.document",

        // end of list
        0
    };
    const int s_documentMimeTypesVersion = 1;

    const char* s_sourceCodeMimeTypes[] = {
        "text/css",
        "text/x-c++src",
        "text/x-c++hdr",
        "text/x-csrc",
        "text/x-chdr", // c header files
        "text/x-python",
        "text/x-assembly",
        "text/x-java",
        "text/x-objsrc",
        "text/x-ruby",
        "text/x-scheme",
        "text/x-pascal",
        "text/x-yacc",
        "text/x-sed",
        "text/x-haskell",
        "text/asp",
        "application/x-awk",
        "application/x-cgi",
        "application/x-csh",
        "application/x-java",
        "application/x-javascript",
        "application/x-perl",
        "application/x-php",
        "application/x-python",
        "application/x-sh",
        "application/x-tex",

        // end of list
        0
    };
    const int s_sourceCodeMimeTypesVersion = 1;
}


QStringList Nepomuk2::defaultExcludeFilterList()
{
    QStringList l;
    for ( int i = 0; s_defaultFileExcludeFilters[i]; ++i )
        l << QLatin1String( s_defaultFileExcludeFilters[i] );
    for ( int i = 0; s_defaultFolderExcludeFilters[i]; ++i )
        l << QLatin1String( s_defaultFolderExcludeFilters[i] );
    return l;
}

int Nepomuk2::defaultExcludeFilterListVersion()
{
    return qMax(s_defaultFileExcludeFiltersVersion, s_defaultFolderExcludeFiltersVersion);
}

QStringList Nepomuk2::documentMimetypes()
{
    QStringList l;
    for( int i = 0; s_documentMimeTypes[i]; i++ )
        l << QLatin1String( s_documentMimeTypes[i] );

    return l;
}

QStringList Nepomuk2::sourceCodeMimeTypes()
{
    QStringList l;
    for( int i = 0; s_sourceCodeMimeTypes[i]; i++ )
        l << QLatin1String( s_sourceCodeMimeTypes[i] );

    return l;
}

QStringList Nepomuk2::defaultExcludeMimetypes()
{
    // By default we want to index everything apart from source code
    return sourceCodeMimeTypes();
}

int Nepomuk2::defaultExcludeMimetypesVersion()
{
    // The +1 is the image, video and audio mimetypes
    return s_documentMimeTypesVersion + s_sourceCodeMimeTypesVersion + 1;
}

