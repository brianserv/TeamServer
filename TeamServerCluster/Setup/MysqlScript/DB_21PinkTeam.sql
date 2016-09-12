/*
Navicat MySQL Data Transfer

Source Server         : mysql10.1.108.65
Source Server Version : 50173
Source Host           : 10.1.108.65:3306
Source Database       : DB_21PinkTeam

Target Server Type    : MYSQL
Target Server Version : 60099
File Encoding         : 65001

Date: 2015-12-29 17:11:50
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `t_account`
-- ----------------------------
DROP TABLE IF EXISTS `t_account`;
CREATE TABLE `t_account` (
`account_id`  int(20) UNSIGNED NOT NULL COMMENT '账号编号' ,
`account_name`  varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '账号名称' ,
`account_password`  varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '账号密钥' ,
`account_platform_id`  int(11) NULL DEFAULT NULL COMMENT '平台编号' ,
`account_third_id`  varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '三方编号' ,
`account_third_account`  varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '三方账号' ,
`account_sex`  tinyint(4) NULL DEFAULT NULL COMMENT '性别' ,
`account_status`  tinyint(4) NULL DEFAULT NULL COMMENT '状态' ,
`account_status_reason`  varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '状态原因' ,
`account_last_login_time`  timestamp NULL DEFAULT NULL COMMENT '上次登录时间' ,
`account_login_times`  int(11) NULL DEFAULT NULL COMMENT '登录次数' ,
`account_ban_time`  timestamp NULL DEFAULT NULL COMMENT '封号时间' ,
`account_exp`  int(11) NULL DEFAULT NULL COMMENT '经验' ,
`account_level`  int(11) NULL DEFAULT NULL COMMENT '等级' ,
`account_unbind_chip`  int(11) NULL DEFAULT NULL COMMENT '非绑筹码' ,
`account_unbind_pink`  int(11) NULL DEFAULT NULL COMMENT '非绑粉钻' ,
`account_bind_chip`  int(11) NULL DEFAULT NULL COMMENT '绑定筹码' ,
`account_bind_pink`  int(11) NULL DEFAULT NULL COMMENT '绑定粉钻' ,
`account_max_pink`  int(11) NULL DEFAULT NULL COMMENT '最大粉钻' ,
`account_max_chip`  int(11) NULL DEFAULT NULL COMMENT '最大筹码' ,
`account_highest_chip`  int(11) NULL DEFAULT NULL COMMENT '最高筹码' ,
`account_vip_type`  int(11) NULL DEFAULT NULL COMMENT 'VIP类型' ,
`account_vip_level`  int(11) NULL DEFAULT NULL COMMENT 'VIP等级' ,
`account_vip_points`  int(11) NULL DEFAULT NULL COMMENT 'VIP积分' ,
`account_win_times`  int(11) NULL DEFAULT NULL COMMENT '赢统计次数' ,
`account_lost_times`  int(11) NULL DEFAULT NULL COMMENT '输统计次数' ,
`account_draw_times`  int(11) NULL DEFAULT NULL COMMENT '平统计次数' ,
`account_max_cardtype`  varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '最大牌型' ,
`account_chat_status`  int(11) NULL DEFAULT NULL COMMENT '聊天状态' ,
`account_gift_spend`  int(11) NULL DEFAULT NULL COMMENT '礼物花费' ,
`account_gift_month`  int(11) NOT NULL DEFAULT 0 COMMENT '礼物花费月份' ,
`account_create_time`  timestamp NULL DEFAULT CURRENT_TIMESTAMP COMMENT '默认创建时间' ,
PRIMARY KEY (`account_id`),
UNIQUE INDEX `idx_account_id` (`account_id`) USING BTREE 
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci

;

-- ----------------------------
-- Table structure for `t_texas_board`
-- ----------------------------
DROP TABLE IF EXISTS `t_texas_board`;
CREATE TABLE `t_texas_board` (
`id`  int(11) NOT NULL AUTO_INCREMENT COMMENT '自增编号' ,
`board_id`  int(11) NULL DEFAULT NULL COMMENT '牌局编号' ,
`board_girl_id`  int(11) NULL DEFAULT NULL COMMENT '荷官编号' ,
`board_card`  varchar(45) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '本局卡牌' ,
`board_showcard`  varchar(45) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '本局展示卡牌' ,
`board_server_id`  int(11) NULL DEFAULT NULL COMMENT '服务器编号' ,
`board_game_id`  int(11) NULL DEFAULT NULL COMMENT '游戏编号' ,
`board_room_id`  int(11) NULL DEFAULT NULL COMMENT '房间编号' ,
`board_sum_chip`  int(11) NULL DEFAULT NULL COMMENT '本局筹码统计' ,
`board_rewardjackpot_type`  int(11) NULL DEFAULT NULL COMMENT 'Jackpot中奖倍数' ,
`board_rewardbonus_type`  int(11) NULL DEFAULT NULL COMMENT 'Bonus中奖倍数' ,
`board_card_type`  int(11) NULL DEFAULT NULL COMMENT '卡牌类型' ,
`board_dealcard_type`  int(11) NULL DEFAULT NULL COMMENT '发牌类型' ,
`board_result`  int(11) NULL DEFAULT NULL COMMENT '牌局结果' ,
`board_end_status`  int(11) NULL DEFAULT NULL COMMENT '牌局结束状态' ,
`board_start_time`  timestamp NULL DEFAULT NULL COMMENT '牌局开始时间' ,
`board_end_time`  timestamp NULL DEFAULT NULL COMMENT '牌局结束时间' ,
`board_create_time`  timestamp NULL DEFAULT CURRENT_TIMESTAMP COMMENT '默认创建时间' ,
PRIMARY KEY (`id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
COMMENT='t_texas_board'
AUTO_INCREMENT=11812

;

-- ----------------------------
-- Table structure for `t_texas_board10`
-- ----------------------------
DROP TABLE IF EXISTS `t_texas_board10`;
CREATE TABLE `t_texas_board10` (
`id`  int(11) NOT NULL COMMENT '自增编号' ,
`board10_game_id`  int(11) NULL DEFAULT NULL COMMENT '游戏编号' ,
`board10_room_id`  int(11) NOT NULL DEFAULT 1 COMMENT '房间编号' ,
`board10_server_id`  int(11) NULL DEFAULT NULL COMMENT '服务器编号' ,
`board10_result_detail`  varchar(45) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '历史牌局输赢结果详情' ,
`board10_board_count`  int(11) NULL DEFAULT NULL COMMENT '历史牌局统计【10】' ,
`board10_create_time`  timestamp NULL DEFAULT CURRENT_TIMESTAMP COMMENT '默认创建时间' ,
PRIMARY KEY (`board10_room_id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
COMMENT='t_texas_board10:\r\nrecent board in [1,10] win or lost'

;

-- ----------------------------
-- Table structure for `t_texas_prizepool`
-- ----------------------------
DROP TABLE IF EXISTS `t_texas_prizepool`;
CREATE TABLE `t_texas_prizepool` (
`id`  int(11) NOT NULL DEFAULT 1 COMMENT '自增编号' ,
`prizepool_total_value`  int(11) NOT NULL COMMENT '奖池总值' ,
`prizepool_pay_value`  int(11) NOT NULL COMMENT '奖池支出统计值' ,
`prizepool_JackpotBonus_Init`  int(11) NOT NULL COMMENT 'JackpotBonus初始阈值' ,
PRIMARY KEY (`id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
COMMENT='t_texas_prizepool'

;

-- ----------------------------
-- Procedure structure for `sp_get_prizepool`
-- ----------------------------
DROP PROCEDURE IF EXISTS `sp_get_prizepool`;
DELIMITER ;;
CREATE DEFINER=`root`@`%` PROCEDURE `sp_get_prizepool`()
BEGIN
	SELECT
    id,
    prizepool_total_value,
    prizepool_pay_value,
    prizepool_JackpotBonus_Init 
    FROM t_texas_prizepool;
END
;;
DELIMITER ;

-- ----------------------------
-- Procedure structure for `sp_get_role`
-- ----------------------------
DROP PROCEDURE IF EXISTS `sp_get_role`;
DELIMITER ;;
CREATE DEFINER=`root`@`%` PROCEDURE `sp_get_role`()
BEGIN
SELECT 
account_id,
account_name,
account_password,
account_platform_id,
account_third_id,
account_third_account,
account_sex,
account_status,
account_status_reason,
unix_timestamp(account_last_login_time),
account_login_times,
account_ban_time,
account_exp,
account_level,
account_unbind_chip,
account_unbind_pink,
account_bind_chip,
account_bind_pink,
account_max_pink,
account_max_chip,
account_highest_chip,
account_vip_type,
account_vip_level,
account_vip_points,
account_win_times,
account_lost_times,
account_draw_times,
account_max_cardtype,
account_chat_status,
account_gift_spend,
account_gift_month,
unix_timestamp(account_create_time) 
FROM t_account;
END
;;
DELIMITER ;

-- ----------------------------
-- Procedure structure for `sp_get_texasboard`
-- ----------------------------
DROP PROCEDURE IF EXISTS `sp_get_texasboard`;
DELIMITER ;;
CREATE DEFINER=`root`@`%` PROCEDURE `sp_get_texasboard`()
BEGIN
	 SELECT board_id,
     board_girl_id,
     board_card,
     board_showcard,
     board_server_id,
     board_game_id,
     board_room_id,
     board_sum_chip,
     board_rewardjackpot_type,
     board_rewardbonus_type,
     board_card_type,
     board_dealcard_type,
     board_result,
     board_end_status,
     unix_timestamp(board_start_time),
     unix_timestamp(board_end_time) 
     FROM t_texas_board 
     WHERE board_create_time = curdate();
END
;;
DELIMITER ;

-- ----------------------------
-- Procedure structure for `sp_get_texasboard10`
-- ----------------------------
DROP PROCEDURE IF EXISTS `sp_get_texasboard10`;
DELIMITER ;;
CREATE DEFINER=`root`@`%` PROCEDURE `sp_get_texasboard10`()
BEGIN
	SELECT 
    board10_game_id,
    board10_room_id,
    board10_server_id,
    board10_result_detail,
    board10_board_count 
    FROM t_texas_board10;
END
;;
DELIMITER ;

-- ----------------------------
-- Procedure structure for `sp_save_prizepool`
-- ----------------------------
DROP PROCEDURE IF EXISTS `sp_save_prizepool`;
DELIMITER ;;
CREATE DEFINER=`root`@`%` PROCEDURE `sp_save_prizepool`(
IN T_prizepool_total_value INT,
IN T_prizepool_pay_value INT,
IN T_prizepool_JackpotBonus_Init INT
)
BEGIN
	REPLACE INTO t_texas_prizepool
    (
    prizepool_total_value,
    prizepool_pay_value,
	prizepool_JackpotBonus_Init
    )
    VALUES
    (
    T_prizepool_total_value,
    T_prizepool_pay_value,
	T_prizepool_JackpotBonus_Init
    );
END
;;
DELIMITER ;

-- ----------------------------
-- Procedure structure for `sp_save_role`
-- ----------------------------
DROP PROCEDURE IF EXISTS `sp_save_role`;
DELIMITER ;;
CREATE DEFINER=`root`@`%` PROCEDURE `sp_save_role`(
IN T_account_id INT,
IN T_account_name varchar(100),
IN T_account_password varchar(100),
IN T_account_platform_id INT,
IN T_account_third_id VARCHAR(64),
IN T_account_third_account varchar(64),
IN T_account_sex TINYINT,
IN T_account_status TINYINT,
IN T_account_status_reason varchar(100),
IN T_account_last_login_time INT,
IN T_account_login_times INT,
IN T_account_ban_time INT,
IN T_account_exp INT,
IN T_account_level INT,
IN T_account_unbind_chip INT,
IN T_account_unbind_pink INT,
IN T_account_bind_chip INT,
IN T_account_bind_pink INT,
IN T_account_max_pink INT,
IN T_account_max_chip INT,
IN T_account_highest_chip INT,
IN T_account_vip_type INT,
IN T_account_vip_level INT,
IN T_account_vip_points INT,
IN T_account_win_times INT,
IN T_account_lost_times INT,
IN T_account_draw_times INT,
IN T_account_max_cardtype VARCHAR(100),
IN T_account_chat_status INT,
IN T_account_gift_spend INT,
IN T_account_gift_month INT
)
BEGIN
	REPLACE INTO t_account
    (
    account_id,
    account_name,
    account_password,
    account_platform_id,
    account_third_id,
    account_third_account,
    account_sex,
    account_status,
    account_status_reason,
    account_last_login_time,
    account_login_times,
    account_ban_time,
    account_exp,
    account_level,
    account_unbind_chip,
    account_unbind_pink,
    account_bind_chip,
    account_bind_pink,
    account_max_pink,
    account_max_chip,
    account_highest_chip,
    account_vip_type,
    account_vip_level,
    account_vip_points,
    account_win_times,
    account_lost_times,
    account_draw_times,
    account_max_cardtype,
    account_chat_status,
    account_gift_spend,
    account_gift_month
    )
    VALUES
    (
    T_account_id,
    T_account_name,
    T_account_password,
    T_account_platform_id,
    T_account_third_id,
    T_account_third_account,
    T_account_sex,
    T_account_status,
    T_account_status_reason,
    from_unixtime(T_account_last_login_time),
    T_account_login_times,
    from_unixtime(T_account_ban_time),
    T_account_exp,
    T_account_level,
    T_account_unbind_chip,
    T_account_unbind_pink,
    T_account_bind_chip,
    T_account_bind_pink,
    T_account_max_pink,
    T_account_max_chip,
    T_account_highest_chip,
    T_account_vip_type,
    T_account_vip_level,
    T_account_vip_points,
    T_account_win_times,
    T_account_lost_times,
    T_account_draw_times,
    T_account_max_cardtype,
    T_account_chat_status,
    T_account_gift_spend,
    T_account_gift_month
    );
    
END
;;
DELIMITER ;

-- ----------------------------
-- Procedure structure for `sp_save_texasboard`
-- ----------------------------
DROP PROCEDURE IF EXISTS `sp_save_texasboard`;
DELIMITER ;;
CREATE DEFINER=`root`@`%` PROCEDURE `sp_save_texasboard`(
IN T_board_id INT,
IN T_board_girl_id INT,
IN T_board_card varchar(45),
IN T_board_showcard VARCHAR(45),
IN T_board_server_id INT,
IN T_board_game_id INT,
IN T_board_room_id INT,
IN T_board_sum_chip INT,
IN T_board_rewardjackpot_type INT,
IN T_board_rewardbonus_type INT,
IN T_board_card_type INT,
IN T_board_dealcard_type INT,
IN T_board_result INT,
IN T_board_end_status INT,
IN T_board_start_time INT,
IN T_board_end_time INT
)
BEGIN
    REPLACE INTO t_texas_board
    (
    board_id,
    board_girl_id,
    board_card,
    board_showcard,
    board_server_id,
    board_game_id,
    board_room_id,
    board_sum_chip,
    board_rewardjackpot_type,
    board_rewardbonus_type,
    board_card_type,
    board_dealcard_type,
    board_result,
    board_end_status,
    board_start_time,
    board_end_time)
    VALUES
    (
    T_board_id,
    T_board_girl_id,
    T_board_card,
    T_board_showcard,
    T_board_server_id,
    T_board_game_id,
    T_board_room_id,
    T_board_sum_chip,
    T_board_rewardjackpot_type,
    T_board_rewardbonus_type,
    T_board_card_type,
    T_board_dealcard_type,
    T_board_result,
    T_board_end_status,
    from_unixtime(T_board_start_time),
    from_unixtime(T_board_end_time)
    );
END
;;
DELIMITER ;

-- ----------------------------
-- Procedure structure for `sp_save_texasboard10`
-- ----------------------------
DROP PROCEDURE IF EXISTS `sp_save_texasboard10`;
DELIMITER ;;
CREATE DEFINER=`root`@`%` PROCEDURE `sp_save_texasboard10`(
IN T_board10_game_id INT,
IN T_board10_room_id INT,
IN T_board10_server_id INT,
IN T_board10_result_detail varchar(45),
IN T_board10_board_count INT)
BEGIN
   REPLACE INTO t_texas_board10
   (
   id,
   board10_game_id,
   board10_room_id,
   board10_server_id,
   board10_result_detail,
   board10_board_count
   )
   VALUES
   (
   T_board10_room_id,
   T_board10_game_id,
   T_board10_room_id,
   T_board10_server_id,
   T_board10_result_detail,
   T_board10_board_count
   );
END
;;
DELIMITER ;

-- ----------------------------
-- Auto increment value for `t_texas_board`
-- ----------------------------
ALTER TABLE `t_texas_board` AUTO_INCREMENT=11812;
