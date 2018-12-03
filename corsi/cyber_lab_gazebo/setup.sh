cp cyber_lab.world ~/catkin_ws/src/turtlebot3_simulations/turtlebot3_gazebo/models/.
cp turtlebot3_cyber_lab.launch ~/catkin_ws/src/turtlebot3_simulations/turtlebot3_gazebo/launch/.
cp -r cyber_lab ~/catkin_ws/src/turtlebot3_simulations/turtlebot3_gazebo/models/.

echo Select your turtlebot model
echo export TURTLEBOT3_MODEL=waffle

echo Launch cyber_lab with turtlebot:
echo roslaunch turtlebot3_gazebo turtlebot3_cyber_lab.launch

echo 
echo Then launch Turtlebot autonomous navigation:
echo roslaunch turtlebot3_gazebo turtlebot3_simulation.launch
