// /d/taiyuan/chaguan.c
// Room in ̫ԭ
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "���");
	set("long", @LONG
����һ����ݲ�����һ����ϯ��ס�����⣬��������ɢ���ڵ��ϣ�
���ﴫ��һ����к�����������һ��Ϸ԰�ӡ�
LONG
	);
set("exits", ([
                "enter" : __DIR__"xiyuan", 
                "south" : __DIR__"xidajie2",    
	]));
	set("objects",([
	__DIR__"npc/xiaoer":1,
	]));
	set("resource/water",1);
       setup();
	replace_program(ROOM);
}	
