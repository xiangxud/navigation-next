/*
Copyright (c) 2018, TeleCommunication Systems, Inc.
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
   * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the TeleCommunication Systems, Inc., nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ARE
DISCLAIMED. IN NO EVENT SHALL TELECOMMUNICATION SYSTEMS, INC.BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*!--------------------------------------------------------------------------

    @file     nbstorerequestparameters.h
*/
/*
    (C) Copyright 2011 by TeleCommunication Systems, Inc.             

    The information contained herein is confidential, proprietary 
    to TeleCommunication Systems, Inc., and considered a trade secret as 
    defined in section 499C of the penal code of the State of     
    California. Use of this information by anyone other than      
    authorized employees of TeleCommunication Systems, Inc. is granted only    
    under a written non-disclosure agreement, expressly           
    prescribing the scope and manner of such use.                 

---------------------------------------------------------------------------*/

#ifndef NBSTOREREQUESTPARAMETERS_H
#define NBSTOREREQUESTPARAMETERS_H


#include "paltypes.h"
#include "nbcontext.h"
#include "nbplace.h"
#include "nbmobilecoupons.h"
#include "nbstorerequestinformation.h"
#include "nbsearchfilter.h"
/*!
    @addtogroup nbstorerequestparameters
    @{
*/


/*! @struct NB_StoreRequestParameters
Opaque data structure that defines the parameters of store coupon request
*/
typedef struct NB_StoreRequestParameters NB_StoreRequestParameters;


/*! Create  parameters of store coupon request

@param context NAVBuilder Context Instance
@param searchRegion  Mobile coupon search region. Cannot be NULL.
@param sliceSize  Specifies how many results should be downloaded per download request.
@param parameters On success, a newly created NB_StoreRequestParameters object; NULL otherwise.  A valid object must be destroyed using NB_StoreRequestParametersDestroy()

@return NB_Error
*/
NB_DEC NB_Error NB_StoreRequestParametersCreate(NB_Context* context,
                                                const NB_CouponSearchRegion* searchRegion,
                                                uint32 sliceSize,
                                                NB_StoreRequestParameters** parameters);


/*! Set search filter.

@param parameters A NB_StoreRequestParameters object
@param filter A search filter

@return NB_Error
*/
NB_DEC NB_Error NB_StoreRequestParametersSetSearchFilter(NB_StoreRequestParameters* parameters,
                                                         NB_SearchFilter* filter);

/*! Create parameters for new iteration of store coupon request

@param context NAVBuilder Context Instance
@param information  The information returned from the previous request
@param iterationCommand  The iteration command to perform
@param parameters On success, a newly created NB_StoreRequestParameters object; NULL otherwise.  A valid object must be destroyed using NB_StoreRequestParametersDestroy()
@return NB_Error
*/
NB_DEC NB_Error NB_StoreRequestParametersCreateIteration(NB_Context* context,
                                                         NB_StoreRequestInformation* information,
                                                         NB_IterationCommand iterationCommand,
                                                         NB_StoreRequestParameters** parameters);


/*! Destroy a previously created StoreRequestParameters object

@param parameters A NB_StoreRequestParameters object created with a call to one of the NB_StoreRequestParametersCreate functions
@return NB_Error
*/
NB_DEC NB_Error NB_StoreRequestParametersDestroy(NB_StoreRequestParameters* parameters);


/*! @} */

#endif
