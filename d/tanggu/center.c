inherit ROOM;
void create()
{
        set("short", "���Ĺ㳡");
        set("long", @LONG
���������������Ĺ㳡������������������ڡ���������������������
���ǵƻ�ͨ����æµ��һ�������������ϲ����������һ�ߣ��㳡�������ֶ�
���Ķ��У����ٽ�������켣���С�
LONG );

        set("exits", ([
                "north" : __DIR__"stbeijie1",
		"south" : __DIR__"stnanjie2",
                "southeast" : __DIR__"kongchangdi",
		"east" : __DIR__"stdongjie1",
		"west" : __DIR__"stxijie1",
	]));

	set("outdoors", "����");

	set("objects", ([
                __DIR__"npc/shuibing" : 2+random(2),
      	]));

	setup();
}
