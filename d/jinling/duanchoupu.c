//jinling duanchoupu
inherit ROOM;


void create()
{
	set("short","�����");
	set("long", @LONG
���߽�һ������˲�ƥ�ĵ���,ԭ����һ�ҳ���̡�����������
�����У����Կ�����������ⲻ��������ר�������ĵط�������
�������·��ġ�
LONG
	);
	set("exits", ([
		"south"    	: __DIR__"xijie2",
	]) );

	set("objects", ([
		__DIR__"npc/buseller" : 1,

			]) );


	setup();
}
