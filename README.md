# teleop_roomba_joy  
ルンバをジョイスティックで動かす  

使用するもの　
ルンバ  
ジョイスティック  
アイロボットルンバ コミュニケーションケーブル（USB）  

インストール  
'$cd catkin_ws/src'  
ルンバのROS用ドライバをインスト−ル  
'$git clone https://github.com/NetBUG/roomba_500_series.git'  
'$git clone https://github.com/NetBUG/cereal_port.git'  
'$git clone https://github.com/nao2853/teleop_roomba_joy.git'  
'$cd roomba_500_series'  
'$vim CMakeList.txt'  
target_link_libraries(roomba560_node cereal_port ${catkin_LIBRARIES})を  
target_link_libraries(roomba560_node /home/USER/catkin_ws/src/cereal_port ${catkin_LIBRARIES})に変更  

使い方  
PCにジョイスティックを接続する  
'$roslaunch roomba_teleop_joy roomba_teleop_joy.launch'  
コミュニケーションケーブルでPCとルンバを接続する  
'$rosrun roomba_500_series roomba500_light_node'  
  
終わり方　　
ノードを殺したあとコミュニケーションケーブルを外す  
その後ルンバのCLEARボタンを押す  

動画  
https://www.youtube.com/edit?video_id=wR1795Z5T-k
