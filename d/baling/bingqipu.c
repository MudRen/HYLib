// baling/nandajie3
// Room in ���� 
// laowuwu 99/04/11
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��˵��ұ������Ǽ���ʦ���������Բ�����ʲô���ı����ر��ǹ�
����������һ���ģ�����������û��ġ�
LONG
	);

	set("exits", ([
		"south":__DIR__"nandajie3",
	]));
set("objects", ([
		__DIR__"npc/tiejiang" : 1
	]));
	setup();
	replace_program(ROOM);
}
