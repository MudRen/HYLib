// baling/edao1
// Room in ����
inherit ROOM;

void create()
{
	set("short", "����Ͽ");
	set("long", @LONG
����Ͽ,�����ı�Ͽ,ȫ��3.7ǧ��.Ͽ�ڰ����о�ʯ������
����ʯ�ˣ��׳��ı�ʯ���Ա����¸ߴ���һ��ɲ����������
Ͽ�Ը����������Ͽ�����������𣬹�ʯ��ᾣ���ˮ������
�ۣ�Ϊ���꽭С��Ͽ�����վ���һ��Ͽ��
LONG
	);

	set("exits", ([
                "northeast" : __DIR__"edao4",
                "southeast" : __DIR__"edao8",
	]));

 	set("outdoors", "baling");
	setup();
	replace_program(ROOM);
}


