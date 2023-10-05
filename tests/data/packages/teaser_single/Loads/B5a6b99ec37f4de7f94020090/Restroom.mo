
within teaser_single.Loads.B5a6b99ec37f4de7f94020090;
model Restroom
  "This is the simulation model of Restroom within building B5a6b99ec37f4de7f94020090 with traceable ID None"


  parameter String filNam="modelica://teaser_single/Loads/Resources/Data/B5a6b99ec37f4de7f94020090/InternalGains_Restroom.txt" "modelica path to the internal gains file used in the model CombiTimeTable";

  parameter Integer nPorts=0 "Number of fluid ports." annotation(connectorSizing=true);

  parameter Boolean use_moisture_balance=false "If true, input connector QLat_flow is enabled and room air computes moisture balance.";

  parameter Real fraLat=1.25 "Fraction latent of sensible persons load = 0.8 for home, 1.25 for office.";

  Buildings.BoundaryConditions.SolarIrradiation.DiffusePerez HDifTil[4](    each outSkyCon=true,
    each outGroCon=true,
    til={1.5707963267948966, 1.5707963267948966, 1.5707963267948966, 1.5707963267948966}
    ,
    azi = {0.0, 1.5707963267948966, -1.5707963267948966, 3.141592653589793})
    "Calculates diffuse solar radiation on titled surface for all directions"
    annotation (Placement(transformation(extent={{-68,20},{-48,40}})));
  Buildings.BoundaryConditions.SolarIrradiation.DirectTiltedSurface HDirTil[4](    til={1.5707963267948966, 1.5707963267948966, 1.5707963267948966, 1.5707963267948966}
    ,
    azi={0.0, 1.5707963267948966, -1.5707963267948966, 3.141592653589793})
    "Calculates direct solar radiation on titled surface for all directions"
    annotation (Placement(transformation(extent={{-68,52},{-48,72}})));
  Buildings.ThermalZones.ReducedOrder.SolarGain.CorrectionGDoublePane corGDoublePane(n=4,  UWin=1.8936557576825384)
    "Correction factor for solar transmission"
    annotation (Placement(transformation(extent={{6,54},{26,74}})));
  Buildings.ThermalZones.ReducedOrder.RC.FourElements
  thermalZoneFourElements(
    redeclare package Medium = Buildings.Media.Air,
    VAir=1712.2268419200004,
    hConExt=2.6999999999999997,
    hConWin=2.7000000000000006,
    gWin=0.6700000000000002,
    ratioWinConRad=0.030000000000000002,
    nExt=1,
    RExt={0.0003491199216114175},
    CExt={32872731.06618568},
    hRad=4.999999999999999,
    AInt=1680.5189374400004,
    hConInt=2.5490566037735847,
    nInt=1,
    RInt={5.301308905050724e-05},
    CInt={141556948.13576505},
    RWin=0.013742118823297953,
    RExtRem=0.0230951892746168,
    AFloor=72.92818030400002,
    hConFloor=1.7000000000000002,
    nFloor=1,
    RFloor={0.00031714253151434287},
    RFloorRem=0.021687546164576507,
    CFloor={5867018.816562118},
    ARoof=72.92818030400002,
    hConRoof=1.7000000000000002,
    nRoof=1,
    RRoof={0.0003261851139741062},
    RRoofRem=0.026473296873515656,
    CRoof={26681729.10514989},
    energyDynamics=Modelica.Fluid.Types.Dynamics.FixedInitial,
    extWallRC(thermCapExt(each der_T(fixed=true))),
    intWallRC(thermCapInt(each der_T(fixed=true))),
    floorRC(thermCapExt(each der_T(fixed=true))),
    roofRC(thermCapExt(each der_T(fixed=true))),
    nOrientations=4,
    AWin={11.92763144924453, 1.1056190934805288, 1.1056190934805288, 11.92763144924453},
    ATransparent={11.92763144924453, 1.1056190934805288, 1.1056190934805288, 11.92763144924453},
    AExt={35.782894347733595, 3.316857280441586, 3.316857280441586, 35.782894347733595}, nPorts=nPorts, use_moisture_balance=use_moisture_balance)
    "Thermal zone"
    annotation (Placement(transformation(extent={{44,-2},{92,34}})));
  Buildings.ThermalZones.ReducedOrder.EquivalentAirTemperature.VDI6007WithWindow eqAirTemp(
    n=4,
    wfGro=0.0,
    wfWall={0.45758467583140006, 0.04241532416859992, 0.04241532416859992, 0.45758467583140006},
    wfWin={0.45758467583140006, 0.04241532416859994, 0.04241532416859994, 0.45758467583140006},
    withLongwave=true,
    aExt=0.5,
    hConWallOut=19.999999999999996,
    hRad=4.999999999999999,
    hConWinOut=20.0,
    TGro=286.15) "Computes equivalent air temperature"
    annotation (Placement(transformation(extent={{-24,-14},{-4,6}})));
  Modelica.Blocks.Math.Add solRad[4]
    "Sums up solar radiation of both directions"
    annotation (Placement(transformation(extent={{-38,6},{-28,16}})));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedTemperature prescribedTemperature
    "Prescribed temperature for exterior walls outdoor surface temperature"
    annotation (Placement(transformation(extent={{8,-6},{20,6}})));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedTemperature prescribedTemperature1
    "Prescribed temperature for windows outdoor surface temperature"
    annotation (Placement(transformation(extent={{8,14},{20,26}})));
  Modelica.Thermal.HeatTransfer.Components.Convection thermalConductorWin
    "Outdoor convective heat transfer of windows"
    annotation (Placement(transformation(extent={{38,16},{28,26}})));
  Modelica.Thermal.HeatTransfer.Components.Convection thermalConductorWall
    "Outdoor convective heat transfer of walls"
    annotation (Placement(transformation(extent={{36,6},{26,-4}})));
  Modelica.Blocks.Sources.Constant const[4](each k=0)
    "Sets sunblind signal to zero (open)"
    annotation (Placement(transformation(extent={{-20,14},{-14,20}})));
  Buildings.BoundaryConditions.WeatherData.Bus weaBus "Weather data bus"
    annotation (Placement(
    transformation(extent={{-100,-10},{-66,22}}),iconTransformation(
    extent={{-70,-12},{-50,8}})));
  Modelica.Blocks.Sources.Constant alphaWall(k=24.999999999999996*78.19950325635037)
    "Outdoor coefficient of heat transfer for walls"
    annotation (Placement(
    transformation(
    extent={{-4,-4},{4,4}},
    rotation=90,
    origin={30,-16})));
  Modelica.Blocks.Sources.Constant hConvWin(k=24.999999999999996*26.066501085450113)
    "Outdoor coefficient of heat transfer for windows"
    annotation (Placement(
    transformation(
    extent={{4,-4},{-4,4}},
    rotation=90,
    origin={32,38})));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow personsRad
    "Radiative heat flow of persons"
    annotation (Placement(transformation(extent={{48,-42},{68,-22}})));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow personsConv
    "Convective heat flow of persons"
    annotation (Placement(transformation(extent={{48,-62},{68,-42}})));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow machinesConv
    "Convective heat flow of machines"
    annotation (Placement(transformation(extent={{48,-84},{68,-64}})));
  Modelica.Blocks.Sources.CombiTimeTable internalGains(
    tableOnFile=true,
    extrapolation=Modelica.Blocks.Types.Extrapolation.Periodic,
    tableName="Internals",
    fileName=Modelica.Utilities.Files.loadResource(filNam),
    columns={2,3,4})
    "Table with profiles for persons (radiative and convective) and machines (convective)"
    annotation (Placement(transformation(extent={{6,-60},{22,-44}})));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedTemperature prescribedTemperatureFloor
    "Prescribed temperature for floor plate outdoor surface temperature"
    annotation (Placement(transformation(
    extent={{-6,-6},{6,6}},
    rotation=90,
    origin={67,-12})));
  Modelica.Blocks.Sources.Constant TSoil(k=286.15)
    "Outdoor surface temperature for floor plate"
    annotation (
    Placement(transformation(
    extent={{-4,-4},{4,4}},
    rotation=180,
    origin={84,-22})));

  Buildings.ThermalZones.ReducedOrder.EquivalentAirTemperature.VDI6007 eqAirTempVDI(
    aExt=0.5,
    wfGro=0,
    hConWallOut=20.000000000000004,
    hRad=5.0,
    n=1,
    wfWall={1.0},
    wfWin={0},
    TGro=285.15) "Computes equivalent air temperature for roof"
    annotation (Placement(transformation(extent={{30,34},{50,54}})));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedTemperature prescribedTemperatureRoof
    "Prescribed temperature for roof outdoor surface temperature"
    annotation (Placement(transformation(extent={{-6,-6},{6,6}},rotation=-90,
    origin={67,44})));
  Modelica.Thermal.HeatTransfer.Components.Convection thermalConductorRoof
    "Outdoor convective heat transfer of roof"
    annotation (Placement(transformation(extent={{5,-5},{-5,5}},rotation=-90,
    origin={67,27})));
  Modelica.Blocks.Sources.Constant hConvRoof(k=1823.204507600001)
    "Outdoor coefficient of heat transfer for roof"
    annotation (Placement(transformation(extent={{4,-4},{-4,4}},rotation=0,
    origin={86,27})));
  Modelica.Blocks.Sources.Constant const1[1](each k=0)
    "Sets sunblind signal to zero (open)" annotation (Placement(transformation(
        extent={{3,-3},{-3,3}},
        rotation=90,
        origin={40,71})));
  Modelica.Blocks.Math.Add solRadRoof[1]
    "Sums up solar radiation of both directions"
    annotation (Placement(transformation(extent={{4,76},{14,86}})));
  Buildings.BoundaryConditions.SolarIrradiation.DirectTiltedSurface HDirTilRoof[1](    til={0.0}
    ,
    azi={0.0})
    "Calculates direct solar radiation on titled surface for both directions"
    annotation (Placement(transformation(extent={{-68,74},{-48,94}})));
  Buildings.BoundaryConditions.SolarIrradiation.DiffusePerez HDifTilRoof[1](    til={0.0}
    ,
    azi={0.0})
    "Calculates diffuse solar radiation on titled surface for both directions"
    annotation (Placement(transformation(extent={{-68,48},{-48,68}})));
  Buildings.Controls.OBC.CDL.Interfaces.RealOutput TAir(quantity="ThermodynamicTemperature", unit="K", displayUnit="degC") if thermalZoneFourElements.VAir > 0 "Room air temperature" annotation(Placement(transformation(extent={{100,38},{120,58}})));

  Buildings.Controls.OBC.CDL.Interfaces.RealOutput TRad(quantity="ThermodynamicTemperature", unit="K", displayUnit="degC") "Mean indoor radiation temperature" annotation(Placement(transformation(extent={{100,-10},{120,10}})));

  Modelica.Blocks.Sources.RealExpression perLatLoa(y=internalGains.y[2]*fraLat) if use_moisture_balance "Latent person loads" annotation(Placement(transformation(extent={{-80,-60},{-60,-40}})));

  Modelica.Fluid.Vessels.BaseClasses.VesselFluidPorts_b ports[nPorts](redeclare each final package Medium=Buildings.Media.Air) "Auxiliary fluid inlets and outlets to indoor air volume." annotation(Placement(transformation(extent={{-30, -8}, {30, 8}},origin={0, -100}), iconTransformation(extent={{-23.25, -7.25}, {23.25, 7.25}},origin={-0.75, -98.75})));

  Modelica.Thermal.HeatTransfer.Interfaces.HeatPort_a port_b "Heat port for radiative heat flow." annotation(Placement(transformation(extent={{30,-110},{50,-90}}, iconTransformation(extent={{40,-112},{60,-92}}))));

  Modelica.Thermal.HeatTransfer.Interfaces.HeatPort_a port_a "Heat port for convective heat flow." annotation(Placement(transformation(extent={{-10,90},{10,110}}), iconTransformation(extent={{-10,90},{10,110}})));


equation
  connect(eqAirTemp.TEqAirWin, prescribedTemperature1.T)
    annotation (Line(
    points={{-3,-0.2},{0,-0.2},{0,20},{6.8,20}},   color={0,0,127}));
  connect(eqAirTemp.TEqAir, prescribedTemperature.T)
    annotation (Line(points={{-3,-4},{4,-4},{4,0},{6.8,0}},
    color={0,0,127}));

  connect(weaBus.TDryBul, eqAirTemp.TDryBul)
    annotation (Line(
    points={{-83,6},{-83,-2},{-38,-2},{-38,-10},{-26,-10}},
    color={255,204,51},
    thickness=0.5), Text(
    string="%first",
    index=-1,
    extent={{-6,3},{-6,3}}));
  connect(internalGains.y[1], personsRad.Q_flow)
    annotation (Line(points={{22.8,
    -52},{28,-52},{28,-32},{48,-32}}, color={0,0,127}));
  connect(internalGains.y[2], personsConv.Q_flow)
    annotation (Line(points={{22.8,-52},{36,-52},{48,-52}}, color={0,0,127}));
  connect(internalGains.y[3], machinesConv.Q_flow)
    annotation (Line(points={{22.8,
    -52},{28,-52},{28,-74},{48,-74}}, color={0,0,127}));
  connect(const.y, eqAirTemp.sunblind)
    annotation (Line(points={{-13.7,17},{-12,17},{-12,8},{-14,8},{-14,8}},
    color={0,0,127}));
  connect(HDifTil.HSkyDifTil, corGDoublePane.HSkyDifTil)
    annotation (Line(
    points={{-47,36},{-28,36},{-6,36},{-6,66},{4,66}}, color={0,0,127}));
  connect(HDirTil.H, corGDoublePane.HDirTil)
    annotation (Line(points={{-47,62},{-10,62},{-10,70},{4,70}},
    color={0,0,127}));
  connect(HDirTil.H,solRad. u1)
    annotation (Line(points={{-47,62},{-42,62},{-42,
    14},{-39,14}}, color={0,0,127}));
  connect(HDirTil.inc, corGDoublePane.inc)
    annotation (Line(points={{-47,58},{4,58},{4,58}}, color={0,0,127}));
  connect(HDifTil.H,solRad. u2)
    annotation (Line(points={{-47,30},{-44,30},{-44,
    8},{-39,8}}, color={0,0,127}));
  connect(HDifTil.HGroDifTil, corGDoublePane.HGroDifTil)
    annotation (Line(
    points={{-47,24},{-4,24},{-4,62},{4,62}}, color={0,0,127}));
  connect(solRad.y, eqAirTemp.HSol)
    annotation (Line(points={{-27.5,11},{-26,11},{-26,2},{-26,2}},
    color={0,0,127}));
    connect(weaBus, HDifTil[1].weaBus)
    annotation (Line(
    points={{-78,62},{-74,62},{-74,30},{-68,30}},
    color={255,204,51},
    thickness=0.5));
    connect(weaBus, HDirTil[1].weaBus)
    annotation (Line(
    points={{-78,62},{-73,62},{-68,62}},
    color={255,204,51},
    thickness=0.5));
    connect(weaBus, HDifTil[2].weaBus)
    annotation (Line(
    points={{-78,62},{-74,62},{-74,30},{-68,30}},
    color={255,204,51},
    thickness=0.5));
    connect(weaBus, HDirTil[2].weaBus)
    annotation (Line(
    points={{-78,62},{-73,62},{-68,62}},
    color={255,204,51},
    thickness=0.5));
    connect(weaBus, HDifTil[3].weaBus)
    annotation (Line(
    points={{-78,62},{-74,62},{-74,30},{-68,30}},
    color={255,204,51},
    thickness=0.5));
    connect(weaBus, HDirTil[3].weaBus)
    annotation (Line(
    points={{-78,62},{-73,62},{-68,62}},
    color={255,204,51},
    thickness=0.5));
    connect(weaBus, HDifTil[4].weaBus)
    annotation (Line(
    points={{-78,62},{-74,62},{-74,30},{-68,30}},
    color={255,204,51},
    thickness=0.5));
    connect(weaBus, HDirTil[4].weaBus)
    annotation (Line(
    points={{-78,62},{-73,62},{-68,62}},
    color={255,204,51},
    thickness=0.5));
  connect(personsRad.port, thermalZoneFourElements.intGainsRad)
    annotation (Line(
    points={{68,-32},{84,-32},{100,-32},{100,24},{92.2,24}},
    color={191,0,0}));
  connect(thermalConductorWin.solid, thermalZoneFourElements.window)
    annotation (
     Line(points={{38,21},{40,21},{40,20},{43.8,20}}, color={191,0,0}));
  connect(prescribedTemperature1.port, thermalConductorWin.fluid)
    annotation (Line(points={{20,20},{28,20},{28,21}}, color={191,0,0}));
  connect(thermalZoneFourElements.extWall, thermalConductorWall.solid)
    annotation (Line(points={{43.8,12},{40,12},{40,1},{36,1}},
    color={191,0,0}));
  connect(thermalConductorWall.fluid, prescribedTemperature.port)
    annotation (Line(points={{26,1},{24,1},{24,0},{20,0}}, color={191,0,0}));
  connect(alphaWall.y, thermalConductorWall.Gc)
    annotation (Line(points={{30,-11.6},{30,-4},{31,-4}}, color={0,0,127}));
  connect(hConvWin.y, thermalConductorWin.Gc)
    annotation (Line(points={{32,33.6},{32,26},{33,26}}, color={0,0,127}));
  connect(weaBus.TBlaSky, eqAirTemp.TBlaSky)
    annotation (Line(
    points={{-83,6},{-58,6},{-58,2},{-32,2},{-32,-4},{-26,-4}},
    color={255,204,51},
    thickness=0.5), Text(
    string="%first",
    index=-1,
    extent={{-6,3},{-6,3}}));
  connect(machinesConv.port, thermalZoneFourElements.intGainsConv)
    annotation (
    Line(points={{68,-74},{82,-74},{96,-74},{96,20},{92,20}}, color={191,
    0,0}));
  connect(personsConv.port, thermalZoneFourElements.intGainsConv)
    annotation (
    Line(points={{68,-52},{96,-52},{96,20},{92,20}}, color={191,0,0}));
  connect(corGDoublePane.solarRadWinTrans, thermalZoneFourElements.solRad)
    annotation (Line(points={{27,64},{34,64},{40,64},{40,31},{43,31}}, color={0,
    0,127}));
  connect(prescribedTemperatureFloor.port, thermalZoneFourElements.floor)
    annotation (Line(points={{67,-6},{68,-6},{68,-2}}, color={191,0,0}));
  connect(prescribedTemperatureFloor.T, TSoil.y) annotation (Line(points={{67,-19.2},
          {72.5,-19.2},{72.5,-22},{79.6,-22}}, color={0,0,127}));
  connect(prescribedTemperatureRoof.port, thermalConductorRoof.fluid)
    annotation (Line(points={{67,38},{67,38},{67,32}}, color={191,0,0}));
  connect(thermalConductorRoof.solid, thermalZoneFourElements.roof)
    annotation (Line(points={{67,22},{66.8,22},{66.8,13}}, color={191,0,0}));
  connect(thermalConductorRoof.Gc, hConvRoof.y)
    annotation (Line(points={{72,27},{78,27},{81.6,27}},color={0,0,127}));
  connect(eqAirTempVDI.TDryBul, eqAirTemp.TDryBul)
    annotation (Line(points={{28,38},{-96,38},{-96,-36},{-38,-36},{-38,-44},{
          -26,-44}},
    color={0,0,127}));
  connect(eqAirTempVDI.TBlaSky, eqAirTemp.TBlaSky)
    annotation (Line(points={{28,44},{-34,44},{-98,44},{-98,-42},{-58,-42},{-58,
          -32},{-32,-32},{-32,-38},{-26,-38}},
    color={0,0,127}));
  connect(const1.y, eqAirTempVDI.sunblind)
    annotation (Line(points={{40,67.7},{40,56}}, color={0,0,127}));
  connect(eqAirTempVDI.TEqAir, prescribedTemperatureRoof.T) annotation (Line(
        points={{51,44},{56,44},{56,58},{67,58},{67,51.2}}, color={0,0,127}));
  connect(weaBus, HDifTilRoof[1].weaBus) annotation (Line(
      points={{-76,22},{-74,22},{-74,58},{-68,58}},
      color={255,204,51},
      thickness=0.5));
  connect(weaBus, HDirTilRoof[1].weaBus) annotation (Line(
      points={{-76,22},{-74,22},{-74,84},{-68,84}},
      color={255,204,51},
      thickness=0.5));
  connect(HDirTilRoof.H, solRadRoof.u1)
    annotation (Line(points={{-47,84},{-22,84},{3,84}}, color={0,0,127}));
  connect(HDifTilRoof.H, solRadRoof.u2) annotation (Line(points={{-47,58},{-22,
          58},{-22,78},{3,78}}, color={0,0,127}));
  connect(eqAirTempVDI.HSol, solRadRoof.y) annotation (Line(points={{28,50},
          {6,50},{6,46},{-83,46},{-83,6}}, color={0,0,127}), Text(
      string="%second",
      index=1,
      extent={{6,3},{6,3}}));
  for i in 1:nPorts loop
    connect(ports[i], thermalZoneFourElements.ports[i])
    	annotation (Line(
    	points={{-18,-102},{-18,-84},{83,-84},{83,-1.95}},
    	color={0,127,255},
    	smooth=Smooth.None));
  end for;
  connect(thermalZoneFourElements.intGainsRad, port_b) annotation(Line(points={{92, 24}, {98, 24}, {98, -100}, {40, -100}}, color={191, 0, 0}));

  connect(thermalZoneFourElements.QLat_flow, perLatLoa.y) annotation(Line(points={{43,4},{40,4},{40,-28},{-40,-28},{-40,-50},{-59,-50}}, color={0, 0,127}));

  connect(thermalZoneFourElements.TRad, TRad) annotation(Line(points={{93,28},{98,28},{98,-20},{110,-20}}, color={0,0,127}));

  connect(thermalZoneFourElements.TAir, TAir) annotation(Line(points={{93,32},{98,32},{98,48},{110,48}}, color={0,0,127}));

  connect(port_a, thermalZoneFourElements.intGainsConv) annotation(Line(points={{0,100},{96,100},{96,20},{92,20}}, color={191,0,0}));

  annotation (experiment(
  StartTime=0,
  StopTime=31536000,
  Interval=3600,
  __Dymola_Algorithm="Cvode"),
  __Dymola_experimentSetupOutput(equidistant=true,
  events=false));
end Restroom;
