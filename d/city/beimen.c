// Room: /city/beimen.c
// YZC 1995/12/04 

#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "����");
	set("long", @LONG
�������ݵı��š����š�����������վ�ż���ʿ�����̲��Ź���
���˳�������ǰ��һ������Ļ��Ǻӣ����Ҹ���һˮ�ţ����ӻ��ǺӺ�
�ٺӼ�С�ػ��ӡ����Ž��и߸ߵ���¥�����м���ʿ����ǹ�ھ��䡣��
¥�����Ž����Ҷ���š�����Ϊ����ʧ�𣬵����ڳ�ǽ���Ǻں���
�ģ���˰�ֽ���ֵĹٸ���ʾ(gaoshi)���Ե��ر����ۡ�
LONG );
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
	set("exits", ([
		"south" : __DIR__"beimendajie",
		//"east" : "/d/shouxihu/hongqiao",
		//"north" : "/d/shaolin/yidao",
		"north" : "/d/nanyang/yidao",
		"west"  : "/d/huanghe/caodi1",
		"up"    : __DIR__"chenglou",
		"northeast" : __DIR__"hangou2",
	]));
        set("objects", ([
                "/kungfu/class/yunlong/ma" : 1,
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
        ]));
//	set("no_clean_up", 0);
	set("outdoors", "city");
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n����֪��\n��ҩ��\n";
}

