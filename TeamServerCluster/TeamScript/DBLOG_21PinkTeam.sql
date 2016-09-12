/*
Navicat MySQL Data Transfer

Source Server         : mysql10.1.108.65
Source Server Version : 50628
Source Host           : 10.1.108.65:3306
Source Database       : DBLOG_21PinkTeam

Target Server Type    : MYSQL
Target Server Version : 60099
File Encoding         : 65001

Date: 2016-01-06 14:12:19
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `t_gm`
-- ----------------------------
DROP TABLE IF EXISTS `t_gm`;
CREATE TABLE `t_gm` (
`id`  int(11) NOT NULL AUTO_INCREMENT ,
`account_id`  int(11) NULL DEFAULT NULL ,
`gm_id`  int(11) NULL DEFAULT NULL ,
`gm_action_type`  int(11) NULL DEFAULT NULL ,
`gm_describe`  varchar(45) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`gm_create_time`  timestamp NULL DEFAULT CURRENT_TIMESTAMP ,
PRIMARY KEY (`id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=latin1 COLLATE=latin1_swedish_ci
AUTO_INCREMENT=1

;

-- ----------------------------
-- Table structure for `t_login`
-- ----------------------------
DROP TABLE IF EXISTS `t_login`;
CREATE TABLE `t_login` (
`id`  int(11) NOT NULL AUTO_INCREMENT COMMENT '自增编号' ,
`account_id`  int(11) NULL DEFAULT NULL COMMENT '账号编号' ,
`login_name`  varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '账号名称' ,
`login_platform_id`  int(11) NULL DEFAULT NULL COMMENT '平台编号' ,
`login_third_id`  varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '三方编号' ,
`login_third_account`  varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '三方账号' ,
`login_login_time`  timestamp NULL DEFAULT NULL COMMENT '登录时间' ,
`login_server_id`  int(11) NULL DEFAULT NULL COMMENT '服务器编号' ,
`login_login_ip`  varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '登录IP地址' ,
`login_login_status`  int(11) NULL DEFAULT NULL COMMENT '登录状态' ,
`login_create_time`  timestamp NULL DEFAULT CURRENT_TIMESTAMP COMMENT '默认创建时间' ,
PRIMARY KEY (`id`),
UNIQUE INDEX `id_UNIQUE` (`id`) USING BTREE 
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
COMMENT='tlog_login:user login log'
AUTO_INCREMENT=95

;

-- ----------------------------
-- Table structure for `t_logout`
-- ----------------------------
DROP TABLE IF EXISTS `t_logout`;
CREATE TABLE `t_logout` (
`id`  int(11) NOT NULL AUTO_INCREMENT COMMENT '自增编号' ,
`account_id`  int(11) NULL DEFAULT NULL COMMENT '账号编号' ,
`logout_name`  varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '账号名称' ,
`logout_platform_id`  int(11) NULL DEFAULT NULL COMMENT '平台编号' ,
`logout_third_id`  varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '三方编号' ,
`logout_third_account`  varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '三方账号' ,
`logout_login_time`  timestamp NULL DEFAULT NULL COMMENT '登录时间' ,
`logout_logout_time`  timestamp NULL DEFAULT NULL COMMENT '登出时间' ,
`logout_server_id`  int(11) NULL DEFAULT NULL COMMENT '服务器编号' ,
`logout_login_ip`  varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '登录IP地址' ,
`logout_create_time`  timestamp NULL DEFAULT CURRENT_TIMESTAMP COMMENT '默认创建时间' ,
PRIMARY KEY (`id`),
UNIQUE INDEX `id_UNIQUE` (`id`) USING BTREE 
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
COMMENT='tlog_logout: use logout'
AUTO_INCREMENT=20

;

-- ----------------------------
-- Table structure for `t_online`
-- ----------------------------
DROP TABLE IF EXISTS `t_online`;
CREATE TABLE `t_online` (
`id`  int(11) NOT NULL AUTO_INCREMENT ,
`online_server_id`  int(11) NULL DEFAULT NULL COMMENT 'online_server_id' ,
`online_game_type`  int(11) NULL DEFAULT NULL COMMENT 'online_game_type' ,
`online_room_type`  int(11) NULL DEFAULT NULL COMMENT 'online_room_type' ,
`online_game_id`  int(11) NULL DEFAULT NULL COMMENT 'online_game_id' ,
`online_room_id`  int(11) NULL DEFAULT NULL COMMENT 'online_room_id' ,
`online_girl_id`  int(11) NULL DEFAULT NULL COMMENT 'online_girl_id' ,
`online_users_count`  int(11) NULL DEFAULT NULL ,
`online_create_time`  timestamp NULL DEFAULT CURRENT_TIMESTAMP ,
PRIMARY KEY (`id`),
UNIQUE INDEX `id_UNIQUE` (`id`) USING BTREE 
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
COMMENT='tlog_online'
AUTO_INCREMENT=1

;

-- ----------------------------
-- Table structure for `t_pvggift`
-- ----------------------------
DROP TABLE IF EXISTS `t_pvggift`;
CREATE TABLE `t_pvggift` (
`id`  int(11) NOT NULL AUTO_INCREMENT ,
`account_id`  int(11) NULL DEFAULT NULL ,
`pvggift_name`  varchar(45) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`pvggift_girl_id`  int(11) NULL DEFAULT NULL ,
`pvggift_girl_third_id`  varchar(45) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`pvggift_gift_id`  int(11) NULL DEFAULT NULL ,
`pvggift_gift_num`  int(11) NULL DEFAULT NULL ,
`pvggift_gift_price`  int(11) NULL DEFAULT NULL ,
`pvggift_money_type`  int(11) NULL DEFAULT NULL ,
`pvggift_unbind_pink`  int(11) NULL DEFAULT NULL ,
`pvggift_bind_pink`  int(11) NULL DEFAULT NULL ,
`pvggift_game_type`  int(11) NULL DEFAULT NULL ,
`pvggift_game_id`  int(11) NULL DEFAULT NULL ,
`pvggift_room_id`  int(11) NULL DEFAULT NULL ,
`pvggift_server_id`  int(11) NULL DEFAULT NULL ,
`pvggift_room_type`  int(11) NULL DEFAULT NULL ,
`pvggift_even_count`  int(11) NULL DEFAULT NULL ,
`pvggift_broadcast_type`  int(11) NULL DEFAULT NULL ,
`pvggift_create_time`  timestamp NULL DEFAULT CURRENT_TIMESTAMP ,
PRIMARY KEY (`id`),
UNIQUE INDEX `id_UNIQUE` (`id`) USING BTREE 
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
COMMENT='tlog_pvggift'
AUTO_INCREMENT=1

;

-- ----------------------------
-- Table structure for `t_pvpgift`
-- ----------------------------
DROP TABLE IF EXISTS `t_pvpgift`;
CREATE TABLE `t_pvpgift` (
`id`  int(11) NOT NULL AUTO_INCREMENT ,
`pvpgift_from_account_id`  int(11) NULL DEFAULT NULL COMMENT 'pvpgift_from_account_id' ,
`pvpgift_to_account_id`  int(11) NULL DEFAULT NULL COMMENT 'pvpgift_to_account_id' ,
`pvpgift_from_name`  varchar(45) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'pvpgift_from_name' ,
`pvpgift_to_name`  varchar(45) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'pvpgift_to_name' ,
`pvpgift_platform_id`  int(11) NULL DEFAULT NULL COMMENT 'pvpgift_platform_id' ,
`pvpgift_from_third_id`  varchar(45) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'pvpgift_from_third_id' ,
`pvpgift_to_third_id`  varchar(45) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'pvpgift_to_third_id' ,
`pvpgift_from_third_account`  varchar(45) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'pvpgift_from_third_account' ,
`pvpgift_to_third_account`  varchar(45) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'pvpgift_to_third_account' ,
`pvpgift_gift_id`  int(11) NULL DEFAULT NULL COMMENT 'pvpgift_gift_id' ,
`pvpgift_gift_price`  int(11) NULL DEFAULT NULL COMMENT 'pvpgift_gift_price' ,
`pvpgift_unbind_chip`  int(11) NULL DEFAULT NULL COMMENT 'pvpgift_unbind_chip cost' ,
`pvpgift_bind_chip`  int(11) NULL DEFAULT NULL COMMENT 'pvpgift_bind_chip cost' ,
`pvpgift_server_id`  int(11) NULL DEFAULT NULL COMMENT 'pvpgift_server_id' ,
`pvpgift_room_id`  int(11) NULL DEFAULT NULL COMMENT 'pvpgift_room_id' ,
`pvpgift_create_time`  timestamp NULL DEFAULT CURRENT_TIMESTAMP COMMENT 'pvpgift_create_time' ,
PRIMARY KEY (`id`),
UNIQUE INDEX `id_UNIQUE` (`id`) USING BTREE 
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
COMMENT='tlog_pvpgift'
AUTO_INCREMENT=1

;

-- ----------------------------
-- Table structure for `t_room`
-- ----------------------------
DROP TABLE IF EXISTS `t_room`;
CREATE TABLE `t_room` (
`id`  int(11) NOT NULL AUTO_INCREMENT ,
`account_id`  int(11) NULL DEFAULT NULL ,
`room_account_name`  varchar(45) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`room_platform_id`  int(11) NULL DEFAULT NULL ,
`room_third_id`  varchar(45) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`room_third_account`  varchar(45) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`room_id`  int(11) NULL DEFAULT NULL ,
`room_girl_id`  int(11) NULL DEFAULT NULL ,
`room_action`  int(11) NULL DEFAULT NULL COMMENT 'room_action\n1:enter room\n2:leave rooom' ,
`room_create_time`  timestamp NULL DEFAULT CURRENT_TIMESTAMP ,
PRIMARY KEY (`id`),
UNIQUE INDEX `id_UNIQUE` (`id`) USING BTREE 
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
COMMENT='tlog_room'
AUTO_INCREMENT=1

;

-- ----------------------------
-- Table structure for `t_texas_bet`
-- ----------------------------
DROP TABLE IF EXISTS `t_texas_bet`;
CREATE TABLE `t_texas_bet` (
`id`  int(11) NOT NULL AUTO_INCREMENT ,
`account_id`  int(11) NULL DEFAULT NULL COMMENT '账号编号' ,
`bet_board_id`  int(11) NULL DEFAULT NULL COMMENT '牌局编号' ,
`bet_game_type`  int(11) NULL DEFAULT NULL COMMENT '游戏类型' ,
`bet_game_id`  int(11) NULL DEFAULT NULL COMMENT '游戏编号' ,
`bet_room_id`  int(11) NULL DEFAULT NULL COMMENT '房间编号' ,
`bet_girl_id`  int(11) NULL DEFAULT NULL COMMENT '荷官编号' ,
`bet_jackpot`  int(11) NULL DEFAULT NULL COMMENT 'Jackpot下注' ,
`bet_bonus`  int(11) NULL DEFAULT NULL COMMENT 'Bonus下注' ,
`bet_jackpot_deatil`  varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'Jackpot下注详情' ,
`bet_bonus_detail`  varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'Bonus下注详情' ,
`bet_ante`  int(11) NULL DEFAULT NULL COMMENT 'Ante下注' ,
`bet_flop`  int(11) NULL DEFAULT NULL COMMENT 'Flop下注' ,
`bet_sum_chip_detail`  varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '下注筹码求和统计详情' ,
`bet_chip_detail`  varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '四轮下注筹码详情' ,
`bet_win_chip`  int(11) NULL DEFAULT NULL COMMENT '赢取筹码' ,
`bet_reward_bonus`  int(11) NULL DEFAULT NULL COMMENT 'Bonus奖励' ,
`bet_reward_jackpot`  int(11) NULL DEFAULT NULL COMMENT 'Jackpot奖励' ,
`bet_tea`  int(11) NULL DEFAULT NULL COMMENT '茶水费' ,
`bet_server_id`  int(11) NULL DEFAULT NULL COMMENT '服务器编号' ,
`bet_win_chip_detail`  varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '赢取筹码详情' ,
`bet_before_chip_detail`  varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '下注前筹码' ,
`bet_after_chip_detail`  varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '下注后筹码' ,
`bet_total_amount`  int(11) NULL DEFAULT NULL COMMENT '总计' ,
`bet_create_time`  timestamp NULL DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间' ,
PRIMARY KEY (`id`),
UNIQUE INDEX `id_UNIQUE` (`id`) USING BTREE 
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
COMMENT='tlog_texas_bet'
AUTO_INCREMENT=184

;

-- ----------------------------
-- Table structure for `t_trace`
-- ----------------------------
DROP TABLE IF EXISTS `t_trace`;
CREATE TABLE `t_trace` (
`id`  int(11) NOT NULL AUTO_INCREMENT ,
`account_id`  int(11) NULL DEFAULT NULL COMMENT 'account_id' ,
`trace_cost_type`  int(11) NULL DEFAULT NULL COMMENT 'trace_cost_type\n\n\n' ,
`trace_unbind_chip`  int(11) NULL DEFAULT NULL COMMENT 'trace_unbind_chip' ,
`trace_unbind_pink`  int(11) NULL DEFAULT NULL COMMENT 'trace_unbind_pink' ,
`trace_bind_chip`  int(11) NULL DEFAULT NULL COMMENT 'trace_bind_chip' ,
`trace_bind_pink`  int(11) NULL DEFAULT NULL COMMENT 'trace_bind_pink' ,
`trace_describe`  varchar(45) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'trace_describe' ,
`trace_create_time`  timestamp NULL DEFAULT CURRENT_TIMESTAMP COMMENT 'trace_create_time' ,
PRIMARY KEY (`id`),
UNIQUE INDEX `id_UNIQUE` (`id`) USING BTREE 
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
COMMENT='tlog_trace'
AUTO_INCREMENT=1

;

-- ----------------------------
-- Procedure structure for `sp_save_bet`
-- ----------------------------
DROP PROCEDURE IF EXISTS `sp_save_bet`;
DELIMITER ;;
CREATE DEFINER=`root`@`%` PROCEDURE `sp_save_bet`(IN T_account_id INT,
IN T_bet_board_id INT,
IN T_bet_game_type INT,
IN T_bet_game_id INT,
IN T_bet_room_id INT,
IN T_bet_girl_id INT,
IN T_bet_jackpot INT,
IN T_bet_bonus INT,
IN T_bet_jackpot_deatil VARCHAR(100),
IN T_bet_bonus_detail VARCHAR(100),
IN T_bet_ante INT,
IN T_bet_flop INT,
IN T_bet_sum_chip_detail VARCHAR(100),
IN T_bet_chip_detail VARCHAR(100),
IN T_bet_win_chip INT,
IN T_bet_reward_bonus INT,
IN T_bet_reward_jackpot INT,
IN T_bet_tea INT,
IN T_bet_server_id INT,
IN T_bet_win_chip_detail VARCHAR(100),
IN T_bet_before_chip_detail VARCHAR(100),
IN T_bet_after_chip_detail VARCHAR(100),
IN T_bet_total_amount INT)
BEGIN
	INSERT INTO t_texas_bet
    (
    account_id,
    bet_board_id,
    bet_game_type,
    bet_game_id,
    bet_room_id,
    bet_girl_id,
    bet_jackpot,
    bet_bonus,
    bet_jackpot_deatil,
    bet_bonus_detail,
    bet_ante,
    bet_flop,
    bet_sum_chip_detail,
    bet_chip_detail,
    bet_win_chip,
    bet_reward_bonus,
    bet_reward_jackpot,
    bet_tea,
    bet_server_id,
    bet_win_chip_detail,
    bet_before_chip_detail,
    bet_after_chip_detail,
    bet_total_amount
    )
	VALUES
    (
    T_account_id,
    T_bet_board_id,
    T_bet_game_type,
    T_bet_game_id,
    T_bet_room_id,
    T_bet_girl_id,
    T_bet_jackpot,
    T_bet_bonus,
    T_bet_jackpot_deatil,
    T_bet_bonus_detail,
    T_bet_ante,
    T_bet_flop,
    T_bet_sum_chip_detail,
    T_bet_chip_detail,
    T_bet_win_chip,
    T_bet_reward_bonus,
    T_bet_reward_jackpot,
    T_bet_tea,
    T_bet_server_id,
    T_bet_win_chip_detail,
    T_bet_before_chip_detail,
    T_bet_after_chip_detail,
    T_bet_total_amount
    );
END
;;
DELIMITER ;

-- ----------------------------
-- Procedure structure for `sp_save_gm`
-- ----------------------------
DROP PROCEDURE IF EXISTS `sp_save_gm`;
DELIMITER ;;
CREATE DEFINER=`root`@`%` PROCEDURE `sp_save_gm`(
IN T_account_id INT,
IN T_gm_id INT,
IN T_gm_action_type INT,
IN T_gm_describe varchar(45)
)
BEGIN
	REPLACE INTO t_gm
    (
    account_id,
    gm_id,
    gm_action_type,
    gm_describe
    )
    VALUES
    (
    T_account_id,
    T_gm_id,
    T_gm_action_type,
    T_gm_describe
    );
END
;;
DELIMITER ;

-- ----------------------------
-- Procedure structure for `sp_save_login`
-- ----------------------------
DROP PROCEDURE IF EXISTS `sp_save_login`;
DELIMITER ;;
CREATE DEFINER=`root`@`%` PROCEDURE `sp_save_login`(
  IN T_account_id INT,
  IN T_login_name varchar (100),
  IN T_login_platform_id INT,
  IN T_login_third_id varchar (100),
  IN T_login_third_account varchar (100),
  IN T_login_login_time INT,
  IN T_login_server_id INT,
  IN T_login_login_ip varchar (100),
  IN T_login_login_status INT
)
BEGIN
  replace INTO t_login (
    account_id,
    login_name,
    login_platform_id,
    login_third_id,
    login_third_account,
    login_login_time,
    login_server_id,
    login_login_ip,
    login_login_status
  ) 
  VALUES
    (
      T_account_id,
      T_login_name,
      T_login_platform_id,
      T_login_third_id,
      T_login_third_account,
      from_unixtime(T_login_login_time),
      T_login_server_id,
      T_login_login_ip,
      T_login_login_status
    ) ;
  END
;;
DELIMITER ;

-- ----------------------------
-- Procedure structure for `sp_save_logout`
-- ----------------------------
DROP PROCEDURE IF EXISTS `sp_save_logout`;
DELIMITER ;;
CREATE DEFINER=`root`@`%` PROCEDURE `sp_save_logout`(
IN T_account_id INT,
IN T_logout_name varchar(100),
IN T_logout_platform_id INT,
IN T_logout_third_id varchar(100),
IN T_logout_third_account varchar(100),
IN T_logout_login_time INT,
IN T_logout_logout_time INT,
IN T_logout_server_id INT, 
IN T_logout_login_ip varchar(100)
)
BEGIN
	REPLACE INTO t_logout
    (
    account_id,
    logout_name,
    logout_platform_id,
    logout_third_id,
    logout_third_account,
    logout_login_time,
    logout_logout_time,
    logout_server_id,
    logout_login_ip
    )
	values
    (
    T_account_id,
    T_logout_name,
    T_logout_platform_id,
    T_logout_third_id,
    T_logout_third_account,
    from_unixtime(T_logout_login_time),
    from_unixtime(T_logout_logout_time),
    T_logout_server_id,
    T_logout_login_ip
    );
END
;;
DELIMITER ;

-- ----------------------------
-- Procedure structure for `sp_save_online`
-- ----------------------------
DROP PROCEDURE IF EXISTS `sp_save_online`;
DELIMITER ;;
CREATE DEFINER=`root`@`%` PROCEDURE `sp_save_online`(
IN T_online_server_id INT,
IN T_online_game_type INT,
IN T_online_room_type INT,
IN T_online_game_id INT,
IN T_online_room_id INT,
IN T_online_girl_id INT,
IN T_OnlineUsersCount INT
)
BEGIN
	REPLACE INTO t_online
    (
    online_server_id,
    online_game_type,
    online_room_type,
    online_game_id,
    online_room_id,
    online_girl_id,
    online_users_count
    )
	VALUES
    (
    T_online_server_id,
    T_online_game_type,
    T_online_room_type,
    T_online_game_id,
    T_online_room_id,
    T_online_girl_id,
    T_OnlineUsersCount
    );
END
;;
DELIMITER ;

-- ----------------------------
-- Procedure structure for `sp_save_pvggift`
-- ----------------------------
DROP PROCEDURE IF EXISTS `sp_save_pvggift`;
DELIMITER ;;
CREATE DEFINER=`root`@`%` PROCEDURE `sp_save_pvggift`(
IN T_account_id INT,
IN T_pvggift_name varchar(45),
IN T_pvggift_girl_id INT,
IN T_pvggift_girl_third_id varchar(45),
IN T_pvggift_gift_id INT,
IN T_pvggift_gift_num INT,
IN T_pvggift_gift_price INT,
IN T_pvggift_money_type INT,
IN T_pvggift_unbind_pink INT,
IN T_pvggift_bind_pink INT,
IN T_pvggift_game_type INT,
IN T_pvggift_game_id INT,
IN T_pvggift_room_id INT,
IN T_pvggift_server_id INT,
IN T_pvggift_room_type INT,
IN T_pvggift_even_count INT,
IN T_pvggift_broadcast_type INT,
IN SaveType INT
)
BEGIN
 
	IF(SaveType = 1) 
    THEN
		SET SQL_SAFE_UPDATES = 0;
		CREATE TABLE tmp 
        AS 
        SELECT id AS col1 
        FROM t_pvggift 
        WHERE pvggift_gift_id = T_pvggift_gift_id AND 
        pvggift_even_count +1 = T_pvggift_even_count AND 
        account_id = T_account_id 
        ORDER BY pvggift_create_time DESC LIMIT 0,1; 
	
		UPDATE t_pvggift
        SET 
        account_id = T_account_id,
        pvggift_name = T_pvggift_name,
        pvggift_girl_id =T_pvggift_girl_id ,
        pvggift_girl_third_id = T_pvggift_girl_third_id,
        pvggift_gift_id = T_pvggift_gift_id,
        pvggift_gift_num = T_pvggift_gift_num,
        pvggift_gift_price = T_pvggift_gift_price,
        pvggift_money_type = T_pvggift_money_type,
        pvggift_unbind_pink =T_pvggift_unbind_pink,
        pvggift_bind_pink= T_pvggift_bind_pink,
        pvggift_game_type = T_pvggift_game_type,
        pvggift_game_id =T_pvggift_game_id ,
        pvggift_room_id = T_pvggift_room_id,
        pvggift_server_id = T_pvggift_server_id,
        pvggift_room_type = T_pvggift_room_type,
        pvggift_even_count = T_pvggift_even_count,
        pvggift_broadcast_type = T_pvggift_broadcast_type,
        pvggift_create_time = now() 
        where id = (select col1 from tmp);
        drop table tmp;
		
	ELSE
		INSERT INTO t_pvggift
        (
        account_id,
        pvggift_name,
        pvggift_girl_id,
        pvggift_girl_third_id,
        pvggift_gift_id,
        pvggift_gift_num,
        pvggift_gift_price,
        pvggift_money_type,
        pvggift_unbind_pink,
        pvggift_bind_pink,
        pvggift_game_type,
        pvggift_game_id,
        pvggift_room_id,
        pvggift_server_id,
        pvggift_room_type,
        pvggift_even_count,
        pvggift_broadcast_type
        )
		VALUES
        (
        T_account_id,
        T_pvggift_name,
        T_pvggift_girl_id,
        T_pvggift_girl_third_id,
        T_pvggift_gift_id,
        T_pvggift_gift_num,
        T_pvggift_gift_price,
        T_pvggift_money_type,
        T_pvggift_unbind_pink,
        T_pvggift_bind_pink,
        T_pvggift_game_type,
        T_pvggift_game_id,
        T_pvggift_room_id,
        T_pvggift_server_id,
        T_pvggift_room_type,
        T_pvggift_even_count,
        T_pvggift_broadcast_type
        );

	end IF;
END
;;
DELIMITER ;

-- ----------------------------
-- Procedure structure for `sp_save_pvpgift`
-- ----------------------------
DROP PROCEDURE IF EXISTS `sp_save_pvpgift`;
DELIMITER ;;
CREATE DEFINER=`root`@`%` PROCEDURE `sp_save_pvpgift`(
IN T_pvpgift_from_account_id INT,
IN T_pvpgift_to_account_id INT,
IN T_pvpgift_from_name varchar(45),
IN T_pvpgift_to_name varchar(45),
IN T_pvpgift_platform_id INT,
IN T_pvpgift_from_third_id varchar(45),
IN T_pvpgift_to_third_id varchar(45),
IN T_pvpgift_from_third_account varchar(45),
IN T_pvpgift_to_third_account varchar(45),
IN T_pvpgift_gift_id INT,
IN T_pvpgift_gift_price INT,
IN T_pvpgift_unbind_chip INT,
IN T_pvpgift_bind_chip INT,
IN T_pvpgift_server_id INT,
IN T_pvpgift_room_id INT
)
BEGIN
	INSERT INTO t_pvpgift
    (
	pvpgift_from_account_id,
    pvpgift_to_account_id,
    pvpgift_from_name,
    pvpgift_to_name,
    pvpgift_platform_id,
    pvpgift_from_third_id,
    pvpgift_to_third_id,
    pvpgift_from_third_account,
    pvpgift_to_third_account,
    pvpgift_gift_id,
    pvpgift_gift_price,
    pvpgift_unbind_chip,
    pvpgift_bind_chip,
    pvpgift_server_id,
    pvpgift_room_id
    )
	VALUES
    (
    T_pvpgift_from_account_id,
    T_pvpgift_to_account_id,
    T_pvpgift_from_name,
    T_pvpgift_to_name,
    T_pvpgift_platform_id,
    T_pvpgift_from_third_id,
    T_pvpgift_to_third_id,
    T_pvpgift_from_third_account,
    T_pvpgift_to_third_account,
    T_pvpgift_gift_id,
    T_pvpgift_gift_price,
    T_pvpgift_unbind_chip,
    T_pvpgift_bind_chip,
    T_pvpgift_server_id,
    T_pvpgift_room_id
    );
END
;;
DELIMITER ;

-- ----------------------------
-- Procedure structure for `sp_save_room`
-- ----------------------------
DROP PROCEDURE IF EXISTS `sp_save_room`;
DELIMITER ;;
CREATE DEFINER=`root`@`%` PROCEDURE `sp_save_room`(
IN T_account_id INT,
IN T_room_account_name varchar(45),
IN T_room_platform_id INT,
IN T_room_third_id varchar(45),
IN T_room_third_account varchar(45),
IN T_room_id INT,
IN T_room_girl_id INT,
IN T_room_action INT
)
BEGIN
   REPLACE INTO t_room(
   account_id,
   room_account_name,
   room_platform_id,
   room_third_id,
   room_third_account,
   room_id,
   room_girl_id,
   room_action
   )
   VALUES
   (
   T_account_id,
   T_room_account_name,
   T_room_platform_id,
   T_room_third_id,
   T_room_third_account,
   T_room_id,
   T_room_girl_id,
   T_room_action
   );
END
;;
DELIMITER ;

-- ----------------------------
-- Procedure structure for `sp_save_trace`
-- ----------------------------
DROP PROCEDURE IF EXISTS `sp_save_trace`;
DELIMITER ;;
CREATE DEFINER=`root`@`%` PROCEDURE `sp_save_trace`(
IN T_account_id INT,
IN T_trace_cost_type INT,
IN T_trace_unbind_chip INT,
IN T_trace_unbind_pink INT,
IN T_trace_bind_chip INT,
IN T_trace_bind_pink INT,
IN T_trace_describe varchar(45))
BEGIN
    REPLACE INTO t_trace(
    account_id,
    trace_cost_type,
    trace_unbind_chip,
    trace_unbind_pink,
    trace_bind_chip,
    trace_bind_pink,
    trace_describe)
    VALUES
    (
    T_account_id,
    T_trace_cost_type,
    T_trace_unbind_chip,
    T_trace_unbind_pink,
    T_trace_bind_chip,
    T_trace_bind_pink,
    T_trace_describe
    );
END
;;
DELIMITER ;

-- ----------------------------
-- Auto increment value for `t_gm`
-- ----------------------------
ALTER TABLE `t_gm` AUTO_INCREMENT=1;

-- ----------------------------
-- Auto increment value for `t_login`
-- ----------------------------
ALTER TABLE `t_login` AUTO_INCREMENT=95;

-- ----------------------------
-- Auto increment value for `t_logout`
-- ----------------------------
ALTER TABLE `t_logout` AUTO_INCREMENT=20;

-- ----------------------------
-- Auto increment value for `t_online`
-- ----------------------------
ALTER TABLE `t_online` AUTO_INCREMENT=1;

-- ----------------------------
-- Auto increment value for `t_pvggift`
-- ----------------------------
ALTER TABLE `t_pvggift` AUTO_INCREMENT=1;

-- ----------------------------
-- Auto increment value for `t_pvpgift`
-- ----------------------------
ALTER TABLE `t_pvpgift` AUTO_INCREMENT=1;

-- ----------------------------
-- Auto increment value for `t_room`
-- ----------------------------
ALTER TABLE `t_room` AUTO_INCREMENT=1;

-- ----------------------------
-- Auto increment value for `t_texas_bet`
-- ----------------------------
ALTER TABLE `t_texas_bet` AUTO_INCREMENT=184;

-- ----------------------------
-- Auto increment value for `t_trace`
-- ----------------------------
ALTER TABLE `t_trace` AUTO_INCREMENT=1;
