// baling/edao1
// Room in ����
inherit ROOM;

void create()
{
	set("short", "Ͽ��");
	set("long", @LONG
��˳��ɽ·�ߵ������������ĵ��ƽϵף�ɽ������ˮ�������
��������ĺܷ��֡�ֲ��Ҳ�����Ķ���������
LONG);

	set("exits", ([
               "eastdown" : __DIR__"gudi",
               "westup" : __DIR__"shanru",
               
	]));

 	set("outdoors", "baling");
	setup();
	replace_program(ROOM);
}


