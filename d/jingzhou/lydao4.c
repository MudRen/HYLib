// Room: /d/jingzhou/lydao4.c
// congw 980830

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ���������������������������ֹ�������ɫ��ʯ�ӣ�������ͷ���졣
����������ֵ��ϴ���ˡ������м���С������ˣ����������г��΢�紵����
ʹ����ȴ�˽����ϵ��������
LONG
	);
        set("outdoors", "jingzhou");
        
	set("exits", ([
		"eastup" : __DIR__"nandajie2",
		"west" : __DIR__"lydao3",
	]));

	setup();
	replace_program(ROOM);
}

