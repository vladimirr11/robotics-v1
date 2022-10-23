import os.path
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    """
    """
    ld = LaunchDescription()
    node_name = 'robo_miner_controller'
    config = os.path.join(
        get_package_share_directory(node_name),
        'config',
        'params.yaml'
    )

    print(f'[launch.py] - loading node ({node_name}) params from: ({config})')

    node = Node(
        package=node_name,
        executable=node_name,
        output='screen',
        # prefix=['gdbserver localhost:3000'],
        emulate_tty=True,
        parameters=[config]
    )

    ld.add_action(node)
    return ld
