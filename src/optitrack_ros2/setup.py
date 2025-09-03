from setuptools import setup

package_name = 'optitrack_ros2'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools', 'rclpy', 'geometry_msgs'],
    zip_safe=True,
    maintainer='your_name',
    maintainer_email='your_email@example.com',
    description='OptiTrack ROS2 Integration',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'opti_track_node = optitrack_ros2.opti_track_node:main',
            'optitrack_streamer = optitrack_ros2.optitrack_streamer:main'
        ],
    },
)
