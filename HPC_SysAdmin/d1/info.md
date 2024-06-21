# HPC System Administration (by Prof. Soundarya Rajan)

### Question: What are the components of a Data Center?


## Agenda:
- Data Center
- Param Utkarsh Architecture
- Applications
- Scheduler
- Sample Script
- Conclusion

## (CPSF) Data Center
- DC Area 1800 SqFt
- Three High Density DLC (Direct Liquid Cooling) racks cooled with Adiabatic dry-cooler
- Two Service node racks
- Server Racks and Storage racks
- Staging area, User terminal area and conference room.

## Question: What are the different types of data centers?

## Example:
- Data Centers can be classified based on downtime.
- For eg: stock exchange is a high availability and low latency data center.
- Similary, amazon data center should also be high availability.

## Types of Data Center:
- Tier 1 = 99
- Tier 2 = 99.36
- Tier 3 = 99.69
- Tier 4 = 99.99

## Question: What is High Performance Cluster Computing?
- Group of nodes.

## BMS - Building Management System
- Integraded systems in BMS
- Generator (1+1 redundant)
- UPS (n+1 redundant)
- Precition Air condition - PAC (n+1 redundant)
- Fire Alarm System - FAS (VESDA and NOVEC)
- Very Early Smoke Detection Apparatus - VESDA
- NOVEC - Fire suppresor
- Dry Cooler (adiabatic)
- temperature and humidity sensors

## Param Utkarsh Security
- Secured Authentication
- Perimeter firewall (UTM)
- Cluster Firewall (HA load balancer and IPS)
- Geographical filtering
- Isolated Network
- Physical security with ACS (access control system)
- CCTV surveillance (14/7)

## HPC cluster architecture system diagram.
- External firewall for external users
- both external and internal users connected to 10 gbps cdac lan network
- then to connect to param utkarsh there is an internal firewall.
- then comes load balancer that transfers connection to one of login nodes.
- login authentication takes place in one of the login nodes.
- After authentication, user gets access to 100 Gbps non-blocking Infiniband (IB) interconnect. 
- Infiniband provides 100-200 Gbps connection speed).
- this IB interconnect is connected to the following:
    - Master Nodes
    - CPU and GPU compute nodes
    - 1 PB Lustre file system
    - Cluster Management Servers

# Different Softwares in Param Utkarsh:
0. Software stackfor building applications (Very high level)
1. HPC programming tools (high level)
2. Middleware applications and management (mid level)
3. Operating systems (low level)

## 0. Software stack for building applications:
- scikit-learn, 
- xgboost, 
- pytorch, 
- tensorflow, 
- keras, 
- numpy, 
- pandas, 
- matplotlib, 
- seaborn, 
- opencv

## 1. HPC Programming tools:
- Performance monitoring: 
    - HPCC, 
    - IMB/OSU, 
    - IOR, 
    - HPCG
- Visualization: 
    - Ferret, 
    - GrADS, 
    - ParaView
- Application libraries: 
    - NetCDF/HDF/etc., 
    - Math Libraries, 
    - Python Libraries, 
    - GNU Scientific Liberary
- Development Tools: 
    - GNU, 
    - CUDA toolkit, 
    - OpenACC, 
    - Intel Cluster Studio
- Communication Libraries: 
    - Intel MPI, 
    - OpenMPI, 
    - PGAS

## 2. Middleware Applications and Management
- Cluster Monitoring / Help Desk: 
    - Ganglia, 
    - Nagios, 
    - C-DAC Tools, 
    - XDMoD, 
    - osTicket
- Resource Managment/ Scheduling/ Accounting: 
    - SLURM, 
    - SLURM Accounting
- Provisioning: 
    - OpenHPC (xCAT)
- File System: 
    - NFS, 
    - Local FS (XFS), 
    - Lustre, 
    - GPFS

## 3. Operating Systems
- Drivers: 
    - OFED, 
    - CUDA, 
    - Network and Storage Drivers
- OS: 
    - Linux (CentOS 7.x)


## Other Tools:
- C-DAC Tools, IDE CAPC: converting serial code to parallel code with CAPC
- CHReME
- C-Chakshu: To calculate CPU time utilization and billing
- HPC Tasks Automation Scripts
- Cluster Checker Scripts
- scada tools: Monitoring power consumption

## Question: What is the command to move data from one system to another?
- scp, ftp, etc. commands.

## Question: What is the technique for creating a file and editing it and it is visible to other computer as well?
- Creating partitions in our NAS, we can share that partition with all computers

## Question: What is the purpose of HPC Clusters?
- Processing jobs like weather forecasting.

## NSM Clusters - Applications, Tools, Programming Models-AI and HPC
- HPC Applications:
    - Bio-informatics: 
        - MUMmer
        - HMMER 
        - MEME 
        - PHYLIP
        - mpiBLAST
        - ClustalW
    - Molecular Dynamics: 
        - NAMD (CPU & GPU), 
        - LAMMPS (CPU & GPU), 
        - GROMACS
    - Material Modeling, Quantum Chemistry: 
        - Quantum-Espresso, 
        - Abinit, 
        - CP2K, 
        - NWChem,
    - CFD, Weather, Ocean, Climate, Disaster Management: 
        - OpenFOAM, 
        - FDS, 
        - SU2, 
        - WRF, 
        - RegCM, 
        - MOM, 
        - ROMS, 
        - ANUGA Hydro
- Visualization Programs:
    - GrADS, 
    - Paraview, 
    - Visit, 
    - VMD.
- Dependency Libraries: - 
    - NetCDF, 
    - PNETCDF, 
    - Jasper, 
    - HDF5, 
    - Tcl, 
    - Boost, 
    - FFTW
- Programming Models: 
    - MPI, 
    - OpenMP, 
    - OpenACC, 
    - CUDA, 
    - PGAS, 
    - Pthreads.
- AI/ML/DL Tools and Technologies:
    - DL Framework: 
        - TensorFlow, 
        - keras, 
        - theano, 
        - pytorch, 
        - scikit-learn, 
        - scipy, 
        - cuDNN
    - Data Science: 
        - Numpy, 
        - RAPIDS,
        - pandas
    - Distributed DL Framework: 
        - TensorFlow with Horovod
    - Container Technology: 
        - enroot
    - JupyterHub: 
        - DL application development platforms and web based IDE.

## Question: How do you use tools like NWChem with other tools like CUDA, OpenMPI, and OpenACC?
## Using NVCC you compile the CUDA code, and then you use the tools like NWChem to create jobs and submit jobs with SLURM.

## How do you size your data center?
- When you decide how much power supply, cooling, server racks, storage you require.
- You are actually "sizing" your data center.
- You need to mention the input power for the Server (in kW) along with other hardware specs.


## What is a U (measurement)?
- A U is a standard unit of measure for designating the height in computer enclosures and server rack cabinets.
- A rack unit is abbreviated as U or RU with a number prefix. 
- A U equals 1.75 inches, so a 4U chassis would be 7 inches high. 
- A 40U rack cabinet would be 70 inches high.

- When we talks about servers, we talk about "U". eg: 1 U server, 2 U server.
- U is nothing but width of server rack
- 1 U = 1.75 inch.


## What is raised floor datacenter?
- A raised floor is a data center construction model in which a slightly higher floor is constructed above the building's original concrete slab floor, leaving the open space between the two floors for wiring or cooling infrastructure. 
- Raised floors often are built to accommodate data center equipment.

# HPC Storage:

## Types of Storage:
- Magnetic Spinning Drives - Hard Disk Drive (HDD) and Magnetic tape drive.
- Optical Storage Drive - Blu-ray, DVD, and CD.
- Flash-based Drives - Solid State Drive (SSD), memory card, and USB flash drive.

## Magnetic Spinning Drive
- Rapid spinning platters with magnetic material on each of the platters.
- Important metric is RPM (Revolutions per Minute).

## HDD types:
- Parallel Advanced Technology Attachment (PATA)
- Serial ATA (SATA)
- Small Computer System Interface (SCSI)
- Serial Attached SCSI (SAS)
- Solid State Drives (SSD)

## PATA 
- Parallel ATA Standards
- IDE & EIDE interfaces
- Data transfer rate upto 133 MB/s
- Max 4 disks
- Instructor says it is not suitable due to low number of disks supported
- link: https://en.wikipedia.org/wiki/Parallel_ATA

## SATA
- More Flexible
- One disk per controller
- Higher storage capacity
- Speed from 150 MB/s
- Hot plug (can unplug or plug in while system is running).
- link: https://en.wikipedia.org/wiki/SATA

## SCSI
- Faster
- More reliable
- Greater scalability
- Suited for large amount of data
- Higher throughputs
- link: https://en.wikipedia.org/wiki/SCSI

## SAS
- Replaces parallel SCSI
- Data rate beyong 10 Gb/s (Using InfiniBand)
- Devices upto 65000
- Support dual ports for redundancy
- Can connect SATA drives also
- link: https://en.wikipedia.org/wiki/Serial_Attached_SCSI

## SSD
- Faster access
- Less susceptible to shock (shock as in sudden physical forces)
- Low latency
- Less Power consumption (due to less moving parts)
- link: https://en.wikipedia.org/wiki/Solid-state_drive


## Optical Storage Devices

## Flash Storage Device
- SSDs, memory card, and USB drives are examples of flash drives
- use silicon for storage.

## Disk performance and access speeds
- refer slides


## RAID (Redundant Array of Independent Disks):
- RAID is a data storage virtualization technology that combines multiple physical disk drive components into one or more logical units for the purposes of data redundancy, performance improvement, or both. 

## What is BIOS Level?
- In computing, BIOS, (Basic Input/Output System, also known as the System BIOS, ROM BIOS, BIOS ROM or PC BIOS) is firmware used to provide runtime services for operating systems and programs and to perform hardware initialization during the booting process (power-on startup).
- The BIOS firmware comes pre-installed on an IBM PC or IBM PC compatible's system board and exists in some UEFI-based systems to maintain compatibility with operating systems that do not support UEFI native operation.

## What is network booting?
- Network booting, shortened netboot, is the process of booting a computer from a network rather than a local drive. 
- This method of booting can be used by routers, diskless workstations and centrally managed computers (thin clients) such as public computers at libraries and schools.
- link: https://en.wikipedia.org/wiki/Network_booting

## What is PXE (Preboot Execution Environment) boot?
- In computing, the Preboot eXecution Environment, PXE (most often pronounced as pixie, often called PXE Boot/pixie boot.) specification describes a standardized client–server environment that boots a software assembly, retrieved from a network, on PXE-enabled clients. 
- On the client side it requires only a PXE-capable network interface controller (NIC), and uses a small set of industry-standard network protocols such as DHCP and TFTP.
- link: https://en.wikipedia.org/wiki/Preboot_Execution_Environment

## Working of RAID
- refer slides
## Levels of RAID
- refer slides

## Standard RAID Levels
### RAID 0
- striping
- Splits ("stripes") data evenly across two r more disks
- no redundancy, parity info or fault tolerance.
### RAID 1
- Disk mirroring
- no striping 
- read perfomrnace is imporved since either disk can be read at same time.
- write performance is same as for single disk storage
### RAID 2
- RAID 2, which is rarely used in practice, stripes data at the bit (rather than block) level, and uses a Hamming code for error correction. 
### RAID 3
- Uses striping and dedicates one drive to storing parity info. 

### RAID 5
- This RAID level is quite commonly used in HPC environments.
- This level is based on parity block-level striping, enabling the array to function, even if one drive were to fail.
- Performance is better than that of a single drive, but not as high as a RAID 0 array.
- RAID 5 requires at least three disks, but it is often recommended to use at least five disks for performance reasons.

### RAID 10 (RAID 1+0)
- Combining RAID 1 and raid 0, this levels offers higher performance than raid 1 but at much higher costs.
- in RAID 1+0 data is mirrored and mirrored data is striped.

## Mirroring
- benefits and drawbacks of mirroring

## RAID comparison:
- The table shows comparison between RAID 0, 1, 1E, 5, 5EE, 6, and 10 levels.
- Based on Capacity Utilization and Data Protections, we will have to select our RAID level
- In PARAM UTKARSH we are using RAID 5.

## RAID level to choose:
- consider the following parameters:
    - Fast
    - cheap
    - fault tolerant
- RAID 5 is Fault tolerant and Cheap but not fast
- Raid 1+0 is Fast and Fault Tolerant but not cheap.
- Raid 0 is fast and cheap but not fault tolerant.

## Windows File Systems
- FAT: File Allocation Table
- NTFS: New Technology File System

## Linux File Systems
- EXT2/3/4 - Journaling file systems
- JFS
- ReiserFS
- XFS

## How to find out which file system your linux distro has in it?
- go to etc/fstap
- link: https://www.redhat.com/sysadmin/etc-fstab

## How to format a file system?
- mkfs command

## NFS (Network File System)

## Types of Storage connectivity:
- Direct-Attached Storage (DAS)
- Network-Attached Storage (NAS)
- Storage Area Network (SAN)

## Direct Attached Storage (DAS)
- Application <-> File System <-> Storage

## Network Attached Storage (NAS)
- Application <-> Network <-> File System <->  Storage

## Storage Area Network (SAN)
- Application <-> File System <-> Network <-> Storage

## What is Formatting a Hard Disk?
- When we purchase a hard disk from market, we cannot use it directly.
- Because we have to install a fresh file system on it to be able to store anything on it.
- This is called formatting.

## Formatting in NAS.
- When we partition our storage in NAS we have to do formatting in NAS to ensure that our file system knows about our storage.

## NAS vs SAN
- Instructor says that,
    - In, NAS, we already have a local system with hard drive, we can extend it with more storage.
    - In SAN, we dont have a local hard drive, all storages are connected through network.

## What is difference between Block storage, NFS storage and SMB Storage.
- Block storage, sometimes referred to as block-level storage, is a technology that is used to store data files on storage area networks (SANs) or cloud-based storage environments. 
- Developers favor block storage for computing situations where they require fast, efficient and reliable data transportation.
- The Network File System (NFS) is a mechanism for storing files on a network (aka NAS). It is a distributed file system that allows users to access files and directories located on remote computers and treat those files and directories as if they were local.
- link: https://www.starwindsoftware.com/blog/virtual-machine-storage-file-vs-block-part-1

## DAS, NAS and SAN more info
- refer slides.

## Lot more missed slides

## SAN Switch

## SAN Fabric

## SAN Topology

## SAN Fibre channel topology

## SAN high availability
- classified into 3 availability levels.
    - 1 - path
    - 2 - switch
    - 3 - fabric

## What is parallel file system?
- A parallel file system is a software component designed to store data across multiple networked servers.
- It facilitates high-performance access through simultaneous, coordinated (I/O) operations between clients and storage nodes.
- Deployed using high-speed networking such as fast ethernet, Infiniband and proprietary technologies, to optimize the I/O path and enable greater bandwidth.

## Parallel file system architecture
- Metadata: identification of hard disks
- OSD

## Lustre architecture
- High perforamnce Data Network (OmniPath for InfiniBand)
- Management target (MGT), MetaData Targets (MOTS), MetaData servers (~10s), Object Storage Targets (OSTS), Object Storage Servers (~1000s)
- Intel Manager for Luster.
- Lustre cliends (~50000s)

## Backup
- Open source tools available.
- Regular Automated Backups
- Full backups and incremental backups
- Incremental backup is done only when there are any changes.
- Cumulative backup = previous full backup. (ie.e all previous backups are available with you).
- After taking backup, how many months you need to keep that backup. This is called "Retention Period".

## Backup tools:
- AMANDA
- Barracuda
- UrBackup

## Performance Parameters for supercomputers
- Floating-Point Operations per Second = FLOPS
- Theoretical peak performance (Rpeak) is calculated by multiplying the number of processors by their clock speed, and then multiplying that product by the number of floating-point operations the processors can perform in one second on standard benchmark programs like the LINPACK DP TPP and HPC Challenge (HPCC), as well as the SPEC integer and floating-point benchmarks.
- Instructor says: consider floating-point operations the processors can perform in one clock cycle as 32, then perform this calculation:
- 2 (no of processors) * 24 (cores per processor) * 2.5 (GHz per core) * 32 (flops per cycle)
- Rmax is the actual performance that system outputs when an applications is running.

## HPC benchparking tools:
- HPL LINPACK: World-wide accepted benchmarking software.
- When you do HPC benchmarking, there are two values Rpeak and Rmax.
- HPL NETLIB
- HPL.DAT website

## For benchmarks of Indian Supercomputers go to topsc.in

- PARAM Shivay iit bhu
- PARAM Shakti iit kgp
- PARAM Yukti iser pune
- param yukti  jncasr bangalore
- param sanganak iit kanpur
- param pravega iisc bengaluru
- param seva iit hyderabad
- param smriti National Agri-Food Biotechnology Institute (NABI), Mohali
- param utkarsh cdac bengaluru
- param ganga iit roorkee
- param ananta iit gandhinagar
- param porul nit trichy


for more info visit:
https://en.wikipedia.org/wiki/PARAM

## Question: why are some racks attached and some isolated?
- In PARAM Utkarsh, racks are isolated
- weight of each rack is 3 tons.
- we cannot keep racks concentrated in area as it might concentrate weight in one area.
- There are some racks in ground level were it is possible to concentrate racks in one area.

## Question: Why are supercomputers installed at IITs and other big R&D institutes?
- Supercomputers are built for MSMEs and R&D organizations
- They are supposed to be utilized for 75% of the time.
- This is why they are installed at IITs and other research institutes.

## Question: What has been your journey in HPC?
- Instructor gives a case study about sizing a data center.

## Question: Calculate the cost of setting up a supercomputer for Online Booking System?
- H.W.

## Question: What services does C-DAC provide?
- CDAC provies HPC services and colocation services.

## Question: What is the maintaince cost C-DAC PARAM UTKARSH?
- per month costs:
    - Power and cooling: 12-14 lakhs
    - Engineer salaries: 25 lakhs 
    - Total per month costs are around 50 lakh.