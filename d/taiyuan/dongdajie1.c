// /d/taiyuan/dongdajie1.c
// Room in ̫ԭ
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
�������������ô�������߾���̫ԭ�Ķ����ˣ�������̫ԭ
�Ļʹ���������̫ԭ�Ĺ����ݡ�
LONG
	);
set("outdoors", "taiyuan");
set("exits", ([
                "north" : __DIR__"huanggong", 
                "south" : __DIR__"guobingguan", 
                "east" : __DIR__"dongmen", 
                "west" : __DIR__"dongdajie2",       
	]));
	set("objects",([
	__DIR__"npc/yegou":1,
	]));
       setup();
	replace_program(ROOM);
}	
