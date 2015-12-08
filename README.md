# Area and Perimeter of an object
Calculate area and perimeter of the image

/* Calculate Area */
1. Load image as grayscale
2. Thresholding using 'CV_THRESH_BINARY_INV' to get inverse of your binary image. You can adjust threshold value and maximum value to get better binary image.
3. Apply image enhancement (optional)
4. Convert your image into matrices
5. Counting total pixel which has intensity = 255 (white) using nested loop

/* Calculate Perimeter */
1. Dilate our binary image using iterations = 1 pixel
2. Invers the dilated image using 'bitwise_not' function. ('Bitwise_not' function will convert 0 -> 1, vice versa)
3. After invers process done, you will find now the object in black and the background in white
4. Then add the dilated invers image with the first binary image
5. Voila, you will get perimeter of your object
6. Counting total pixel which has intensity = 0 (black) using nested loop
