/****************************************************************/
/* Dirichlet boundary condition to impose displacement in a     */
/* direction transversal to element normal vector, by taking a  */
/* vectorial product of the normal with a given vector          */
/****************************************************************/

#ifndef FUNCTIONDIRICHLETTRANSVERSEBC
#define FUNCTIONDIRICHLETTRANSVERSEBC

#include "PresetNodalBC.h"
#include "FEProblem.h"

//Forward Declarations
class FunctionDirichletTransverseBC;
class Function;

template<>
InputParameters validParams<FunctionDirichletTransverseBC>();

/**
 * Defines a boundary condition that forces the value to be a user specified
 * function at the boundary.
 */
class FunctionDirichletTransverseBC : public PresetNodalBC
{
public:
  FunctionDirichletTransverseBC(const std::string & name, InputParameters parameters);

protected:
  /**
   * Evaluate the function at the current quadrature point and timestep.
   */
  virtual Real computeQpValue();

  /// Function being used for evaluation of this BC
  Function & _func;

  /// Center point to calculate transversal direction for boundary point.
  const RealVectorValue & _center;

  /// Axis of rotation, vector to calculate transversal direction for boundary point.
  const RealVectorValue & _axis;

  /// Direction index (0 for X, 1 for Y, 2 for Z), since we can't really rely on variable name "disp_x"...
  const unsigned int & _dir_index;

  // FEProblem is needed to access the time step.
  FEProblem & _feproblem;
};

#endif /* FUNCTIONDIRICHLETTRANSVERSEBC */
