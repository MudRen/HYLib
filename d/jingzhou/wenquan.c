// Room: /d/jingzhou/wenquan
// congw 980830

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�㿴��һ����Ȫ�����������ǰ����������ð��������Ȫˮ����Ȫ�䲻��
������ʹ���뵽��ȥ��һ�ݣ���˵�����������β���
LONG
	);
        set("outdoors", "jingzhou");
	
	set("exits", ([
		"northup" : __DIR__"lydao2",
		"eastup" : __DIR__"lydao3",
	]));

	setup();
	replace_program(ROOM);
}

