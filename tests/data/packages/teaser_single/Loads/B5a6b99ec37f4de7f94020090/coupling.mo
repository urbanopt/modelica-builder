within teaser_single.Loads.B5a6b99ec37f4de7f94020090;
model coupling
  "Example illustrating the coupling of TEASER building loads with infinite heating and cooling sources with no ETS"
  extends Modelica.Icons.Example;
  parameter String weaName="modelica://teaser_single/Loads/Resources/Data/B5a6b99ec37f4de7f94020090/USA_IL_Chicago-OHare.Intl.AP.725300_TMY3.mos"
     "Path of the weather file";
  package MediumW=Buildings.Media.Water
    "Source side medium";
  building bui(
    nPorts_aHeaWat=1,
    nPorts_bHeaWat=1,
    nPorts_aChiWat=1,
    nPorts_bChiWat=1)
    "Building with thermal loads as TEASER zones"
    annotation (Placement(transformation(extent={{20,40},{40,60}})));
  Buildings.Fluid.Sources.Boundary_pT sinHeaWat(
    redeclare package Medium=MediumW,
    p=300000,
    nPorts=1)
    "Sink for heating water"
    annotation (Placement(transformation(extent={{10,-10},{-10,10}},rotation=0,origin={130,80})));
  Buildings.Fluid.Sources.Boundary_pT sinChiWat(
    redeclare package Medium=MediumW,
    p=300000,
    nPorts=1)
    "Sink for chilled water"
    annotation (Placement(transformation(extent={{10,-10},{-10,10}},rotation=0,origin={130,20})));
  Modelica.Blocks.Sources.RealExpression THeaWatSup(
    y=313.15)
     "Heating water supply temperature"
    annotation (Placement(transformation(extent={{-120,70},{-100,90}})));
  Modelica.Blocks.Sources.RealExpression TChiWatSup(
    y=280.15)
     "Chilled water supply temperature"
    annotation (Placement(transformation(extent={{-120,10},{-100,30}})));
  Buildings.Fluid.Sources.Boundary_pT supHeaWat(
    redeclare package Medium=MediumW,
    use_T_in=true,
    nPorts=1)
    "Heating water supply"
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},rotation=0,origin={-50,80})));
  Buildings.Fluid.Sources.Boundary_pT supChiWat(
    redeclare package Medium=MediumW,
    use_T_in=true,
    nPorts=1)
    "Chilled water supply"
    annotation (Placement(transformation(extent={{-10,-10},{10,10}},rotation=0,origin={-50,20})));
  Buildings.BoundaryConditions.WeatherData.ReaderTMY3 weaDat(
    calTSky=Buildings.BoundaryConditions.Types.SkyTemperatureCalculation.HorizontalRadiation,
    pAtm(
      displayUnit="Pa")=101339,
    filNam=Modelica.Utilities.Files.loadResource(
      weaName),
    computeWetBulbTemperature=true)
    "Weather data reader"
    annotation (Placement(transformation(extent={{10,-10},{-10,10}},rotation=90,origin={56,96})));
equation
   connect(supHeaWat.T_in,THeaWatSup.y)
    annotation (Line(points={{-62,84},{-80,84},{-80,80},{-99,80}},color={0,0,127}));
  connect(TChiWatSup.y,supChiWat.T_in)
    annotation (Line(points={{-99,20},{-80,20},{-80,24},{-62,24}},color={0,0,127}));
  connect(sinChiWat.ports[1],bui.ports_bChiWat[1])
    annotation (Line(points={{120,20},{74,20},{74,44},{40,44}},color={0,127,255}));
  connect(bui.ports_bHeaWat[1],sinHeaWat.ports[1])
    annotation (Line(points={{40,48},{74,48},{74,80},{120,80}},color={0,127,255}));
  connect(supHeaWat.ports[1],bui.ports_aHeaWat[1])
    annotation (Line(points={{-40,80},{0,80},{0,48},{20,48}},color={0,127,255}));
  connect(supChiWat.ports[1],bui.ports_aChiWat[1])
    annotation (Line(points={{-40,20},{0,20},{0,44},{20,44}},color={0,127,255}));
  connect(weaDat.weaBus,bui.weaBus)
    annotation (Line(points={{56,86},{36,86},{36,55.1333},{38.0333,55.1333}},color={255,204,51}));
  // TODO: determine how to handle the "lines"
  annotation (
    Diagram(
      coordinateSystem(
        preserveAspectRatio=false,
        extent={{-140,-40},{160,140}})),
    __Dymola_Commands(
      file="modelica://teaser_single/Loads/Resources/Scripts/B5a6b99ec37f4de7f94020090/Dymola/RunTeaserCouplingBuilding.mos"  "Simulate and plot"),
    experiment(
      StopTime=604800,
      Tolerance=1e-06),
    Documentation(
      info="<html>
<p>
This example illustrates the use of
<a href=\"modelica://Buildings.Experimental.DHC.Loads.BaseClasses.PartialBuilding\">
Buildings.Experimental.DHC.Loads.BaseClasses.PartialBuilding</a>,
<a href=\"modelica://Buildings.Experimental.DHC.Loads.BaseClasses.PartialTerminalUnit\">
Buildings.Experimental.DHC.Loads.BaseClasses.PartialTerminalUnit</a>
and
<a href=\"modelica://Buildings.Experimental.DHC.Loads.BaseClasses.FlowDistribution\">
Buildings.Experimental.DHC.Loads.BaseClasses.FlowDistribution</a>
in a configuration with:
</p>
<ul>
<li>
building thermal loads integrating teaser zones.
</li>
<li>
secondary pumps.
</li>
</ul>
</html>",
      revisions="<html>
<ul>
<li>
April 8, 2020, by Hagar Elarga:<br/>
GeoJson-Modelica translator template first implementation.
</li>
<li>
February 21, 2020, by Antoine Gautier:<br/>
Model first implementation.
</li>
</ul>
</html>"));
end coupling;
