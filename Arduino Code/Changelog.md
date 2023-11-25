# 11/10/2023 1:50 PM EST
Committed the original file into the repository with the ability to sense distance and give power to a pin on an Arduino board based on the distance measured.
# 11/10/2023 2:04 PM EST
Changed around some of the descriptions to fit properly into newer code and added more robust descriptions.
# 11/14/2023 3:05 PM EST
Made it so no data will be displayed when distance > 8000mm.
# 11/16/2023 3:14 PM EST
Turned the data into 8 bit unsigned integers to prevent overflow of one data type to the other.
# 11/25/2023 6:34 PM EST
Converted the code to use the TOFSense-M sensor instead of the TOFSense-P, and then using the average distance to send voltage to the motor associated with each sensor in cascade. This is using a radar style approach where we go around the person, using one sensor at a time.
# 11/25/2023 6:44 PM EST
Fixed an error in the code that made it so that only one sensor's data was used for each motor. Now each sensor's data should be scanned.
