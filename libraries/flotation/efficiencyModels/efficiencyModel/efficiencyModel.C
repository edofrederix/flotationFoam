#include "efficiencyModel.H"
#include "flotationSystem.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(efficiencyModel, 0);
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::efficiencyModel::efficiencyModel
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system,
    const bool registerObject,
    const word subTypeName
)
:
    regIOobject
    (
        IOobject
        (
            IOobject::groupName(typeName, subTypeName),
            mesh.time().timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::NO_WRITE,
            registerObject
        )
    ),
    mesh_(mesh),
    system_(system),
    dict_(dict)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::efficiencyModel::~efficiencyModel()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField> Foam::efficiencyModel::emptyEfficiencyField
(
    const Foam::word& fieldName
) const
{
    tmp<volScalarField> tfield
    (
        new volScalarField
        (
            IOobject
            (
                fieldName,
                mesh_.time().timeName(),
                mesh_,
                IOobject::NO_READ,
                IOobject::NO_WRITE
            ),
            mesh_,
            dimensionedScalar(fieldName, dimless, 0.0)
        )
    );

    return tfield;
}

bool Foam::efficiencyModel::writeData(Ostream& os) const
{
    return os.good();
}

Foam::tmp<Foam::volScalarField> Foam::efficiencyModel::clip
(
    const Foam::tmp<Foam::volScalarField> P
) const
{
    const dimensionedScalar zero(P.ref().name(), P.ref().dimensions(), 0.0);
    const dimensionedScalar unity(P.ref().name(), P.ref().dimensions(), 1.0);

    return min(max(P, zero), unity);
}

Foam::tmp<Foam::volScalarField> Foam::efficiencyModel::R
(
    const Foam::label sectionI
) const
{
    return
        system_.distribution()[sectionI]
      / system_.twoPhasePair().dispersed().d();
}

// ************************************************************************* //
