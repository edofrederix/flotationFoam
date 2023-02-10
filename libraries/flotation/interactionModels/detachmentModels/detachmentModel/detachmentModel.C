#include "detachmentModel.H"
#include "flotationSystem.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(detachmentModel, 0);
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::detachmentModel::detachmentModel
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

Foam::detachmentModel::~detachmentModel()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField> Foam::detachmentModel::emptyRateField
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
            dimensionedScalar(fieldName, dimless/dimTime, 0.0)
        )
    );

    return tfield;
}

// ************************************************************************* //
