// ROOM: /city/youju.c
// Date: 28/5/2000 by happy
#include <ansi.h>;
inherit ROOM;
void create()
{
  set ("short",HIG"�ĺ����˵�"NOR);
set ("long",@LONG
�����������ĺ����˵�,�����������˺ܶ�,�ǳ���æ��
�˵��������ս�����ʿǰ����æ���Դλ��һЩ���ꡣǽ������һ�Ų���(post)��
LONG
);
  set("objects",([
  "/quest/songhuo/postman":1,
]));
set("item_desc",([
"post":"��������д��:��������ͻ�Ա���ⶼ����quest��������\n",
]));
  set("exits",([
  "north": "d/city/youju",
]));
set("no_steal", "1");
set("no_fight", "1");
set("no_sleep_room", "1");
setup();
replace_program(ROOM);
}
