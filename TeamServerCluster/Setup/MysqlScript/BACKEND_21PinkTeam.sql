/*
Navicat MySQL Data Transfer

Source Server         : mysql10.1.108.65
Source Server Version : 50173
Source Host           : 10.1.108.65:3306
Source Database       : BACKEND_21PinkTeam

Target Server Type    : MYSQL
Target Server Version : 60099
File Encoding         : 65001

Date: 2015-12-29 17:11:32
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `t_girl`
-- ----------------------------
DROP TABLE IF EXISTS `t_girl`;
CREATE TABLE `t_girl` (
`girl_id`  int(11) NOT NULL DEFAULT 0 COMMENT '荷官编号' ,
`girl_account_id`  int(11) NULL DEFAULT NULL COMMENT '荷官账号' ,
`girl_name`  varchar(45) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '荷官名称' ,
`girl_password`  varchar(45) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '荷官密码' ,
`girl_third_id`  varchar(45) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '荷官三方账号' ,
`girl_create_time`  timestamp NULL DEFAULT CURRENT_TIMESTAMP COMMENT '默认创建时间' ,
PRIMARY KEY (`girl_id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci

;

-- ----------------------------
-- Table structure for `t_hall`
-- ----------------------------
DROP TABLE IF EXISTS `t_hall`;
CREATE TABLE `t_hall` (
`id`  int(11) NOT NULL AUTO_INCREMENT COMMENT '自增ID' ,
`hall_server_id`  int(11) NULL DEFAULT NULL COMMENT '服务器编号' ,
`hall_server_name`  varchar(45) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '服务器名称' ,
`hall_room_id`  int(11) NOT NULL COMMENT '房间编号' ,
`hall_room_class`  int(11) NULL DEFAULT 0 COMMENT '房间标识【0:静态初始,1:动态添加】' ,
`hall_room_type`  int(11) NULL DEFAULT NULL COMMENT '房间类型【0:普通,1:特殊VIP】' ,
`hall_room_name`  varchar(45) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '房间名称' ,
`hall_room_game_id`  int(11) NULL DEFAULT NULL COMMENT '游戏编号' ,
`hall_room_game_type`  int(11) NOT NULL COMMENT '游戏类型【1:Texas,2:Baccarat】' ,
`hall_room_game_name`  varchar(45) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '游戏名称' ,
`hall_room_create_time`  timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '默认创建时间' ,
PRIMARY KEY (`hall_room_game_type`, `hall_room_id`),
INDEX `id` (`id`) USING BTREE 
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
AUTO_INCREMENT=5

;

-- ----------------------------
-- Table structure for `t_realtime_online`
-- ----------------------------
DROP TABLE IF EXISTS `t_realtime_online`;
CREATE TABLE `t_realtime_online` (
`id`  int(11) NOT NULL AUTO_INCREMENT COMMENT '自增ID' ,
`realtime_online_server_id`  int(11) NULL DEFAULT NULL COMMENT '服务器编号' ,
`realtime_online_server_name`  varchar(45) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '服务器名称' ,
`realtime_online_game_id`  int(11) NULL DEFAULT NULL COMMENT '游戏编号' ,
`realtime_online_game_type`  int(11) NOT NULL COMMENT '游戏类型【1:Texas,2:Baccarat】' ,
`realtime_online_game_name`  varchar(45) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '游戏名称' ,
`realtime_online_room_id`  int(11) NOT NULL COMMENT '房间编号' ,
`realtime_online_room_type`  int(11) NULL DEFAULT NULL COMMENT '房间类型[0:普通,1:特殊VIP]' ,
`realtime_online_room_name`  varchar(45) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '房间名称' ,
`realtime_online_dealer_id`  int(11) NULL DEFAULT NULL COMMENT '荷官编号' ,
`realtime_online_dealer_name`  varchar(45) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '荷官名称' ,
`realtime_online_usercounts`  bigint(20) NULL DEFAULT NULL COMMENT '实时在线用户统计' ,
`realtime_online_create_time`  timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '默认创建时间' ,
PRIMARY KEY (`realtime_online_game_type`, `realtime_online_room_id`),
INDEX `id` (`id`) USING BTREE 
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
AUTO_INCREMENT=1

;

-- ----------------------------
-- Procedure structure for `sp_get_girl`
-- ----------------------------
DROP PROCEDURE IF EXISTS `sp_get_girl`;
DELIMITER ;;
CREATE DEFINER=`root`@`%` PROCEDURE `sp_get_girl`()
BEGIN
	SELECT
    girl_id,
    girl_account_id,
    girl_name,
    girl_password,
    girl_third_id,
    unix_timestamp(girl_create_time)
    FROM t_girl;
END
;;
DELIMITER ;

-- ----------------------------
-- Procedure structure for `sp_get_hall`
-- ----------------------------
DROP PROCEDURE IF EXISTS `sp_get_hall`;
DELIMITER ;;
CREATE DEFINER=`root`@`%` PROCEDURE `sp_get_hall`(
IN T_hall_server_id INT,
IN T_hall_room_game_type INT
)
BEGIN
	SELECT
    hall_server_id,
    hall_server_name,
    hall_room_id,
    hall_room_class,
    hall_room_type,
    hall_room_name,
    hall_room_game_id,
    hall_room_game_type,
    hall_room_game_name,
    unix_timestamp(hall_room_create_time)
    FROM t_hall
    WHERE 
    hall_server_id = T_hall_server_id AND 
    hall_room_game_type = T_hall_room_game_type;
END
;;
DELIMITER ;

-- ----------------------------
-- Procedure structure for `sp_save_realtime_online`
-- ----------------------------
DROP PROCEDURE IF EXISTS `sp_save_realtime_online`;
DELIMITER ;;
CREATE DEFINER=`root`@`%` PROCEDURE `sp_save_realtime_online`(
IN T_realtime_online_server_id INT,
IN T_realtime_online_server_name VARCHAR(45),
IN T_realtime_online_game_id INT,
IN T_realtime_online_game_type INT,
IN T_realtime_online_game_name VARCHAR(45),
IN T_realtime_online_room_id INT,
IN T_realtime_online_room_type INT,
IN T_realtime_online_room_name VARCHAR(45),
IN T_realtime_online_dealer_id INT,
IN T_realtime_online_dealer_name VARCHAR(45),
IN T_realtime_online_usercounts BIGINT
)
BEGIN
	REPLACE INTO t_realtime_online
    ( realtime_online_server_id,
      realtime_online_server_name,
      realtime_online_game_id,
      realtime_online_game_type,
      realtime_online_game_name,
      realtime_online_room_id,
      realtime_online_room_type,
      realtime_online_room_name,
      realtime_online_dealer_id,
      realtime_online_dealer_name,
      realtime_online_usercounts
	)
    VALUES 
    (
      T_realtime_online_server_id,
      T_realtime_online_server_name,
      T_realtime_online_game_id,
      T_realtime_online_game_type,
      T_realtime_online_game_name,
      T_realtime_online_room_id,
      T_realtime_online_room_type,
      T_realtime_online_room_name,
      T_realtime_online_dealer_id,
      T_realtime_online_dealer_name,
      T_realtime_online_usercounts
	);
END
;;
DELIMITER ;

-- ----------------------------
-- Auto increment value for `t_hall`
-- ----------------------------
ALTER TABLE `t_hall` AUTO_INCREMENT=5;

-- ----------------------------
-- Auto increment value for `t_realtime_online`
-- ----------------------------
ALTER TABLE `t_realtime_online` AUTO_INCREMENT=1;
