import numpy as np
import os, sys
from scipy.special import erf

b = 1e-10
Nt = 1e9

# ---- Read arguments

if len(sys.argv) != 5:

    print('Invalid number of arguments (should be 4)')
    exit(1)

dMin = float(sys.argv[1])
dMax = float(sys.argv[2])

N = int(sys.argv[3])

phi = float(sys.argv[4])

# ---- Calculate things

# Correlations from preliminary data:

Pi = 0.512*phi**0.7

# Correlations from estimates paper:

dam = np.exp(0.72358712 + 0.72423169*np.log(1/Pi) + 0.02373566*np.log(1/Pi)**2) * b
dcm = np.exp(0.44905228 + 0.30367165*np.log(1/Pi) + 0.02039534*np.log(1/Pi)**2) * b
dmm = np.exp(1.27265681 + 1.56535176*np.log(1/Pi) + 0.03041629*np.log(1/Pi)**2) * b

sigmaSqr = 0.5*np.log(dmm/dam)

CMD = dam*np.exp(-3/2*sigmaSqr)

# ---- Print stuff

print('Pi =', Pi)

print('CMD =', CMD)
print('dcm =', dcm)
print('dam =', dam)
print('dmm =', dmm)

print('sigma =', sigmaSqr**(1/2))

# ---- Compute sectional number concentrations and store

x = np.exp(np.linspace(np.log(dMin), np.log(dMax), N, endpoint=True))
y = np.exp((np.log(x[1:])+np.log(x[:-1]))/2)

y = np.insert(y, 0, 1e-16)
y = np.append(y, 1e-3)

Ns = np.zeros(N)

for i,xi in enumerate(x):

    Ns[i] = \
        0.5*Nt \
      * ( \
            erf( np.log(y[i+1]/CMD)/(2*sigmaSqr)**0.5 ) \
          - erf( np.log(y[i  ]/CMD)/(2*sigmaSqr)**0.5 ) \
        )

np.savetxt('sections.txt', Ns, fmt='%.8e')
