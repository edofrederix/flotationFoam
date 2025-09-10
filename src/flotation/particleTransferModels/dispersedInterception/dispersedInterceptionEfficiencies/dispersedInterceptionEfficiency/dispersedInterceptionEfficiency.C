#include "dispersedInterceptionEfficiency.H"
#include "dispersedInterception.H"
#include "particleModel.H"
#include "flotationSystem.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace particleTransferModels
{
    defineTypeNameAndDebug(dispersedInterceptionEfficiency, 0);
    defineRunTimeSelectionTable(dispersedInterceptionEfficiency, dictionary);
}
}

// * * * * * * * * * * * * * Protected Member Functions * * * * * * * * * * *//

void Foam::particleTransferModels::dispersedInterceptionEfficiency::
setInductionTime()
{
    if (!induction_.valid())
    {
        induction_.set
        (
            inductionTime::New
            (
                transfer_,
                dict_.subDict("inductionTime")
            ).ptr()
        );
    }
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleTransferModels::dispersedInterceptionEfficiency::
dispersedInterceptionEfficiency
(
    dispersedInterception& transfer,
    const dictionary& dict
)
:
    transfer_(transfer),
    dict_(dict)
{}

// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::particleTransferModels::dispersedInterceptionEfficiency::
~dispersedInterceptionEfficiency()
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::autoPtr<Foam::particleTransferModels::dispersedInterceptionEfficiency>
Foam::particleTransferModels::dispersedInterceptionEfficiency::New
(
    dispersedInterception& transfer,
    const dictionary& dict
)
{
    word dispersedInterceptionEfficiencyType(dict.lookup("type"));

    Info<< "Selecting dispersedInterceptionEfficiency" << endl;

    dictionaryConstructorTable::iterator cstrIter =
        dictionaryConstructorTablePtr_->find
        (
            dispersedInterceptionEfficiencyType
        );

    if (cstrIter == dictionaryConstructorTablePtr_->end())
    {
        FatalErrorInFunction
            << "Unknown dispersed deposition dispersedInterceptionEfficiency "
            << dispersedInterceptionEfficiencyType << endl << endl
            << "Valid dispersed deposition efficiencies are : " << endl
            << dictionaryConstructorTablePtr_->sortedToc()
            << exit(FatalError);
    }

    return cstrIter()(transfer, dict);
}

Foam::tmp<Foam::volScalarField>
Foam::particleTransferModels::dispersedInterceptionEfficiency::clip
(
    const tmp<volScalarField>& E
) const
{
    const dimensionedScalar zero(dimless, 0.0);
    const dimensionedScalar unity(dimless, 1.0);

    return min(max(E, zero), unity);
}

Foam::tmp<Foam::volScalarField>
Foam::particleTransferModels::dispersedInterceptionEfficiency::R
(
    const volScalarField& N
)
const
{
    label i = Foam::flotationSystem::sectionNum(N);

    return
        transfer_.model().system().distribution()[i]
      / transfer_.interface().dispersed().d();
}

// ************************************************************************* //
