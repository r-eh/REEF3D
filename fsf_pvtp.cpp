/*--------------------------------------------------------------------
REEF3D
Copyright 2008-2020 Hans Bihs

This file is part of REEF3D.

REEF3D is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, see <http://www.gnu.org/licenses/>.
--------------------------------------------------------------------
--------------------------------------------------------------------*/

#include"fsf_vtp.h"
#include<string>
#include"lexer.h"
#include"fdm.h"
#include"ghostcell.h"

void fsf_vtp::pvtp(lexer* p, fdm* a, ghostcell* pgc)
{
    int num=0;

    if(p->P15==1)
    num = fsfprintcount;

    if(p->P15==2)
    num = p->count;
	
	if(p->P14==0)
	{
    if(num<10)
	sprintf(name,"REEF3D-CFD-FSF-00000%d.pvtp",num);

	if(num<100&&num>9)
	sprintf(name,"REEF3D-CFD-FSF-0000%d.pvtp",num);

	if(num<1000&&num>99)
	sprintf(name,"REEF3D-CFD-FSF-000%d.pvtp",num);

	if(num<10000&&num>999)
	sprintf(name,"REEF3D-CFD-FSF-00%d.pvtp",num);

	if(num<100000&&num>9999)
	sprintf(name,"REEF3D-CFD-FSF-0%d.pvtp",num);

	if(num>99999)
	sprintf(name,"REEF3D-CFD-FSF-%d.pvtp",num);
	}

	if(p->P14==1)
	{
    if(num<10)
	sprintf(name,"./REEF3D_CFD_FSF/REEF3D-CFD-FSF-00000%d.pvtp",num);

	if(num<100&&num>9)
	sprintf(name,"./REEF3D_CFD_FSF/REEF3D-CFD-FSF-0000%d.pvtp",num);

	if(num<1000&&num>99)
	sprintf(name,"./REEF3D_CFD_FSF/REEF3D-CFD-FSF-000%d.pvtp",num);

	if(num<10000&&num>999)
	sprintf(name,"./REEF3D_CFD_FSF/REEF3D-CFD-FSF-00%d.pvtp",num);

	if(num<100000&&num>9999)
	sprintf(name,"./REEF3D_CFD_FSF/REEF3D-CFD-FSF-0%d.pvtp",num);

	if(num>99999)
	sprintf(name,"./REEF3D_CFD_FSF/REEF3D-CFD-FSF-%d.pvtp",num);
	}

	ofstream result;
	result.open(name);

	result<<"<?xml version=\"1.0\"?>"<<endl;
	result<<"<VTKFile type=\"PPolyData\" version=\"0.1\" byte_order=\"LittleEndian\">"<<endl;
	result<<"<PPolyData  GhostLevel=\"0\">"<<endl;


	result<<"<PPoints>"<<endl;
	result<<"<PDataArray type=\"Float32\" NumberOfComponents=\"3\"/>"<<endl;
	result<<"</PPoints>"<<endl;
	
	result<<"<PPointData>"<<endl;
	result<<"<PDataArray type=\"Float32\" Name=\"velocity\" NumberOfComponents=\"3\"/>"<<endl;
	result<<"<PDataArray type=\"Float32\" Name=\"elevation\"/>"<<endl;
	result<<"</PPointData>"<<endl;
	
	result<<"<Polys>"<<endl;
    result<<"<DataArray type=\"Int32\"  Name=\"connectivity\"/>"<<endl;
    ++n;
	result<<"<DataArray type=\"Int32\"  Name=\"offsets\"/>"<<endl;
	++n;
    result<<"<DataArray type=\"Int32\"  Name=\"types\"/>"<<endl;
	result<<"</Polys>"<<endl;

	for(n=0; n<p->M10; ++n)
	{
    piecename(p,a,pgc,n);
    result<<"<Piece Source=\""<<pname<<"\"/>"<<endl;
	}

	result<<"</PPolyData>"<<endl;
	result<<"</VTKFile>"<<endl;

	result.close();
}

void fsf_vtp::piecename(lexer* p, fdm* a,  ghostcell* pgc, int n)
{
    int num=0;


    if(p->P15==1)
    num = fsfprintcount;

    if(p->P15==2)
    num = p->count;

	if(n<9)
	{
		if(num<10)
		sprintf(pname,"REEF3D-CFD-FSF-00000%d-0000%d.vtp",num,n+1);

		if(num<100&&num>9)
		sprintf(pname,"REEF3D-CFD-FSF-0000%d-0000%d.vtp",num,n+1);

		if(num<1000&&num>99)
		sprintf(pname,"REEF3D-CFD-FSF-000%d-0000%d.vtp",num,n+1);

		if(num<10000&&num>999)
		sprintf(pname,"REEF3D-CFD-FSF-00%d-0000%d.vtp",num,n+1);

		if(num<100000&&num>9999)
		sprintf(pname,"REEF3D-CFD-FSF-0%d-0000%d.vtp",num,n+1);

		if(num>99999)
		sprintf(pname,"REEF3D-CFD-FSF-%d-0000%d.vtp",num,n+1);
	}

	if(n<99&&n>8)
	{
		if(num<10)
		sprintf(pname,"REEF3D-CFD-FSF-00000%d-000%d.vtp",num,n+1);

		if(num<100&&num>9)
		sprintf(pname,"REEF3D-CFD-FSF-0000%d-000%d.vtp",num,n+1);

		if(num<1000&&num>99)
		sprintf(pname,"REEF3D-CFD-FSF-000%d-000%d.vtp",num,n+1);

		if(num<10000&&num>999)
		sprintf(pname,"REEF3D-CFD-FSF-00%d-000%d.vtp",num,n+1);

		if(num<100000&&num>9999)
		sprintf(pname,"REEF3D-CFD-FSF-0%d-000%d.vtp",num,n+1);

		if(num>99999)
		sprintf(pname,"REEF3D-CFD-FSF-%d-000%d.vtp",num,n+1);
	}
	if(n<999&&n>98)
	{
		if(num<10)
		sprintf(pname,"REEF3D-CFD-FSF-00000%d-00%d.vtp",num,n+1);

		if(num<100&&num>9)
		sprintf(pname,"REEF3D-CFD-FSF-0000%d-00%d.vtp",num,n+1);

		if(num<1000&&num>99)
		sprintf(pname,"REEF3D-CFD-FSF-000%d-00%d.vtp",num,n+1);

		if(num<10000&&num>999)
		sprintf(pname,"REEF3D-CFD-FSF-00%d-00%d.vtp",num,n+1);

		if(num<100000&&num>9999)
		sprintf(pname,"REEF3D-CFD-FSF-0%d-00%d.vtp",num,n+1);

		if(num>99999)
		sprintf(pname,"REEF3D-CFD-FSF-%d-00%d.vtp",num,n+1);
	}

	if(n<9999&&n>998)
	{
		if(num<10)
		sprintf(pname,"REEF3D-CFD-FSF-00000%d-0%d.vtp",num,n+1);

		if(num<100&&num>9)
		sprintf(pname,"REEF3D-CFD-FSF-0000%d-0%d.vtp",num,n+1);

		if(num<1000&&num>99)
		sprintf(pname,"REEF3D-CFD-FSF-000%d-0%d.vtp",num,n+1);

		if(num<10000&&num>999)
		sprintf(pname,"REEF3D-CFD-FSF-00%d-0%d.vtp",num,n+1);

		if(num<100000&&num>9999)
		sprintf(pname,"REEF3D-CFD-FSF-0%d-0%d.vtp",num,n+1);

		if(num>99999)
		sprintf(pname,"REEF3D-CFD-FSF-%d-0%d.vtp",num,n+1);
	}

	if(n>9998)
	{
		if(num<10)
		sprintf(pname,"REEF3D-CFD-FSF-00000%d-%d.vtp",num,n+1);

		if(num<100&&num>9)
		sprintf(pname,"REEF3D-CFD-FSF-0000%d-%d.vtp",num,n+1);

		if(num<1000&&num>99)
		sprintf(pname,"REEF3D-CFD-FSF-000%d-%d.vtp",num,n+1);

		if(num<10000&&num>999)
		sprintf(pname,"REEF3D-CFD-FSF-00%d-%d.vtp",num,n+1);

		if(num<100000&&num>9999)
		sprintf(pname,"REEF3D-CFD-FSF-0%d-%d.vtp",num,n+1);

		if(num>99999)
		sprintf(pname,"REEF3D-CFD-FSF-%d-%d.vtp",num,n+1);
	}


}
