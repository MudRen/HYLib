// Room: /jingzhou/chaliao.c
// congw 980830

inherit ROOM;

void create()
{
        set("short", "���ݲ���");
	set("long", @LONG
�����Ǿ��ݵĲ��ţ�������·�˶�붼������Ъ�š����������ˮ������
��������ЩЪ�ŵ��ˣ������̸Ц����ͷ�Ӷ�����Ҫ����������ƹʺ�ҥ�ԣ�
�����Ǹ������ڡ�
LONG
	);
	set("resource/water", 1);

	set("exits", ([
                "east" : __DIR__"nandajie1",
	]));

	set("objects", ([
                __DIR__"afang" : 1,
	]));

        set("no_fight", 1);
	setup();
	replace_program(ROOM);
}

