// Room: /d/henshan/shanjian.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
˳ɽ��Ư�����£���Ϫ�鲼��ϡ��ľ��Ȫʯ����ľ�����ݼ����;�
�����ˡ����������۵���й���£�����ɽ�ȡ�
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "down"     : __DIR__"heishatan",
           "northup"  : __DIR__"fangguangsi",
        ]));
        set("outdoors", "henshan");
	set("wayao1", 1);
	set("objects", ([

"quest/skills2/wakuang/kuang/kuangmai" : 1,
	])); 
	set("coor/x", -370);
	set("coor/y", -1060);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
