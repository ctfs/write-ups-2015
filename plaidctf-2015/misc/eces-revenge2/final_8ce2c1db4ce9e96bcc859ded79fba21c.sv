`default_nettype none
module testbench;
   logic clock, reset_L, win;
   logic [9:0] counter;
   logic [31:0] user_in;

   datapath d(.*);

   initial begin
      clock = 0;
      // Fill in the constant such that when the circuit hits cycle 360, 
      // the logic "win" should be high. 
      user_in = 32'b????????????????????????????????;
      reset_L = 0;
      #5 clock = ~clock;
      #5 clock = ~clock;
      #5 clock = ~clock;
      reset_L <= #1 1;
      for(counter = 0; counter < 70; counter++) begin
        #5 clock = ~clock;
      end

   end
   
endmodule : testbench

module datapath(
    input logic clock, reset_L,
    input logic [31:0] user_in,
    output logic win);

   logic [3:0] r1_out, r2_out, a_out, s_l, s_h;
   logic m_o,  win_in, filler;
   logic i_g_o, reset, init, init_L, c2_clock, reg_en, reg_en_opp;
   logic out_x1, w_t, IMO1, IMO2, IMO3, IMO4, im_f, init_delay;
   logic [7:0] is_i;

   part_d c1(clock, reset_L, init_L, 1'b1, 4'b0, s_l);
   part_d c2(c2_clock, reset_L, 1'b1, 1'b1, 4'b0, s_h);

   part_a r1(a_out, 1'b0, reset, reg_en, r1_out);
   part_a r2(a_out, 1'b0, reset, reg_en_opp, r2_out);
   part_a s({w_t, 1'b1, win_in, init}, 1'b0, reset, clock, {i_g_o, init_L, win, init_delay});

   part_c m1({r2_out, r1_out}, is_i[2:0], 1'b0, m_o);

   part_b a1(r1_out, r2_out, init_delay, a_out,);
   part_c IM1(user_in[7:0], is_i[2:0], 1'b0, IMO1);
   part_c IM2(user_in[15:8], is_i[2:0], 1'b0, IMO2);
   part_c IM3(user_in[23:16], is_i[2:0], 1'b0, IMO3);
   part_c IM4(user_in[31:24], is_i[2:0], 1'b0, IMO4);
   part_c IM5({4'b0, IMO4, IMO3, IMO2, IMO1}, is_i[5:3], 1'b0, im_f);

   assign reset = ~reset_L;
   assign init = ~init_L;
   assign c2_clock = ~s_l[3];
   
   assign reg_en = init | is_i[2];
   assign reg_en_opp = ~reg_en;

   assign out_x1 = im_f ^ m_o;

   assign w_t = i_g_o | out_x1;
   
   assign win_in = (~w_t & (is_i == 8'b00011111)) | win;

   assign is_i = {s_h, s_l};

endmodule: datapath

module part_a
  (input  logic [3:0] D,
   input  logic       en_L, clear, clock,
   output logic [3:0] Q);

  always_ff @(posedge clock, posedge clear) begin
    if(~clear) begin 
      if(~en_L)
        Q <= D;
    end
    else
      Q <= 0;
  end 
endmodule : part_a

module part_b
  (input  logic [3:0] A, B,
   input  logic       Cin,
   output logic [3:0] S,
   output logic       Cout);

  assign {Cout, S} = A + B + Cin;

endmodule : part_b

module part_c
  (input  logic [7:0] I,
   input  logic [2:0] S,
   input  logic       strobe,
   output logic       Y);

  assign Y = (strobe) ? 1'b0 : I[S];

endmodule : part_c

module part_d
  (input logic clk, rst_L, en, Pload_L,
   input logic [3:0] Pin,
   output logic [3:0] count);

  always @(posedge clk) begin
    if (~rst_L)
      count <= 0;
    else begin
      if(~Pload_L)
        count <= Pin;
      else
        count <= en ? (count + 1) : count;
    end
  end
endmodule: part_d