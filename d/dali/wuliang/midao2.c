// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "�ܵ�");
	set("long", @LONG
�������ܵ����ں����ģ�ʲôҲ�������У���ֻ����������ǰ�ߣ��ܷѾ�
�����һ�������ܵ���
LONG
	);
        
	set("exits", ([
	      "south" : __DIR__"midao3",
              "northup" : __DIR__"midao1",
	]));

	setup();
	replace_program(ROOM);
}
