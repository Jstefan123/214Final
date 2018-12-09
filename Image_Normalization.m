% Aric Landy, John Landy, John Stefan
% This file will take in an image, resize it to 16x16, and the export the 
    % values of each of the color channels to 3 txt files

% Read in the image
img = imread('rw_test2.jpg');

% Resize the image to be 16x16 for simpler processing
small_img = imresize(img, [16, 16]);

% Extract the red, green, and blue channels
red = small_img(:,:,1);
green = small_img(:,:,2);
blue = small_img(:,:,3);

% Create the txt files for each color channel
dlmwrite('rw_test_2_red.txt', red, ' ');
dlmwrite('rw_test_2_green.txt', green, ' ');
dlmwrite('rw_test_2_blue.txt', blue, ' ');