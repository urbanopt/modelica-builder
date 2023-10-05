within teaser_single.Districts;
model DistrictEnergySystem
  extends Modelica.Icons.Example;
  // District Parameters
  package MediumW=Buildings.Media.Water
    "Source side medium";
  package MediumA=Buildings.Media.Air
    "Load side medium";

  // TODO: dehardcode these
  parameter Modelica.Units.SI.TemperatureDifference delChiWatTemDis(displayUnit="degC")=7;
  parameter Modelica.Units.SI.TemperatureDifference delChiWatTemBui(displayUnit="degC")=5;
  parameter Modelica.Units.SI.TemperatureDifference delHeaWatTemDis(displayUnit="degC")=12;
  parameter Modelica.Units.SI.TemperatureDifference delHeaWatTemBui(displayUnit="degC")=5;
  parameter Integer numberofchillers = 2;

  // Models

  //
  // Begin Model Instance for TeaserLoad_be9c7414
  // Source template: /model_connectors/load_connectors/templates/Teaser_Instance.mopt
  //
  Loads.B5a6b99ec37f4de7f94020090.building TeaserLoad_be9c7414(
    nPorts_aHeaWat=1,
    nPorts_bHeaWat=1,
    nPorts_aChiWat=1,
    nPorts_bChiWat=1)
    "Building with thermal loads as TEASER zones"
    annotation (Placement(transformation(extent={{50.0,30.0},{70.0,50.0}})));
  //
  // End Model Instance for TeaserLoad_be9c7414
  //



  //
  // Begin Model Instance for etsHotWatStub_317cd3ed
  // Source template: /model_connectors/energy_transfer_systems/templates/EtsHotWaterStub_Instance.mopt
  //
  // TODO: move these components into a single component
  Buildings.Fluid.Sources.Boundary_pT supHeaWat_etsHotWatStub_317cd3ed(
    redeclare package Medium=MediumW,
    use_T_in=true,
    nPorts=1)
    "Heating water supply"
    annotation (Placement(transformation(extent={{10.0,-10.0},{30.0,10.0}})));
  Buildings.Fluid.Sources.Boundary_pT sinHeaWat_etsHotWatStub_317cd3ed(
    redeclare package Medium=MediumW,
    nPorts=1)
    "Heating water sink"
    annotation (Placement(transformation(extent={{50.0,-10.0},{70.0,10.0}})));
  //
  // End Model Instance for etsHotWatStub_317cd3ed
  //



  //
  // Begin Model Instance for etsColWatStub_f01390c3
  // Source template: /model_connectors/energy_transfer_systems/templates/EtsColdWaterStub_Instance.mopt
  //
  // TODO: move these components into a single component
  Buildings.Fluid.Sources.Boundary_pT supChiWat_etsColWatStub_f01390c3(
    redeclare package Medium=MediumW,
    use_T_in=true,
    nPorts=1)
    "Chilled water supply"
    annotation (Placement(transformation(extent={{-70.0,-50.0},{-50.0,-30.0}})));
  Buildings.Fluid.Sources.Boundary_pT sinChiWat_etsColWatStub_f01390c3(
    redeclare package Medium=MediumW,
    nPorts=1)
    "Chilled water sink"
    annotation (Placement(transformation(extent={{-30.0,-50.0},{-10.0,-30.0}})));
  //
  // End Model Instance for etsColWatStub_f01390c3
  //




  // Model dependencies

  //
  // Begin Component Definitions for a58ec2e9
  // Source template: /model_connectors/couplings/templates/Teaser_EtsHotWaterStub/ComponentDefinitions.mopt
  //
  Modelica.Blocks.Sources.RealExpression THeaWatSup_a58ec2e9(
    y=max(
      TeaserLoad_be9c7414.terUni.T_aHeaWat_nominal))
    "Heating water supply temperature"
    annotation (Placement(transformation(extent={{-70.0,-10.0},{-50.0,10.0}})));

  //
  // End Component Definitions for a58ec2e9
  //



  //
  // Begin Component Definitions for 8e55a31a
  // Source template: /model_connectors/couplings/templates/Teaser_EtsColdWaterStub/ComponentDefinitions.mopt
  //
  Modelica.Blocks.Sources.RealExpression TChiWatSup_8e55a31a(
    y=min(
      TeaserLoad_be9c7414.terUni.T_aChiWat_nominal))
    "Chilled water supply temperature"
    annotation (Placement(transformation(extent={{-30.0,-10.0},{-10.0,10.0}})));

  //
  // End Component Definitions for 8e55a31a
  //



equation
  // Connections

  //
  // Begin Connect Statements for a58ec2e9
  // Source template: /model_connectors/couplings/templates/Teaser_EtsHotWaterStub/ConnectStatements.mopt
  //

  // teaser, ets hot water stub connections
  connect(supHeaWat_etsHotWatStub_317cd3ed.T_in,THeaWatSup_a58ec2e9.y)
    annotation (Line(points={{28.591729349738088,19.769083940326155},{8.591729349738088,19.769083940326155},{-11.408270650261912,19.769083940326155},{-31.408270650261912,19.769083940326155},{-31.408270650261912,-0.2309160596738451},{-51.40827065026191,-0.2309160596738451}},color={0,0,127}));
  connect(supHeaWat_etsHotWatStub_317cd3ed.ports[1],TeaserLoad_be9c7414.ports_aHeaWat[1])
    annotation (Line(points={{20.023987755774314,26.434106474132236},{20.023987755774314,46.434106474132236},{40.0239877557743,46.434106474132236},{60.0239877557743,46.434106474132236}},color={0,0,127}));
  connect(sinHeaWat_etsHotWatStub_317cd3ed.ports[1],TeaserLoad_be9c7414.ports_bHeaWat[1])
    annotation (Line(points={{66.67138553607464,20.871302462969837},{66.67138553607464,40.87130246296984}},color={0,0,127}));

  //
  // End Connect Statements for a58ec2e9
  //



  //
  // Begin Connect Statements for 8e55a31a
  // Source template: /model_connectors/couplings/templates/Teaser_EtsColdWaterStub/ConnectStatements.mopt
  //

  // teaser, ets cold water stub connections
  connect(TChiWatSup_8e55a31a.y,supChiWat_etsColWatStub_f01390c3.T_in)
    annotation (Line(points={{-13.044910860110875,-25.907712156325545},{-33.044910860110875,-25.907712156325545},{-33.044910860110875,-45.907712156325545},{-53.044910860110875,-45.907712156325545}},color={0,0,127}));
  connect(supChiWat_etsColWatStub_f01390c3.ports[1],TeaserLoad_be9c7414.ports_aChiWat[1])
    annotation (Line(points={{-64.01769206593764,-11.316852504956202},{-44.01769206593764,-11.316852504956202},{-44.01769206593764,8.683147495043798},{-44.01769206593764,28.683147495043798},{-44.01769206593764,48.6831474950438},{-24.017692065937638,48.6831474950438},{-4.017692065937638,48.6831474950438},{15.982307934062362,48.6831474950438},{35.98230793406236,48.6831474950438},{55.98230793406236,48.6831474950438}},color={0,0,127}));
  connect(sinChiWat_etsColWatStub_f01390c3.ports[1],TeaserLoad_be9c7414.ports_bChiWat[1])
    annotation (Line(points={{-22.217300978711407,-12.177140029189147},{-2.217300978711407,-12.177140029189147},{-2.217300978711407,7.822859970810853},{-2.217300978711407,27.822859970810853},{-2.217300978711407,47.82285997081085},{17.782699021288593,47.82285997081085},{37.78269902128859,47.82285997081085},{57.78269902128858,47.82285997081085}},color={0,0,127}));

  //
  // End Connect Statements for 8e55a31a
  //




annotation(
  experiment(
    StopTime=86400,
    Interval=3600,
    Tolerance=1e-06),
  Diagram(
    coordinateSystem(
      preserveAspectRatio=false,
      extent={{-90.0,-70.0},{90.0,70.0}})),
  Documentation(
    revisions="<html>
 <li>
 May 10, 2020: Hagar Elarga<br/>
Updated implementation to handle template needed for GeoJSON to Modelica.
</li>
</html>"));
end DistrictEnergySystem;
