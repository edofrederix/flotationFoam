#include "attachmentModel.H"
#include "flotationSystem.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(attachmentModel, 0);
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::attachmentModel::attachmentModel
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system,
    const bool registerObject,
    const word subTypeName
)
:
    interactionModel
    (
        dict,
        mesh,
        system,
        registerObject,
        typeName,
        subTypeName
    )
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::attachmentModel::~attachmentModel()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField> Foam::attachmentModel::emptyRateField
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
            dimensionedScalar(fieldName, dimVolume/dimTime, 0.0)
        )
    );

    return tfield;
}

// ************************************************************************* //
