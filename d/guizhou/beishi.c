inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǵı�������ҵ���������ǹ��ú;��ӵ�פ�أ�����Ϊ�ϳǱ�
�С��������������������ַǷ���˿�����������´��ҵ����ӡ�
LONG );

	set("exits", ([
                          "north"      : __DIR__"beimen",
                         "south"      : __DIR__"center",
                         "northwest"      : __DIR__"chaguan",
                         "northeast"      : __DIR__"dangpu",
                         "southwest"      : __DIR__"qianzhuang",
		        "southeast"      : __DIR__"tiejiangpu",
	]));


 	set("outdoors", "guizhou");
	setup();
	replace_program(ROOM);
}



