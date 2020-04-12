/*=============================================================================

  PHAS0100ASSIGNMENT2: PHAS0100 Assignment 2 Social Force Model

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

  VTK based viewer for Social Force Model simulation: 12 Apr 2020
      Author: Jim Dobson

=============================================================================*/

#ifndef sfmVisualiser_h
#define sfmVisualiser_h

#include "vtkSmartPointer.h"

class vtkContextView;
class vtkChartXY;
class vtkTable;
class vtkPlot;

namespace sfm {

class Visualiser {

  public:
    Visualiser(unsigned int n_pedestrians = 0,
                  double world_x = 0., double world_y = 0.);
    ~Visualiser();
    void CreateWorld(unsigned int n_pedestrians, 
		    double width_x, double width_y);
    bool SetPedestrian(unsigned int i,  
		       double xpos, double ypos,
		       double xspeed, double yspeed);
    void UpdateScene();
    void SetWindowScale(double scale);

  private:
    void CreateTable();
    vtkSmartPointer<vtkContextView> m_view;
    vtkSmartPointer<vtkChartXY> m_chart;
    vtkSmartPointer<vtkTable> m_table;
    vtkSmartPointer<vtkPlot> m_points;
    int m_n_pedestrians;
    double m_world_x, m_world_y;
    double m_window_scale; // scale size of window

}; // end class Visualiser

} // end namespace

#endif