#ifndef particleTransferModel_H
#define particleTransferModel_H

#include "dictionary.H"
#include "fvMatrix.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

class particleModel;

/*---------------------------------------------------------------------------*\
                         Class particleTransferModel Declaration
\*---------------------------------------------------------------------------*/

class particleTransferModel
{

protected:

    // Protected data

        //- Reference to the particle model
        const particleModel& model_;

public:

    //- Runtime type information
    TypeName("particleTransferModel");


    // Declare run-time constructor selection table

        declareRunTimeSelectionTable
        (
            autoPtr,
            particleTransferModel,
            dictionary,
            (
                const particleModel& model,
                const dictionary& dict
            ),
            (model, dict)
        );


    //- Class used for the read-construction of
    //  PtrLists of particleModel sources
    class iNew
    {
        const particleModel& model_;

    public:

        iNew(const particleModel& model)
        :
            model_(model)
        {}

        autoPtr<particleTransferModel> operator()(Istream& is) const
        {
            word type(is);
            dictionary dict(is);
            return particleTransferModel::New(type, model_, dict);
        }
    };


    // Constructors

        particleTransferModel(const particleModel& model)
        :
            model_(model)
        {}

        autoPtr<particleTransferModel> clone() const
        {
            NotImplemented;
            return autoPtr<particleTransferModel>(nullptr);
        }


    // Selectors

        static autoPtr<particleTransferModel> New
        (
            const word& type,
            const particleModel& model,
            const dictionary& dict
        );


    //- Destructor
    virtual ~particleTransferModel()
    {}


    // Member Functions

        // Return reference to the model
        const particleModel& model() const
        {
            return model_;
        }

        // Return the source term
        virtual tmp<fvScalarMatrix> R(volScalarField& N) const = 0;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
