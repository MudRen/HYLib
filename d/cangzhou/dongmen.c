// Room: /d/cangzhou/dongmen.c

inherit ROOM;
string look_gaoshi();

void create()
{
        set("short", "���ݶ���");
        set("long", @LONG
���ǲ��ݶ����ţ��������Ϸ����š����š�����������֣���ǽ�����ż��Ź�
����ʾ(gaoshi)���ٱ��Ǿ����ע���Ź������ˣ������С��Ϊ�һ����ֱ
����ʯ���������������졣����Ľ�Ұ����һƬ���֡�
LONG );
        set("exits", ([
                "west" : __DIR__"dongjie1",
        	"east" : __DIR__"eroad1",
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
