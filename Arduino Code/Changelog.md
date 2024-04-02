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
# 11/29/2023 5:18 PM EST
Fixed an error where sum, avg, and count kept increasing and made it easier to distinguish when the program is changing sensors.
# 1/18/2024 2:13 PM EST
Switched functionality to work with TOFSense-M sensors rather than TOFSense-P, which allows for greater accuracy and gives more context to the user. Additionally, split the sensor into 4 quadrants, enabling us to use 4 separate motors for each sensor, which can allow for us to provide more situational awareness to the user.
# 2/6/2024 3:22 PM EST
Due to innacuracies in lidar sensing, swapped to a hybrid ultrasonic and lidar sensing. The ultrasonic sensors are used for forward and backward sensing as they are more accurate in that scenario. The lidar sensors are used in side movement sensing as they are much more accurate in detecting objects moving around.
# 2/8/2024 3:50 PM EST
Fixed some number discrepencies.
# 2/23/2024 12:47 PM EST
Swapped to fully ultrasonic sensing. Updated functionality to incorporate 4 sensors and motors simultaneously.
# 4/2/2024 11:44 AM EST
Improved error checking algorithm. Also included ability to wirelessly monitor the board via the Arduino Cloud.
