// /d/yazhang/guandao1.c
// Room in ����
// modify by yang

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
������һ���ٵ��ϣ����׿�Ĵ���ɲ�����������������ӵ����
·��������Ⱥ�����˶����������ε������ˡ�ż���йٱ�����ɳ۶�����
�����������£��������������ˡ�
LONG 
        );
	set("exits", ([
		"north" : __DIR__"nanmen",
		"south" : __DIR__"guandao2",
	]));
	
	
 	set("outdoors", "yazhang");
	setup();
	replace_program(ROOM);
}

