// little hotel
// by steel 

inherit ROOM;

void create()
{
	set("short", "ѩԭС��");
	set("long", @LONG
        ����һ�Һ�С�ľƵ�,�����⻹����,�ڷ�ѩ�б������˵���
����,��Ҫͣ������һ���������Ҿ�,ůһů���ӡ�	   
LONG
	);
    set("exits", ([
		"east" : __DIR__"road3",
			]));
    set("objects",([
          __DIR__"npc/xiaoer":1,
    ]) ); 
	setup();
	replace_program(ROOM);
}

