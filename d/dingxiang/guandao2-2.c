// /d/yazhang/guandao2.c
// Room in ����
// modify by yang

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
������һ���ٵ��ϣ����׿�Ĵ���ɲ�����������������ӵ����
·��������Ⱥ�����˶����������ε������ˡ�ż���йٱ�����ɳ۶�����
LONG 
        );
	set("exits", ([
		"north" : __DIR__"guandao2-1",
		"south" : __DIR__"guandao2-3",
	]));
	
	
 	set("outdoors", "yazhang");
	setup();
	replace_program(ROOM);
}

