# Area and Perimeter of an object<br>
Calculate area and perimeter of the image<br>
<br>
<h2> Calculate Area </h2>
1. Load image as grayscale<br>
2. Thresholding using 'CV_THRESH_BINARY_INV' to get inverse of your binary image. You can adjust threshold value and maximum value to get better binary image.<br>
3. Apply image enhancement (optional)<br>
4. Convert your image into matrices<br>
5. Counting total pixel which has intensity = 255 (white) using nested loop<br>

<h2>Calculate Perimeter </h2>
1. Dilate our binary image using iterations = 1 pixel<br>
2. Invers the dilated image using 'bitwise_not' function. ('Bitwise_not' function will convert 0 -> 1, vice versa)<br>
3. After invers process done, you will find now the object in black and the background in white<br>
4. Then add the dilated invers image with the first binary image<br>
5. You will get perimeter of your object (black line)<br>
6. Counting total pixel which has intensity = 0 (black) using nested loop<br>
