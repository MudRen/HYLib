// /d/taiyuan/xidajie2.c
// Room in ̫ԭ
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
��������������У���ô����������ԼԼ�ܿ��������ţ�������
���Ĺ㳡��������һ�Ҳ�ݣ�������̫ԭ��˾�����ڵ��ˡ�
LONG
	);
set("outdoors", "taiyuan");
set("exits", ([
                "north" : __DIR__"chaguan", 
                "south" : __DIR__"yansi", 
                "west" : __DIR__"xidajie1", 
                "east" : __DIR__"center",       
	]));
       setup();
	replace_program(ROOM);
}	
