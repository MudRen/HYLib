// /d/yazhang/guandao3.c
// Room in ����
// modify by yang

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
������һ���ٵ��ϣ����׿�Ĵ���ɲ�����������������ӵ����
·��������Ⱥ�����˶����������ε������ˡ�
LONG 
        );
	set("exits", ([
		"north" : __DIR__"guandao2-4",
		"southeast" : __DIR__"xiaolu1",
	]));
	
	
 	set("outdoors", "yazhang");
	setup();
	replace_program(ROOM);
}

