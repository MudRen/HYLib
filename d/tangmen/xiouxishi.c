// Room: /d/tangmen/xiouxishi.c
// xws  1998/11/05

inherit ROOM;

void create()
{
	set("short", "��Ϣ��");
	set("long", @LONG
    ����һ��ܴ����Ϣ�ң�����Ҳ�ܼ򵥡���ǽ����ʮ�����񴲡��������ŵ�
�������¶��ԣ������Ӷ��Ǻ����Ĵ������������Ŵ��ǿյ�,��������ŵ����˹�ȥ
LONG
	);

	
	set("sleep_room", "1");
	set("no_fight", "1");
       

	set("exits", ([
		"south" : __DIR__"lianwuchang",
		"north" : __DIR__"meiyuan1",
	]));

	setup();
}

