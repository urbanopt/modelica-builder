model DCMotor
  Resistor R(R=100);
  Inductor L(L=100);
  VsourceDC DC(f=10);
  Ground G;
  ElectroMechanicalElement EM(k=8, J=10, b=2);
  Inertia load;
equation
  connect(DC.n, R.n);
  connect(R.p, L.n);
  connect(L.p, EM.n);
  connect(EM.p, DC.n);
  connect(DC.n, G.p);
  connect(EM.flange, load.flange);
end DCMotor;
