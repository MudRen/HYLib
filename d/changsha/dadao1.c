// /d/zhuojun/dadao1.c
// Room in �ÿ�
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "�潭ɽ·");
	set("long", @LONG
������һ����ʯ����ϣ������ǹ������潭,�˴���
Ⱥϡ�٣�����Ҳ�����ĵġ�
LONG
        );
set("outdoors", "changsha");
set("exits", ([
                "northeast":__DIR__"dadao2",  
                "south":__DIR__"beimen", 
	]));
       setup();
	replace_program(ROOM);
}
