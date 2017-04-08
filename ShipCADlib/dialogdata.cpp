/*##############################################################################################
 *    ShipCAD
 *    Copyright 2017, by Greg Green <ggreen@bit-builder.com>
 *                                                                                             *
 *    This program is free software; you can redistribute it and/or modify it under            *
 *    the terms of the GNU General Public License as published by the                          *
 *    Free Software Foundation; either version 2 of the License, or (at your option)           *
 *    any later version.                                                                       *
 *                                                                                             *
 *    This program is distributed in the hope that it will be useful, but WITHOUT ANY          *
 *    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A          *
 *    PARTICULAR PURPOSE. See the GNU General Public License for more details.                 *
 *                                                                                             *
 *    You should have received a copy of the GNU General Public License along with             *
 *    this program; if not, write to the Free Software Foundation, Inc.,                       *
 *    59 Temple Place, Suite 330, Boston, MA 02111-1307 USA                                    *
 *                                                                                             *
 *#############################################################################################*/

#include "dialogdata.h"

using namespace ShipCAD;
using namespace std;

InsertPlaneDialogData::InsertPlaneDialogData()
    : accepted(false),
      addControlCurveSelected(false),
      planeSelected(transverse),
      distance(0.0), min(ZERO), max(ZERO)
{
    // does nothing
}

IntersectLayersDialogData::IntersectLayersDialogData()
    : accepted(false), layer1(0), layer2(0)
{
    // does nothing
}

ExtrudeEdgeDialogData::ExtrudeEdgeDialogData()
    : accepted(false), vector(ZERO)
{
    // does nothing
}

ChooseColorDialogData::ChooseColorDialogData(const QString& title, const QColor& initial)
    : accepted(false), title(title), initial(initial), options(QColorDialog::ColorDialogOptions())
{
    // does nothing
}

LayerDialogData::LayerDialogData()
{
    // does nothing
}

ChooseLayerDialogData::ChooseLayerDialogData(vector<SubdivisionLayer*> list_of_layers,
    LayerSelectMode m)
    : accepted(false), mode(m)
{
    for (size_t i=0; i<list_of_layers.size(); i++)
        layers.push_back(make_pair(list_of_layers[i], true));
}

MirrorDialogData::MirrorDialogData(bool connect, plane_selected_t init, float d)
    : accepted(false), connect_points(connect), which_plane(init), distance(d)
{
    // does nothing
}