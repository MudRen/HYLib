// baling/edao1
// Room in ����
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
��˳�Ŵ������ǰ�ߣ��������߽���ɽ�һ���Ǹ�������ĸ�ɽ
���룬һ���Ƕ��͵�ɽ�£�����Ͽ������ȥ���о���һ��ѣ�Σ��㲻��
С�ĵ����ߣ����˵��ٶ�Ҳ������������.	
LONG
	);

	set("exits", ([
		"southup" : __DIR__"shandao5",
                "eastdown" : __DIR__"shandao7",
	]));

 	set("outdoors", "baling");
	setup();
	replace_program(ROOM);
}


