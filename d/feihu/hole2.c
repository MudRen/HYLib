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
                "north" : __DIR__"hole1",
                "west" : __DIR__"hole"+(random(10)+1),
                "north":__DIR__"hole"+(random(10)+1),
                "south":__DIR__"hole"+(random(10)+1),
                "northwest":__DIR__"hole3",     
          ]));
	setup();
	replace_program(ROOM);
}

