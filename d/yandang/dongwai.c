// Room: /d/yandang/dongwai.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
'�ᵱ�����,һ����ɽС',�Ӵ˴���ȥ,Զɽ��ˮ,�޲�������Ŀ,
Զ��ɽ�����,Ⱥɽ����,Ϧ������,�����޹�,����һ�����ɻ���.����
��һʯһľ,�޲���������.����̾Ϊ��ֹ.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "enter" : __DIR__"shandong7.c",
  "west" : __DIR__"xiyaotai",
  "east" : __DIR__"dongyaotai",
]));
	set("outdoors", "/d/yandang");

	setup();
	replace_program(ROOM);
}
