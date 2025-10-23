#!/bin/python

p = 1e4             # Pressure [Pa]
T = 923.0           # Temperature [K]

sigma = 0.06        # Surface tension [N/m]

rho_salt = 4124     # Salt mass density [kg/m3]

mu_salt = 6.068e-3  # Salt viscosity [kg/(ms)]
mu_gas = 4.6913e-5  # Gas viscosity [kg/(ms)]

M_gas = 4.0         # Gas molar weight [g/mol]

d = 0.1             # Nozzle diameter [m]
U = 5.0             # Injection velocity [m/s]

##

R = 8.3145          # Gas constant [J/(mol K)]
g = 9.81            # Gravity [m/s2]

##

rho_gas = M_gas*1e-3/(R*T)*p

print('rho_gas =', rho_gas, 'kg/m3')

We = rho_gas*U**2*d/sigma

print('Weber number =', We)

Oh = mu_salt/(rho_salt*d*sigma)**0.5

print('Ohnesorge number =', Oh)
