#!/bin/python

import numpy as np
import matplotlib.pyplot as plt
import figStyle as fs
import os, sys

# Parameters

figSize = 'small'

A = np.pi*0.25*0.07**2
H = 0.3
V = A*H

alphaNitro = 0.01
UNitro = 0.03464
Q = UNitro*A*alphaNitro

dsm = 0.00016374

ds = np.array([1e-9, 2e-9, 4e-9, 8e-9, 1.6e-8, 3.2e-8, 6.4e-8, 1.28e-7, 2.56e-7, 5.12e-7, 1.024e-6, 2.048e-6, 4.069e-6, 8.138e-6, 1.6276e-5, 3.2552e-5])

# Prepare figure

fs.prep(plt, figSize)

# Plot

data = np.loadtxt('postProcessing/Nfs/0/volFieldValue.dat')

t = data[:,0]

fig = plt.figure('Nf')

ks = np.zeros(len(ds))

for i,d in enumerate(ds):

    Nf = data[:,i+1]

    plt.plot(t, Nf/Nf[0], lw=1.5, label='flotationFoam' if i == 0 else None)

    ks[i] = -np.log(Nf[-1]/Nf[0])/t[-1]

E = 2.0*dsm*ks*V/(3.0*Q*H)

fig = plt.figure('E')

plt.plot(ds*1e9, E, label='flotationFoam')

dataNguyenS20L = np.loadtxt('data/Nguyen-Snowtex-20L.txt')
dataNguyenSZL = np.loadtxt('data/Nguyen-Snowtex-ZL.txt')
dataNguyenN20 = np.loadtxt('data/Nguyen-Nyasil-20.txt')

fitS20L = np.polyfit(np.log(dataNguyenS20L[:-1,0]), np.log(dataNguyenS20L[:-1,1]), 1)
xS20L = np.log(np.array([dataNguyenS20L[0,0]*0.8, dataNguyenS20L[-1,0]*1.2]))
yS20L = fitS20L[1] + fitS20L[0]*xS20L

plt.plot(np.exp(xS20L), np.exp(yS20L), '--', color='C1')

plt.plot(dataNguyenS20L[:,0], dataNguyenS20L[:,1], 'o', color='C1', mfc="none", label='Nguyen (Snowtex 20L)')
plt.plot(dataNguyenSZL[:,0], dataNguyenSZL[:,1], 's', color='C2', mfc="none", label='Nguyen (Snowtex ZL)')
plt.plot(dataNguyenN20[:,0], dataNguyenN20[:,1], '^', color='C3', mfc="none", label='Nguyen (Nyasil 20)')

# Style/save

fig = plt.figure('Nf');

plt.xlabel(r'$t$ [s]')
plt.ylabel(r'$N_f/N_0$')

fs.post(fig, figSize, plt.legend())

plt.savefig('Nf.pdf')
plt.savefig('Nf.png', dpi=512)

fig = plt.figure('E');

plt.xlabel(r'$d$ [nm]')
plt.ylabel(r'$E$')

plt.xscale('log')
plt.yscale('log')

fs.post(fig, figSize, plt.legend())

plt.savefig('E.pdf')
plt.savefig('E.png', dpi=512)
