# HPC Clusters and Architecture

## Agenda
- HPC Clusters and Architecture
- HPC System components
- Parallel file systems
- Performance Parameters for supercomputers
- Cluster Design and network considerations
- Components of supercomputer network
- Building a linux cluster
- HPC cluster security
- Supercomputer detailswith images
- Access Remote HPC cluster
- Designing and running first program on HPC.

## Quick talk on processor speed and hard disk partitioning.

## formula for calculating FLOPS of a processor:
- FLOPS = no_of_cores * Clock_cycles_per_second * Floating_point_operations_per_cycle

## What is HPC?
- The term traditionally applied to systems that function above a teraflop.
- HPC is synonymous with supercomputing, although technically a supercomputer is all about peak operational rate for computers.

- Definition: High-performance computing (HPC) is a technique for quickly processing massive volumes of data and carrying out difficult computations.

- HPC used in simulation design, Computational Fluid Design, CAD, Molecular Dynamics, Stock markets and banking.

## What is HPC cluster?
- refer slides

## HPC Architecture
- refer slides

## HPC system key components:
- Compute
- Network
- Storage
- Security

## What type of network fabric should be used? 
- Ethernet: cat6 or cat7 = 100 gbps this is not sufficient.
- Infiniband provides faster speeds.

## Different types of architecture for storage (NAS vs SAN)
- Speed of SAN is much faster than NAS.
- SAN is much more expensive than NAS.
- SSD is now more popular than outdated SATA system.

## Security in HPC:
- In order to ensure that data is safe, we need:
    - Good authentication and authorisation
    - Encryption of data
    - using https (encrypted http), this ensures that the data trasfer is encrypted and secure.

## Key Components:

### Compute:
- The compute component is concerned with processing data, programs or algorithms, and resolving issues.
- For example, An HPC compute node has two clusters, each of which includes a single CPU, a hard disk, RAM, and a network card.
- Temporary file may be kept on compute nodes.
### Standard server rack size is 42 U. So you can put 42 servers in a single rack.
- Therefore, if you go for a high number of cores per processor per server, you can pack in lot of computing power in the same space.

### Network:
- In order to reduce network downtime, different network topologies have to be considred.
    - Bus
    - point to point
    - mesh or grid
    - torus
- HPC networks are different from common LAN network.
- Packaging restrictions and wire length are just two of the variables taken into account while designing an HPC network.
- Tool to measure network speed:
    - eth tool interface name
    - ifconfig for info

### Storage:
- refer slides.

## HPC Architecture tools:
- HPC Schedulers
- Load Balancer
- Cluster Management tool (for eg: Ganglia, Nagios, etc.)

## HPC cluster components:
- refer slides

## HPC Hardware and Software components.
- refer slides

## HPC: Challenges
- Cost
- Scalability
- Data Management
- Programming
- Support for software and tools
- Power consumption and cooling

### Instructor says 10 lakh electricity bill and 20-30 lakhs for manpower salaries for PARAM Utkarsh HPC system.
### In HPC system three things take the maximum amount of budget: GPUs, Power, and cooling.

## Parallel file systems
- In PARAM UTKARSH we will use parallel file system called "Lustre".
- Primary purpose of file system:
    - to keep the files namespace organized and up to date.
    - to keep the contents
- What is metadata in file system?
    - An assortment of data about files is known as metadata. They include for instance:
        - Placement of data on the disks
        - data sizes
        - dates of creation, update, and last access
        - the UID, GID, and the permissions.

## Local sequential file systems
- It cannot be accessed remotely, on the other hand, parallel file system can be accessed by various compute nodes.
- refer slides.

## structure of a  file on ext4 file system
- refer slides.

## Parallel file systems available:
- lustre (Most commonly used parallel file system in HPC)
- gpfs
- pvfs/orangefs
- panfs

## Lustre
- refer slides

## HPL - High-Performance Linpack benchmark.
- solves a (random) dense linear system in double precision arithmetic.
- Because the problem is so consistent, the realized performance is rather high, and the performance data offer an accurate correction of peak performance.

## Cluster design and network considerations
- major requirements while designing a cluster:
    - physical facilities to house the cluster
    - hardware requirements
    - software requirements

### bullsequena rack is used in Param utkarsh
- This is a water cooled rack.
- Water flows through the rack frame all the way to the motherboard.

## Facilities requirements
- refer slides

## Important components of HPC networking:
- NIC
- Switches
- Firewall (Hardware as well as software)
- Network medium (Ethernet, fibre channel, Intel Omni-Path, and Infiniband)

- Commands like: "iptable" can act as software firewall
- you can view the rules that you have set by "iptable -l"

## Steps of building a linux cluster - Hardware:
- refer slides

## Steps of building a linux cluster - Software:
- refer slides

## HPC cluster security
- Perimeter Firewall - UTM (Unified Thread Management)
- Cluster Firewall (HA load balancer and IPS)
- Geographical filtering & Isolated Networks
- Secured authentication & ACS
- refer slides

## Supercomputer details with images
- PARAM Shivay = IIT BHU 837 TFLOPS
- PARAM Shakti = IIT Kharagpur
- PARAM Brahma = IISER Pune 1.75 Petaflops
- PARAM Yukti  = JNCASR Bangalore 1.8 Pentaflops
- PARAM Sanganak = IIT Kanpur = 1.67 Pentaflops
- PARAM Pravega = IISc Bengaluru = 3 PF
- PARAM Seva = 838 TF
- PARAM Smriti = 838 TF
- PARAM Utkarsh = 838 TF (for 155 nodes we only have 3 racks, so only 50 nodes per rack).

## Access remote HPC Cluster
- How to login to PARAM Utkarsh (refer slides)

# SLURM

## Job Scheduler - SLURM
- refer slides

## SLURM Commands
- refer slides 

## Running jobs
- refer slides

## Compiling and executing the program
- refer slides

## Job script to run in CPU nodes
- very important to specify wall time in HH:MM:SS, max value is 72:00:00

## What is SLURM
- SLURM is open source, fault-tolerant, highly scalable cluster management tool.
- refer slides

## History...
- Slurm was developed in C (500,000 lines)
- refer slides.

## SLURM components
- refer slides

## SLURM Architecture
- refer slides

## Resources managed by SLURM
- refer slides

## SLURM commands demo

## Question: What will you do if a node stops responding?
- Every server gets a Internet protocol management interface port.
- You will have an IP of that server.
- You will go to the IPMI port 

## Instructor says a field trip to PARAM Utkarsh might be arranged.

## Assignment 
- HPL Linpack benchmark and nagios monitoring on local system.
- just google how to install and use.
- on linux based os.

## Instructor email id: 
- Instructor name: Shreekant 
- Email: sreek@cdac.in