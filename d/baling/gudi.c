// baling/edao1
// Room in ����
inherit ROOM;

void create()
{
	set("short", "�ȵ�");
	set("long", @LONG
��˳��Ͽ�ȼ��ѵ����ţ���Ȼ����ǰ��Ȼ���ʣ�������ӭ��������
����羰������ɽˮ�续���������¡�һ�ֻع���Ȼ�ĸо���Ȼ������ʹ
�㲻���������涯������ᡣ
LONG);

	set("exits", ([
                "eastup" : __DIR__"xiagu",
                "westup" : __DIR__"xiagu1",
	]));

 	set("outdoors", "baling");
	setup();
	replace_program(ROOM);
}


