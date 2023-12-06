# EMG-Based-Elbow-Exoskeleton
The project focuses on the development of an upper limb elbow exoskeleton, a wearable robot designed to enhance human work. Specifically, this exoskeleton utilizes two main components: the primary and secondary systems, aimed at optimizing its functionality.

In the primary system, the crucial data acquisition process begins with surface electromyography (sEMG). This involves capturing the EMG signal from the kit, which is already rectified and smoothed internally. The microcontroller plays a pivotal role in this phase, equipped with programmed filters that extract essential data while eliminating noise and motion artifacts from the signal.

Concurrently, the secondary input involves state information gathered from two limit switches mounted on the motor pulley. These switches provide critical joint position data, signaling when the elbow joint reaches its fully flexed or extended positions.

The challenge arises in interpreting the muscle's intentions - the force exerted and the desired joint movement. This is addressed by feeding the filtered EMG signal into the microcontroller, which employs the Threshold Difference method to calculate the intended position. Once the desired output is determined, the microcontroller commands the motor unit to move the elbow joint accordingly.

The system continually refines its movements through a feedback loop. The motor's action prompts the limit switches to signal joint position changes, which are then compared to the intended position calculated from the EMG signal. This iterative process allows for seamless adjustments in real-time.

![image](https://github.com/alik912/EMG-Based-Elbow-Exoskeleton/assets/64403968/da628e37-15f2-4b15-9fd3-d0a2f91f820b)

By combining data acquisition through sEMG, joint position detection using limit switches, and intelligent interpretation of muscle intentions by the microcontroller, this project aims to develop an innovative upper limb elbow exoskeleton. Ultimately, this technology seeks to augment human capabilities by precisely assisting and enhancing upper limb movements, fostering potential applications in various fields requiring enhanced human work support.

For details about the project, visit here: https://www.instructables.com/EMG-Based-Elbow-Exoskeleton-With-Arduino-Mega/
