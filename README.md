# DroneKit LogAnalyzer (LA)

![Logo](https://cloud.githubusercontent.com/assets/5368500/10805537/90dd4b14-7e22-11e5-9592-5925348a7df9.png)

[![Circle CI](https://circleci.com/gh/dronekit/dronekit-la/tree/master.svg?style=svg)](https://circleci.com/gh/dronekit/dronekit-la/tree/master)

Log Analyzer for ArduPilot DataFlash logs and MAVLink telemetry logs.

## Overview

DroneKit Log Analyzer (DroneKit-LA) is a powerful open source static analyzer for ArduPilot DataFlash logs and MAVLink telemetry logs. 

The tool can read and analyze several log formats, including telemetry logs (tlogs), dataflash binary logs (.BIN) and dataflash text dumps (.log), and output detailed error and warning information in several formats (json, text, summary). The output includes detailed information about the tests, including what tests were run, the results (pass, fail, warn), severity, and supporting evidence.

DroneKit-LA is also fast, memory efficient and extensible. It supports numerous analyzers and can quickly analyzing even very large logs.

The tool is written in C++ and can compile on a Linux computer or within a Vagrant-based Linux VM.


The project documentation (including tool [download links]((http://la.dronekit.io/guide/getting_started.html#installing))) is available at [la.dronekit.io](http://la.dronekit.io/) logs for testing the tool can be found in the [/dronekit/dronekit-la-testdata](https://github.com/dronekit/dronekit-la-testdata) repository.



## Getting Started

The [Getting Started](http://la.dronekit.io/guide/getting_started.html) guide explains how to install DroneKit-LA on a Linux computer (or Linux VM), how to run the tool, and how to interpret the results.

After installing, the tool, running an analysis can be as simple as entering the following command on a terminal:

```bash
# You only need to specify the target file for a dataflash log
./dronekit-la log_file.bin

# Additionally specify frame and model type for a Solo TLOG
./dronekit-la a_log_file.tlog -f copter -m QUAD
```

The guide also lists all the other [command line arguments](http://la.dronekit.io/reference/command_line_reference.html), provides information about the [current set of analyzers](http://la.dronekit.io/reference/analyzers.html), and explains how you can extend DroneKit-LA to [get more information out of logs](http://la.dronekit.io/contributing/add_message_handler.html) and [add new analyzers](http://la.dronekit.io/contributing/add_analyzer.html).

The [DroneKit Forums](http://discuss.dronekit.io) are the best place to ask for technical support on how to use the tool. You can also check out our [Gitter channel](https://gitter.im/dronekit/dronekit-la?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge) though we prefer posts on the forums where possible.

## Developer Setup

You can build dronekit-la natively on Linux. The requirements are:

- `build-essential` package
- `g++` >= 4.8
- `libjsoncpp-dev` && `libjsoncpp0`

Use the `Makefile` in the **dronekit-la** root directory:

```bash
make
```
Both the tool and documentation can also be [built and run from within a Vagrant VM](http://la.dronekit.io/contributing/developer_setup_vagrant.html).

**Note:** At time of writing the process for building natively on Windows has [not yet been documented](https://github.com/dronekit/dronekit-la/issues/60). 



## Users and contributors wanted!

We'd love your [feedback and suggestions](https://github.com/dronekit/dronekit-la/issues) about this API and are eager to evolve it to meet your needs. Please feel free to create an issue to report bugs or feature requests.

If you want to help more directly, see our [Contributing](http://la.dronekit.io/contributing/index.html) guidelines. We welcome all types of contributions but mostly contributions that would help us shrink our [issues list](https://github.com/dronekit/dronekit-la/issues).


## Licence

DroneKit-LA is made available under the permissive open source [Apache 2.0 License](http://la.dronekit.io/about/license.html). 

## Resources

* **Documentation:** [http://la.dronekit.io/](http://la.dronekit.io/)
* **Test Logs:** [/dronekit/dronekit-la-testdata](https://github.com/dronekit/dronekit-la-testdata)
* **Forums:** TBD [http://discuss.dronekit.io/](http://discuss.dronekit.io)
* **Gitter:** TBD [https://gitter.im/dronekit/dronekit-la](https://gitter.im/dronekit/dronekit-python?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge) though we prefer posts on the forums where possible.


***

Copyright 2016 3D Robotics, Inc.