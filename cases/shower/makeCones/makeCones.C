#include "argList.H"
#include "fvMesh.H"
#include "volFields.H"

using namespace Foam;
using constant::mathematical::pi;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    argList::validArgs.append("cone radius");
    argList::validArgs.append("floor radius");

    argList::validArgs.append("cone angle");
    argList::validArgs.append("floor angle");

    argList::validArgs.append("cone vertical position");
    argList::validArgs.append("ceiling height");
    argList::validArgs.append("sink depth");

    #include "setRootCase.H"

    const word phaseName(args.argRead<word>(1));

    label arg = 1;

    const scalar Rc = args.argRead<scalar>(arg++);
    const scalar R = args.argRead<scalar>(arg++);

    const scalar coneAngle = args.argRead<scalar>(arg++);
    const scalar floorAngle = args.argRead<scalar>(arg++);

    const scalar Hc = args.argRead<scalar>(arg++);
    const scalar H = args.argRead<scalar>(arg++);
    const scalar Ds = args.argRead<scalar>(arg++);

    Info<< "Rc = " << Rc << endl;
    Info<< "R = " << R << endl;

    Info<< "coneAngle = " << coneAngle << endl;
    Info<< "floorAngle = " << floorAngle << endl;

    Info<< "Hc = " << Hc << endl;
    Info<< "Ds = " << Ds << endl;

    #include "createTime.H"
    #include "createMesh.H"

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

    const pointField& p = mesh.points();
    pointField q(p);

    const scalar tf = Foam::tan(floorAngle/360.0*2.0*pi);
    const scalar tc = Foam::tan(coneAngle/360.0*2.0*pi);

    forAll(q, i)
    {
        const scalar r =
            Foam::sqrt(Foam::sqr(p[i].x()) + Foam::sqr(p[i].y()));

        const scalar h = p[i].z();

        // Conical floor

        if (h < Hc && h >= -1e-8 && r < R)
        {
            q[i].z() = h + tf*(R - r)*(1.0 - h/Hc);
        }

        // Conical sink

        if (h < Hc && r > R)
        {
            q[i].z() = h - tf*(r-R)*(Hc-h-Ds)/(Hc+Ds);
        }

        // Cone

        if (r < Rc && h > Hc+1e-8)
        {
            q[i].z() = h + tc*(Rc - r)*(1.0 - (h-Hc)/(H-Hc));
        }
    }

    mesh.setPoints(q);
    mesh.write();

    Info<< "end" << endl;

    return 0;
}

// ************************************************************************* //