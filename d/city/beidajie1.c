// Room: /city/beidajie1.c
// YZC 1995/12/04 

inherit ROOM;
void create()
{
	set("short", "ʮ�ﳤ��");
	set("long", @LONG
ʮ�ﳤ�����ǳ���ķ����ضΣ�һ�����ϣ�һ�ɵƺ���̣���Ϊ��
�֡�Ц�������������������������һƬ��������Ķ��䣬�㲻����Գ
��������ʹ�ͣ������һ����������һ��������¡�Ŀ�ջ�����Ը���
�����ǽ�����������˵Ҳ�������ǵ��Ļ�ص㡣������һ��Ǯׯ������
�������������Ľ���������
LONG
	);
        set("outdoors", "city");
	set("objects", ([
		CLASS_D("btshan") + "/ouyangke" : 1,
		__DIR__"obj/jiao" : 1,
	]));
	set("exits", ([
		"east"  : __DIR__"kedian",
		"south" : __DIR__"guangchang",
		"west"  : __DIR__"qianzhuang",
		"north" : __DIR__"beidajie2",
	]));
	set("objects", ([
"/clone/master/master"+(random(24)+1): random(2),
	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

