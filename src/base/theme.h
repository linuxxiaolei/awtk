﻿/**
 * File:   theme.h
 * Author: AWTK Develop Team
 * Brief:  theme interface
 *
 * Copyright (c) 2018 - 2018  Guangzhou ZHIYUAN Electronics Co.,Ltd.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ================================================================
 * 2018-01-19 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#ifndef TK_THEME_H
#define TK_THEME_H

#include "base/color.h"
#include "base/widget_consts.h"

BEGIN_C_DECLS

/**
 * @class theme_t
 * 主题。
 */
typedef struct _theme_t {
  const uint8_t* data;
} theme_t;

/**
 * @method theme
 * 获取缺省的主题对象。
 * @alias theme_instance
 * @annotation ["constructor"]
 * @return {theme_t*} 返回主题对象。
 */
theme_t* theme(void);

/**
 * @method theme_init
 * 初始化主题对象。
 * @annotation ["constructor"]
 * @param {const uint8_t*} data 主题数据。
 *
 * @return {theme_t*} 返回主题对象。
 */
theme_t* theme_init(const uint8_t* data);

/**
 * @method theme_find_style
 * 查找满足条件的style。
 * @param {theme_t*} data 主题对象。
 * @param {const char*} widget_type 控件的类型名。
 * @param {const char*} name style的名称。
 * @param {widget_state_t} widget_state 控件的状态。
 *
 * @return {theme_t*} 返回主题对象。
 */
const uint8_t* theme_find_style(theme_t* t, const char* widget_type, const char* name,
                                widget_state_t widget_state);

uint32_t style_data_get_int(const uint8_t* s, uint32_t name, uint32_t defval);
color_t style_data_get_color(const uint8_t* s, uint32_t name, color_t defval);
const char* style_data_get_str(const uint8_t* s, uint32_t name, const char* defval);

/*public for tools only*/
#define THEME_MAGIC 0xFAFBFCFD
#define TK_DEFAULT_STYLE "default"

typedef struct _theme_header_t {
  uint32_t magic;
  uint32_t version;
  uint32_t nr;
} theme_header_t;

typedef struct _theme_item_t {
  uint32_t offset;
  uint32_t state;
  char name[NAME_LEN + 1];
  char widget_type[NAME_LEN + 1];
} theme_item_t;

END_C_DECLS

#endif /*TK_THEME_H*/
