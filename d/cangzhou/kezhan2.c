// Room: /d/cangzhou/kezhan2.c

inherit ROOM;

void create()
{
	set("short", "��ջ��¥");
	set("long", @LONG
�����ǲ��ݴ��ջ�Ķ�¥����¥�²�ͬ������ֻ��ס�޲��ܳ�����ǳ���
¡���������˵��˴˵ض�ѡ��������ţ���С����������æ������ת���Ӵ���
��ǻ�����Ŀ��ˡ���һ������(paizi)��
LONG );
	set("no_fight", 1);
	set("valid_startroom", 1);
        set("no_sleep_room",1);
	set("item_desc", ([
		"paizi" : "�ŷ���ÿҹ����������\n",
	]));
	set("exits", ([
		"down" : __DIR__"kezhan",
		"enter"   : __DIR__"sleeproom",
	]));

	setup();
}
