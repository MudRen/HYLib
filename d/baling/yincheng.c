// baling/edao1
// Room in ����
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
  �������꽭���㴦�������أ����滷ˮ��һ��ͨ½�����ư뵺����
�����س�����֮�ף���Ϊ�������¾���ó�׵����ģ��������λ��Ҳ
�Ǳ��ұ���֮�ء�
LONG
	);

	set("exits", ([
                "south" : __DIR__"edao3",
                "west" : __DIR__"eroad2",
	]));

 	set("outdoors", "baling");
	setup();
	replace_program(ROOM);
}


