clear all;
close all;
clc;

load("part4_mflops_nkm_mnk.dat");
figure;
grid on; hold on;
plot(part4_mflops_nkm_mnk(:,1),part4_mflops_nkm_mnk(:,2),"*");
plot(part4_mflops_nkm_mnk(:,1),part4_mflops_nkm_mnk(:,3),"d");
title("Matrix multiplication with different block size");
legend("nkm","nat");
xlabel("Block size");
ylabel("MFlops");

%%
close all;
clc;
load("part4_l1_l2_miss_nkm_mnk.dat")

figure;
grid on; hold on;
plot(part4_l1_l2_miss_nkm_mnk(:,1),part4_l1_l2_miss_nkm_mnk(:,2),"-*");
plot(part4_l1_l2_miss_nkm_mnk(:,1),part4_l1_l2_miss_nkm_mnk(:,3),"-d");
xlabel("Block size");
ylabel("Number of miss");
title("L1 cache miss with different block size");
legend("nkm","nat");
figure;
grid on; hold on;
plot(part4_l1_l2_miss_nkm_mnk(:,1),part4_l1_l2_miss_nkm_mnk(:,4),"-*");
plot(part4_l1_l2_miss_nkm_mnk(:,1),part4_l1_l2_miss_nkm_mnk(:,5),"-d");
legend("nkm","nat");
xlabel("Block size");
ylabel("Number of miss");
title("L2 cache miss with different block size");