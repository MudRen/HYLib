// /d/yazhang/dangpu.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "����");
	set("long", @LONG
���Ƕ����������һ�ҵ����ˣ�������������ƽ�ųƣ���˵����
�����˵��ѵ㣬��������򵽲��ٺö�����
LONG
	);
set("exits", ([
                   "north" : __DIR__"xidajie2",  
	]));
	set("objects",([
	__DIR__"npc/zhou":1,
	]));
       setup();
	replace_program(ROOM);
}	
