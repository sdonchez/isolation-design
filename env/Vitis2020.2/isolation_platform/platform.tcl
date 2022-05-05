# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct C:\Users\sgdon\Source\sdonchez\isolation-test\env\Vitis2020.2\isolation_platform\platform.tcl
# 
# OR launch xsct and run below command.
# source C:\Users\sgdon\Source\sdonchez\isolation-test\env\Vitis2020.2\isolation_platform\platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {isolation_platform}\
-hw {C:\Users\sgdon\Source\sdonchez\isolation-test\Vivado\isolation_design\isolation_design.xsa}\
-proc {psu_cortexa53_0} -os {standalone} -arch {64-bit} -no-boot-bsp -fsbl-target {psu_cortexa53_0} -out {C:/Users/sgdon/Source/sdonchez/isolation-test/env/Vitis2020.2}

platform write
platform generate -domains 
platform active {isolation_platform}
domain create -name {standalone_psu_cortexr5_0} -os {standalone} -proc {psu_cortexr5_0} -arch {32-bit} -display-name {standalone_psu_cortexr5_0} -desc {} -runtime {cpp}
platform generate -domains 
platform write
domain -report -json
domain create -name {zynqmp_fsbl} -os {standalone} -proc {psu_cortexr5_0} -arch {32-bit} -display-name {zynqmp_fsbl} -desc {} -runtime {cpp}
platform generate -domains 
domain -report -json
platform write
bsp reload
bsp setlib -name xilffs -ver 4.4
bsp setlib -name xilpm -ver 3.2
bsp setlib -name xilsecure -ver 4.3
bsp config zynqmp_fsbl_bsp "true"
bsp write
bsp reload
catch {bsp regenerate}
domain create -name {zynqmp_pmufw_u0} -os {standalone} -proc {psu_pmu_0} -arch {32-bit} -display-name {zynqmp_pmufw_u0} -desc {} -runtime {cpp}
platform generate -domains 
platform write
domain -report -json
platform generate
platform active {isolation_platform}
platform generate
platform generate
platform generate
platform generate
platform generate
platform generate
platform active {isolation_platform}
platform generate -domains 
platform config -create-boot-bsp -fsbl-target psu_cortexr5_0
platform generate
platform generate
platform generate
platform generate
platform generate
platform generate
platform generate
platform active {isolation_platform}
domain active {standalone_domain}
bsp reload
bsp config stdout "psu_coresight_0"
bsp config stdin "psu_coresight_0"
bsp write
bsp reload
catch {bsp regenerate}
domain active {standalone_psu_cortexr5_0}
bsp reload
bsp config stdin "psu_coresight_0"
bsp config stdout "psu_coresight_0"
bsp write
bsp reload
catch {bsp regenerate}
domain active {zynqmp_fsbl}
bsp reload
bsp config stdin "psu_coresight_0"
bsp config stdout "psu_coresight_0"
bsp write
bsp reload
catch {bsp regenerate}
domain active {zynqmp_pmufw_u0}
bsp reload
bsp write
