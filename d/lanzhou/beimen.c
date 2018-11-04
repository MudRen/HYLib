// Room: /wizhome/lanzhou/beimen.c
// Date: inca 98/08/14

#include <ansi.h>
inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "����");
	set("long", @LONG
�������ݳǵı����ţ���������Ļ��������������ķ�ɳ��ʴ�Ե���Щ
�ưܡ��������Ϸ�����ǿǿ�����ϳ������š��������֣���ǽ�����ż���ͨ����
ʾ(gaoshi)������ﷸ�������������ӵ����򣬹ٱ��ǽ䱸ɭ�ϣ��������ͽ�ס
���˽������ʡ�һ����ֱ����ʯ������ϱ��������졣�����ǽ��⣬���������
�����˶���������ǡ���౾����Ҳ�������ڴ����ﾭ����������ȥ�����Լ���
�ĹϹ���������������Ʒ���ϱ��ǳ��
LONG
	);
        set("outdoors", "lanzhou");

	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits", ([
		"east" : "/d/lanzhouchen/yizhan",
		"north" : __DIR__"nroad1",
 "northwest" : "/d/lanzhouchen/road4",
"south" : "/d/lanzhouchen/road3",		
	]));
        set("objects", ([
                "/d/city/npc/wujiang" : 2,
                "/d/city/npc/bing" : 4,
        ]));
	setup();
}

string look_gaoshi()
{
        return FINGER_D->get_killer() + "\n         �ڳ��й�\n          ��  ��\n";
}

