// ROOM: /city/youju.c
// Date: 28/5/2000 by happy
#include <ansi.h>;
inherit ROOM;
void create()
{
  set ("short",HIC"�����ʾ�"NOR);
set ("long",@LONG
�����������ʾ�,�����������˺ܶ�,�ǳ���æ�������ʾ�������
����Ա���࣬�ʲ����ֲ������ż����ŷ�����ȥ����һЩ������ʿ��
�˱�����ʱ������æ���Դλ��һЩ���ꡣǽ������һ�Ų���(post)��
LONG
);
  set("objects",([
  "/quest/letter/foxmail.c":1,
]));
set("item_desc",([
"post":"��������д��:���ʾֳ����ʵ�Ա��\n",
]));
  set("exits",([
  "north":__DIR__"ximen",
  "south":"quest/songhuo/huowo",
]));
set("no_steal", "1");
set("no_fight", "1");
set("no_sleep_room", "1");
setup();
replace_program(ROOM);
}
