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
    @file         RouteSelectListPresenter.h
    @defgroup     nkui
*/
/*
    (C) Copyright 2014 by TeleCommunications Systems, Inc.

    The information contained herein is confidential, proprietary to
    TeleCommunication Systems, Inc., and considered a trade secret as defined
    in section 499C of the penal code of the State of California. Use of this
    information by anyone other than authorized employees of TeleCommunication
    Systems is granted only under a written non-disclosure agreement, expressly
    prescribing the scope and manner of such use.
    --------------------------------------------------------------------------
*/

/*! @{ */

#ifndef __NAVIGATIONUIKIT__ROUTESELECTLISTPRESENTER__
#define __NAVIGATIONUIKIT__ROUTESELECTLISTPRESENTER__

#include "PresenterBase.h"
#include "NavApiListeners.h"
#include "RouteSelectListWidget.h"
#include "RouteSelectHeaderWidget.h"

namespace nkui
{
class RouteSelectListPresenter
    : public PresenterBase
    , private nbnav::SessionListener
    , private nbnav::RoutePositionListener
    , private nbnav::TrafficListener
{
public:
    RouteSelectListPresenter();
    virtual ~RouteSelectListPresenter();

    // override PresenterBase
    virtual void HandleEvent(NKEventID id, void* data);

protected:
    virtual void OnActive();
    virtual void OnDeactivate();
    virtual void OnSetWidget();

private:
    // override NKUIEventListener
    virtual void NotifyEvent(NKEventID event, NKUIEventData data);

    // nbnav::SessionListener
    void UpdateRoute(const nbnav::RouteInformation& route);

    // override nbnav::RoutePositionListener
    virtual void ManeuverRemainingDistance(double distance);
    virtual void UpdateManeuverList(const nbnav::ManeuverList& maneuverList);
    virtual void NextRoadName(std::string primaryName, std::string secondaryName);
    virtual void CurrentRoadName(std::string primaryName, std::string secondaryName);

    // override nbnav::TrafficListener
    virtual void TrafficChanged(const nbnav::TrafficInformation& trafficInfo);

    void FormatDestinationManeuverText(char turnCharacter, std::string& text);
    void ShowCurrentRoute();

    RouteSelectListWidget*          m_pListWedget;
    RouteSelectHeaderWidget*        m_prtsHeader;
    std::vector<ManeuverListData>   m_currentManeuvers;
    std::vector<TrafficListData>    m_trafficEvents;
    std::string                     m_currentRoadName;
    std::string                     m_nextRoadName;
    double                          m_currentManeuverDistance;
};
}

#endif /* defined(RouteSelectListPresenter__) */

/*! @} */
