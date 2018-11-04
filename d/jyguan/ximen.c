// Room: /jyguan/ximen.c ����������
// Ver 0.1 08/14/1998 by Freeze

#include <ansi.h>
inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", HIY "�� �� ��");
	set("long", @LONG
���������ţ��������Ϸ����š����š�����������֣�һ���ǽ�����ż���
�ٸ���ʾ(gaoshi)���ٱ��Ǿ����ע������������������ϡ�١�������һ����ֱ
����ש��ͨ����ڡ�����ɳ��ãã�������ǵ���������ֵ���ǰ�ء�
LONG
	);
        set("outdoors", "city");

	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		 "east" : __DIR__"guangchang",
		"north" : __DIR__"shamo",
		 "northwest" : "d/huizhu/guanwai",
                "south" : __DIR__"shamo",
	]));

	set("objects", ([
		__DIR__"npc/wujiang" : 2,
		__DIR__"npc/bing" : 5,
	]));

	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n�������ܱ�\n    ��־��\n";
}

