/***************************************************************************
 *   Copyright (C) 2010 by Robert Keevil                                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; under version 2 of the License.         *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.         *
 ***************************************************************************/

#include "app.h"

int main(int argc, char **argv)
{
    app *cli = new app(argc, argv);
    if (!cli->parse_cmd(argc, argv))
        exit(1);
    
    QTranslator translator;
    if (QFile::exists(":/language.qm")) {
        translator.load(":/language");
        cli->installTranslator(&translator);
    }

    // HACK - allows exec() to kick in before run() is called
    // how else are you supposed to get a class setup as a console app in Qt?
    QTimer::singleShot(100, cli, SLOT(run()));

    return cli->exec();
}
