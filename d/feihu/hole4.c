//ɽ��
// by steel 

inherit ROOM;

void create()
{
	set("short", "ѩ��");
	set("long", @LONG
	����ѩɽ�е�һ����,���ڷ�ѩ��ȻС�˵�,�����溮�ޱ�,����û
��ʲô������������������.  
LONG
	);
	
	set("exits", ([
                "southeast" : __DIR__"hole3",
                "west" : __DIR__"hole"+(random(10)+1),
                "north":__DIR__"hole"+(random(10)+1),
                "east":__DIR__"hole"+(random(10)+1),
                "northeast":__DIR__"hole5",     
          ]));
	setup();
	replace_program(ROOM);
}

