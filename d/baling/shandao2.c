// baling/edao1
// Room in ����
inherit ROOM;

void create()
{
	set("short", "�ٲ���");
	set("long", @LONG
��˳�Ŵ������ǰ�ߣ��������߽���ɽ�һ���Ǹ�������ĸ�ɽ
���룬һ���Ƕ��͵�ɽ�£�����Ͽ������ȥ���о���һ��ѣ�Σ��㲻��
С�ĵ����ߣ����˵��ٶ�Ҳ������������.	
LONG
	);

	set("exits", ([
		"westdown" : __DIR__"shandao1",
                "northeast" : __DIR__"shandao3",
	]));

 	set("outdoors", "baling");
	setup();
	replace_program(ROOM);
}


