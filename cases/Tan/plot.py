#!/bin/python

import numpy as np
import matplotlib.pyplot as plt
import figStyle as fs
import os, sys

# Parameters

figSize = 'small'

R = 0.006
A = np.pi*R**2
H = 0.26
V = A*H

dsm = 0.001

alphaNitro = 0.01
UNitro = 0.1
Q = UNitro*A*alphaNitro

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

dataTan00 = np.loadtxt('data/Tan-00.txt')
dataTan40 = np.loadtxt('data/Tan-40.txt')
dataTan60 = np.loadtxt('data/Tan-60.txt')

fit00 = np.polyfit(np.log(dataTan00[:-1,0]), np.log(dataTan00[:-1,1]), 1)
fit40 = np.polyfit(np.log(dataTan40[:-1,0]), np.log(dataTan40[:-1,1]), 1)
fit60 = np.polyfit(np.log(dataTan60[:-1,0]), np.log(dataTan60[:-1,1]), 1)

x00 = np.log(np.array([dataTan00[0,0]*0.5, dataTan00[-1,0]*2.0]))
x40 = np.log(np.array([dataTan40[0,0]*0.5, dataTan40[-1,0]*2.0]))
x60 = np.log(np.array([dataTan60[0,0]*0.5, dataTan60[-1,0]*2.0]))

y00 = fit00[1] + fit00[0]*x00
y40 = fit40[1] + fit40[0]*x40
y60 = fit60[1] + fit60[0]*x60

plt.plot(np.exp(x00), np.exp(y00), '--', color='C1')
plt.plot(np.exp(x40), np.exp(y40), '--', color='C2')
plt.plot(np.exp(x60), np.exp(y60), '--', color='C3')

plt.plot(dataTan00[:,0], dataTan00[:,1], '^', color='C1', mfc="none", label=r'Tan et al. ($\theta = 0^\circ$)')
plt.plot(dataTan40[:,0], dataTan40[:,1], '^', color='C2', mfc="none", label=r'Tan et al. ($\theta = 40^\circ$)')
plt.plot(dataTan60[:,0], dataTan60[:,1], '^', color='C3', mfc="none", label=r'Tan et al. ($\theta = 60^\circ$)')

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

#plt.ylim([6e-4, 1.1])

fs.post(fig, figSize, plt.legend())

plt.savefig('E.pdf')
plt.savefig('E.png', dpi=512)
