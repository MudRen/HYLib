// /d/zhuojun/dadao2.c
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
                "northeast":__DIR__"dadao3",  
                "southwest":__DIR__"dadao1",    
	]));
       setup();
	replace_program(ROOM);
}
