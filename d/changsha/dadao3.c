// /d/zhuojun/dadao3.c
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
                "northwest":"/d/yueyang/nanmen",  
                "southwest":__DIR__"dadao2",    
	]));
       setup();
	replace_program(ROOM);
}
