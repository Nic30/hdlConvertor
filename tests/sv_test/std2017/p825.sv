module tri_latch (qout, nqout, clock, data, enable);
output qout, nqout;
input clock, data, enable;
tri
qout, nqout;
not #5 n1 (ndata, data);
nand #(3,5) n2 (wa, data, clock),
            n3 (wb, ndata, clock);
nand #(12,15) n4 (q, nq, wa),
              n5 (q, nq, wa);
bufif1 #(3,7,13)  q_drive (qout, q, enable),
                  nq_drive (nqout, nq, enable);
endmodule


module iobuf (io1, io2, dir);
bufif0
#(5:7:9, 8:10:12, 15:18:21) b1 (io1, io2, dir);
bufif1
#(6:8:10, 5:7:9, 13:17:19) b2 (io2, io1, dir);
endmodule
