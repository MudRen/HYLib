// Room: /d/quanzhou/jiaxing.c
// Date: May 21, 96   Jay

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
�����Ǿ�������С�򡣳Ƕ��Ƿ羰�续���Ϻ��ϰ�������
�����ʵ���羰��������Χ�кܶ���Ȫ�����Ա���Ϊ���ء�
LONG );
	set("exits", ([
                "west" : __DIR__"qzroad2",
                "east" : __DIR__"nanhu",
		"south" : __DIR__"jxnanmen",
	]));
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

