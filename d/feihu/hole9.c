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
                "southwest" : __DIR__"hole8",
                "northwest":__DIR__"hole"+(random(10)+1),
                "west":__DIR__"hole"+(random(10)+1),
                "northeast":__DIR__"hole"+(random(10)+1),
                "north":__DIR__"hole10",     
          ]));
	setup();
	replace_program(ROOM);
}
