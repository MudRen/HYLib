// /d/taiyuan/huichuntang.c
// Room in ̫ԭ
// rich 99/05/05
inherit ROOM;
void create()	
{
	set("short", "�ش���");
	set("long", @LONG
����һ�����ϰ�����ʷ�����ֺţ�ҩ�Ķ��Ǵ�ԭ����ֱ�ӹ�������
�������ֵĵ��䣬���������˶�Ը����������ҩ��
LONG
	);
set("exits", ([
                "east" : __DIR__"nandajie2", 
	]));
	set("objects",([
	__DIR__"npc/leng":1,
	]));
       setup();
	replace_program(ROOM);
}	
