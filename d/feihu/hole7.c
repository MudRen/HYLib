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
                "south" : __DIR__"hole6",
                "northwest":__DIR__"hole"+(random(10)+1),
                "east":__DIR__"hole"+(random(10)+1),
                "west":__DIR__"hole8",     
          ]));
	setup();
	replace_program(ROOM);
}

