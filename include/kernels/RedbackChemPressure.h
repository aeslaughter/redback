/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef REDBACKCHEMPRESSURE_H
#define REDBACKCHEMPRESSURE_H

#include "Kernel.h"

class RedbackChemPressure;

template<>
InputParameters validParams<RedbackChemPressure>();


class RedbackChemPressure : public Kernel
{
public:
  RedbackChemPressure(const std::string & name, InputParameters parameters);
  virtual ~RedbackChemPressure();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  virtual Real computeQpOffDiagJacobian(unsigned int jvar);

 // VariableValue &_temp;
  MaterialProperty<Real> & _chemical_source_mass;
  MaterialProperty<Real> & _chemical_source_mass_jac;

  unsigned int _temp_var; // variable number of the temperature variable
};


#endif /* REDBACKCHEMPRESSURE_H */
