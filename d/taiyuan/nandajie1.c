// /d/taiyuan/nandajie1.c
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
                "north" : __DIR__"nandajie2", 
                "south" : __DIR__"nanmen", 
                "east" : __DIR__"wanjinzhai", 
                "west" : __DIR__"shuyuan",       
	]));
       setup();
	replace_program(ROOM);
}	
