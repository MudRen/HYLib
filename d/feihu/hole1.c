//ɽ��
// by steel 

inherit ROOM;

void create()
{
	set("short", "ѩ��");
	set("long", @LONG
	����ѩɽ�е�һ����,���ڷ�ѩ��ȻС�˵�,�����溮�ޱ�,����û
��ʲô������������������.  ���Ϸ�͸��һ��ѩ�⡣
LONG
	);
	
	set("exits", ([
		"southeast":__DIR__"road5",
                "north" : __DIR__"hole"+(random(10)+1),
                "west" : __DIR__"hole"+(random(10)+1),
                "northwest":__DIR__"hole"+(random(10)+1),
                "south":__DIR__"hole2",     
          ]));
	setup();
	replace_program(ROOM);
}

