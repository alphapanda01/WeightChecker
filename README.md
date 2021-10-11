# WeightChecker
A simple cross-paltform weight checker

![WeightCheck](https://i.imgur.com/PLcFQgq.gif)

NOTE: INSTALL AT YOUR OWN RISK

## Installation (Using CMake)
### Linux
  1.Install wxWidgets
    + Build from the source: [wxWiki](https://wiki.wxwidgets.org/Compiling_and_getting_started)
  - From repos
    + Ubuntu:
    ```
    sudo apt-get install libwxgtk-webview3.0-gtk3-0v5 libwxgtk-media3.0-gtk3-0v5 libgtk-3-dev
    ```
    + It's all convoluted for other distro's, figure it out yourself
  
  2. Build WeightCalculator
     - clone the repo
     ```
     git clone https://github.com/alphapanda01/WeightChecker.git
     ```
     - Create a build folder for CMake(Name doesn't matter)
     ```
     mkdir out && cd out/
     ```
     - Build using cmake
     ```
     cmake -S /path/to/WeightChecker -B /path/to/out/
     ```
     - Make and install
     ```
     sudo make install 
     ```
     
