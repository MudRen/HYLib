// Room: /d/cangzhou/nanmen.c

inherit ROOM;
string look_gaoshi();
void create()
{
        set("short", "��������");
        set("long", @LONG
���Ǿ��ǲ��ݳǵ��ϳ����ˣ���ǽ�������˹���ƣ������˻������̸���
��ҵ�Ĺ�棬һ���ֳֳ����������׵��佫�������Ļ���Ц��������������
���ĵ��̲��Ź��������ˡ�
LONG );
        set("exits", ([
                "north" : __DIR__"nanjie1",
                "south" : __DIR__"sroad1",
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
