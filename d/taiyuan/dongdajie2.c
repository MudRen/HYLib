// /d/taiyuan/dongdajie2.c
// Room in ̫ԭ
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
�����������������ô������ȥ�Ѿ����Կ������������ӣ�
������̫ԭ�����Ĺ㳡��������һ��С�ƹݣ����洫��һ�󳪽�����ԭ
��������һ�Ҷĳ���
LONG
	);
set("outdoors", "taiyuan");
set("exits", ([
                "north" : __DIR__"jiuguan", 
                "south" : __DIR__"duchang", 
                "east" : __DIR__"dongdajie1", 
                "west" : __DIR__"center",       
	]));
       setup();
	replace_program(ROOM);
}
