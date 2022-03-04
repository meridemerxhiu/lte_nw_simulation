#include <ns3/core-module.h>
#include <ns3/network-module.h>
#include <ns3/mobility-module.h>
#include <ns3/lte-module.h>
#include "ns3/netanim-module.h"
#include "ns3/flow-monitor-module.h"
#include "ns3/point-to-point-module.h"

using namespace ns3;

int main (int argc, char *argv[])
{
  CommandLine cmd;

  //Declaration of a new object LteHelper, to create nodes
  Ptr<LteHelper> lteHelper = CreateObject<LteHelper> ();
 

  Config::SetDefault ("ns3::UdpClient::Interval", TimeValue (MilliSeconds (1000)));
  Config::SetDefault ("ns3::UdpClient::MaxPackets", UintegerValue (1000000));
  Config::SetDefault ("ns3::LteHelper::UseIdealRrc", BooleanValue (false));
  
  PointToPointHelper pointToPoint;
  pointToPoint.SetDeviceAttribute ("DataRate", StringValue ("5Mbps"));
  pointToPoint.SetChannelAttribute ("Delay", StringValue ("2ms"));

  //Create Node objects for the eNB(s) and the UEs. Here nodes are emptz
  NodeContainer enbNodes;
  enbNodes.Create (1);
  NodeContainer ueNodes;
  ueNodes.Create (20);

  //Configure the Mobility model for all the nodes:
  MobilityHelper mobility;
  //---------Set Mobility---------------------------------
  mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
  mobility.Install (enbNodes);
  mobility.SetPositionAllocator ("ns3::GridPositionAllocator",
  "MinX", DoubleValue (0.0),
  "MinY", DoubleValue (0.0),
  "DeltaX", DoubleValue (5.0),
  "DeltaY", DoubleValue (1000.0),
  "GridWidth", UintegerValue (3),
  "LayoutType", StringValue ("RowFirst"));
  mobility.SetMobilityModel ("ns3::RandomWalk2dMobilityModel",
  "Bounds", RectangleValue (Rectangle (-2000, 2000, -2000, 2000)));
  mobility.Install (ueNodes);

  //Install an LTE protocol stack on the eNB(s):
  NetDeviceContainer enbDevs;
  enbDevs = lteHelper->InstallEnbDevice (enbNodes);

  //Install an LTE protocol stack on the UEs:
  NetDeviceContainer ueDevs;
  ueDevs = lteHelper->InstallUeDevice (ueNodes);

  //Attach the UEs to an eNB. This will configure each UE according to the eNB configuration, and create an RRC connection between them:
  lteHelper->Attach (ueDevs, enbDevs.Get (0));
  

  /*** 
   * Activate a data radio bearer between each UE and the eNB it is attached to: 
   * This method will also activate two saturation traffic generators for that bearer, one in uplink and one in downlink.
   ***/
  enum EpsBearer::Qci q = EpsBearer::GBR_CONV_VOICE;
  EpsBearer bearer (q);
  lteHelper->ActivateDataRadioBearer (ueDevs, bearer);

  //Set the stop time
  Simulator::Stop (Seconds (20));

  ///This is needed otherwise the simulation will last forever, because (among others) the start-of-subframe event is scheduled repeatedly, and the ns-3 simulator scheduler will hence never run out of events.
    lteHelper->EnablePhyTraces ();
    lteHelper->EnableMacTraces ();
    lteHelper->EnableRlcTraces ();

  
  //Run the simulation:
    AnimationInterface anim ("lte1.xml");
    anim.SetMobilityPollInterval(Seconds(1.00));
    anim.SetMaxPktsPerTraceFile (100000000000);

  //Adding function to generate tr file in which data can be extracted to plot the metric of performance, Qos
   AsciiTraceHelper ascii;
   pointToPoint.EnableAsciiAll (ascii.CreateFileStream ("myfirst.tr"));
   Simulator::Run ();
   Simulator::Destroy ();
   return 0;
}
