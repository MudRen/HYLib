// baling/edao1
// Room in ����
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
   ����λ�ڳ����ڽ����㴦��ˮ½��ͨ������С��ڽ��Ż���֮��
�����ڽ���������ʼ�ɢ�ء�����ش���Ͽ�������ĵش���
LONG
	);

	set("exits", ([
                "south" : __DIR__"eroad3",
                "east" : __DIR__"shandao1",
	]));

 	set("outdoors", "baling");
	setup();
	replace_program(ROOM);
}


