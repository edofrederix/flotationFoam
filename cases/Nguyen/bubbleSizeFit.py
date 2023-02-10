#!/bin/python

import numpy as np
import matplotlib.pyplot as plt
import figStyle as fs
import os, sys
import scipy.special as sps

figSize = 'small'

# Data from Fig. 6 in Nguyen et al., 2006

d = np.array([9.47821e+1, 1.14934e+2, 1.24850e+2, 1.34926e+2, 1.54918e+2, 1.64994e+2, 1.84986e+2, 1.95062e+2, 2.14894e+2, 2.25130e+2, 2.34886e+2])
f = np.array([1.36148e+0, 4.20284e+0, 1.05959e+1, 1.56077e+1, 2.00276e+1, 1.95935e+1, 1.38713e+1, 8.07024e+0, 2.07182e+0, 2.07182e+0, 8.87924e-1])/100.0

# Fit distribution

ai = np.sum(f*np.pi*d**2.0)/np.sum(f)
dm = (np.sum(f*d**3)/np.sum(f))**(1.0/3.0)

print('ai =', ai/1e6, 'mm^2')
print('dm =', dm/1e3, 'mm')

sigmaSqr = -np.log(ai/(np.pi*dm**2))
sigma = np.sqrt(sigmaSqr)

print('sigma =', sigmaSqr**0.5)

dcm = np.sum(f*d)/np.sum(f)
CMD = dcm*np.exp(-1.5*sigmaSqr)
dsm = CMD*np.exp(2.5*sigmaSqr)

print('CMD =', CMD/1e3, 'mm')
print('dsm =', dsm/1e3, 'mm')

# Cumulative distributions

fsum = np.zeros([len(f)])

for i in range(len(f)):

    fsum[i] = np.sum(f[:(i+1)])


fsumln = 0.5*(sps.erf(np.log(d/CMD)/(2**0.5*sigma)) + 1.0)

# Prepare figure

fs.prep(plt, figSize)

fig = plt.figure()

# Plot

plt.plot(d/1e3, fsum, '-o', label='Nguyen et al., 2006')
plt.plot(d/1e3, fsumln, '-o', label='Log-normal fit')

# Style/save

plt.xlabel(r'd [mm]')
plt.ylabel(r'cumulative fraction')

fs.post(fig, figSize, plt.legend())

plt.savefig('bubbleSizeFit.pdf')
