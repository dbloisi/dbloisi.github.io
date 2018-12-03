# simple_line_follower.py

#ASL Giugno 2018 UNIVR
#this code is derived from
#https://gist.github.com/CS2098/ecb3a078ed502c6a7d6e8d17dc095b48

# Import the EV3-robot library
import ev3dev.ev3 as ev3
from time import sleep


class LineFollower:
    # Constructor
    def __init__(self):
        self.ts = ev3.TouchSensor()
        assert self.ts.connected, "Connect a touch sensor to any port"
        self.shut_down = False

    # Main method
    def run(self):

        # sensors
        cs = ev3.ColorSensor();      assert cs.connected  # measures light intensity
        us = ev3.UltrasonicSensor(); assert us.connected  # measures distance

        cs.mode = 'COL-REFLECT'  # measure light intensity
        us.mode = 'US-DIST-CM'   # measure distance in cm

        ev3.Sound.speak('Sensors OK!').wait()
		
		sleep(2)

        # motors
        lm = ev3.LargeMotor('outB');  assert lm.connected  # left motor
        rm = ev3.LargeMotor('outA');  assert rm.connected  # right motor

        ev3.Sound.speak('Motors OK!').wait()

        sleep(2)

        speed = 360/4  # deg/sec, [-1000, 1000]

        # initial measurment
        target_value = cs.value()

        # Start the main loop
        while not self.shut_down:

            # deal with obstacles
            distance = us.value() // 10  # convert mm to cm


            # Calculate steering using PID algorithm
            error = abs(target_value - cs.value())
			 print("error: " + str(error))

            if error < 20:
                # run motors
                lm.run_timed(time_sp=200, speed_sp=speed)
                rm.run_timed(time_sp=200, speed_sp=speed)
                sleep(0.5)
            else:
                #search left side
                lm.run_timed(time_sp=100, speed_sp=speed)
                rm.run_timed(time_sp=100, speed_sp=-speed)
                sleep(0.5)
                error = abs(target_value - cs.value())
				if error > 20:
                    #search left side
                    lm.run_timed(time_sp=200, speed_sp=-speed)
                    rm.run_timed(time_sp=200, speed_sp=speed)
                    sleep(0.5)
                    error = abs(target_value - cs.value())

            # Check if buttons pressed (for pause or stop)
            #print("ts.value:" + str(self.ts.value()))
            if self.ts.value():  # Stop
                print("Exit program... ")
                self.shut_down = True


        print("[Continue]")
        ev3.Leds.set_color(ev3.Leds.LEFT, ev3.Leds.GREEN)
        ev3.Leds.set_color(ev3.Leds.RIGHT, ev3.Leds.GREEN)


# Main function
if __name__ == "__main__":
    robot = LineFollower()
    robot.run()
