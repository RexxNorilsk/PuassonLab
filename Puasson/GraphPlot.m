tmp_data = importdata('output.txt',' ');


x = 1:size(tmp_data, 1);
y = 1:size(tmp_data, 2);
tmp_data(tmp_data==0)=nan;
s = surf(x,y,tmp_data);
s.EdgeColor = 'none';
colorbar;
