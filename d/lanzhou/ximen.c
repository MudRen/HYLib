// Room: /wizhome/lanzhou/ximen.c
// Date: inca 98/08/14

#include <ansi.h>
inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "����");
	set("long", @LONG
�������ݳǵ������ţ���������Ļ��������������ķ�ɳ��ʴ�Ե���Щ
�ưܡ��������Ϸ�����ǿǿ�����ϳ������š��������֣���ǽ�����ż���ͨ����
ʾ(gaoshi)��������߽����������ﷸ�������������ӻ���ԭ���ٱ��ǽ䱸ɭ�ϣ�
�������ͽ�ס���˽������ʡ�һ����ֱ����ʯ��������������졣�����ǽ��⣬
һֱ����ȥ���Ǿ��������Ķػͣ�����ο����ҵ��򵼺����������������ȥ
�����ػ͡���౾���˸������ڴ����ﾭ����������ȥ�����Լ��ֵĹϹ�������
���������Ʒ�������ǳ��
LONG
	);
        set("outdoors", "lanzhou");

	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits", ([
                "west"  : "/d/xingxiu/xxroad1",
                "east"  : __DIR__"xidajie1",
		
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

