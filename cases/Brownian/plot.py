#!/bin/python

import numpy as np
import matplotlib.pyplot as plt
import figStyle as fs
import os, sys

# Parameters

figSize = 'small'

N0 = 1e4

ds = [1e-9, 2e-9, 4e-9, 8e-9, 1.6e-8, 3.2e-8, 6.4e-8, 1.28e-7, 2.56e-7]

R = 8.314462
kB = 1.380649e-23

Ui = 0.23
alphai = 0.01

T0 = 300
Ma = 28.9
g = -9.81
db = 4e-3

rhoa = 1.0
rhow = 1000.0

mua = 1.86e-5
muw = 7.97e-4

nua = mua/rhoa
nuw = muw/rhow

sigma = 0.07

gamma = rhow/rhoa

# Prepare figure

fs.prep(plt, figSize)

# Plot

data = np.loadtxt('postProcessing/Nfs/0/volFieldValue.dat')

t = data[:,0]

fig = plt.figure('Nf')

ks = np.zeros(len(ds))

for i,d in enumerate(ds):

    Nf = data[:,i+1]

    plt.plot(t/3600, Nf/N0, lw=1.5, label='flotationFoam' if i == 0 else None)

    ks[i] = -np.log(Nf[-1]/N0)/t[-1]

# Analytical solution, based on Mishchuk et al. (2012)

# Bubble rise velocity

r = 1e9
tolerance = 1e-5
v = 0.2
iter = 0
maxIter = 1000
relax = 0.1

while r > tolerance and iter < maxIter:

    Re = abs(v)*db/nuw
    Eo = (rhow-rhoa)*db**2*abs(g)/sigma

    CD = max(24.0*min(1.0+0.15*Re**0.687,3.0),8.0*Eo*Re/(3.0*Eo+12.0))/Re

    tau = rhoa*db**2/(18.0*muw)

    v1 = (1.0-relax)*v + relax*(1.0-gamma)*g*24.0*tau/(CD*Re)

    r = abs((v1-v)/v)
    v = v1

    iter = iter+1

# Flotation rate constants

alpha = Ui*alphai/v
Nb = 6.0*alpha/(np.pi*db**3)

ksa = np.zeros(len(ds))

for i,d in enumerate(ds):

    D = kB*T0/(3.0*np.pi*muw*d)

    Re = abs(v)*db/nuw
    Sc = nuw/D

    Sh = 2.0 + 0.6*Re**0.5*Sc**(1.0/3.0)

    k = np.pi*Sh*D*db*Nb

    ksa[i] = k

    plt.plot(t/3600, np.exp(-k*t), '-ok', markevery=10000, lw=0.5, ms=3, mew=0.25, mec='white', label='Mishchuk et al. (2012)' if i == 0 else None)


# Annotate

for i,d in enumerate(ds):

    j = int(1.0/3.0*len(t)+2.0/3.0*len(t)/(len(ds)+1)*i)

    rot = np.arctan2((data[j+1,i+1]-data[j,i+1])/N0*(t[-1]/3600), (t[j+1]-t[j])/3600)*360/(2.0*np.pi)

    plt.gca().text(t[j]/3600, data[j,i+1]/N0, str(int(d/1e-9)) + " nm", rotation=rot, ha='center', va='center', fontsize=6, bbox=dict(fc='white', ec='none', boxstyle='square,pad=0.1'))

# Plot flotation rates

plt.figure('k')

plt.plot(np.array(ds)*1e9, ks, lw=1.5, label='flotationFoam')
plt.plot(np.array(ds)*1e9, ksa, '-ok', lw=0.5, ms=3, mew=0.25, mec='white', label='Mishchuk et al. (2012)')

# Style/save

fig = plt.figure('Nf');

plt.xlabel(r'$t$ [h]')
plt.ylabel(r'$N_f/N_0$')

fs.post(fig, figSize, plt.legend())

plt.savefig('Nf.pdf')
plt.savefig('Nf.png', dpi=512)

##

fig = plt.figure('k');

plt.xlabel(r'$d$ [nm]')
plt.ylabel(r'$k$ [1/s]')

plt.xscale('log')
plt.yscale('log')

fs.post(fig, figSize, plt.legend())

plt.savefig('k.pdf')
plt.savefig('k.png', dpi=512)
