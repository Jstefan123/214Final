% Aric Landy, John Landy, John Stefan
% This file will take in an image, resize it to 16x16, and the export the 
    % values of each of the color channels to 3 txt files

% Read in the image
img = imread('oneway3.jpg');

% Resize the image to be 16x16 for simpler processing
small_img = imresize(img, [16, 16]);

% Extract the red, green, and blue channels
red = small_img(:,:,1);
green = small_img(:,:,2);
blue = small_img(:,:,3);

% Create the txt files for each color channel
dlmwrite('oneway_3_red.txt', red, ' ');
dlmwrite('oneway_3_green.txt', green, ' ');
dlmwrite('oneway_3_blue.txt', blue, ' ');