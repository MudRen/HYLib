inherit ROOM;

void create()
{
	set("short", "����ʮ�ֽ�ͷ");
	set("long", @LONG
���ǹ��������ϱ��Ͷ����Ľ���㡣����ɫɫ�Ľ������ڶ��ߴ���
�˷������಻����·�ϳ�ˮ��������ɫ����Ħ����࣬���ַǷ������
���Ը���������¥�ƣ������Ǿ��ӵ�פ�أ���������������ӡ�
LONG );

	set("exits", ([
                          "north"      : __DIR__"beishi",
                         "south"      : __DIR__"chengmen",
                         "west"      : __DIR__"xidajie",
                         "east"      : __DIR__"dongdajie",
		
	]));
set("objects",([
__DIR__"npc/chefu":1,
"/clone/npc/man":2,	
     "/clone/misc/dache":1,
]));

 	set("outdoors", "guizhou");
	setup();
	replace_program(ROOM);
}



