# FlotationFoam

This code accompanies the paper "Simulation of noble metal particle growth and
removal in the molten salt fast reactor" by E.M.A. Frederix and E.M.J. Komen.

## Authors

FlotationFoam is developed by Edo Frederix as was initially part of the
SAMOSAFER H2020 Euroatom project at NRG Pallas, Westerduinweg 3, 1755 LE Petten,
the Netherlands. This project has received funding from the Euratom research and
training program 2019–2023, under grant agreement No. 847527.

## License

FlotationFoam is published under the GNU GPL Version 3 license.

## Prerequisites

* OpenFOAM-13 Foundation version. While it may compile against other versions,
  this is not tested and currently not supported.
* LogMoM: https://github.com/edofrederix/LogMoM

## Usage

* Make sure that OpenFOAM-13 is loaded into your environment
* Download and compile the LogMoM library. The LogMoM library can be found at
  https://github.com/edofrederix/LogMoM
* Compile flotationFoam with

<pre>
./Allwmake
</pre>

* All cases can be run using

<pre>
./prep.sh <args>
foamRun
</pre>

* The prep shell scripts set up the case by configuring the required parameters.
  Some prep shell scripts take optional arguments.
* Some cases can also be run in parallel, with

<pre>
./prep.sh
mpirun -np 4 foamRun -parallel
</pre>

* To reconstruct the results from the paper, use the MSFR2D case with the
  appropriate parameters

## Using flotationFoam in your own OpenFOAM cases

The flotation model is provided as an fvModel. When compiled, it can be
dynamically loaded into your OpenFOAM case by adding

<pre>
libs
(
    "libflotation.so"
);
</pre>

to your case's `system/controlDict` file. Next, you can select the flotation
model by adding

<pre>
flotation
{
    type    flotation;
}
</pre>

to `constant/fvModels`. Parameters are then read from the
`constant/flotationProperties` file. Finally, your case should provide initial
and boundary conditions for the `N.<phase>:<#>` fields for each phase `<phase>`
of the interface to which the flotation model is applied and for each section
number `<#>`. One may also specify a general initial and boundary condition file
that is named `N.<phase>` which is then read for all sections for which no file
with the name `N.<phase>:<#>` exists. See the cases directory for a few
examples.

## Contact & support

For bug reports or support, feel free to contact Edo Frederix at
frederix@nrg.eu. Please note that this code is not maintained nor regularly
updated, and is only tested with OpenFOAM-13. Questions related to other
versions will thus not be answered.

## Disclaimer

FlotationFoam is provided by the copyright holders and contributors "as-is" and
any express or implied warranties, including, but not limited to, the implied
warranties of merchantability and fitness for a particular purpose are
disclaimed. In no event shall the copyright owner or contributors be liable for
any direct, indirect, incidental, special, exemplary, or consequential damages
(including, but not limited to, procurement of substitute goods or services;
loss of use, data, or profits; or business interruption) however caused and on
any theory of liability, whether in contract, strict liability, or tort
(including negligence or otherwise) arising in any way out of the use of this
software, even if advised of the possibility of such damage.
