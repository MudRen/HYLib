// Room: /d/cangzhou/ximen.c

inherit ROOM;
string look_gaoshi();
void create()
{
        set("short", "��������");
        set("long", @LONG
���ǲ��������ţ�����ǰ�����⵽���˵Ĺ�������Ե���Щ�ưܡ���������
������ǿǿ�����ϳ������š��������֡��������ﷸ��������ıؾ�֮�أ���
���ǽ䱸ɭ�ϣ��������ͽ�ס�������ʡ�һ����ֱ����ʯ��������������
�졣
LONG );
        set("exits", ([
		"east" : __DIR__"xijie1",
		"west" : __DIR__"wroad1",
        ]));
        set("item_desc", ([
                "gaoshi" : (:look_gaoshi:),
        ]));

	set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
        ]));
        	set("outdoors", "����");

	setup();
}

string look_gaoshi()
{
        return FINGER_D->get_killer() + "\n����֪��\n����ͨ\n";
}
