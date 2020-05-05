#include "boundary_conditions/reflect_functions.hpp"
#include "classes/class_Rxns.hpp"
#include "io/io.hpp"
#include "reactions/association/association.hpp"
#include "reactions/association/functions_for_spherical_system.hpp"
#include "reactions/shared_reaction_functions.hpp"
#include <cmath>
#include <iomanip>

void associate(
    int ifaceIndex1, int ifaceIndex2, Molecule& reactMol1, Molecule& reactMol2,
    Complex& reactCom1, Complex& reactCom2, const Parameters& params,
    ForwardRxn& currRxn, std::vector<Molecule>& moleculeList,
    std::vector<MolTemplate>& molTemplateList, std::vector<int>& emptyMolList,
    std::vector<int>& emptyComList, std::map<std::string, int>& observablesList,
    copyCounters& counterArrays, std::vector<Complex>& complexList,
    Membrane& membraneObject, const std::vector<ForwardRxn>& forwardRxns,
    const std::vector<BackRxn>& backRxns)
{
    if (membraneObject.isSphere == true) {
        associate_sphere(ifaceIndex1, ifaceIndex2, reactMol1, reactMol2, reactCom1, reactCom2, params,
            currRxn, moleculeList, molTemplateList, emptyMolList, emptyComList, observablesList,
            counterArrays, complexList, membraneObject, forwardRxns, backRxns);
    } else {
        associate_box(ifaceIndex1, ifaceIndex2, reactMol1, reactMol2, reactCom1, reactCom2, params,
            currRxn, moleculeList, molTemplateList, emptyMolList, emptyComList, observablesList,
            counterArrays, complexList, membraneObject, forwardRxns, backRxns);
    }
}