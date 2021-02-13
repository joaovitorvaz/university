module portao (a, b, c, d, v);
  input a, b, c, d;
  output v;
  reg v;
  always @ (*)
    begin
        v= (a | b & c) | (~(a | b) & d);
    end
endmodule

module top;
    reg t_a, t_b, t_c, t_d;
    wire t_v;
    initial
        begin
            t_a = 0;
            t_b = 0;
            t_c = 0;
            t_d = 0;
        end

    initial
        begin
            #16 $dumpflush; $stop;
        end

    initial
        begin
          $dumpfile("portao.dump");
    	    $dumpvars(0,t_a,t_b,t_c,t_d,t_v);
    	    $dumpon;
        	$display("Tempo \t a \t b \t c \t d \t v");
	        $display("-----------------------------------");
        	$monitor("%0d \t %b \t %b \t %b \t %b \t %b",$time,t_a,t_b,t_c,t_d,t_v);
         end

    always
        begin
        	#1 {t_a,t_b,t_c,t_d}={t_a,t_b,t_c,t_d}+1;
        end

    portao porta(.a(t_a),.b(t_b),.c(t_c),.d(t_d),.v(t_v));

endmodule
