// taijie.c
// bbb 1997/07/20
// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "̨��");
	set("long", @LONG
һ��̨��б���������ߵ�һ�ٶ༶ʱ������������¡��¡��ˮ�������ж�
���༶��ˮ���Ѿ����������ǰ�沢�й���͸�룬�ߵ�̨�׵ľ�ͷ��ǰ���Ǹ�
��������Ķ�Ѩ��
LONG
	);

	set("exits", ([
            "down" : __DIR__"dong1",
            "out" : __DIR__"jiangpan",
	]));
	setup();
}
