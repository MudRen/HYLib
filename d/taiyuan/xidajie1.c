// /d/taiyuan/xidajie1.c
// Room in ̫ԭ
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
̫ԭλ���������ֵ�������Կ���������������ţ��ֵ��ı�����
һ�����У�������һ����վ��һƥƥ����ɳ۶�����
LONG
	);
set("outdoors", "taiyuan");
set("exits", ([
                "north" : __DIR__"shanghang", 
                "south" : __DIR__"yizhan", 
                "west" : __DIR__"ximen", 
                "east" : __DIR__"xidajie2",       
	]));
        set("objects", ([
              "/clone/misc/dache" : 1,
        ]) );		
       setup();
	replace_program(ROOM);
}	
