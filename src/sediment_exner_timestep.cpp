/*--------------------------------------------------------------------
REEF3D
Copyright 2008-2021 Hans Bihs

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
--------------------------------------------------------------------*/

#include"sediment_exner.h"
#include"lexer.h"
#include"fdm.h"
#include"ghostcell.h"

void sediment_exner::timestep(lexer* p,fdm* a, ghostcell *pgc)
{
	maxdh=0.0;
    
	SLICELOOP4
	maxdh = MAX(fabs(dh(i,j)),maxdh);	

	
	double localmaxdh = maxdh;
	maxdh=pgc->globalmax(maxdh);
	
	if(p->S15==0)
    p->dtsed=MIN(p->S13, (p->S14*p->DXM)/(fabs(maxdh)>1.0e-15?maxdh:1.0e-15));

    if(p->S15==1)
    p->dtsed=MIN(p->dt, (p->S14*p->DXM)/(fabs(maxdh)>1.0e-15?maxdh:1.0e-15));
    
    if(p->S15==2)
    p->dtsed=p->S13;

    p->dtsed=pgc->timesync(p->dtsed);
	
	if(p->mpirank==0)
	cout<<p->mpirank<<" maxdh: "<<setprecision(4)<<maxdh<<" dtsed: "<<setprecision(4)<<p->dtsed<<endl;
}