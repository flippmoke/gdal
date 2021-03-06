/*
 * gvartype.c
$Log$
Revision 1.3  2006/02/07 10:17:15  kdejong
Fixed endian compile problem
some rcs issues of Kor, I guess
Checked in by cees (cees@pcraster.nl) on account of Kor

Revision 1.2  2005/10/03 07:23:00  kor
Removed rcs id string

Revision 1.1.1.1  2000/01/04 21:04:44  cees
Initial import Cees

Revision 2.0  1996/05/23 13:16:26  cees
csf2clean

Revision 1.1  1996/05/23 13:11:49  cees
Initial revision

Revision 1.3  1995/11/01 17:23:03  cees
.

 * Revision 1.2  1994/09/05  13:20:54  cees
 * const'ified 2nd arg
 *
 * Revision 1.1  1994/08/26  13:33:23  cees
 * Initial revision
 *
 */
#include "csf.h"
#include "csfimpl.h"

/* perform a simple byte-copy of 8,4,2 or 1 byte (LIBRARY_INTERNAL)
 */
void CsfGetVarType( void *dest, const CSF_VAR_TYPE *src, CSF_CR cellRepr)
{
	switch (LOG_CELLSIZE(cellRepr))  /* 2log size */
	{
		case 3 : ((UINT4 *)dest)[1] = ((const UINT4 *)src)[1];
		         ((UINT4 *)dest)[0] = ((const UINT4 *)src)[0];
			 break;
		case 2 : (*(UINT4 *)dest)    = (*(const UINT4 *)src);
			break;
		case 1 : (*(UINT2 *)dest)    = (*(const UINT2 *)src);
			break;
		default: POSTCOND(LOG_CELLSIZE(cellRepr) == 0);
			 (*(UINT1 *)dest)    = (*(const UINT1 *)src);
	}
}
