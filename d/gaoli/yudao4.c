// /d/gaoli/yudao4
// Room in ����
inherit ROOM;
void create()	
{
	set("short", "�ʳ�����");
	set("long", @LONG
����Ľֵ������ɾ�������������·�汻��ˮ��ù����羵����
���ڲ��Ǹߴ��ΰ�Ļʳǳ�ǽ�������Ǹ����ĳǷ����ţ����������Ķ�
��һЩʿ����
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
                "north":__DIR__"yudao6", 
                "south":__DIR__"yudao2", 
                "west":__DIR__"qinglong-1", 
                "east":__DIR__"yamen",
	]));
       setup();
	replace_program(ROOM);
}	
