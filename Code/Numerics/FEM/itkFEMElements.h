/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkFEMElements.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2002 Insight Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/


/**
 * \file itkFEMElements.h
 * \brief Include all finite element classes defined in FEM toolkit.
 *
 * To make sure you have everything, just include this header file.
 */
#include "itkFEMElement2DC0LinearLineStress.h"
#include "itkFEMElement2DC1Beam.h"
#include "itkFEMElement2DC0LinearTriangularStress.h"
#include "itkFEMElement2DC0LinearQuadrilateralStress.h"
#include "itkFEMElement3DC0LinearTetrahedronStrain.h"
#include "itkFEMElement3DC0LinearHexahedronStrain.h"
#include "itkFEMElement2DC0QuadraticTriangularStress.h"
