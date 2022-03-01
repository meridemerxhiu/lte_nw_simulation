# LTE Network Simulation using NS3

## Explanation of configuration of the first script lte_basic.cc

1. Create a script file in c++ called lte_netw_config.cc in which we will code the configurations
2. Set a group of node objects, and add methods to make them behave like eNodeBs or UEs
3. Install LTE stack of protocols 
4. Configure mobility model for all nodes
5. Set initial positions of nodes by using ‘SetPositionAllocator’ function of the mobility module. We assign the position of nodes in a way that they can form a grid.
6. Attach all the UE nodes to one of the eNodeBs. We configure UE to eNodeBs, in order to create a Radio Resource Control (RRC)  between each other. In this way we have all are channels 
7. firmly in place so that we can start the required communications between the UEs and the eNodeBs.
8. Activate a data radio bearer, for activating two traffic generators for any given bearer, one for uplink and other for downlink.
9. In simulation we can see the activation of previous step, by communication between the UEs and the eNodeBs, by a group of round circles
The more higher the number of circles in the region, the more dense is the traffic flowing. We can monitor this step by activating ./NetAnim
in ns3 found in path 
ns-allinone-3.33/netanim-3.108$ ./NetAnim 
10. in the configuration file we set a lte1.xml file in order to generate the communication scenario. And this file we import in NetAnim
GUI interface to see graphicaly the simulation

