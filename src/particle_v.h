/*--------------------------------------------------------------------
REEF3D
Copyright 2008-2023 Hans Bihs

This file is part of REEF3D.

REEF3D is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTIBILITY or
FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, see <http://www.gnu.org/licenses/>.
--------------------------------------------------------------------
Author: Hans Bihs
--------------------------------------------------------------------*/

#include"particle.h"

using namespace std;

#ifndef PARTICLE_V_H_
#define PARTICLE_V_H_

class particle_v : public particle_base
{
public:
    particle_v();
	virtual ~particle_v();

    virtual void start(lexer*,fdm*,ghostcell*,ioflow*);
	virtual void setup(lexer*,fdm*,ghostcell*);
	virtual void correct(lexer*, fdm*, ghostcell*,ioflow*);
	virtual void picardmove(lexer*, fdm*, ghostcell*);
};

#endif

