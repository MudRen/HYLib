// baling/edao1
// Room in ����
inherit ROOM;

void create()
{
	set("short", "��·��");
	set("long", @LONG
���ߵ�һ������·�ڣ�����ͨ�����Ĵ�·������
���Ҫ����ɽ���ĵؽ��ˡ�
LONG
	);

	set("exits", ([
                "southwest" : __DIR__"edao13",
                "northeast" : __DIR__"edao7",
	]));

 	set("outdoors", "baling");
	setup();
	replace_program(ROOM);
}


