// baling/edao1
// Room in ����
inherit ROOM;

void create()
{
	set("short", "����Ͽ");
	set("long", @LONG
�ֳ�ţ��Ͽ,ͭ��Ͽ,λ�ںϴ��ξ���һ��,ȫ��3ǧ��.Ͽ
�н����ļ���ˮ��Ī�⣬Ͽ��Ⱥ����ʣ���������о���̲
��ʨ�ӷء�Ц���С�ţ�Ƕ�������ʯ��ĥ������������ۡ�
LONG
	);

	set("exits", ([
		"north" : __DIR__"yincheng",
                "southeast" : __DIR__"shanjiao",
	]));

 	set("outdoors", "baling");
	setup();
	replace_program(ROOM);
}


