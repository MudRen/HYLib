// Room: /d/nanyang/ruzhou.c
// Last Modified by winder on Nov. 20 2001

inherit ROOM;

void create()
{
	set("short", "����ؿ�");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ����̣�
���Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ������
����������߷ɳ۶���������һ·��������·�������������������
�֡����������ݳǲ�Զ�����Կ���Զ���ĳ�ǽ
LONG );
	set("exits", ([
		"south" : __DIR__"yidao3",
		"westdown"  : "/d/songshan/taishique",
		"northwest" : "/d/cangzhou/sroad4",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 3,
		"/d/city/npc/bing" : 3,
	]));
	set("outdoors", "nanyang");
	set("coor/x", 10);
	set("coor/y", 700);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
