// baling/edao1
// Room in ����
inherit ROOM;

void create()
{
	set("short", "Ͽ��");
	set("long", @LONG
��˳��ɽ·�ߵ������������ĵ��ƽϵף�ɽ������ˮ�������
��������ĺܷ��֡�ֲ��Ҳ�����Ķ������������滹�ܿ���һƬïʢ��
���֡�
LONG);

	set("exits", ([
               "westdown" : __DIR__"gudi",
               "eastup" : __DIR__"shanlu1",
               "east" : __DIR__"xiaoshulin",
               
	]));

 	set("outdoors", "baling");
	setup();
	replace_program(ROOM);
}


