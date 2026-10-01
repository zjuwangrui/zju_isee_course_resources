// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2023.1 (win64) Build 3865809 Sun May  7 15:05:29 MDT 2023
// Date        : Sun Mar 29 23:03:58 2026
// Host        : LAPTOP-8QC78VQI running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub
//               d:/constructing_projects/FPGA_projects/FPGA_design_course/lab3_IPCore/vivado/IPCore.gen/sources_1/ip/PictureROM/PictureROM_stub.v
// Design      : PictureROM
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7a200tfbg484-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* x_core_info = "dist_mem_gen_v8_0_13,Vivado 2023.1" *)
module PictureROM(a, clk, qspo_ce, qspo)
/* synthesis syn_black_box black_box_pad_pin="a[11:0],qspo_ce,qspo[23:0]" */
/* synthesis syn_force_seq_prim="clk" */;
  input [11:0]a;
  input clk /* synthesis syn_isclock = 1 */;
  input qspo_ce;
  output [23:0]qspo;
endmodule
