// Room: /wizhome/lanzhou/dongmen.c
// Date: xws 98/10/13

#include <ansi.h>
inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "����");
	set("long", @LONG
�������ݳǵĶ����ţ���������Ļ��������������ķ�ɳ��ʴ�Ե���Щ
�ưܡ��������Ϸ�����ǿǿ�����ϳ������š��������֣���ǽ�����ż���ͨ����
ʾ(gaoshi)��������߽����������ﷸ�������������ӻ���ԭ���ٱ��ǽ䱸ɭ�ϣ�
�������ͽ�ס���˽������ʡ�һ����ֱ����ʯ��������������졣�����ǽ��⣬
��������������˶���������ǣ��򶫵�����ԭ����౾����Ҳ�������ڴ�����
������������ȥ�����Լ��ֵĹϹ���������������Ʒ�������ǳ��
LONG
	);
        set("outdoors", "lanzhou");

	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits", ([
		"west"  : __DIR__"dongdajie1",
		"north"  : __DIR__"majiu",	
		
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

