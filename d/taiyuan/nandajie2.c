// /d/taiyuan/nandajie2.c
// Room in ̫ԭ
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "�ϴ��");
	set("long", @LONG
��������ʯ�̳ɵĽֵ��ϣ��ֵ���������������ô�������Ը�
��������ӵ��������������Ĺ㳡�ˣ��������ߵ����������������ϣ�
��һƬ������¡�ľ���
LONG
	);
set("outdoors", "taiyuan");
set("exits", ([
                "north" : __DIR__"center", 
                "south" : __DIR__"nandajie1", 
                "east" : __DIR__"qibaozhai", 
                "west" : __DIR__"huichuntang",       
	]));
	set("objects",([
	__DIR__"npc/chefu":1,
	]));
       setup();
	replace_program(ROOM);
}	
