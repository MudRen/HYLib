// Room: /d/hainan/baiyunan.c

inherit ROOM;
#include <room.h>
void create()
{
	set("short", "������");
	set("long", @LONG
��ãã�ԲԵ�����������,һ��С������ӳ����,�Ե÷��⵭������
�߽���,����Ϲҵ�һ��ľ���Ѿ����ƾ���,�����ܿ���'����'����.����
����һ��װ��,����Ѱ�����������ͭ�嶼û��,ȷ�Եø���ƮȻ����.
LONG
	);
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "north" : (: look_door,     "north" :),
]));
	set("outdoors", "/d/hainan");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road3",
  "north" : __DIR__"jingtang",
]));
create_door("north","����","south",DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
