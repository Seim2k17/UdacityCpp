# UdacityCpp
Source to the Udacity C++ Course (Become a C++ Developer)

Project #2: System Monitor

0. Links
   https://github.com/udacity/CppND-System-Monitor 

1. Infos
   git clone git@github:udacity/CppND-System-Monitor.git / git clone https://github.com/udacity/CppND-System-Monitor-Project-Updated.git 
   (sudo) apt install libncurses5-dev libncursesw5-dev
   cd repo
   mkdir build && cd build
   cmake ..
   make
   ./monitor

Project #1: OpenStreetMap Route Planner using IO2D

0. Links
   OpenStreetMap: https://www.openstreetmap.org/export#map=12/53.5751/10.0710
   OpenStreetmap-Data: https://planet.openstreetmap.org/
   OpenStreetmap-Wiki: https://wiki.openstreetmap.org/wiki/Main_Page

1. Infos
   - in this repo only the diffs to the UdacityProjects were uploaded.
   - to make it run you need to follow the instructions on: 
      a) https://github.com/cpp-io2d/P0267_RefImpl/blob/master/BUILDING.md
      b) https://github.com/udacity/CppND-Route-Planning-Project

2. Compiling (project from 1b))
  - mkdir build && cd build
  - cmake ..
  - make

3. Running
  ./OSM_A_star_search
