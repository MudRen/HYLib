// Room: /jyguan/nanmen.c ����������
// Ver 0.1 08/14/1998 by Freeze

#include <ansi.h>
inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", HIY "�� �� ��");
	set("long", @LONG
�����ϳ��ţ��������Ϸ����š����š�����������֣�һ���ǽ�����ż���
�ٸ���ʾ(gaoshi)���ٱ��Ǿ����ע���ű�������������ϡ�١�������һ����ֱ
����ש��ͨ����ڡ�������ɳĮ��Ե����ȥ����ıؾ�֮·��
LONG
	);
        set("outdoors", "city");

	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
//		 "east" : __DIR__"",
		"south" : "/d/xingxiu/jiayuguan",
		"north" : __DIR__"guangchang",
		 "west" : __DIR__"shamo",
                "southwest" : __DIR__"shaqiu",
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

