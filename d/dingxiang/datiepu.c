// /d/yazhang/datiepu.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "������");
	set("long", @LONG
�����Ƕ�������������̣�һ���ž�������������Ĵ���������
�����ȥ��������һ���Ǿ�Ʒ��������������Լ����������
LONG
	);
set("exits", ([
                 "north" : __DIR__"dongdajie1",    
	]));
	set("objects",([
	__DIR__"npc/tiejiang":1,
	]));
       setup();
	replace_program(ROOM);
}
